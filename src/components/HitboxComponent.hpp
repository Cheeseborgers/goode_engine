//
// Created by fason on 12/07/2020.
//

#ifndef ENGINE_BASE_HITBOXCOMPONENT_HPP
#define ENGINE_BASE_HITBOXCOMPONENT_HPP

#include "../pch.hpp"

namespace gcb
{
class HitboxComponent {
  private:
    sf::Sprite& mSpriteRef;
    sf::RectangleShape mShape;

    const float mOffsetX;
    const float mOffsetY;

    // Private Methods
  public:
    // Constructor
    HitboxComponent(
        sf::Sprite &sprite, float offsetX,
      float offsetY, float width, float height);
    HitboxComponent(
      sf::Sprite &sprite, float offsetX,
      float offsetY,  float width, float height, const sf::Color &color);

    // Getters
    bool checkIntersect(const sf::FloatRect&floatRect);

    //Setters
    void setOutlineColor(const sf::Color &color);
    void setOutlineThickness(float size);

    // Methods
    void update();
    void render(sf::RenderTarget &target);
};

}


#endif//ENGINE_BASE_HITBOXCOMPONENT_HPP
