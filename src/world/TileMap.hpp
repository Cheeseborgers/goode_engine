//////////////////////////////////////////////////////////////////////////////////////////
//      file: TileMap.hpp
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


#ifndef ENGINE_BASE_TILEMAP_HPP
#define ENGINE_BASE_TILEMAP_HPP

#include "../pch.hpp"

#include "../tiles/Tile.hpp"


namespace gcb::tilemap
{
using PLevel = std::shared_ptr<std::vector<gcb::tilemap::Tile>>;

class TileMap : public sf::Drawable, public sf::Transformable
{
private:
    unsigned long int mLevelWidth;
    unsigned long int mLevelSize;
    PLevel mPLevel;

public:
    TileMap();
    TileMap(const TileMap &) = delete; // non construction-copyable
    TileMap & operator=(const TileMap &) = delete; // non copyable

    void update();
    void setLevel();
    void setLevel(std::shared_ptr<std::vector<gcb::tilemap::Tile>> level);
    void render(sf::RenderTarget& target);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

} // namespace gcb::tiles

#endif//ENGINE_BASE_TILEMAP_HPP
