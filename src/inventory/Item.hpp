//////////////////////////////////////////////////////////////////////////////////////////
//      file: Item.hpp
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

#ifndef ENGINE_BASE_ITEM_HPP
#define ENGINE_BASE_ITEM_HPP

#include "../pch.hpp"

namespace gcb {

enum ItemType : char { WEAPON = 0, POTION, TOOL };
enum AllowDuplicateItem : char { ALLOW = 0, NEVER};

class Item
{
private:
    std::string mName;
    std::string mDescription;
    const ItemType mType;
    const int mId;

    static int& getCount ()
    {
        static int count = 0;
        return count;
    }

public:
  Item(const std::string& name, const std::string& description, const ItemType type);
    virtual ~Item();

    // Getters
    const std::string& getName() const;
    const std::string& getDescription() const;
    ItemType getType() const;
    int getId() const;

    // Setters
    void setName(const std::string& mName);
    void setDescription(const std::string& mDescription);

    // Pure Virtual Methods
    virtual void doSomething() = 0;
};

}// namespace gcb

#endif//ENGINE_BASE_ITEM_HPP
