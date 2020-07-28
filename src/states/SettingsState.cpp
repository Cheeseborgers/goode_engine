//////////////////////////////////////////////////////////////////////////////////////////
//      file: SettingsState.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 12/07/2020.
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

#include "SettingsState.hpp"
#include "../gui/Gui.hpp"
#include "MainMenuState.hpp"

namespace gcb
{
// Initializers --------------------------------------------------------------------------
void SettingsState::initVariables()
{
    mCurrentMenu = SettingsMenuStates::GRAPHICS_SETTINGS;
}
// ---------------------------------------------------------------------------------------
void SettingsState::initTextures()
{
    if (!mData->textures->isLoaded(Definitions::SETTINGS_STATE_BACKGROUND_NAME))
    {
        mData->textures->load(
          Definitions::SETTINGS_STATE_BACKGROUND_NAME,
          Definitions::SETTINGS_STATE_BACKGROUND_FILEPATH);
    }
}
// ---------------------------------------------------------------------------------------
void SettingsState::initFonts()
{
    if (!mData->fonts->isLoaded(Definitions::PRIMARY_FONT_NAME))
    {
        mData->fonts->load(
          Definitions::PRIMARY_FONT_NAME,
          Definitions::PRIMARY_FONT_FILEPATH);
    }
}
// ---------------------------------------------------------------------------------------
void SettingsState::initBackground()
{
    mBackground.setTexture(
      mData->textures->get(Definitions::SETTINGS_STATE_BACKGROUND_NAME));
}
// ---------------------------------------------------------------------------------------
void SettingsState::initContainer()
{
    mContainer.setSize(sf::Vector2f (
      static_cast<float>(mData->window->getSize().x) - 700.0F,
      static_cast<float>(mData->window->getSize().y) - 140.0F));

    mContainer.setPosition(
      static_cast<float>(mData->window->getSize().x / 2)
        - mContainer.getGlobalBounds().width / 2,
      60.0F);

    mContainer.setFillColor(sf::Color(100, 100, 100, 160));
}
// ---------------------------------------------------------------------------------------
void SettingsState::initText()
{
    mHeaderText.setFont(mData->fonts->get(Definitions::PRIMARY_FONT_NAME));
    mHeaderText.setFillColor(sf::Color::White);
    mHeaderText.setString("Settings");
    mHeaderText.setCharacterSize(
      gui::calcCharSize(mData->window->getVideoMode(), 40));

    //TODO CENTER THIS TEXT ==============================================================
    mHeaderText.setPosition(
      (mContainer.getPosition().x
        + (mContainer.getGlobalBounds().width / 2)
        - (mHeaderText.getGlobalBounds().width / 2)),
      mContainer.getPosition().y + 20.F);
}
// ---------------------------------------------------------------------------------------
void SettingsState::initGui()
{
    const auto& vm = mData->window->getVideoMode();

    // Header buttons ----------------------------------------------------
    mButtons["graphics"] = std::make_unique<gui::Button>(
        gui::p2Px(30.0F, vm), gui::p2Py(20.0F, vm),
        gui::p2Px(8.0F, vm), gui::p2Py(6.0F, vm),
        mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
        "Graphics", gui::calcCharSize(vm, 60),
        // Text color
        sf::Color(250, 250, 250, 250), // IDLE
        sf::Color(150, 150, 150, 250), // HOVER
        sf::Color(20, 20, 20, 50),     // ACTIVE
        // Button color
        sf::Color(100, 100, 100, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0),
        0);

    mButtons["audio"] = std::make_unique<gui::Button>(
        gui::p2Px(40.0F, vm), gui::p2Py(20.0F, vm),
        gui::p2Px(8.0F, vm), gui::p2Py(6.0F, vm),
        mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
        "Audio", gui::calcCharSize(vm, 60),
        // Text color
        sf::Color(250, 250, 250, 250), // IDLE
        sf::Color(150, 150, 150, 250), // HOVER
        sf::Color(20, 20, 20, 50),     // ACTIVE
        // Button color
        sf::Color(100, 100, 100, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0),
        0);

    mButtons["controls"] = std::make_unique<gui::Button>(
        gui::p2Px(50.0F, vm), gui::p2Py(20.0F, vm),
        gui::p2Px(8.0F, vm), gui::p2Py(6.0F, vm),
        mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
        "Controls", gui::calcCharSize(vm, 60),
        // Text color
        sf::Color(250, 250, 250, 250), // IDLE
        sf::Color(150, 150, 150, 250), // HOVER
        sf::Color(20, 20, 20, 50),     // ACTIVE
        // Button color
        sf::Color(100, 100, 100, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0),
        0);

    // Footer buttons --------------------------------------------------
    mButtons["back"] = std::make_unique<gui::Button>(
        gui::p2Px(73.0F, vm), gui::p2Py(83.0F, vm),
        gui::p2Px(8.0F, vm), gui::p2Py(6.0F, vm),
        mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
        "Back", gui::calcCharSize(vm, 60),
        // Text color
        sf::Color(250, 250, 250, 250), // IDLE
        sf::Color(150, 150, 150, 250), // HOVER
        sf::Color(20, 20, 20, 50),     // ACTIVE
        // Button color
        sf::Color(100, 100, 100, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0),
        0);

    mButtons["apply"] = std::make_unique<gui::Button>(
        gui::p2Px(64.5F, vm), gui::p2Py(83.0F, vm),
        gui::p2Px(8.0F, vm), gui::p2Py(6.0F, vm),
        mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
        "Apply", gui::calcCharSize(vm, 60),
        // Text color
        sf::Color(250, 250, 250, 250), // IDLE
        sf::Color(150, 150, 150, 250), // HOVER
        sf::Color(20, 20, 20, 50),     // ACTIVE
        // Button color
        sf::Color(100, 100, 100, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0),
        0);

    // Video Modes ================================================================
    std::vector<std::string> modesStr;

    for (auto &it : mData->window->getVideoModes())
    {
        modesStr.push_back(std::to_string(it.width) + 'x' + std::to_string(it.height));
    }

    sort( modesStr.begin(), modesStr.end() );
    modesStr.erase( unique( modesStr.begin(), modesStr.end() ), modesStr.end() );

    //Drop down lists ------------------------------------------------------
    mDropDownLists["resolution"] = std::make_unique<gui::DropDownList>(
      gui::p2Px(42.0F, vm), gui::p2Py(28.0F, vm),
      gui::p2Px(10.4F, vm), gui::p2Py(4.5F, vm),
      mData->fonts->get(Definitions::PRIMARY_FONT_NAME),
      gui::calcCharSize(vm, 70),
      modesStr.data(), modesStr.size(),
      sf::Color(70, 70, 70, 200),
      sf::Color(250, 250, 250, 250),
      sf::Color(20, 20, 20, 50),
      sf::Color(100, 100, 100, 255),
      sf::Color(150, 150, 150, 255),
      sf::Color(20, 20, 20, 255),
      sf::Color(100, 100, 100, 0),
      sf::Color(150, 150, 150, 0),
      sf::Color(20, 20, 20, 0),
      0);
}
// Constructor ---------------------------------------------------------------------------
SettingsState::SettingsState(GameDataRef data)  : mData(data){}
// Destructor ----------------------------------------------------------------------------
SettingsState::~SettingsState() {}
// Methods -------------------------------------------------------------------------------
void SettingsState::init()
{
    initVariables();
    initTextures();
    initFonts();
    initBackground();
    initContainer();
    initText();
    initGui();

    mData->machine.setCurrentState(States::SETTINGS_STATE);
}
// ---------------------------------------------------------------------------------------
void SettingsState::handlePlayerInput([[maybe_unused]] const float& dT)
{

}
// ---------------------------------------------------------------------------------------
void SettingsState::handleInput([[maybe_unused]] const float& dT)
{
    /*************************************************************
    * @return void
    *
    * @brief Polls SF events to handle keyboard key and window
    * close control functionality.
     *
    * Calls the Player input handler.
    *
    * @param None
    *************************************************************/

    sf::Event ev;

    // TODO: MOVE ALL THIS GENERIC INPUT STUFF??? ===================================
    while (mData->window->getRenderWindow()->pollEvent(ev))
    {
        if (sf::Event::Closed == ev.type)
        {
            mData->window->close();
        }

        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
        {
            mData->window->close();
        }

        if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::F5)
        {
            mData->window->toggleFullScreen();
        }
    }

