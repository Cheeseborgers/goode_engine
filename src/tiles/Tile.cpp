//////////////////////////////////////////////////////////////////////////////////////////
//      file: Tile.cpp
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

#include "Tile.hpp"

namespace gcb::tilemap
{
// Initializers -------------------------------------------------------------------------
void Tile::initText()
{
    mText.setFont(mFont);
    mText.setFillColor(sf::Color::White);
    mText.setCharacterSize(14);
    mText.setString(
     std::to_string(static_cast<int>(mTilePos.x))
     + "\n" + std::to_string(static_cast<int>(mTilePos.y)));
    mText.setPosition(mTilePos.x + 5.0F, mTilePos.y + 5.0F);
}
// Constructors --------------------------------------------------------------------------
Tile::Tile(const sf::Vector2f &tilePos, const sf::Vector2f &tileSize, sf::Font &font)
    : mTilePos(tilePos), mFont(font)
{
    mShape.setSize(tileSize);
    mShape.setPosition(mTilePos);

    mShape.setFillColor(sf::Color::Red);
    mShape.setOutlineThickness(1.0F);
    mShape.setOutlineColor(sf::Color::Green);

    initText();
}
// ---------------------------------------------------------------------------------------
Tile::Tile(float tilePosX, float tilePosY,
    float tileSizeX, float tileSizeY, sf::Font &font)
    : mTilePos(sf::Vector2f(tilePosX, tilePosY)), mFont(font)
{
    mShape.setSize(sf::Vector2f(tileSizeX, tileSizeY));
    mShape.setPosition(mTilePos);

    mShape.setFillColor(sf::Color::Red);
    mShape.setOutlineThickness(1.0F);
    mShape.setOutlineColor(sf::Color::Green);

   initText();
}
// ---------------------------------------------------------------------------------------
Tile::~Tile() {}
// ---------------------------------------------------------------------------------------
void Tile::update() {}
// ---------------------------------------------------------------------------------------
void Tile::draw(sf::RenderTarget &target)
{
    target.draw(mShape);
    target.draw(mText);
}
// ---------------------------------------------------------------------------------------

}// namespace gcb::tilemap

