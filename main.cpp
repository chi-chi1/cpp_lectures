#include <algorithm>
#include <ios>
#include <iostream>
#include <optional>
#include <vector>

constexpr auto MAX_CARS = 30;
constexpr auto MAX_MODEL_Name = 64;

enum class Automobile
{
        Invalid = -1,
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

constexpr auto is_valid_automobile(Automobile autom) { return autom > Automobile::Invalid && autom < Automobile::Count; }

constexpr auto get_automobile_name(Automobile autom)
{
        if (!is_valid_automobile(autom)) { return std::string_view {""};  }

        return AUTOMOBILE_NAMES[static_cast<int>(autom)];
}

auto list_automobiles()
{
        std::cout << "Automobile list: \n";
        std::for_each_n(std::begin(AUTOMOBILE_NAMES), std::size(AUTOMOBILE_NAMES), [i = 0](const auto& name) mutable {
                std::printf("(%d) %s\n", i, name.data());
                i++;
        });
        std::printf("-----------------------------\n");
}

struct Car
{
        Automobile    id;
        std::string   name;
        float         price;
        int           nstock;

        Car()   = default;

        Car(const Automobile autom, const std::string& name, const float price, const int nstock) :
               id {autom}, name {name}, price {price}, nstock {nstock}
        {}        
};

struct Inventory
{
        using SearchPredicate = std::function<bool(const Car&)>;
        using Cars            = std::vector<Car>;
        using CarPtr          = Cars::iterator;

        Cars cars;

        Inventory()  { cars.reserve(MAX_CARS);  }
        auto add(const Car& car)  {cars.emplace_back(car); }
        auto remove(CarPtr pcar) {cars.erase(pcar); }
        auto search(const SearchPredicate& pred) -> CarPtr
        {
                auto pcar = std::find_if(cars.begin(), cars.end(), pred);
                if (pcar != cars.end()) { return pcar; }
                return {};
        }

        auto list()
        {
                std::printf("%32s%64s%16s%8s\n",  "Automobile", "Model Name", "Price (USD)",  "Qty.");
                std::for_each(cars.begin(), cars.end(), [](const auto& car) {
                        std::printf("%32s%64s%16.2f%8d\n", get_automobile_name(car.id).data(), car.name.c_str(), car.price, car.nstock);
                });
                std::printf("------------------------/n");
        }
};

struct InventoryUI
{
        enum class Option
        {
                Invalid                    =-1,
                AddCar                     ='a',
                RemoveCar                  ='r',
                EditCar                    ='e',
                SearchCar                  ='s',
                ListAutomobiles            ='p',
                ListItems                  ='l',
                Quit                       ='q',
        };

        Inventory inventory;

        auto         user_input_handler()  {}

        auto         list_options()
        {
                std::printf("(%c)  Add Car\n", static_cast<char> (Option::AddCar));
                std::printf("(%c)  Search Car\n", static_cast<char> (Option::SearchCar));
                std::printf("(%c)  List Automobile Categories\n", static_cast<char>(Option::ListAutomobiles));
                std::printf("(%c)  List Cars in stock\n", static_cast<char>(Option::ListCars));
                std::printf("(%c)  Quit\n", static_cast<char>(Option::Quit));
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
                do {
                        list_automobiles();

                        std::printf("Select automobile category to add: ");
                        int pid {};
                        std::scanf("%d", &car.id);

                        if (!is_valid_automobile(car.id)) { std::printf("Invalid option selected. Try again.\n"); }
                        else
                        {
                                std::printf("Enter model name:   ");
                                std::getline(std::cin >> std::ws,  car.name);

                                std::printf("Enter price: ");
                                std::cin >> car.price;

                                std::printf("Enter quantity:  ");
                                std::cin >> car.nstock;

                                return car;
                        }
                } while (true);
        }

        auto handle_search_option()
        {
                char opt {};
                std::printf("Search by (n) Name, (a) Automobile Category: ");
                std::cin >> opt;

                Inventory::CarPtr pcar;

                if (opt == 'n' )
                {
                        std::string name {};
                        std::printf("Enter model name: ");
                        std::getline(std::cin >> std::ws, name);
                        pcar = inventory.search([&](const Car& car) { return car.name == name; });
                }
                else if (opt == 'a')
                {
                        Automobile autom {Automobile::Invalid};
                        list_automobiles();
                        std::printf("select automobile id: ");
                        std::scanf("%d",  &autom);

                        pcar = inventory.search([&](const Car& car) { return car.id == autom; });

                }
                else
                {
                        std::printf("Invalid option selected. please try again.\n");
                        return;
                }
                if (pcar != Inventory::CarPtr {})
                {
                        do{
                                std::printf("(%c) Remove Car\n", static_cast<char>(Option::RemoveCar));
                                std::printf("(%c) Edit Car\n", static_cast<char>(Option::EditCar));
                                std::printf("(%c) Quit\n", static_cast<char> (Option::Quit));

                                if (opt == static_cast<char>(Option::RemoveCar))
                                {
                                        inventory.remove(pcar);
                                        break;
                                }
                                else if (opt == static_cast<char>(Option::EditCar))
                                {
                                        const auto new_car = handle_add_option();
                                        inventory.remove(pcar);
                                        inventory.add(new_car);
                                        break;
                                }
                                else if (opt == static_cast<char>(Option::Quit)) { break; }
                                else { std::printf("Invalid option selected. Please try again.\n"); }
                        }while (true); 
                }  
                else { std::printf("Car not found. Try adding an item.\n"); }      
        }

        auto run()
        {
                std::printf("Showroom Inventory v0.1\n");

                do {
                         list_options();
                         const auto opt = get_user_action();
                         if (opt == static_cast<char> (Option::AddCar))
                         {
                                 const auto car = handle_add_option();
                                 inventory.add(car);
                                 std::printf("Added car\n\n");
                         }
                         else if (opt == static_cast<char>(Option::SearchCar)) { handle_search_option(); }
                         else if (opt == static_cast<char>(Option::ListAutomobiles)) { list_automobiles(); }
                         else if (opt == static_cast<char>(Option::ListCars)) { inventory.list(); }
                         else if (opt == static_cast<char>(Option::Quit)) { break; }
                         else {std::printf("Invalid option selected. Please try again.\n"); }      
                }while (true);
        }
};        

auto main() -> int
{
        InventoryUI ui {};

        ui.run();
}