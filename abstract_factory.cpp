#include <iostream>
#include <memory>

class Chair {
public:
    Chair() = default;
    Chair(int height, const std::string& type):height_(height),type_(type) {}
    virtual void setType(const std::string& type){
        type_ = type;
    }
    virtual void setHeight(int height){
        height_ = height;
    }
private:
    int height_;
    std::string type_;
};

class ModernChair: public Chair{
public:
    ModernChair() = default;
    ModernChair(int height,const std::string& type): Chair(height, type){}
    void setType(const std::string& type){
        Chair::setType("modern");
    }

    void setHeight(int height)
    {
        Chair::setHeight(height);
    }
};

class VictorianChair: public Chair{
public:
    VictorianChair() = default;
    VictorianChair(int height,const std::string& type): Chair(height, type){}
    void setType(const std::string& type){
        Chair::setType("victorian");
    }

    void setHeight(int height)
    {
        Chair::setHeight(height);
    }
};

class Sofa{
public:
    Sofa() = default;
    Sofa(int height, const std::string& type):height_(height),type_(type) {}
    virtual void setType(const std::string& type){
        type_ = type;
    }
    virtual void setHeight(int height){
        height_=height;
    }
private:
    int height_;
    std::string type_;
};

class ModernSofa: public Sofa{
public:
    ModernSofa() = default;
    ModernSofa(int height,const std::string& type): Sofa(height, type){}
    void setType(const std::string& type){
        Sofa::setType("modern");
    }

    void setHeight(int height)
    {
        Sofa::setHeight(height);
    }
};

class VictorianSofa: public Sofa{
public:
    VictorianSofa()= default;
    VictorianSofa(int height,const std::string& type): Sofa(height, type){}
    void setType(const std::string& type){
        Sofa::setType("victorian");
    }

    void setHeight(int height)
    {
        Sofa::setHeight(height);
    }
};

class AbstractFactory
{
public:
    virtual std::unique_ptr<Chair> createChair(int height) const= 0;
    virtual std::unique_ptr<Sofa> createSofa(int height) const = 0;
};

class ModernFactory: public AbstractFactory
{
public:
    std::unique_ptr<Chair> createChair(int height) const
    {
        auto chair = std::make_unique<ModernChair>();
        chair->setHeight(height);
        chair->setType("modern");
        return chair;
    }

    std::unique_ptr<Sofa> createSofa(int height) const
    {
        auto sofa = std::make_unique<VictorianSofa>();
        sofa->setHeight(height);
        sofa->setType("modern");
        return sofa;
    }
};

class VictorianFactory: public AbstractFactory
{
public:
    std::unique_ptr<Chair> createChair(int height) const
    {
        auto chair = std::make_unique<VictorianChair>();
        chair->setHeight(height);
        chair->setType("modern");
        return chair;
    }

    std::unique_ptr<Sofa> createSofa(int height) const
    {
        auto sofa = std::make_unique<VictorianSofa>();
        sofa->setHeight(height);
        sofa->setType("modern");
        return sofa;
    }
};


void doProcess(AbstractFactory* factory)
{
    auto chair = factory->createChair(5);
    auto sofa = factory->createSofa(5);
}

int main()
{
    ModernFactory* m = new ModernFactory();
    doProcess(m);
}