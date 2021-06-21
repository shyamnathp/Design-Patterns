//
// Created by shyamnath on 6/5/21.
//
#include <iostream>
#include <memory>
namespace {
    class Chair {
    public:
        enum class ChairType { modern, victorian };
        Chair() = default;
        Chair(int height, const std::string &type) : height_(height), type_(type) {}
        virtual void setType(const std::string &type) {
            type_ = type;
        }
        virtual void setHeight(int height) {
            height_ = height;
        }
        static std::unique_ptr<Chair> chairFactory(ChairType);

    private:
        int height_;
        std::string type_;
    };

    class ModernChair : public Chair {
    public:
        ModernChair() = default;
        ModernChair(int height, const std::string &type) : Chair(height, type) {}
        void setType(const std::string &type) {
            Chair::setType("modern");
        }

        void setHeight(int height) {
            Chair::setHeight(height);
        }
    };

    class VictorianChair : public Chair {
    public:
        VictorianChair() = default;
        VictorianChair(int height, const std::string &type) : Chair(height, type) {}
        void setType(const std::string &type) {
            Chair::setType("victorian");
        }

        void setHeight(int height) {
            Chair::setHeight(height);
        }
    };
}

std::unique_ptr<Chair> Chair::chairFactory(Chair::ChairType chair) {
    if(chair==Chair::ChairType::modern)
        return std::make_unique<ModernChair>();
    else if(chair==Chair::ChairType::victorian)
        return std::make_unique<VictorianChair>();
    else
        nullptr;
}

int main()
{
    auto chair = Chair::chairFactory(Chair::ChairType::modern);
    chair->setType("modern");
}
