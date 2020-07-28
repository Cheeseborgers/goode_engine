//////////////////////////////////////////////////////////////////////////////////////////
//      file: GameOverState.cpp
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

#include "GameOverState.hpp"

namespace gcb
{
// Initializers --------------------------------------------------------------------------
void GameOverState::initTextures()
{
    /**************************************************************************
    * @brief Loads textures into the asset manager, if not already loaded.
    * Sets textures to their appropriate spites.
     *
    * @param None
    *
    * @return void
    *************************************************************************/

    if (!mData->textures->isLoaded(Definitions::GAMEOVER_BACKGROUND_NAME))
    {
        mData->textures->load(
          Definitions::GAMEOVER_BACKGROUND_NAME,
          Definitions::GAMEOVER_BACKGROUND_FILEPATH);

    }

    mBackground.setTexture(
      mData->textures->get(Definitions::GAMEOVER_BACKGROUND_NAME));
}
// Constructor ---------------------------------------------------------------------------
GameOverState::GameOverState(GameDataRef data)  : mData(data) {}
// Destructor ----------------------------------------------------------------------------
GameOverState::~GameOverState() {}
// Methods -------------------------------------------------------------------------------
void GameOverState::init()
{
    initTextures();

    mData->machine.setCurrentState(States::GAME_OVER_STATE);
}
// ---------------------------------------------------------------------------------------
void GameOverState::handleInput([[maybe_unused]] const float& dT) {}
// ---------------------------------------------------------------------------------------
void GameOverState::handleWindowInput()
{
    sf::Event ev;

    while (mData->window->getRenderWindow()->pollEvent(ev))
    {
        if (sf::Event::Closed == ev.type)
        {
            mData->window->close();
        }
    }
}
// ---------------------------------------------------------------------------------------
void GameOverState::update([[maybe_unused]] const float &dT) {}
// ---------------------------------------------------------------------------------------
void GameOverState::render([[maybe_unused]] const float &dT)
{
    mData->window->beginDraw();

    mData->window->draw(mBackground);

    mData->window->endDraw();
}
// ---------------------------------------------------------------------------------------


}// namespace gcb
