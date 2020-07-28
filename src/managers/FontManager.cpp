//////////////////////////////////////////////////////////////////////////////////////////
//      file: FontManager.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 13/07/2020.
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

#include "FontManager.hpp"


namespace gcb
{
// Constructor ---------------------------------------------------------------------------
FontManager::FontManager(){}
// Accessors -----------------------------------------------------------------------------
sf::Font &FontManager::get(const std::string &name)
{
    return mFonts.at(name);
}
// ---------------------------------------------------------------------------------------
bool FontManager::isLoaded(const std::string &name) const
{
    return mFonts.contains(name);
}
// Setters -------------------------------------------------------------------------------
void FontManager::unload(const std::string &name)
{
    if (isLoaded(name))
    {
        mFonts.erase(name);
    }
}
// Methods -------------------------------------------------------------------------------
void FontManager::load(const std::string &name, const std::string &fileName)
{
    sf::Font font;

    if (font.loadFromFile(fileName)) {
        mFonts[name] = font;
    } else {
        std::cout << "ERROR::ASSETMANAGER::LOADFONT::COULD NOT OPEN FILE: "
                  << fileName << "\n";
    }
}
// ---------------------------------------------------------------------------------------


}// namespace gcb

