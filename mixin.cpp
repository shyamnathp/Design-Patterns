//
// Created by shyamnath on 6/5/21.
//

#include <iostream>

class Circle
{
public:
    Circle(int r): r_(r){}
    float getArea() const
    {
        return 3.14 * r_ * r_;
    }
private:
    int r_;
};

class Square
{
public:
    Square(int a, int b): a_(a), b_(b){}
    float getArea() const
    {
        return a_*b_;
    }
private:
    int a_, b_;
};

template<typename Derived>
class Printable
{
public:
    Printable(Derived printable):printable_(printable)
    {}
    void printArea()
    {
        std::cout<<printable_.getArea();
    }

private:
    Derived printable_;
};

template<typename T>
Printable<T> makePrintable(T a)
{
    return Printable<T>(a);
}

int main()
{
    Square s(1, 2);
    makePrintable(s).printArea();
}