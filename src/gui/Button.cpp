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

#include "Button.hpp"


namespace gcb::gui
{
// Initializers --------------------------------------------------------------------------
void Button::init(float positionX, float positionY, float width, float height,
  const std::string &text, unsigned int characterSize)
{
    mShape.setSize(sf::Vector2f(width, height));
    mShape.setPosition(sf::Vector2f(positionX, positionY));
    mShape.setFillColor(mIdleColor);
    mShape.setOutlineThickness(1.0F);
    mShape.setOutlineColor(mOutlineIdleColor);

    mText.setFont(mFont);
    mText.setString(text);
    mText.setFillColor(sf::Color::White);
    mText.setCharacterSize(characterSize);
    mText.setPosition(
      mShape.getPosition().x + (mShape.getGlobalBounds().width / 2.0F)
      - mText.getGlobalBounds().width / 2.0F,
      mShape.getPosition().y + (mShape.getGlobalBounds().height / 2.0F)
      - mText.getGlobalBounds().height / 2.0F
    );
}
// Constructor ---------------------------------------------------------------------------
Button::Button(float positionX, float positionY, float width, float height,
    sf::Font &font, const std::string &text, unsigned characterSize,
    const sf::Color &textIdleColor,
    const sf::Color &textHoverColor,
    const sf::Color &textActiveColor,
    const sf::Color &idleColor,
    const sf::Color &hoverColor,
    const sf::Color &activeColor,
    const sf::Color &outlineIdleColor,
    const sf::Color &outlineHoverColor,
    const sf::Color &outlineActiveColor)
    : mBtnState(BTN_IDLE), mId(0), mFont(font),
      mTextIdleColor(textIdleColor), mTextHoverColor(textHoverColor),
      mTextActiveColor(textActiveColor), mIdleColor(idleColor), mHoverColor(hoverColor),
      mActiveColor(activeColor), mOutlineIdleColor(outlineIdleColor),
      mOutlineHoverColor(outlineHoverColor), mOutlineActiveColor(outlineActiveColor)
{
    init(positionX, positionY, width, height, text, characterSize);
}
// ---------------------------------------------------------------------------------------
Button::Button(float positionX, float positionY, float width, float height,
    sf::Font &font, const std::string &text, unsigned characterSize,
    const sf::Color &textIdleColor,
    const sf::Color &textHoverColor,
    const sf::Color &textActiveColor,
    const sf::Color &idleColor,
    const sf::Color &hoverColor,
    const sf::Color &activeColor,
    const sf::Color &outlineIdleColor,
    const sf::Color &outlineHoverColor,
    const sf::Color &outlineActiveColor,
    short unsigned id)
  : mBtnState(BTN_IDLE), mId(id), mFont(font),
    mTextIdleColor(textIdleColor), mTextHoverColor(textHoverColor),
    mTextActiveColor(textActiveColor), mIdleColor(idleColor), mHoverColor(hoverColor),
    mActiveColor(activeColor), mOutlineIdleColor(outlineIdleColor),
    mOutlineHoverColor(outlineHoverColor), mOutlineActiveColor(outlineActiveColor)
{
    init(positionX, positionY, width, height, text, characterSize);
}
// ---------------------------------------------------------------------------------------
Button::Button(float positionX, float positionY, float width, float height,
      sf::Font &font, const std::string &text, unsigned int characterSize,
      const sf::Color &textIdleColor, const sf::Color &textHoverColor,
      const sf::Color &textActiveColor, const sf::Color &idleColor,
      const sf::Color &hoverColor, const sf::Color &activeColor)
    : mBtnState(BTN_IDLE), mId(0), mFont(font),
      mTextIdleColor(textIdleColor), mTextHoverColor(textHoverColor),
      mTextActiveColor(textActiveColor), mIdleColor(idleColor), mHoverColor(hoverColor),
      mActiveColor(activeColor), mOutlineIdleColor(sf::Color::Transparent),
      mOutlineHoverColor(sf::Color::Transparent),
      mOutlineActiveColor(sf::Color::Transparent)
{
    init(positionX, positionY, width, height, text, characterSize);
}
// ---------------------------------------------------------------------------------------
Button::Button(float positionX, float positionY, float width, float height,
      sf::Font &font, const std::string &text, unsigned int characterSize,
      const sf::Color &textIdleColor, const sf::Color &textHoverColor,
      const sf::Color &textActiveColor, const sf::Color &idleColor,
      const sf::Color &hoverColor, const sf::Color &activeColor,
      unsigned short id)
    : mBtnState(BTN_IDLE), mId(id), mFont(font),
      mTextIdleColor(textIdleColor), mTextHoverColor(textHoverColor),
      mTextActiveColor(textActiveColor), mIdleColor(idleColor), mHoverColor(hoverColor),
      mActiveColor(activeColor), mOutlineIdleColor(sf::Color::Transparent),
      mOutlineHoverColor(sf::Color::Transparent),
      mOutlineActiveColor(sf::Color::Transparent)

{
    init(positionX, positionY, width, height, text, characterSize);
}
// Accessors -----------------------------------------------------------------------------
bool Button::isPressed() const { return mBtnState == BTN_ACTIVE; }
// ---------------------------------------------------------------------------------------
const std::string Button::getText() const { return mText.getString(); }
// ---------------------------------------------------------------------------------------
const unsigned short &Button::getId() const { return mId; }
// Modifiers -----------------------------------------------------------------------------
void Button::setText(const std::string &text) { mText.setString(text); }
// ---------------------------------------------------------------------------------------
void Button::setId(const unsigned short &id) { mId = id; }
// Methods -------------------------------------------------------------------------------
void Button::update(const sf::Vector2f &mousePosition, [[maybe_unused]] const float &dT)
{
    // Idle
    mBtnState = BTN_IDLE;
    mShape.setFillColor(mIdleColor);
    mShape.setOutlineColor(mOutlineIdleColor);

    // Hover
    if (mShape.getGlobalBounds().contains(mousePosition))
    {
        mBtnState = BTN_HOVER;

        // Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mBtnState = BTN_ACTIVE;
        }
    }

    switch (mBtnState)
    {
    case BTN_IDLE:
        mShape.setFillColor(mIdleColor);
        mText.setFillColor(mTextIdleColor);
        mShape.setOutlineColor(mOutlineIdleColor);
        break;
    case BTN_HOVER:
        mShape.setFillColor(mHoverColor);
        mText.setFillColor(mTextHoverColor);
        mShape.setOutlineColor(mOutlineHoverColor);
        break;
    case BTN_ACTIVE:
        mShape.setFillColor(mActiveColor);
        mText.setFillColor(mTextActiveColor);
        mShape.setOutlineColor(mOutlineActiveColor);
        break;
    default:
        mShape.setFillColor(sf::Color::Red);
        mText.setFillColor(sf::Color::Yellow);
        mShape.setOutlineColor(sf::Color::Green);
        mText.setString("ERROR!");
        break;
    }
}
// ---------------------------------------------------------------------------------------
void Button::render(sf::RenderTarget& target) const
{
    target.draw(mShape);
    target.draw(mText);
}
// ---------------------------------------------------------------------------------------


}// namespace gcb::gui


