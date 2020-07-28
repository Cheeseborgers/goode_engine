//////////////////////////////////////////////////////////////////////////////////////////
//      file: SlashState.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 13/06/2020.
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

#include "SplashState.hpp"

namespace gcb
{
// Initializers --------------------------------------------------------------------------
void SplashState::initTextures()
{
    /**************************************************************************
     * @return void
     *
     * @brief Loads Textures into the their managers.
     * Sets textures to their appropriate sprites.
     *
     * @param None
     *************************************************************************/

    // Background
    mData->textures->load(
      Definitions::SPLASH_STATE_BACKGROUND_NAME,
      Definitions::SPLASH_STATE_BACKGROUND_FILEPATH);

    mBackground.setTexture(
      mData->textures->get(
        Definitions::SPLASH_STATE_BACKGROUND_NAME));
}
// ---------------------------------------------------------------------------------------
void SplashState::initSounds()
{
    /**************************************************************************
     * @return void
     *
     * @brief Loads Sounds into the their managers.
     *
     * Initializes any sound related variables for state
     * Sets sounds.
     *
     * @param None
     *************************************************************************/

    mSoundPlayed = false;
    
    mData->sounds->load(
      Definitions::SPLASH_STATE_SOUND_NAME,
      Definitions::SPLASH_STATE_SOUND_FILEPATH);
}
// Constructor ---------------------------------------------------------------------------
SplashState::SplashState(GameDataRef data)  : mData(data) {}
// Destructor ----------------------------------------------------------------------------
SplashState::~SplashState()
{
    mData->sounds->unload(Definitions::SPLASH_STATE_SOUND_NAME);
}
// Methods -------------------------------------------------------------------------------
void SplashState::init()
{
    /**************************************************************************
      * @return void
      *
      * Initializes Textures.
      * Initializes Sounds.
      *
      * @param None
      *************************************************************************/

    initTextures();
    initSounds();

    mData->machine.setCurrentState(States::SPLASH_STATE);
}
// ---------------------------------------------------------------------------------------
void SplashState::handleInput([[maybe_unused]] const float& dT)
{
    /**************************************************************************
    * @return void
    * Polls SF events to handle button functionality
    *
    * @param None
    **************************************************************************/

    sf::Event ev;

    while (mData->window->getRenderWindow()->pollEvent(ev))
    {
        switch (ev.type)
        {
            case (sf::Event::Closed):
            {
                mData->window->close();
                break;
            }
            case (sf::Event::KeyPressed):
            {
                if (ev.key.code == sf::Keyboard::F5)
                {
                    mData->window->toggleFullScreen();
                }
                break;
            }
            default:
                break;
        }
    }
}
// ---------------------------------------------------------------------------------------
void SplashState::update([[maybe_unused]] const float &dT)
{
    if (!mSoundPlayed)
    {
        mSound.setBuffer(mData->sounds->getSoundBuffer(
          Definitions::SPLASH_STATE_SOUND_NAME));
        mSound.play();
        mSoundPlayed = true;
    }

    if (mClock.getElapsedTime().asSeconds()
        > Definitions::SPLASHSTATE_SHOW_TIME)
    {
        mData->machine.addState(
            StateRef(
                std::make_unique<MainMenuState>(mData)), true);
    }
}
// ---------------------------------------------------------------------------------------
void SplashState::render([[maybe_unused]] const float &dT)
{
    mData->window->beginDraw();

    mData->window->draw(mBackground);

    mData->window->endDraw();
}
void SplashState::handleWindowInput()
{
}
// ---------------------------------------------------------------------------------------

}// namespace gcb

