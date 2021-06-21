//
// Created by shyamnath on 6/20/21.
//

#include <type_traits>
#include <string>

template<typename... Ts>
using AllStrings = std::enable_if_t<std::conjunction_v<std::is_convertible<Ts, std::string>...>>;

template<typename... Ts, typename = AllStrings<Ts...>>
void f(Ts const&... xs)
{
    // ...
}

//template<typename... Ts>
//void fTwo(Ts const&... ts)
//{
//    static_assert(AllStrings<Ts...>, "All parameters must be std::string");
//
//    // ...
//}


//another way
template<typename T, typename... Ts>
using AllSame = std::enable_if_t<std::conjunction_v<std::is_same<T, Ts>...>>;

template<typename T, typename... Ts, typename = AllSame<T, Ts...>>
void fOne(T const& value, Ts const& ...values)
{
}

int main()
{
    std::string a = "hello", b="shyam";
    fOne(a, b);
    f(a, b);
}