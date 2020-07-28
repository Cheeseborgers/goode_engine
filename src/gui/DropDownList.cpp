//
// Created by fason on 16/07/2020.
//

#include "DropDownList.hpp"

namespace gcb::gui
{
// Constructor ---------------------------------------------------------------------------
DropDownList::DropDownList(float posX, float posY,float width, float height,
    sf::Font &font, unsigned charSize, std::string elements[], unsigned nrOfElements,
    const sf::Color &textIdleColor, const sf::Color &textHoverColor,
    const sf::Color &textActiveColor, const sf::Color &idleColor,
    const sf::Color &hoverColor, const sf::Color &activeColor,
    const sf::Color &outlineIdleColor, const sf::Color &outlineHoverColor,
    const sf::Color &outlineActiveColor)
    : mFont(font), mShowList(false), mKeyTimeMax(10.0F), mKeyTime(0.0F)
{
    std::cout << "meh 99\n";
    mActiveElement = std::make_shared<gui::Button>(
      posX, posY, width, height, mFont, elements[0], charSize,
      textIdleColor, textHoverColor, textActiveColor,
      idleColor, hoverColor, activeColor,
      outlineIdleColor, outlineHoverColor, outlineActiveColor,
      0);

    for (unsigned id = 0; id < nrOfElements; ++id)
    {
        mElements.push_back(std::make_shared<gui::Button>(
            posX, (posY + (static_cast<float>(id) * height)), width, height,
            mFont, elements[id], charSize,
            textIdleColor, textHoverColor, textActiveColor,
            idleColor, hoverColor, activeColor,
            sf::Color(outlineIdleColor.r, outlineIdleColor.g,
                outlineIdleColor.b,outlineIdleColor.a - outlineIdleColor.a),
            sf::Color(outlineHoverColor.r, outlineHoverColor.g,
                outlineHoverColor.b, outlineHoverColor.a - outlineHoverColor.a),
            sf::Color(outlineActiveColor.r, outlineActiveColor.g,
                outlineActiveColor.b, outlineActiveColor.a - outlineActiveColor.a),
            id));
    }
}
// ---------------------------------------------------------------------------------------
DropDownList::DropDownList(float posX, float posY,float width, float height,
    sf::Font &font, unsigned charSize, std::string elements[], unsigned nrOfElements,
    const sf::Color &textIdleColor, const sf::Color &textHoverColor,
    const sf::Color &textActiveColor, const sf::Color &idleColor,
    const sf::Color &hoverColor, const sf::Color &activeColor,
    const sf::Color &outlineIdleColor, const sf::Color &outlineHoverColor,
    const sf::Color &outlineActiveColor, unsigned defaultIndex)
    : mFont(font), mShowList(false), mKeyTimeMax(10.0F), mKeyTime(0.0F)
{
    std::cout << "meh 999\n"; //TODO whats all this about ??????????? ==========================================================================
    mActiveElement = std::make_shared<gui::Button>(
      posX, posY, width, height, mFont, elements[defaultIndex], charSize,
      textIdleColor, textHoverColor, textActiveColor,
      idleColor, hoverColor, activeColor,
      outlineIdleColor, outlineHoverColor, outlineActiveColor,
      0);

    for (unsigned id = 0; id < nrOfElements; ++id)
    {
        mElements.push_back(std::make_shared<gui::Button>(
          posX, (posY + (static_cast<float>(id) * height)), width, height,
          mFont, elements[id], charSize,
          textIdleColor, textHoverColor, textActiveColor,
          idleColor, hoverColor, activeColor,
          sf::Color(outlineIdleColor.r, outlineIdleColor.g,
                outlineIdleColor.b,outlineIdleColor.a - outlineIdleColor.a),
          sf::Color(outlineHoverColor.r, outlineHoverColor.g,
                outlineHoverColor.b, outlineHoverColor.a - outlineHoverColor.a),
          sf::Color(outlineActiveColor.r, outlineActiveColor.g,
                outlineActiveColor.b, outlineActiveColor.a - outlineActiveColor.a),
          id));
    }
}
// ---------------------------------------------------------------------------------------
DropDownList::DropDownList(float posX, float posY, float width, float height,
  sf::Font &font, unsigned int charSize, std::string *elements, unsigned int nrOfElements,
  const sf::Color &activeElementTextIdleColor,
  const sf::Color &activeElementTextHoverColor,
  const sf::Color &activeElementTextActiveColor,
  const sf::Color &activeElementIdleColor,
  const sf::Color &activeElementHoverColor,
  const sf::Color &activeElementActiveColor,
  const sf::Color &activeElementOutlineIdleColor,
  const sf::Color &activeElementOutlineHoverColor,
  const sf::Color &activeElementOutlineActiveColor,
  const sf::Color &textIdleColor, const sf::Color &textHoverColor,
  const sf::Color &textActiveColor, const sf::Color &idleColor,
  const sf::Color &hoverColor, const sf::Color &activeColor,
  const sf::Color &outlineIdleColor, const sf::Color &outlineHoverColor,
  const sf::Color &outlineActiveColor, unsigned int defaultIndex)
  : mFont(font), mShowList(false), mKeyTimeMax(10.0F), mKeyTime(0.0F)
{

    std::cout << "meh 9999\n";
    mActiveElement = std::make_shared<gui::Button>(
        posX, posY, width, height, mFont, elements[defaultIndex], charSize,
        activeElementTextIdleColor, activeElementTextHoverColor,
        activeElementTextActiveColor,
        activeElementIdleColor, activeElementHoverColor, activeElementActiveColor,
        activeElementOutlineIdleColor, activeElementOutlineHoverColor,
        activeElementOutlineActiveColor,0);

    for (unsigned id = 0; id < nrOfElements; ++id)
    {
        mElements.push_back(std::make_shared<gui::Button>(
          posX, (posY + (static_cast<float>(id) * height)), width, height,
          mFont, elements[id], charSize,
          textIdleColor, textHoverColor, textActiveColor,
          idleColor, hoverColor, activeColor,
          outlineIdleColor, outlineHoverColor, outlineActiveColor,
          id));
    }
}
// Getters -------------------------------------------------------------------------------
bool DropDownList::getKeyTime()
{
    if (mKeyTime >= mKeyTimeMax)
    {
        mKeyTime = 0.0F;
        return true;
    }

    return false;
}
// ---------------------------------------------------------------------------------------
const unsigned short &DropDownList::getActiveElementId() const
{
    return mActiveElement->getId();
}
// Methods -------------------------------------------------------------------------------
void DropDownList::updateKeyTime(const float &dT)
{
    if (mKeyTime < mKeyTimeMax)
    {
        mKeyTime += 25.0F * dT;
    }
}
// ---------------------------------------------------------------------------------------
void DropDownList::update(const sf::Vector2f &mousePos, const float &dT)
{
    updateKeyTime(dT);

    mActiveElement->update(mousePos, dT);

    // Only display the list IF active element is clicked and outside of KeyTime bounds
    if (mActiveElement->isPressed() && getKeyTime())
    {
        // Flip the show list member variable
        mShowList = !mShowList;
    }

    // Update each button element in the list
    if (mShowList)
    {
        for (const auto &it : mElements)
        {
            it->update(mousePos, dT);

            if (it->isPressed() && getKeyTime())
            {
                mShowList = false;
                mActiveElement->setText(it->getText());
                mActiveElement->setId(it->getId());
            }
        }
    }
}
// ---------------------------------------------------------------------------------------
void DropDownList::render(sf::RenderTarget &target) const
{
    mActiveElement->render(target);

    if (mShowList)
    {
        for (const auto &it : mElements)
        {
            it->render(target);
        }
    }
}
// ---------------------------------------------------------------------------------------

}// namespace gcb::gui
