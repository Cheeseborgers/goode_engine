//////////////////////////////////////////////////////////////////////////////////////////
//      file: TileMap.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 03/07/2020.
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

#include <iostream>
#include <memory>
#include "TileMap.hpp"

namespace gcb::tilemap
{
// ---------------------------------------------------------------------------------------
TileMap::TileMap() : mPLevel(nullptr)
{
}
// ---------------------------------------------------------------------------------------
void TileMap::setLevel()
{
}
// ---------------------------------------------------------------------------------------
void TileMap::setLevel(std::shared_ptr<std::vector<gcb::tilemap::Tile>> level)
{
    mPLevel = std::make_shared<std::vector<gcb::tilemap::Tile>>();
    mPLevel = std::move(level);
}
// ---------------------------------------------------------------------------------------
void TileMap::update()
{
}
// ---------------------------------------------------------------------------------------
void TileMap::render(sf::RenderTarget& target)
{

    for (auto& i : *mPLevel)
    {
        i.draw(target);
    }

}
// ---------------------------------------------------------------------------------------
void TileMap::draw(sf::RenderTarget &target,
  [[maybe_unused]] sf::RenderStates states) const
{
    for (auto& i : *mPLevel)
    {
        i.draw(target);
    }
}
// ---------------------------------------------------------------------------------------

} // gcb ns end