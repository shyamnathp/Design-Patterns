//
// Created by shyamnath on 6/6/21.
//
#include <iostream>
#include <string>
#include <variant>

struct PrintVisitor{

    void operator()(int a)
    {
        std::cout<<"Integer"<<a<<"\n";
    }

    void operator()(float a)
    {
        std::cout<<"Float"<<a<<"\n";
    }

    void operator()(const std::string& a)
    {
        std::cout<<"String"<<a<<"\n";
    }
};


int main()
{
    std::variant<int, float, std::string> v;
    v=9;
    std::visit(PrintVisitor{}, v);
    v="shyam";
    std::visit(PrintVisitor{}, v);
    v.emplace<1>(1.79);
    std::visit(PrintVisitor{}, v);
}
