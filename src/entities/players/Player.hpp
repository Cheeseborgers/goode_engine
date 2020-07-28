//
//      Player.h
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

#ifndef ENGINE_BASE_PLAYER_HPP
#define ENGINE_BASE_PLAYER_HPP

#include "../Entity.hpp"
#include "../../inventory/Inventory.hpp"


namespace gcb
{
class  Entity;

class Player : public Entity
{
private:
    // Member Variables
    bool mAttacking;
    std::unique_ptr<Inventory> mInventory;

    // Initializers
    void initVariables() override;
    void initAnimations() override;
    void initInventory();

public:
    // Constructor
    Player(float positionX, float positionY, sf::Texture& textureSheet);

    // Getters
    const std::unique_ptr<Inventory> &getInventory() const;

    // Methods
    void updateAttack();
    void updateAnimations(const float &deltaTime);

    virtual void update(const float &deltaTime) override;
    virtual void render(sf::RenderTarget &target) override ;
};


}// namespace gcb



#endif//ENGINE_BASE_PLAYER_HPP
