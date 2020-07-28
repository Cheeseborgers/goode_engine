//////////////////////////////////////////////////////////////////////////////////////////
//      file: TextureManager.hpp
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

#ifndef ENGINE_BASE_TEXTUREMANAGER_HPP
#define ENGINE_BASE_TEXTUREMANAGER_HPP

#include "../pch.hpp"


namespace gcb {
class TextureManager
{
  private:
    std::unordered_map<std::string, sf::Texture> mTextures;

  public:
    TextureManager();

    // Getters
    sf::Texture &get(const std::string &name);
    bool isLoaded(const std::string& name) const;

    // Setters
    void unload(const std::string &name);

    // Methods
    void load(const std::string &name, const std::string &fileName);

};

}// namespace gcb

#endif//ENGINE_BASE_TEXTUREMANAGER_HPP
