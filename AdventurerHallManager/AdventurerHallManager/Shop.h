#pragma once
#include <stack>

#include "ShopItem.h"

class Shop
{
public:
    explicit Shop(const std::stack<ShopItem>& shop_item)
        : shopItem(shop_item)
    {
    }
    std::stack<ShopItem> shopItem;

    void DisplayTopItem()
    {
        shopItem.top().DisplayItemInfo();
    }
    
};
