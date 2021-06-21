//
// Created by shyamnath on 6/21/21.
//
#include<iostream>
#include<stdio.h>

using namespace std;

struct Base
{

};


struct A: public Base
{
    std::string s;
    A() : s("test") { }
    A(const A& o) : s(o.s) { std::cout << "copy constructed!\n"; }
    A(A&& o) : s(std::move(o.s)) { std::cout << "move constructed!\n";}
    A& operator=(const A& other)
    {
        s = other.s;
        std::cout << "copy assigned\n";
        return *this;
    }
    A& operator=(A&& other)
    {
        s = std::move(other.s);
        std::cout << "move assigned\n";
        return *this;
    }

    ~A()
    {
        std::cout<<"destructor called\n";
    }
};

// Driver code
int main()
{
    A a;
    A b;
    Base c;
    b = *((A*)&c);
//    A c = std::move(b);
}