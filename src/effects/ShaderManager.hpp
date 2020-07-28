//
// Created by fason on 15/07/2020.
//

#ifndef ENGINE_BASE_SHADERMANAGER_HPP
#define ENGINE_BASE_SHADERMANAGER_HPP


#include "../pch.hpp"
#include "Effect.hpp"

namespace gcb
{
class ShaderManager
{
private:
    std::map<std::string, gcb::Effect> mShaders;
};

}// namespace gcb



#endif//ENGINE_BASE_SHADERMANAGER_HPP
