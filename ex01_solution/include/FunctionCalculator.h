#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iosfwd>
#include <optional>

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

    template <typename FuncType>
    void binaryFunc()
    {
        if (auto f0 = readFunctionIndex(), f1 = readFunctionIndex(); f0 && f1)
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
    std::istream& m_istr;
    std::ostream& m_ostr;

    std::optional<int> readFunctionIndex() const;
    Action readAction() const;
    void runAction(Action action);

    static ActionMap createActions();
    static FunctionList createFunctions();
};
