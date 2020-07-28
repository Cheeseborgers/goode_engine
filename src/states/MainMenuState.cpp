//////////////////////////////////////////////////////////////////////////////////////////
//      file: MainMenuState.cpp
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

#include "MainMenuState.hpp"

#include "EditorState.hpp"
#include "SettingsState.hpp"


namespace gcb {

// Initializers --------------------------------------------------------------------------
void MainMenuState::initTextures()
{
    /**************************************************************************
     * @return void
     * Loads textures into the asset manager.
     * Sets textures to their appropriate spites.
     * Sets sprite positions.
     *
     * @param None
     **************************************************************************/

    mData->textures->load(
      "main_menu_bg",
      Definitions::MAIN_MENU_BACKGROUND_FILEPATH);
    mData->textures->load(
      "game_title",
      Definitions::GAME_TITLE_FILEPATH);

    mBackground.setTexture(
      mData->textures->get("main_menu_bg"));
    mTitle.setTexture(
      mData->textures->get("game_title"));

    mTitle.setPosition(
        (static_cast<float>(mData->window->getSize().x)
         / 2.0F) - (mTitle.getGlobalBounds().width / 2.0F),
      mTitle.getGlobalBounds().height / 2.0F);

}
// ---------------------------------------------------------------------------------------
void MainMenuState::initFonts()
{
    mData->fonts->load(
      Definitions::PRIMARY_FONT_NAME, Definitions::PRIMARY_FONT_FILEPATH);

    mFooterText.setFont(
      mData->fonts->get(Definitions::PRIMARY_FONT_NAME));

    sf::VideoMode vm = mData->window->getVideoMode();
    mFooterText.setPosition(
      gcb::gui::p2Px(80, vm),
      gcb::gui::p2Py(90, vm));

    mFooterText.setFillColor(sf::Color::White);

    mFooterText.setCharacterSize(24);

    mFooterText.setString(Definitions::FOOTER_TEXT);
}
// ---------------------------------------------------------------------------------------
void MainMenuState::initButtons()
{
    sf::VideoMode vm = mData->window->getVideoMode();

    //gameState
    mButtons["play"] = std::make_unique<gui::Button>(
      gcb::gui::p2Px(50, vm), gcb::gui::p2Py(35, vm),
      50, 100, mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
      "Play", 50,
      sf::Color(70, 70, 70, 200),
      sf::Color(250, 250, 250, 250),
      sf::Color(20, 20, 20, 50),

      sf::Color(70, 70, 70, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0),
      sf::Color(70, 70, 70, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0), 0);

    mButtons["editor"] = std::make_unique<gui::Button>(
      gcb::gui::p2Px(50, vm), gcb::gui::p2Py(45, vm),
      50, 100, mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
      "Editor", 50,
      sf::Color(70, 70, 70, 200),
      sf::Color(250, 250, 250, 250),
      sf::Color(20, 20, 20, 50),

      sf::Color(70, 70, 70, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0),
      sf::Color(70, 70, 70, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0), 0);

    mButtons["settings"] = std::make_unique<gui::Button>(
      gcb::gui::p2Px(50, vm), gcb::gui::p2Py(55, vm),
      50, 100, mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
      "Settings", 50,
      sf::Color(70, 70, 70, 200),
      sf::Color(250, 250, 250, 250),
      sf::Color(20, 20, 20, 50),

      sf::Color(70, 70, 70, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0),
      sf::Color(70, 70, 70, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0), 0);

    mButtons["quit"] = std::make_unique<gui::Button>(
      gcb::gui::p2Px(50, vm), gcb::gui::p2Py(75, vm),
      50, 100, mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
      "Quit", 50,
      sf::Color(70, 70, 70, 200),
      sf::Color(250, 250, 250, 250),
      sf::Color(20, 20, 20, 50),

      sf::Color(70, 70, 70, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0),
      sf::Color(70, 70, 70, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0), 0);
}
// ---------------------------------------------------------------------------------------
void MainMenuState::loadGameState()
{
    mData->machine.addState(
      StateRef(std::make_unique<GameState>(mData)), true);
}
// ---------------------------------------------------------------------------------------
void MainMenuState::loadEditorState()
{
    mData->machine.addState(
      StateRef(std::make_unique<EditorState>(mData)), true);
}
// ---------------------------------------------------------------------------------------
void MainMenuState::loadSettingsState()
{
    mData->machine.addState(
      StateRef(std::make_unique<SettingsState>(mData)), true);
}
// Constructor ---------------------------------------------------------------------------
MainMenuState::MainMenuState(GameDataRef data) : mData(data) {}
// Destructor ----------------------------------------------------------------------------
MainMenuState::~MainMenuState() {}
// Accessors -----------------------------------------------------------------------------
// Modifiers -----------------------------------------------------------------------------
// Methods -------------------------------------------------------------------------------
void MainMenuState::init()
{
    /**************************************************************************
     * @return void
     * Initializes a MainMenuState object.
     *
     * Initializes textures.
     * Initializes fonts.
     * Initializes buttons.
     *
     * @param None
     **************************************************************************/

    initTextures();
    initFonts();
    initButtons();

    mData->machine.setCurrentState(States::MAIN_MENU_STATE);
}
// ---------------------------------------------------------------------------------------
void MainMenuState::handleInput([[maybe_unused]] const float& dT)
{
    /**************************************************************************
    * @return void
    * Polls SF events to handle button functionality
    *
    * @param None
    **************************************************************************/

    // TODO: MOVE ALL THIS TO THE INPUT HANDLER OR WHAAA?
    // COMMAND PATTERN
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
            if (ev.key.code == sf::Keyboard::Escape)
            {
                mData->window->close();
            }

            if (ev.key.code == sf::Keyboard::F5)
            {
                mData->window->toggleFullScreen();
            }

            if (ev.key.code == sf::Keyboard::Enter)
            {
                loadGameState();
            }

            break;
        }
        default:
            break;
        }
    }
}
// ---------------------------------------------------------------------------------------
void MainMenuState::updateButtons(const sf::Vector2f &mousePos, const float &dT)
{
    for (const auto &i : mButtons)
    {
        i.second->update(mousePos, dT);
    }

    if (mButtons["play"]->isPressed())
    {
        loadGameState();
    }

    if (mButtons["editor"]->isPressed())
    {
        loadEditorState();
    }

    if (mButtons["settings"]->isPressed())
    {
        loadSettingsState();
    }

    if (mButtons["quit"]->isPressed())
    {
        mData->window->close();
    }
}
// ---------------------------------------------------------------------------------------
void MainMenuState::update(const float &dT)
{
    updateButtons(mData->input->getMousePosView(), dT);
}
// ---------------------------------------------------------------------------------------
void MainMenuState::render([[maybe_unused]] const float &dT)
{
    mData->window->beginDraw();

    mData->window->draw(mBackground);
    mData->window->draw(mTitle);

    for (const auto &i : mButtons)
    {
        i.second->render(*mData->window->getRenderWindow());
    }

    mData->window->draw(mFooterText);

    mData->window->endDraw();
}
// ---------------------------------------------------------------------------------------
void MainMenuState::handleWindowInput()
{
}
// ---------------------------------------------------------------------------------------


}// namespace gcb

