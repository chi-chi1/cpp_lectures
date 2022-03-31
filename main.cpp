#include <iostream>
#include <string_view>
#include <algorithm>

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
        {static_cast<int>(Automobile:: )}
        {static_cast<int>(Automobile::)}
        {static_cast<int>(Automobile::)}
        {static_cast<int>(Automobile::)}
        {static_cast<int>(Automobile::)}
        {static_cast<int>(Automobile::)}
        {static_cast<int>(Automobile::)}
        {static_cast<int>(Automobile::)}
        {static_cast<int>(Automobile::RangeRover,)}
        {static_cast<int>(Automobile::RolceRoyce)}
}