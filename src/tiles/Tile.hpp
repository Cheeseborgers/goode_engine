//////////////////////////////////////////////////////////////////////////////////////////
//      file: Tile.hpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 04/07/2020.
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

#ifndef ENGINE_BASE_TILE_HPP
#define ENGINE_BASE_TILE_HPP


#include "../pch.hpp"


namespace gcb::tilemap
{
class Tile
{
  private:
    // Private Methods
    sf::RectangleShape mShape;
    sf::Vector2f mTilePos;

    sf::Text mText;
    sf::Font& mFont;

    void initText();

  public:
    // Constructor
    Tile(const sf::Vector2f &tilePos, const sf::Vector2f &tileSize, sf::Font &font);
    Tile(float tilePosX, float tilePosY, float tileSizeX, float tileSizeY, sf::Font &font);
    ~Tile();

    // Methods
    void update();
    void draw(sf::RenderTarget &target);
};

}// namespace gcb::tilemap


#endif//ENGINE_BASE_TILE_HPP
