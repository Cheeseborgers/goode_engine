//////////////////////////////////////////////////////////////////////////////////////////
//      file: Weapon.cpp
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

#include "Weapon.hpp"

namespace gcb
{
// ---------------------------------------------------------------------------------------
Weapon::Weapon(const std::string& name, const std::string& description,
  const ItemType type)
    : Item(name, description, type)
{
}
// ---------------------------------------------------------------------------------------
void Weapon::doSomething()
{
    std::cout << "Weapon something\n";
}
// ---------------------------------------------------------------------------------------
}// namespace gcb
