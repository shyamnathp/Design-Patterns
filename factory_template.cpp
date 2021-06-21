//
// Created by shyamnath on 6/6/21.
//
#include <iostream>
#include <memory>
#include <type_traits>

namespace {

    class ModernChair;
    class VictorianChair;

    class Chair {
    public:
        enum class ChairType { modern,
                               victorian };
        Chair() = default;
        Chair(int height, const std::string &type) : height_(height), type_(type) {}
        virtual void setType(const std::string &type) {
            type_ = type;
        }
        virtual void setHeight(int height) {
            height_ = height;
        }

        template<typename... Ts>
        static std::unique_ptr<Chair> chairFactory(ChairType type, Ts... params)
        {
            if (type == ChairType::modern)
                return ConstructArgs<ModernChair, Ts...>(std::forward<Ts>(params)...);
            else if (type == ChairType::victorian)
                return ConstructArgs<VictorianChair, Ts...>(std::forward<Ts>(params)...);

        }


    private:
        int height_;
        std::string type_;
        template<typename T, typename... Ts>
        static std::unique_ptr<T> ConstructArgs(Ts... params)
        {
            if constexpr (std::is_constructible_v<T, Ts...>)
                return std::make_unique<T>(std::forward<Ts>(params)...);
            else
                nullptr;
        }
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

int main()
{
    auto chair = Chair::chairFactory(Chair::ChairType::modern, 5, "modern");
    chair->setType("modern");
}
