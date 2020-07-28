//
// Created by fason on 14/07/2020.
//

#ifndef ENGINE_BASE_PAUSEMENU_HPP
#define ENGINE_BASE_PAUSEMENU_HPP

#include "../pch.hpp"
#include "Button.hpp"

namespace gcb::gui
{
class PauseMenu
{
  private:
    //Variables
    sf::RectangleShape mBackground;
    sf::RectangleShape mContainer;
    sf::Font& mFont;
    sf::Text mMenuText;

    std::unordered_map<std::string, std::unique_ptr<Button>> mButtons;

    // Private Methods
    void initButtons();

  public:
    // Constructor / Destructor
    PauseMenu(sf::RenderWindow &window, sf::Font& font);
    ~PauseMenu();

    // Accessors
    const std::unordered_map<std::string, std::unique_ptr<gui::Button>>
      &getButtons() const;
    bool isButtonPressed(const std::string &key);

    // Modifiers
    void addButton(const std::string &key, const float &posY, const std::string &text);

    // Methods
    void update(const sf::Vector2f &mousePos, const float &dT);
    void render(sf::RenderTarget &target) const;
};

}// namespace gcb::gui






#endif//ENGINE_BASE_PAUSEMENU_HPP
