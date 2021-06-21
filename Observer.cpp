//
// Created by shyamnath on 6/6/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Observer
{
public:
    void Update(const std::string message)
    {
        message_from_subject = message;
        std::cout<<"new message: "<<message_from_subject<<"\n";
    }
private:
    std::string message_from_subject;
};

class Subject
{
public:
    Subject(const std::string& message): message_(message){};
    void addObserver(const std::shared_ptr<Observer> observer)
    {
        std::weak_ptr<Observer> wObserver = observer;
        observers.emplace_back(wObserver);
    }
    void removeObserver(const std::shared_ptr<Observer> observer)
    {
        std::erase_if(observers, [&observer](auto observer_){return observer_.lock()==observer;});
    }
    void updateMessage(const std::string& message)
    {
        message_ = message;
        Notify();
    }

private:

    void Notify()
    {
        for(auto observer: observers)
        {
            if (not observer.expired())
            {
                auto sObserver = observer.lock();
                sObserver->Update(message_);
            }
        }
    }
    std::vector<std::weak_ptr<Observer>> observers;
    std::string message_;
};

int main()
{
    auto observer1 = std::make_shared<Observer>();
    std::string message1= "shyam";
    Subject subject(message1);
    subject.addObserver(observer1);
    subject.updateMessage(message1);
    auto observer2 = std::make_shared<Observer>();
    std::string message2= "shyam1";
    subject.addObserver(observer2);
    subject.updateMessage(message2);
}