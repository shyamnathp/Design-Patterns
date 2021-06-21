//
// Created by shyamnath on 6/5/21.
//

#include <iostream>

template<typename T>
class crtp
{
    T& underlying(){return static_cast<T&>(*this)->getArea();}
    const T& underlying() const{return static_cast<const T&>(*this)->getArea();}

};

template<typename Derived>
class Shape: public crtp<Derived>{
public:
    void doProcess() const
    {
        static_cast<const Derived&>(*this)->getArea();
    }
    
    virtual float getArea() const =0;

private:
    Shape() = default;
    friend Derived;
};

class Circle: public Shape<Circle>
{
public:
    Circle(int r): r_(r){}
    float getArea() const override
    {
        return 3.14 * r_ * r_;
    }
private:
    int r_;
};

class Square: public Shape<Square>
{
public:
    Square(int a, int b): a_(a), b_(b){}
    float getArea() const override
    {
        return a_*b_;
    }
private:
    int a_, b_;
};

template<typename Derived>
void printArea(const Shape<Derived>& derived)
{
    std::cout<<derived.getArea()<<"\n";
}

int main()
{
    Circle c(2);
    printArea(c);
    Square s(2, 3);
    printArea(s);
}


