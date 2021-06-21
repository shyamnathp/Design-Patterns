//
// Created by shyamnath on 6/6/21.
//
#include <iostream>
#include <vector>
#include <memory>

class House{
public:
    std::vector<std::string> parts;
};

class Builder{
public:
    
    Builder(): house_(std::make_unique<House>()){
                        buildMinimalViableHouse();
                };

    void buildHouseWithSwimminPool()
    {
        house_->parts.emplace_back("Swimming Pool");
    }

    void buildHouseWithGarden()
    {
        house_->parts.emplace_back("Garden");
    }

    void buildHouseWithFancyStatues()
    {
        house_->parts.emplace_back("Fancy Statues");
    }

    void buildHouseWithGarage()
    {
        house_->parts.emplace_back("Garage");
    }



private:
    void buildMinimalViableHouse()
    {
        house_->parts.emplace_back("Windows");
        house_->parts.emplace_back("Walls");
        house_->parts.emplace_back("Roof");
        house_->parts.emplace_back("Doors");
    }
    std::unique_ptr<House> house_;
};

int main()
{
    auto b = Builder();
    b.buildHouseWithFancyStatues();
    int test = 1;
}
