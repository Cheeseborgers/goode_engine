//
// Created by fason on 14/07/2020.
//

#include "PauseMenu.hpp"

namespace gcb::gui
{
// Private Methods -----------------------------------------------------------------------
// Initializers --------------------------------------------------------------------------
void PauseMenu::initButtons()
{

}
// Constructor ---------------------------------------------------------------------------
PauseMenu::PauseMenu(sf::RenderWindow &window, sf::Font &font) : mFont(font)
{
    //Init background
    mBackground.setSize(
        sf::Vector2f(
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y)
        )
    );
    mBackground.setFillColor(
        sf::Color(20, 20, 20, 100));

    //Init container
    mContainer.setSize(
        sf::Vector2f(
            static_cast<float>(window.getSize().x) / 4.f,
            static_cast<float>(window.getSize().y) - 100.f
        )
    );
    mContainer.setFillColor(
        sf::Color(20, 20, 20, 200));
    mContainer.setPosition(
        static_cast<float>(window.getSize().x) / 2.f
            - mContainer.getSize().x / 2.f,
        30.f);

    // Buttons
    initButtons();

    // Header text
    mMenuText.setFont(font);
    mMenuText.setFillColor(
        sf::Color(255, 255, 255, 200));
    mMenuText.setCharacterSize(60);
    mMenuText.setString("Paused");
    mMenuText.setPosition(
      mContainer.getPosition().x + mContainer.getSize().x / 2.0F
         - mMenuText.getGlobalBounds().width / 2.0F,
      mContainer.getPosition().y + 40.0F);

}
// ---------------------------------------------------------------------------------------
PauseMenu::~PauseMenu() {}
// Accessors -----------------------------------------------------------------------------
const std::unordered_map<std::string, std::unique_ptr<gui::Button>>
    &PauseMenu::getButtons() const
{
    return mButtons;
}
// ---------------------------------------------------------------------------------------
bool PauseMenu::isButtonPressed(const std::string &key)
{
    return mButtons[key]->isPressed();
}
// Modifiers -----------------------------------------------------------------------------
void PauseMenu::addButton(
    const std::string &key, const float &posY, const std::string &text)
{
    float width = 250.0F;
    float height = 50.0F;
    float x = mContainer.getPosition().x
              + mContainer.getSize().x / 2.0F - width / 2.F;

    // TODO Make these colours constant
    mButtons[key] = std::make_unique<gui::Button>(
        x, posY, width, height, mFont, text, 50,
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
// Methods -------------------------------------------------------------------------------
void PauseMenu::update(const sf::Vector2f &mousePos, const float &dT)
{
    for (const auto &i : mButtons)
    {
        i.second->update(mousePos, dT);
    }
}
// ---------------------------------------------------------------------------------------
void PauseMenu::render(sf::RenderTarget &target) const
{
    target.draw(mBackground);

    target.draw(mContainer);

    target.draw(mMenuText);

    for (const auto &i : mButtons)
    {
        i.second->render(target);
    }
}
// ---------------------------------------------------------------------------------------


}// namespace gcb::gui
