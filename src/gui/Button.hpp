//
//      Created by Goodecheeseburgers on 22/06/2020.
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
//

#ifndef ENGINE_BASE_BUTTON_HPP
#define ENGINE_BASE_BUTTON_HPP

#include "../pch.hpp"
#include "Widget.hpp"

namespace gcb::gui
{
enum ButtonStates : unsigned char {
    BTN_IDLE = 0,
    BTN_HOVER,
    BTN_ACTIVE };

class Button : public Widget{
public:
    // ConstructorS
    Button(float positionX, float positionY, float width, float height,
        sf::Font &font, const std::string &text, unsigned characterSize,
        const sf::Color &textIdleColor, const sf::Color &textHoverColor,
        const sf::Color &textActiveColor, const sf::Color &idleColor,
        const sf::Color &hoverColor, const sf::Color &activeColor,
        const sf::Color &outlineIdleColor,
        const sf::Color &outlineHoverColor,
        const sf::Color &outlineActiveColor);

    Button(float positionX, float positionY, float width, float height,
        sf::Font &font, const std::string &text, unsigned characterSize,
        const sf::Color &textIdleColor, const sf::Color &textHoverColor,
        const sf::Color &textActiveColor, const sf::Color &idleColor,
        const sf::Color &hoverColor, const sf::Color &activeColor,
        const sf::Color &outlineIdleColor,
        const sf::Color &outlineHoverColor,
        const sf::Color &outlineActiveColor,
        short unsigned id);

    Button(float positionX, float positionY, float width, float height,
       sf::Font &font, const std::string &text, unsigned characterSize,
       const sf::Color &textIdleColor, const sf::Color &textHoverColor,
       const sf::Color &textActiveColor, const sf::Color &idleColor,
       const sf::Color &hoverColor, const sf::Color &activeColor);

    Button(float positionX, float positionY, float width, float height,
       sf::Font &font, const std::string &text, unsigned characterSize,
       const sf::Color &textIdleColor, const sf::Color &textHoverColor,
       const sf::Color &textActiveColor, const sf::Color &idleColor,
       const sf::Color &hoverColor, const sf::Color &activeColor,
       short unsigned id);

    // Accessors
    bool isPressed() const;
    const std::string getText() const;
    const unsigned short &getId() const;

    // Modifiers
    void setText(const std::string &text);
    void setId(const unsigned short &id);

    // Methods
    void update(const sf::Vector2f &mousePosition, const float &dT) override;
    void render(sf::RenderTarget& target) const override;

private:
    ButtonStates mBtnState;
    short unsigned mId;

    sf::RectangleShape mShape;
    sf::Font mFont;
    sf::Text mText;

    sf::Color mTextIdleColor;
    sf::Color mTextHoverColor;
    sf::Color mTextActiveColor;

    sf::Color mIdleColor;
    sf::Color mHoverColor;
    sf::Color mActiveColor;

    sf::Color mOutlineIdleColor;
    sf::Color mOutlineHoverColor;
    sf::Color mOutlineActiveColor;

    void init(float positionX, float positionY, float width, float height,
      const std::string &text, unsigned characterSize);
};

using Buttons = std::unordered_map<std::string, std::unique_ptr<Button>>;

}// namespace gcb::gui



#endif//ENGINE_BASE_BUTTON_HPP
