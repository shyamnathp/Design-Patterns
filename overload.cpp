//
// Created by shyamnath on 6/6/21.
//

#include <iostream>
#include <variant>
#include <string>

namespace {
    template<class ...Ts>
    struct overload: Ts...{using Ts::operator()...;};

    template<class ...Ts>
    overload(Ts...)->overload<Ts...>;
}

int main()
{
    std::variant<int, float> intFloat { 0.0f };
    std::visit(overload{
            [](const int& i) {   std::cout<<"Integer"<<i<<"\n"; },
            [](const float& f) {   std::cout<<"Float"<<f<<"\n"; }},intFloat
    );
}
