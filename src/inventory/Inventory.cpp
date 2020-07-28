//////////////////////////////////////////////////////////////////////////////////////////
//      file: Inventory.hpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 26/07/2020.
//      Copyright (C) 2020 - goodecheeseburgers@gmail.com
//
//      https://github.com/Cheeseborgers/GoodeEngine
//
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <https://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////////////////////////

#include "Inventory.hpp"


namespace gcb
{
// Constructor ---------------------------------------------------------------------------
Inventory::Inventory()
{
}
// Destructor ----------------------------------------------------------------------------
Inventory::~Inventory()
{
}
// ---------------------------------------------------------------------------------------
void Inventory::addItem(std::unique_ptr<Item> itemPtr)
{
    mItems.emplace_back(std::move(itemPtr));
}
// ---------------------------------------------------------------------------------------
void Inventory::removeItemById(const int id)
{
    for (auto& it : mItems)
    {
        if (it->getId() == id)
        {
            mItems.erase(std::remove(
           mItems.begin(), mItems.end(), it),mItems.end());

            return;
        }
    }
}
// ---------------------------------------------------------------------------------------
void Inventory::removeItemByName(const std::string& itemName)
{
    for (auto& it : mItems)
    {
        if (it->getName() == itemName)
        {

            mItems.erase(std::remove(
              mItems.begin(), mItems.end(), it),mItems.end());

            return;
        }
    }
}
// ---------------------------------------------------------------------------------------
const std::vector<std::unique_ptr<Item>> &Inventory::getItems() const
{
    return mItems;
}
// ---------------------------------------------------------------------------------------
const std::string &Inventory::getItemsAsString() const
{
    static std::string tempStr;

    for (const auto& it : mItems)
    {
        tempStr.append(
          "Id: (" + std::to_string(it->getId())
                + ") Name: " + it->getName()
                + " : Desc: " + it->getDescription());

        switch (it->getType())
        {
        case WEAPON:
            tempStr.append(" (Weapon)");
            break;
        case POTION:
            tempStr.append(" (Potion)");
            break;
        case TOOL:
            tempStr.append(" (Tool)");
            break;
        }

        tempStr.append("\n");
    }

    return tempStr;
}
// ---------------------------------------------------------------------------------------
int Inventory::getItemIdByName(const std::string& name) const
{
    for (const auto& it : mItems)
    {
        if (it->getName() == name)
        {
            return it->getId();
        }
    }

    return 0;
}
// ---------------------------------------------------------------------------------------
void Inventory::removeItem(std::unique_ptr<Item>& itemPtr)
{
    auto const& it = std::find_if(mItems.begin(), mItems.end(),
      [&](std::unique_ptr<Item>& p)
    {
           return p.get() == itemPtr.get();
    });

    if (it != mItems.end())
    {
        mItems.erase(it);
    }
}
// ---------------------------------------------------------------------------------------



}// namespace gcb

