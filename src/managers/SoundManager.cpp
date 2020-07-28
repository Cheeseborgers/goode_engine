//////////////////////////////////////////////////////////////////////////////////////////
//      file: SoundManager.cpp
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

#include "SoundManager.hpp"

namespace gcb
{

// Constructor ---------------------------------------------------------------------------
SoundManager::SoundManager(){}
// Getters -------------------------------------------------------------------------------
sf::SoundBuffer &SoundManager::getSoundBuffer(const std::string &name)
{
    return mSoundBuffers.at(name);
}
// ---------------------------------------------------------------------------------------
bool SoundManager::isLoaded(const std::string &name) const
{
    return mSoundBuffers.contains(name);
}
// Setters -------------------------------------------------------------------------------
void SoundManager::unload(const std::string &name)
{
    if (isLoaded(name))
    {
        mSoundBuffers.erase(name);
    }
}
// Methods ---------------------------------------------------------------------------------------
void SoundManager::load(const std::string &name, const std::string &fileName)
{
    sf::SoundBuffer buf;

    if (buf.loadFromFile(fileName))
    {
        mSoundBuffers[name] = buf;
    }
    else
    {
        std::cout << "ERROR::SoundManger::load::LOADSOUNDBUFFER::COULD "
             "NOT OPEN FILE: " << fileName << "\n";

    }
}
// ---------------------------------------------------------------------------------------
/*sf::Sound load(const std::string &name, const std::string &fileName)
{
    sf::SoundBuffer buf;

    auto mSoundBuffers;
    if (buf.loadFromFile(fileName))
    {

        mSoundBuffers[name] = buf;
        //return sf::Sound(buffer);
    }
    else
    {
        std::cout << "ERROR::SoundManger::load::LOADSOUNDBUFFER::COULD "
                     "NOT OPEN FILE: " << fileName << "\n";
    }
    mSoundBuffers.loadFromFile(name);
    return sf::Sound(buffer);
} */

// ---------------------------------------------------------------------------------------
void SoundManager::play(const std::string &name, float volume)
{
    sf::Sound sound;

    sound.setBuffer(mSoundBuffers.at(name));
    sound.setVolume(volume);
    sound.play();
}
// ---------------------------------------------------------------------------------------

}// namespace gcb
