//
// Created by fason on 16/07/2020.
//

#ifndef ENGINE_BASE_DROPDOWNLIST_HPP
#define ENGINE_BASE_DROPDOWNLIST_HPP


#include "Button.hpp"

namespace gcb::gui
{
class DropDownList : Widget{

public:
    // Constructor / Destructor
    DropDownList(float posX, float posY,float width, float height,
         sf::Font &font, unsigned charSize, std::string elements[], unsigned nrOfElements,
         const sf::Color &textIdleColor, const sf::Color &textHoverColor,
         const sf::Color &textActiveColor, const sf::Color &idleColor,
         const sf::Color &hoverColor, const sf::Color &activeColor,
         const sf::Color &outlineIdleColor, const sf::Color &outlineHoverColor,
         const sf::Color &outlineActiveColor);

    DropDownList(float posX, float posY,float width, float height,
         sf::Font &font, unsigned charSize, std::string elements[], unsigned nrOfElements,
         const sf::Color &textIdleColor, const sf::Color &textHoverColor,
         const sf::Color &textActiveColor, const sf::Color &idleColor,
         const sf::Color &hoverColor, const sf::Color &activeColor,
         const sf::Color &outlineIdleColor, const sf::Color &outlineHoverColor,
         const sf::Color &outlineActiveColor, unsigned defaultIndex);

    DropDownList(float posX, float posY,float width, float height,
         sf::Font &font, unsigned charSize, std::string elements[], unsigned nrOfElements,
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
         const sf::Color &outlineActiveColor, unsigned defaultIndex);

    // Getters
    bool getKeyTime();
    const unsigned short &getActiveElementId() const;

    // Methods
    void update(const sf::Vector2f &mousePos, const float &dT) override;
    void render(sf::RenderTarget &target) const override;

private:
    sf::Font& mFont;
    std::shared_ptr<gui::Button> mActiveElement;
    std::vector<std::shared_ptr<gui::Button>> mElements;

    bool mShowList;
    float mKeyTimeMax;
    float mKeyTime;

    // Methods
    void updateKeyTime(const float &dT);
};

using dropDownLists = std::unordered_map<std::string, std::unique_ptr<gui::DropDownList>>;

}// namespace gcb::gui


#endif//ENGINE_BASE_DROPDOWNLIST_HPP
