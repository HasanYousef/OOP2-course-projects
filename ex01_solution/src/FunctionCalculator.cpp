#include "FunctionCalculator.h"

#include "Sin.h"
#include "Ln.h"
#include "Poly.h"
#include "Mul.h"
#include "Add.h"
#include "Comp.h"
#include "Log.h"

#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>

FunctionCalculator::FunctionCalculator(std::istream& istr, std::ostream& ostr)
    : m_actions(createActions()), m_functions(createFunctions()), m_istr(&istr), m_ostr(ostr)
{
}

void FunctionCalculator::run()
{
    //get max number of function
    readMaxNumOfFuncs();
    
    m_ostr << std::setprecision(2) << std::fixed;
    do
    {
        m_ostr << '\n';
        printFunctions();
        m_ostr << "Enter command ('help' for the list of available commands): ";
        // try to read ad action from the user
        try {
            const auto action = readAction();
            runAction(action);
        }
        catch (std::domain_error err) {
            m_ostr << err.what();
        }
        catch (std::out_of_range err) {
            m_ostr << err.what();
        }
        catch (std::length_error err) {
            std::string answer;
            m_ostr << "The number you gave is smaller than the number of functions, " <<
                "Do you want to resize anyway? if yes it will delete the last functions from the list (y/n)?\n";
            *m_istr >> answer;
            if (answer == "yes" || answer == "y") {
                // removing the last functions from the functions list
                std::vector<std::shared_ptr<Function>> newFuncs;
                m_maxNumOfFuncs = std::stoi(err.what());
                for (int i = 0; i < m_maxNumOfFuncs; i++)
                    newFuncs.push_back(m_functions[i]);
                m_functions = newFuncs;
            }
        }
    } while (m_running);
}

void FunctionCalculator::eval()
{
    if (auto i = readFunctionIndex(); i && i != -1)
    {
        auto x = 0.;
        auto sstr = std::ostringstream();

        try {
            // if the didn't give a valid int it will throw an err
            std::string num;
            *m_istr >> num;
            x = std::stod(num); //convert to double: stod do throw automatic
            sstr << std::setprecision(2) << std::fixed << x;
            m_ostr << m_functions[*i]->to_string(sstr.str())
                << " = "
                << (*m_functions[*i])(x)
                << '\n';
        }
        //if intered an invalid int
        catch (const std::exception& err) { // exeption instead std::ios::failiar
            m_ostr << err.what();
        }
    }
}

void FunctionCalculator::poly()
{
    try {
        // if the didn't give a valid int it will throw an err
        int n;
        n = readNum();  //added
        auto coeffs = std::vector<double>(n);
        for (int i = 0; i < coeffs.size(); i++) {
            n = readNum(); //added
            coeffs[i] = n;
        }
        m_functions.push_back(std::make_shared<Poly>(coeffs));
    }
    //if intered an invalid int
    catch (const std::ios_base::failure& err) {
        m_ostr << err.what();
    }
}

void FunctionCalculator::log()
{
    try {
        // if the didn't give a valid int it will throw an err
        int base;
        base = readNum();
        if (base <= 1) {
            throw std::range_error("can't insert a base less than 1\n");
        }
        if (auto f = readFunctionIndex(); f != -1 && f) //added f!=-1 to make sure valid input
        {
            m_functions.push_back(std::make_shared<Log>(base, m_functions[*f]));
        }
    }
    //if intered an invalid int
    catch (const std::ios_base::failure& err) {
        m_ostr << err.what();
    }
    catch (const std::range_error negNum) {
        m_ostr << negNum.what();
    }
}

void FunctionCalculator::del()
{
    if (auto i = readFunctionIndex(); i != -1 && i)
    {
        m_functions.erase(m_functions.begin() + *i);
    }
}

void FunctionCalculator::help()
{
    m_ostr << "The available commands are:\n";
    for (const auto& action : m_actions)
    {
        m_ostr << "* " << action.command << action.description << '\n';
    }
    m_ostr << '\n';
}

void FunctionCalculator::exit()
{
    m_ostr << "Goodbye!\n";
    m_running = false;
}

void FunctionCalculator::printFunctions() const
{
    m_ostr << "List of available gates:\n";
    for (decltype(m_functions.size()) i = 0; i < m_functions.size(); ++i)
    {
        m_ostr << i << ".\t" << m_functions[i]->to_string("x") << '\n';
    }
    m_ostr << '\n';
}

std::optional<int> FunctionCalculator::readFunctionIndex() const
{
    int i = 0;
    std::string str;
    try {
        *m_istr >> str;
        i = stoi(str);
        if (i >= m_functions.size())
        {
            m_ostr << "Function #" << i << " doesn't exist\n";
            return {};
        }
        return i; //valid input
    }
    catch (const std::exception& err) {
        m_ostr << err.what();
    }
    return -1; //wrong input
}

FunctionCalculator::Action FunctionCalculator::readAction() const
{
    auto action = std::string();
    *m_istr >> action;

    for (decltype(m_actions.size()) i = 0; i < m_actions.size(); ++i)
    {
        if (action == m_actions[i].command)
        {
            return m_actions[i].action;
        }
    }

    // in case that the user entered an invalid action
    throw std::domain_error("Command not found\n");
}

