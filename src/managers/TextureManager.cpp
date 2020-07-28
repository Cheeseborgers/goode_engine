//////////////////////////////////////////////////////////////////////////////////////////
//      file: TextureManager.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 03/06/2020.
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

#include "TextureManager.hpp"


namespace gcb
{
// Constructor ---------------------------------------------------------------------------
TextureManager::TextureManager() {}
// Getters -------------------------------------------------------------------------------
sf::Texture &TextureManager::get(const std::string &name)
{
    return mTextures.at(name);
}
// ---------------------------------------------------------------------------------------
bool TextureManager::isLoaded(const std::string &name) const
{
    return mTextures.contains(name);
}
// Setters -------------------------------------------------------------------------------
void TextureManager::unload(const std::string &name)
{
    if (isLoaded(name))
    {
        mTextures.erase(name);
    }
}
// Methods -------------------------------------------------------------------------------
void TextureManager::load(const std::string &name, const std::string &fileName)
{
    sf::Texture tex;

    if (tex.loadFromFile(fileName)) {
        mTextures[name] = tex;
    } else {
        std::cout << "ERROR::TextureManager::load::COULD NOT OPEN FILE: "
                  << fileName << "\n";
    }
}
// ---------------------------------------------------------------------------------------

}// namespace gcb