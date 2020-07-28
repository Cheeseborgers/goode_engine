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

#ifndef ENGINE_BASE_INVENTORY_HPP
#define ENGINE_BASE_INVENTORY_HPP

#include "../pch.hpp"
#include "Item.hpp"
#include "Item.hpp"
#include "Weapon.hpp"
#include "Tool.hpp"

namespace gcb
{
class Inventory
{
private:
  std::vector<std::unique_ptr<Item>> mItems;

public:
  Inventory();
  virtual ~Inventory();

  // Getters
  int getItemIdByName(const std::string& name) const;
  const std::vector<std::unique_ptr<Item>> &getItems() const;
  const std::string &getItemsAsString() const;

  // Methods
  virtual void addItem(std::unique_ptr<Item> itemPtr);
  virtual void removeItem(std::unique_ptr<Item>& itemPtr);
  virtual void removeItemById(const int id);
  virtual void removeItemByName(const std::string& itemName);
};

}// namespace gcb



#endif//ENGINE_BASE_INVENTORY_HPP
