#pragma once
#include <iostream>
#include <string>

class ShopItem
{
public:
    std::string description;
    std::string name;
    int price;
    ShopItem(const std::string& description, const std::string& name, int price)
        : description(description),
          name(name),
          price(price)
    {
    }
    void DisplayItemInfo()
    {
        std::cout << name + " || "<< description + " || "<< std::to_string(price);
    }
    
    //~ShopItem();
};
