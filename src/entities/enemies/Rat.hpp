//
// Created by fason on 15/07/2020.
//

#ifndef ENGINE_BASE_RAT_HPP
#define ENGINE_BASE_RAT_HPP

#include "Enemy.hpp"

namespace gcb
{
class Rat : public Enemy
{
  private:
    // Initializers
    void initVariables();
    void initAnimations();

  public:
    // Constructor / Destructor
    Rat(float posX, float posY, sf::Texture& textureSheet);
    virtual ~Rat();

    // Methods
    void updateAnimation(const float& dt);

    void update(const float& dT);

    void render(sf::RenderTarget& target);
};



}// namespace gcb


#endif//ENGINE_BASE_RAT_HPP
