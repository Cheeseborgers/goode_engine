//
//      Command.h
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

#ifndef ENGINE_BASE_COMMAND_HPP
#define ENGINE_BASE_COMMAND_HPP

#include "../pch.hpp"

#include "../entities/Entity.hpp"


namespace gcb
{
class Command
{
  public:
    virtual ~Command() = default;

    // Pure virtual methods
    virtual void execute(Entity &entity, const float& dT) = 0;

  protected:
     plf::stack<std::unique_ptr<Command>> mCommandStack;

};

}// namespace gcb

#endif//ENGINE_BASE_COMMAND_HPP
