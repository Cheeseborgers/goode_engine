//////////////////////////////////////////////////////////////////////////////////////////
//      file: EditorState.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 15/07/2020.
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

#include "EditorState.hpp"
#include "MainMenuState.hpp"

namespace gcb
{
// Initializers --------------------------------------------------------------------------
void EditorState::initTextures()
{
    /**************************************************************************
    * @return void
    *
    * @brief Checks if textures where previously loaded into the
    * texture manager, Loading any required textures that are not already
    * available to the state.
    *
    * Sets textures to their respective sprites.
    *
    * @param None
    *************************************************************************/

    if (!mData->textures->isLoaded(Definitions::EDITOR_STATE_BACKGROUND_NAME))
    {
        mData->textures->load(
          Definitions::EDITOR_STATE_BACKGROUND_NAME,
          Definitions::EDITOR_STATE_BACKGROUND_FILEPATH);
    }

    mBackground.setTexture(
      mData->textures->get(Definitions::EDITOR_STATE_BACKGROUND_NAME));
}
// ---------------------------------------------------------------------------------------
void EditorState::initFonts()
{
    /**************************************************************************
    * @return void
    *
    * @brief Checks if fonts previously loaded into font manager, Loading
    * any required fonts that are not already available to the state.
    *
    * @param None
    *************************************************************************/

    if (!mData->fonts->isLoaded(Definitions::PRIMARY_FONT_NAME))
    {
        mData->fonts->load(
          Definitions::PRIMARY_FONT_NAME,
          Definitions::PRIMARY_FONT_FILEPATH);
    }
}
// ---------------------------------------------------------------------------------------
void EditorState::initPauseMenu()
{
    /************************************************************
     * @return void
     *
     * @brief Initializes the Pause menu and its buttons
     *
     * @param None
     ************************************************************/

    mPauseMenu = std::make_unique<gui::PauseMenu>(
      *mData->window->getRenderWindow(),
      mData->fonts->get(Definitions::PRIMARY_FONT_NAME));

    mPauseMenu->addButton("unpause", 500.0F, "Unpause");
    mPauseMenu->addButton("back", 700.0F, "Back");
    mPauseMenu->addButton("quit", 800.0F, "Quit");
}
// ---------------------------------------------------------------------------------------
void EditorState::initGui()
{
    /************************************************************
     * @return void
     *
     * @brief Initializes the Gui and its Widgets
     *
     * @param None
     ************************************************************/

    mGui = std::make_unique<gcb::gui::Gui>(*mData->window->getRenderWindow());
}
// Constructor ---------------------------------------------------------------------------
EditorState::EditorState(GameDataRef data)  : mData(data){}
// Destructor ----------------------------------------------------------------------------
EditorState::~EditorState() {}
// Methods -------------------------------------------------------------------------------
void EditorState::init()
{
    initTextures();
    initFonts();
    initPauseMenu();
    initGui();

    mData->machine.setCurrentState(States::EDITOR_STATE);
}
// ---------------------------------------------------------------------------------------
void EditorState::handleInput([[maybe_unused]] const float& dT)
{
    /**************************************************************************
    * @return void
    * Polls SF events to handle button functionality
    *
    * @param None
    **************************************************************************/

    // TODO: MOVE ALL THIS GENERIC INPUT STUFF???
    //  ALSO  FIX THE COMMENTS TO MATCH FUNCTIONALITY====================================

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

                if (ev.key.code == sf::Keyboard::Escape) {
                    if (!isPaused())
                    {
                        setPause();
                    }
                    else
                    {
                        resume();
                    }
                }

                break;
            }
            default:
                break;
        }
    }
}
// ---------------------------------------------------------------------------------------
void EditorState::handlePauseMenuButtons()
{
    /********************************************************
     * @return void
     *
     * @brief Checks if the pause menu buttons are pressed and
     * performs the corresponding action.
     *
     * 'back': goes back to main menu state on left mouse click.
     * 'quit': quits the entire game.
     * 'unpause': returns back to the editor state.
     *
     * @param None
     ********************************************************/

    // TODO: FIX THE PAUSE MENU GAME END =================================================
    if (mPauseMenu->isButtonPressed("back"))
    {
        mData->machine.addState(StateRef(
          std::make_unique<MainMenuState>(mData)), true);
    }

    if (mPauseMenu->isButtonPressed("quit"))
    {
        setQuit(true);
    }

    if (mPauseMenu->isButtonPressed("unpause"))
    {
        if (!isPaused())
        {
            setPause();
        }
        else
        {
            resume();
        }
    }
}
// ---------------------------------------------------------------------------------------
void EditorState::handleWindowInput() {}
// ---------------------------------------------------------------------------------------
void EditorState::update(const float &dT)
{
    /**********************************************************
     * @return void
     *
     * @brief Updates the Editor state.
     *
     * If not paused, updates the tile map and editor gui.
     * If Paused updates the Pause menu and its buttons.
     *
     * @param dT: delta time / interpolation since last frame
     * update.
     *********************************************************/

    if (!isPaused())
    {
        mGui->update();
    }
    else
    {
        mPauseMenu->update(mData->input->getMousePosView(), dT);
        handlePauseMenuButtons();
    }
}
// ---------------------------------------------------------------------------------------
void EditorState::render([[maybe_unused]] const float &dT)
{
    /*************************************************************
     * @return void
     *
     * @brief Draws the Editor state scene to the render window.
     *
     * Clears the window framebuffer.
     * Draws the Tile map.
     * If paused, draws the Pause menu.
     * Draws the framebuffer to the window.
     *
     * @param dT: delta time/ interpolation since
     * last update and render cycle.
     **************************************************************/

    mData->window->beginDraw();

    mData->window->draw(mBackground);

    // Tilemap
    //mMap->render(*mData->window->getRenderWindow());

    if (isPaused())
    {
        // Pause menu
        mPauseMenu->render(*mData->window->getRenderWindow());
    }

    mData->window->endDraw();
}
// ---------------------------------------------------------------------------------------


}// namespace gcb