    handlePlayerInput(dT);
}
// ---------------------------------------------------------------------------------------
void SettingsState::updateGraphicsSettingsMenu()
{
   /***********************************************************
   * @return void
   *
   * @brief Updates the Graphics settings menu.
   *
   * @param None
   *************************************************************/
}
// ---------------------------------------------------------------------------------------
void SettingsState::updateAudioSettingsMenu()
{
   /***********************************************************
   * @return void
   *
   * @brief Updates the Audio settings menu.
   *
   * @param None
   *************************************************************/
}
// ---------------------------------------------------------------------------------------
void SettingsState::updateControlSettingsMenu()
{
    /***********************************************************
   * @return void
   *
   * @brief Updates the Control settings menu.
   *
   * @param None
   *************************************************************/
}
// ---------------------------------------------------------------------------------------
void SettingsState::updateGui(const float &dT)
{
    /*********************************************************
     * @brief Updates all the gui elements in the state and
     * handles their functionality
     *
     * @param float dT:
     *
     * @return void
     ********************************************************/

    // Buttons =================================================================
    for (const auto &it : mButtons)
    {
        it.second->update(mData->input->getMousePosView(), dT);
    }

    if (mButtons["graphics"]->isPressed())
    {
        mCurrentMenu = SettingsMenuStates::GRAPHICS_SETTINGS;
    }

    if (mButtons["audio"]->isPressed())
    {
        mCurrentMenu = SettingsMenuStates::AUDIO_SETTINGS;
    }

    if (mButtons["controls"]->isPressed())
    {
        mCurrentMenu = SettingsMenuStates::CONTROL_SETTINGS;
    }

    // Button functionality
    // Apply the current selected settings
    if (mButtons["apply"]->isPressed())
    {
        // TODO: FIX THIS CRASH ON APPLICATION ==========================================
        mData->window->setVideoMode(
          mData->window->getVideoModes()[mDropDownLists["resolution"]->getActiveElementId()]);

        mData->window->create();
    }

    // Back to main menu
    if (mButtons["back"]->isPressed())
    {
        mData->machine.addState(
          StateRef(
            std::make_unique<MainMenuState>(mData)), true);
    }

    // Dropdown lists update ====================================================
    for (const auto &it : mDropDownLists)
    {
        it.second->update(mData->input->getMousePosView(), dT);
    }

    // Dropdown list functionality
}
// ---------------------------------------------------------------------------------------
void SettingsState::update([[maybe_unused]] const float &dT)
{
    /***********************************************************
   * @brief Determines and updates the current menu.
   *
   * @param None
   *
   * @return void
   *************************************************************/

    switch (mCurrentMenu)
    {
    case (SettingsMenuStates::GRAPHICS_SETTINGS):
    {
        updateGraphicsSettingsMenu();
        break;
    }
    case (SettingsMenuStates::AUDIO_SETTINGS):
    {
        updateAudioSettingsMenu();
        break;
    }
    case (SettingsMenuStates::CONTROL_SETTINGS):
    {
        updateControlSettingsMenu();
        break;
    }
    default:
        // TODO ADD LOGGING HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        break;
    }

    updateGui(dT);
}
// ---------------------------------------------------------------------------------------
void SettingsState::renderGraphicsSettingsMenu()
{
   /***********************************************************
   * @brief Draws the Graphics settings menu.
   *
   * @param None
   *
   * @return void
   *************************************************************/

   std::cout << "graphics\n";
}
// ---------------------------------------------------------------------------------------
void SettingsState::renderAudioSettingsMenu()
{
    /***********************************************************
    * @brief Draws the Audio settings menu.
    *
    * @param None
    *
    * @return void
    *************************************************************/

    std::cout << "audio\n";
}
// ---------------------------------------------------------------------------------------
void SettingsState::renderControlSettingsMenu()
{
    /***********************************************************
    * @brief Draws the Control settings menu.
    *
    * @param None
    *
    * @return void
    *************************************************************/

    std::cout << "control\n";
}
// ---------------------------------------------------------------------------------------
void SettingsState::renderGui()
{
    /***********************************************************
    * @brief Draws the Gui elements to the current
    * window Context.
    *
    * Renders all the Gui buttons
    * Renders all the drop down list elements
    *
    * @param None
    *
    * @return void
    *************************************************************/

    for (const auto &it : mButtons)
    {
        it.second->render(*mData->window->getRenderWindow());
    }

    for (const auto &it : mDropDownLists)
    {
        it.second->render(*mData->window->getRenderWindow());
    }
}
// ---------------------------------------------------------------------------------------
void SettingsState::render([[maybe_unused]] const float &dT)
{
    /***********************************************************
    * @return void
    *
    * @brief Clears the framebuffer and renders the states
    * sf::Drawable objects.
    *
    * Draws the background.
    * Draws the container.
    * Draws the "Settings" title.
    * Displays the framebuffer to the window.
    *
    * @param dT: Delta Time since last frame update and render.
    *************************************************************/

    mData->window->beginDraw();

    mData->window->draw(mBackground);
    mData->window->draw(mContainer);
    mData->window->draw(mHeaderText);

    renderGui();

    mMousePosition.render(*mData->window->getRenderWindow(),
      *mData->input);

    switch (mCurrentMenu)
    {
    case (SettingsMenuStates::GRAPHICS_SETTINGS):
    {
        renderGraphicsSettingsMenu();
        break;
    }
    case (SettingsMenuStates::AUDIO_SETTINGS):
    {
        renderAudioSettingsMenu();
        break;
    }
    case (SettingsMenuStates::CONTROL_SETTINGS):
    {
        renderControlSettingsMenu();
        break;
    }
    default:
        // TODO ADD LOGGING HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        break;
    }

    mData->window->endDraw();
}
void SettingsState::handleWindowInput()
{
}
// ---------------------------------------------------------------------------------------

}// namespace gcb

