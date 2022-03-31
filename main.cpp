#include <cstdio>
#include <iostream>
#include <ios>
#include <string_view>
#include <algorithm>
#include <vector>

constexpr auto MAX_CARS = 30;
constexpr auto MAX_MODEL_Name = 80;

enum class Automobile
{
        invalid = -1,
        Audi,
        Bentley,
        BMW,
        Ferrari,
        Tesla,
        Maserati,
        MercedezBenz,
        Porsche,
        RangeRover,
        RolceRoyce,
        Count
};


constexpr std::string_view AUTOMOBILE_NAMES[static_cast<int>(Automobile::Count)] = {
        [static_cast<int>(Automobile::Audi)]                 = "Audi",
        [static_cast<int>(Automobile::Bentley)]              = "Bentley",
        [static_cast<int>(Automobile::BMW)]                  = "BMW",
        [static_cast<int>(Automobile::Ferrari)]              = "Ferrari",
        [static_cast<int>(Automobile::Tesla)]                = "Tesla",
        [static_cast<int>(Automobile::Maserati)]             = "Maserati",
        [static_cast<int>(Automobile::MercedezBenz)]         = "MercedezBenz",
        [static_cast<int>(Automobile::Porsche)]              = "Porsche",
        [static_cast<int>(Automobile::RangeRover)]           = "RangeRover",
        [static_cast<int>(Automobile::RolceRoyce)]           = "RolceRoyce",
};

constexpr auto is_Valid_automobile(Automobile autom)
{
        if (!is_Valid_automobile(autom)) { return std::string_view {""};  }

        return AUTOMOBILE_NAMES[static_cast<int>(autom)];
}

auto list_automobiles()
{
        std::cout << "Automobile list: /n";
        std::for_each_n(std::begin(AUTOMOBILE_NAMES)), std::size(AUTOMOBILE_NAMES), [i = 0] (const auto& name) mutable{
                std::printf("(%d) %s/n", i, name.data());
                i++;
        };
        std::printf("-----------------------------/n");
}

struct Car
{
        Automobile    id;
        std::string   name;
        float         price;
        int           stock;

        Car()   = default;

        Car(const Automobile autom, const std::string& name, const float price, const int stock) :
                  id {autom}, name {}, price{price}, stock{stock}
        {}        
};

struct Inventory
(
        using SearchPredicate = std::function<bool(const Cars&)>;
        using Cars            = std::vector<Car>;
        using CarPtr          = Cars::iterator;

        Cars cars;

        Inventory()  { cars.reserve(MAX_CARS);  }
        auto add(const Car& car)  {cars.emplace_back(car); }
        auto remove(CarPtr acar) {car.erase(acar); }
        auto search(const SearchPredicates& pred) -> CarPtr
        {
                auto acar = std::find if(cars.begin(), cars.end(), pred);
                if (acar != cars.end()) {return acar;}
                return {};
        }

        auto list()
        {
                std::printf("%32s%64s%16s%8s\n",  "Automobile" "Model Name", "Price(USD)",  "Qty.");
                std::for_each(cars.begin(), cars.end(), [](const auto& Car) {
                        std::printf("%32s%64s%16.2f%8d\n")
                        
                }
        }
