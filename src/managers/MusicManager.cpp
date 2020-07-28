//
// Created by fason on 13/07/2020.
//

#include "MusicManager.hpp"

namespace gcb
{
// Constructor ---------------------------------------------------------------------------
MusicManager::MusicManager() {}
// Getters -------------------------------------------------------------------------------
sf::SoundBuffer &MusicManager::get(const std::string &name)
{
    return mMusicBuffers.at(name);
}
// ---------------------------------------------------------------------------------------
bool MusicManager::isLoaded(const std::string &name) const
{
    return mMusicBuffers.contains(name);
}
// Setters -------------------------------------------------------------------------------
void MusicManager::unload(const std::string &name)
{
    if (isLoaded(name))
    {
        mMusicBuffers.erase(name);
    }
}
// Methods -------------------------------------------------------------------------------
void MusicManager::load(const std::string &name, const std::string &fileName)
{
    sf::SoundBuffer buf;

    if (buf.loadFromFile(fileName))
    {
        mMusicBuffers[name] = buf;
    }
    else
    {
        std::cout << "ERROR::MusicManager::load::COULD NOT OPEN FILE: "
                  << fileName << "\n";
    }
}
// ---------------------------------------------------------------------------------------


}// namespace gcb
