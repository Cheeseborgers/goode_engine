//
//      Entity.h
//      Created by Goodecheeseburgers on 09/07/2020.
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

#ifndef ENGINE_BASE_ENTITY_HPP
#define ENGINE_BASE_ENTITY_HPP


#include "../pch.hpp"

#include "../components/MovementComponent.hpp"
#include "../components/HitboxComponent.hpp"
#include "../components/AnimationComponent.hpp"

namespace gcb
{
class Entity
{
protected:
    sf::Sprite mSprite;
    bool mShowHitbox;

  protected:
    // Components ===========================================================
    std::unique_ptr<HitboxComponent> mHitbox;
    std::unique_ptr<MovementComponent> mMovement;
    std::unique_ptr<AnimationComponent> mAnimation;

    void createHitboxComponent(sf::Sprite &sprite, float offsetX, float offsetY,
       float width, float height);
    void createMovementComponent(
        float velocityMax, float acceleration, float deceleration);
    void createAnimationComponent(sf::Texture &textureSheet);
    // ======================================================================

    // Modifiers
    void setTexture(sf::Texture& texture);

    // Initializers
    virtual void initVariables() = 0;
    virtual void initAnimations() = 0;

public:
    // Constructor
    Entity();
    virtual ~Entity() = default;

    // Accessors
    const std::unique_ptr<MovementComponent> &getMovementComponent() const;
    bool isShowHitbox() const;

    // Modifiers
    virtual void setPosition(float positionX, float positionY);
    void setShowHitbox(bool mShowHitbox);

    // Methods
    virtual void move(const float directionX, const float directionY, const float& dT);

    // Pure virtual Methods
    virtual void update(const float &dT) = 0;
    virtual void render(sf::RenderTarget &target) = 0;
};


}// namespace gcb


#endif//ENGINE_BASE_ENTITY_HPP
