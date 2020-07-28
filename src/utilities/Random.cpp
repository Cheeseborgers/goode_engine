//////////////////////////////////////////////////////////////////////////////////////////
//      file: Random.cpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 18/06/2020.
//      Copyright (C) 2020 - goodecheeseburgers@gmail.com
//
//      https://github.com/Cheeseborgers/GoodeEngine
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
//////////////////////////////////////////////////////////////////////////////////////////

#include "Random.hpp"

namespace gcb
{
// ---------------------------------------------------------------------------------------
std::mt19937  Random::mEngine;
// ---------------------------------------------------------------------------------------
UniIntDist Random::mIntDistribution;
// ---------------------------------------------------------------------------------------
UniRealDist Random::mFloatDistribution(0.0, 1.0);
// Private Constructor -------------------------------------------------------------------
Random::Random()
{
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    mEngine.seed(seed);
}
// ---------------------------------------------------------------------------------------
double Random::mRandomFloatGenerator()
{
    return mFloatDistribution(mEngine);
}
// ---------------------------------------------------------------------------------------
unsigned long Random::mRandomIntGenerator()
{
    return mIntDistribution(mEngine);
}
// ---------------------------------------------------------------------------------------
std::mt19937 Random::iGenerator()
{
      return mEngine;
}
// ---------------------------------------------------------------------------------------
UniIntDist Random::iIntDistribution()
{
    return mIntDistribution;
}
// ---------------------------------------------------------------------------------------
UniRealDist Random::iFloatDistribution()
{
    return mFloatDistribution;
}
// ---------------------------------------------------------------------------------------
double Random::randFloat()
{
    return get().iFloat();
}
// ---------------------------------------------------------------------------------------
unsigned long Random::randInt()
{
    return get().iInt();
}
// ---------------------------------------------------------------------------------------
std::mt19937 Random::randEngine()
{
    return get().iGenerator();
}
// ---------------------------------------------------------------------------------------
UniIntDist Random::randIntDistribution()
{
    return get().iIntDistribution();
}
// ---------------------------------------------------------------------------------------
UniRealDist Random::randFloatDistribution()
{
    return get().iFloatDistribution();
}
// ---------------------------------------------------------------------------------------
}// namespace gcb
