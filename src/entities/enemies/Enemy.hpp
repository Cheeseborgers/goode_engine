//
// Created by fason on 15/07/2020.
//

#ifndef ENGINE_BASE_ENEMY_HPP
#define ENGINE_BASE_ENEMY_HPP

#include "../Entity.hpp"

namespace gcb
{
class Entity;

class Enemy : public Entity
{

protected:
    sf::Clock damageTimer;
    sf::Int32 damageTimerMax;

public:
    // Constructor
    Enemy();
    virtual ~Enemy();

    //Modifiers
    void resetDamageTimer();

    // Methods
    void update(const float &dT) = 0;
    void render(sf::RenderTarget &target) = 0;
};

}// namespace gcb



#endif//ENGINE_BASE_ENEMY_HPP
