//
// Created by shyamnath on 6/6/21.
//
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
    void produceDoor()
    {
        house_->parts.emplace_back("door");
    }

    void produceWindows()
    {
        house_->parts.emplace_back("Windows");
    }

    void produceFancyStatues()
    {
        house_->parts.emplace_back("Fancy Statues");
    }

    void produceGarden()
    {
        house_->parts.emplace_back("Garden");
    }

    std::unique_ptr<House> getHouse()
    {
        return std::move(house_);
    }

private:
    std::unique_ptr<House> house_;

};

class Director{
public:

    Director(): builder_(std::make_unique<Builder>()){
    };

    void buildHouseWithGarden()
    {
        builder_->produceGarden();
    }

    void buildHouseWithFancyStatues()
    {
        builder_->produceDoor();
        builder_->produceFancyStatues();
    }

private:
    std::unique_ptr<Builder> builder_;
};

int main()
{
    Director director;
    director.buildHouseWithFancyStatues();
}
