//
// Created by shyamnath on 6/6/21.
//
#include <iostream>
#include <string>
#include <memory>
#include <charconv>

class Target{
public:
    Target() = default;
    Target(const std::string& message): message_(message){};
    virtual std::string getMessage() const{
        return message_;
    }
private:
    std::string message_;
};

class LegacyTarget{
public:
    LegacyTarget()=default;
    LegacyTarget(int b):a(b){};
    int getMessage() const
    {
        return a;
    }
private:
    int a;
};

class Adapter: public Target
{
public:
    Adapter(int b): legacyTarget(std::make_unique<LegacyTarget>(b)){};
    std::string getMessage() const override final
    {
        std::string message;
        int a = legacyTarget->getMessage();
        message = std::to_string(a);
        return message;
    }
private:
    std::unique_ptr<LegacyTarget> legacyTarget;
};

void doSomethingWithMessage(Target* target)
{
    std::cout<<target->getMessage()<<"\n";
}

int main()
{
    Target* target = new Adapter(2);
    doSomethingWithMessage(target);
    Target* target1 = new Target("shyam");
    doSomethingWithMessage(target1);
}
