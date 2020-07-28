//
//      WalkUp.h
//      Created by Goodecheeseburgers on 11/07/2020.
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

#ifndef ENGINE_BASE_WALK_HPP
#define ENGINE_BASE_WALK_HPP

#include "Command.hpp"

namespace gcb
{

// ---------------------------------------------------------------------------------------
class WalkLeft : public Command
{
  public:
    ~WalkLeft() override = default;

    void execute(Entity &entity, const float& dT) override
    {
        entity.getMovementComponent()->move(-1.0F, 0.0F, dT);
        std::cout << "L\n";
    }
};
// ---------------------------------------------------------------------------------------
class WalkRight : public Command
{
  public:
    ~WalkRight() override = default;

    void execute(Entity &entity, const float& dT) override
    {

        entity.getMovementComponent()->move(1.0F, 0.0F, dT);
        std::cout << "R\n";
    }

};
// ---------------------------------------------------------------------------------------
class WalkDown : public Command
{
  public:
    ~WalkDown() override = default;

    void execute(Entity &entity, const float& dT) override
    {
        entity.getMovementComponent()->move(0.0F, 1.0F, dT);
        std::cout << "D\n";
    }
};
// ---------------------------------------------------------------------------------------
class WalkUp : public Command
{
  public:
    ~WalkUp() override = default;

    void execute(Entity &entity, const float& dT) override
    {
        entity.getMovementComponent()->move(0.0F, -1.0F, dT);
        std::cout << "U\n";
    }
};
// ---------------------------------------------------------------------------------------

}// namespace gcb

#endif//ENGINE_BASE_WALK_HPP
