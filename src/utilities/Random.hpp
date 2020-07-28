//////////////////////////////////////////////////////////////////////////////////////////
//      file: Random.hpp
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

#ifndef ENGINE_BASE_RANDOM_HPP
#define ENGINE_BASE_RANDOM_HPP

#include <random>
#include <iomanip>


namespace gcb
{
using UniRealDist = std::uniform_real_distribution<>;
using UniIntDist = std::uniform_int_distribution<std::mt19937::result_type>;

class Random
{
private:
    Random();

    static std::mt19937 mEngine;
    static UniRealDist mFloatDistribution;
    static UniIntDist mIntDistribution;

    double iFloat() {return mRandomFloatGenerator(); };
    unsigned long iInt() {return mRandomIntGenerator(); };
    std::mt19937 iGenerator();
    UniIntDist iIntDistribution();
    UniRealDist iFloatDistribution();

    double mRandomFloatGenerator();
    unsigned long mRandomIntGenerator();

  public:

    Random(Random const&)          = delete;
    void operator=(Random const&)  = delete;
    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status

    static Random& get()
    {
        static Random instance;
        return instance;
    }

    static double randFloat();
    static unsigned long randInt();
    static std::mt19937 randEngine();
    static UniIntDist randIntDistribution();
    static UniRealDist randFloatDistribution();

};

}// namespace gcb


#endif//ENGINE_BASE_RANDOM_HPP
