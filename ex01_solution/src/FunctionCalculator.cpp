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
    : m_actions(createActions()), m_functions(createFunctions()), m_istr(istr), m_ostr(ostr)
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
    } while (m_running);
}

void FunctionCalculator::eval()
{
    if (auto i = readFunctionIndex(); i)
    {
        auto x = 0.;
        auto sstr = std::ostringstream();

        try {
            // if the didn't give a valid int it will throw an err
            m_istr >> x;

            sstr << std::setprecision(2) << std::fixed << x;
            m_ostr << m_functions[*i]->to_string(sstr.str())
                << " = "
                << (*m_functions[*i])(x)
                << '\n';
        }
        //if intered an invalid int
        catch (const std::ios_base::failure& err) {
            m_ostr << err.what();
        }
    }
}

void FunctionCalculator::poly()
{

    try {
        // if the didn't give a valid int it will throw an err
        int n;
        m_istr >> n;
        auto coeffs = std::vector<double>(n);
        for (auto& coeff : coeffs) {
            m_istr >> n;
            coeffs.push_back(n);
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
        m_istr >> base;
        if (base <= 1) {
            throw std::range_error("can't insert a base less than 1\n");
        }
        if (auto f = readFunctionIndex(); f)
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
    if (auto i = readFunctionIndex(); i)
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
    auto i = 0;
    m_istr >> i;
    if (i >= m_functions.size())
    {
        m_ostr << "Function #" << i << " doesn't exist\n";
        return {};
    }
    return i;
}

FunctionCalculator::Action FunctionCalculator::readAction() const
{
    auto action = std::string();
    m_istr >> action;

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
        case Action::Read: read();             break;
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

void FunctionCalculator::read() {
    std::string fileName;
    std::ifstream file;
    //read file name and open it
    try {
        m_istr >> fileName;
        file.open(fileName);
        if (!file.is_open()) {
            throw std::ifstream::failure("cant open the file\n");
        }
    }
    catch (const std::ifstream::failure err) {
        m_ostr << err.what();
    }
}

// Returns true if s is a number else false
int FunctionCalculator::readNum()
{
    std::string s;
    m_istr >> s;
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            throw std::domain_error("invalid number\n");
    return std::stoi(s);
}