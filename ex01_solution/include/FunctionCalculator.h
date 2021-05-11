#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <iosfwd>
#include <optional>
#include <fstream> //added

class Function;

class FunctionCalculator
{
public:
    FunctionCalculator(std::istream& istr, std::ostream& ostr);
    void run();
    
private:
    void eval();
    void poly();
    void log();
    void del();
    void help();
    void exit();
    //----------------
    void readFile();
    void openFile();
    void readMaxNumOfFuncs();
    std::istream* getFile(std::string);
    int readNum();

    template <typename FuncType>
    void binaryFunc()
    {   //add f = -1 when we get invalid input
        if (auto f0 = readFunctionIndex(), f1 = readFunctionIndex();
             f0 != -1 && f1 != -1 && f0 && f1) //added f!=1 to check valid input
        {
            m_functions.push_back(std::make_shared<FuncType>(m_functions[*f0], m_functions[*f1]));
        }
    }

    void printFunctions() const;

    enum class Action
    {
        Eval,
        Poly,
        Mul,
        Add,
        Comp,
        Log,
        Read,
        Resize,
        Del,
        Help,
        Exit,
    };

    struct ActionDetails
    {
        std::string command;
        std::string description;
        Action action;
    };

    using ActionMap = std::vector<ActionDetails>;
    using FunctionList = std::vector<std::shared_ptr<Function>>;

    const ActionMap m_actions;
    FunctionList m_functions;
    bool m_running = true;
    std::istream* m_istr;
    std::ostream& m_ostr;

    std::optional<int> readFunctionIndex() const;
    Action readAction() const;
    void runAction(Action action);
    void resize();

    static ActionMap createActions();
    static FunctionList createFunctions();
    //--added----
    int m_maxNumOfFuncs = 0;
};
