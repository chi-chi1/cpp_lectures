#include <cstdio>
#include <iostream>
#include <ios>
#include <optional>
#include <string>
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
        std::string   colour;

        Car()   = default;

        Car(const Automobile autom, const std::string& name, const float price, const int stock) :
                  id {autom}, name {name}, price{price}, stock{stock}, const std::string& colour
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
                return {};d
        }

        auto list()
        {
                std::printf("%32s%64s%16s%8s%16s\n",  "Automobile" "Model Name", "Price(USD)",  "Qty", "color.");
                std::for_each(cars.begin(), cars.end(), [](const auto& Car) {
                        std::printf("%32s%64s%16.2f%8d%16s\n",
get_automobile_name(car.id).data(), car.name.c_str(), car.price, car.stock);
                });
                std::printf("------------------------/n");
        }
};

struct InventoryUI
{
        enum class Option
        {
                invalid =-1,
                AddCar                     ='a',
                RemoveCar                  ='r',
                EditCar                    ='e',
                SearchAutomobile           ='s',
                ListCars                   ='p',
                Quit                       ='q',
        };

        Inventory inventory;

        auto         user_input_handler()  {}
        auto         list_options()
        {
                std::printf("(%c)  Add Car/n", static_cast<char> (Option::AddCar));
                std::printf("(%c)  Search Car/n", static_cast<char> (Option::SearchCar));
                std::printf("(%c)  List Automobile/n", static_cast<char> (Option::ListAutomobiles));
                std::printf("(%c)  List Cars in stock/n", static_cast<char> (Option::ListCars));
                std::printf("(%c)  Quit/n", static_cast<char> (Option::Quit));
        }
        auto get_user_action()
        {
                char opt{};
                std::printf("select operation:  ");
                std::scanf(" %c, &opt");
                return opt;
        }
        auto handle_add_option()
        {
                Car car;
                do{
                        list_automobiles();

                        std::printf("Select automobile category to add: ");
                        int aid {};
                        std::scanf("%d", &car.id);

                        if (!is_valid_product(car.id)) {std::printf("invalid option select. try again.\n"); }
                        else
                        {
                                std::printf("Enter model name:   ");
                                std::getline(std::cin >> std::ws,  car.name);

                                std::printf("enter price: ");
                                std::cin >> car.price;

                                std::printf("Enter quantity:  ");
                                std::cin >> car.stock;

                                return car;
                        }
                }while (true);
        }

        auto handle_search_option
        {
                char opt {};
                std::printf("Search by (n) Name, (a) automobile Category: ");
                std::cin >> opt;

                Inventory::CarPtr acar;

                if (opt == 'n' )
                {
                        std::string name {};
                        std::printf("Enter model name: ");
                        std::getline(std::cin >> std::ws, name);
                        acar = Inventory.std::search([&] (const Car& car) { return car.name == name; });
                }
                else if (opt == 'a')
                {
                        Automobile autom {Automobile};
                        list_automobiles();
                        std::printf("select automobile id: ");
                        std::scanf("%d",  &autom);

                        acar = inventory.search([&](const Car& car) { return car.id == autom; });

                }
                else
                {
                        std::printf("invalid option selected. please try again.\n");
                        return;
                }
                if (acar != Inventory::CarPtr {})
                {
                        std::printf("()")
                }
        }

