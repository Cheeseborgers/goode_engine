//
// Created by fason on 12/07/2020.
//

#include "HitboxComponent.hpp"


namespace gcb
{
// Constructor ---------------------------------------------------------------------------
HitboxComponent::HitboxComponent(
    sf::Sprite &sprite, float offsetX,
    float offsetY, float width, float height
) : mSpriteRef(sprite), mOffsetX(offsetX), mOffsetY(offsetY)
{
    mShape.setPosition(
      mSpriteRef.getPosition().x + mOffsetX,
      mSpriteRef.getPosition().y + mOffsetY);
    mShape.setSize(sf::Vector2f(width, height));
    mShape.setFillColor(sf::Color::Transparent);
    mShape.setOutlineThickness(1.0F);
    mShape.setOutlineColor(sf::Color::Green);
}
// ---------------------------------------------------------------------------------------
HitboxComponent::HitboxComponent(
    sf::Sprite &sprite, float offsetX,
    float offsetY,  float width, float height, const sf::Color &color
) : mSpriteRef(sprite), mOffsetX(offsetX), mOffsetY(offsetY)
{
    mShape.setPosition(
      mSpriteRef.getPosition().x + mOffsetX,
      mSpriteRef.getPosition().y + mOffsetY);
    mShape.setSize(sf::Vector2f(width, height));
    mShape.setFillColor(sf::Color::Transparent);
    mShape.setOutlineThickness(1.0F);
    mShape.setOutlineColor(color);
}
// Getters -------------------------------------------------------------------------------
bool HitboxComponent::checkIntersect(const sf::FloatRect &floatRect)
{
    return mShape.getGlobalBounds().intersects(floatRect);
}
// Setters -------------------------------------------------------------------------------
void HitboxComponent::setOutlineColor(const sf::Color &color)
{
    mShape.setOutlineColor(color);
}
// ---------------------------------------------------------------------------------------
void HitboxComponent::setOutlineThickness(float size)
{
    mShape.setOutlineThickness(size);
}
// Methods -------------------------------------------------------------------------------
void HitboxComponent::update()
{
    mShape.setPosition(
      mSpriteRef.getPosition().x + mOffsetX,
      mSpriteRef.getPosition().y + mOffsetY);
}
// ---------------------------------------------------------------------------------------
void HitboxComponent::render([[maybe_unused]] sf::RenderTarget &target)
{
    target.draw(mShape);
}
// ---------------------------------------------------------------------------------------


}// namespace gcb