void FunctionCalculator::runAction(Action action)
{
    //if reached the max num of functions
    if (m_functions.size() >= m_maxNumOfFuncs && 
        (action == Action::Poly ||
            action == Action::Mul ||
            action == Action::Add || 
            action == Action::Comp ||
            action == Action::Log)) {
        throw std::out_of_range("You can't add a new function, you reached the max number of fucntions\n");
    }

    switch (action)
    {
        default:
            m_ostr << "Unknown enum entry used!\n";
            break;

        case Action::Eval: eval();             break;
        case Action::Poly: poly();             break;
        case Action::Mul:  binaryFunc<Mul>();  break;
        case Action::Add:  binaryFunc<Add>();  break;
        case Action::Comp: binaryFunc<Comp>(); break;
        case Action::Log:  log();              break;
        case Action::Read: readFile();         break;
        case Action::Resize: resize();         break;
        case Action::Del:  del();              break;
        case Action::Help: help();             break;
        case Action::Exit: exit();             break;
    }
}

FunctionCalculator::ActionMap FunctionCalculator::createActions()
{
    return ActionMap
    {
        {
            "eval",
            "(uate) num x - compute the result of function #num on x",
            Action::Eval
        },
        {
            "poly",
            "(nomial) N c_0 c_1 ... c_(N-1) - creates a polynomial with N coefficients",
            Action::Poly
        },
        {
            "mul",
            "(tiply) num1 num2 - Creates a function that is the multiplication of "
            "function #num1 and function #num2",
            Action::Mul
        },
        {
            "add",
            " num1 num2 - Creates a function that is the sum of function #num1 and "
            "function #num2",
            Action::Add
        },
        {
            "comp",
            "(osite) num1 num2 - creates a function that is the composition of "
            "function #num1 and function #num2",
            Action::Comp
        },
        {
            "log",
            " N num - create a function that is the log_N of function #num",
            Action::Log
        },
        {
            "read",
            " path-name - Enter the path name of the file that you want to read the commands from",
            Action::Read
        },
        {
            "resize",
            " num - Reset the max num of functions that could be stored in the functions list",
            Action::Resize
        },
        {
            "del",
            "(ete) num - delete function #num from the function list",
            Action::Del
        },
        {
            "help",
            " - print this command list",
            Action::Help
        },
        {
            "exit",
            " - exit the program",
            Action::Exit
        }
    };
}

FunctionCalculator::FunctionList FunctionCalculator::createFunctions()
{
    return FunctionList
    {
        std::make_shared<Sin>(),
        std::make_shared<Ln>()
    };
}

//===NEW-FUNCTION-ADDED===========================
void FunctionCalculator::readMaxNumOfFuncs() {
    int num;
    do {
        try {
            m_ostr << "Enter the max number of functions that you want to store: ";
            num = readNum();
            if (num < 2 || num > 100) {
                throw std::out_of_range("out of range: 2 and 100\n");
            }
            m_maxNumOfFuncs = num;
        }
        //if intered an invalid int
        catch (std::domain_error err) {
            m_ostr << err.what();
        }
        catch (const std::out_of_range& err) {
            m_ostr << err.what();
        }
    } while (m_maxNumOfFuncs == 0);
}

void FunctionCalculator::readFile() {
    try {
        // storing the current input stream
        std::istream* prevIstream = m_istr;
        openFile();

        m_ostr << std::setprecision(2) << std::fixed;
        do
        {
            // try to read ad action from the user
            try {
                const auto action = readAction();
                runAction(action);
            }
            catch (std::domain_error err) {
                m_ostr << err.what();
            }
            catch (std::out_of_range err) {
                m_ostr << err.what();
            }
        } while (m_running && !m_istr->eof());

        // recovering the old input stream
        m_istr = prevIstream;
    }
    catch (const std::invalid_argument err) {
        m_ostr << err.what();
    }
}

void FunctionCalculator::resize() {
    try {
        int num = readNum();
        if (num < 2 || num > 100) {
            throw std::out_of_range("out of range: 2 and 100\n");
        }
        if (num < m_functions.size())
            throw std::length_error(std::to_string(num));
        m_maxNumOfFuncs = num;
    }
    //if intered an invalid int
    catch (std::domain_error err) {
        m_ostr << err.what();
    }
    catch (const std::out_of_range& err) {
        m_ostr << err.what();
    }
}

void FunctionCalculator::openFile() {
    std::string fileName;
    //read file name and open it
    *m_istr >> fileName;
    m_istr =  getFile(fileName);
}

std::istream* FunctionCalculator::getFile(std::string file_path)
{
    std::ifstream* File = new std::ifstream(file_path);
    std::istream* ifile = File;

    // if file exists
    if ((*ifile)) {
        return ifile;
    }
    // if file does exists
    else
        throw std::invalid_argument("file \"" + file_path + "\" doesnt exist\n");
}

// Returns true if s is a number else false
int FunctionCalculator::readNum()
{
    std::string s;
    *m_istr >> s;
    for (int i = 0; i < s.length(); i++)
        if (!isdigit(s[i]))
            throw std::domain_error("Enter a number\n");
    return std::stoi(s);
}
