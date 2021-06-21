//
// Created by shyamnath on 6/5/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Shapes{
public:
    Shapes(): impl(std::make_unique<Impl>()){}
    void doSomething(std::string s);
    ~Shapes();
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};

struct Shapes::Impl
{
    std::vector<std::string> shapeNames;
};


Shapes::~Shapes() = default;

void Shapes::doSomething(std::string s) {
    impl->shapeNames.emplace_back(s);
}

int main()
{
    Shapes().doSomething("circle");
    int test = 1;
}
