//////////////////////////////////////////////////////////////////////////////////////////
//      file: WorldTime.hpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 21/07/2020.
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

#ifndef ENGINE_BASE_WORLDTIME_HPP
#define ENGINE_BASE_WORLDTIME_HPP

namespace gcb
{
struct WorldTime
{
    /*****************************************************************
    * @brief Handles World time
    *
    * @details mWorldTime is represented as a double ranging from,
    * 0.0 -> 1440.0, updating approximately every second or every
    * update/render cycle of the gameState.
    *
    * For every update to mWorldTime, dT is applied with the effect
    * of 0.01. This is reflected in game world time as:
    *
    * 1 update/sec = 1 Game minute, OR ~60 real seconds = 1 Game Hour.
    ****************************************************************/

    enum periodsOfDay : unsigned char {
        MIDNIGHT = 0,
        MORNING,
        MIDDAY,
        AFTERNOON,
        EVENING};

    void update(const float& dT)
    {
        /*****************************************************************
         * @brief Updates the World time to reflect day/night.
         *
         * @param dT: delta time/ interpolation since
         * last update and render cycle
         *
         * @return void
         ****************************************************************/

        mTotalPlayTime += mWorldTime;
        mWorldTime += static_cast<double>(dT);

        if (mWorldTime > midnight)
        {
            mWorldTime = 0.0;
        }

        if ((mWorldTime > midnightMin && mWorldTime < midnight)
            || (mWorldTime >= 0.0 && mWorldTime < midnightMax))
        {
            mPeriodOfDay = periodsOfDay::MIDNIGHT;
        }
        else if (mWorldTime > morningMin && mWorldTime <= morningMax)
        {
            mPeriodOfDay = periodsOfDay::MORNING;
        }
        else if (mWorldTime > middayMin && mWorldTime <= middayMax)
        {
            mPeriodOfDay = periodsOfDay::MIDDAY;
        }
        else if (mWorldTime > afternoonMin && mWorldTime <= afternoonMax)
        {
            mPeriodOfDay = periodsOfDay::AFTERNOON;
        }
        else if (mWorldTime > eveningMin && mWorldTime <= eveningMax)
        {
            mPeriodOfDay = periodsOfDay::EVENING;
        }
        else
        {
            // TODO: LOG THIS WITH TIME!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            std::cout << "Error in setting world time of day.\n";
        }
    }
    // -----------------------------------------------------------------------------------
    inline void setTimeOfDay(double worldTime, double totalPlayTime)
    {
        /*****************************************************************
        * @brief Sets the Time of day and total play time to a
        * desired point. (For game save continuation).
        *
        * @param double worldTime: time of day between 0.0-1440.0
        * @param double totalPlayTime: Total time the player has been
        * in the world.
        * last update and render cycle
        *
        * @return void
        ****************************************************************/

        mWorldTime = worldTime;
        mTotalPlayTime = totalPlayTime;
    }
    // -----------------------------------------------------------------------------------
    [[nodiscard]] inline short getPeriodOfDay() const
    {
        /*****************************************************************
        * @brief Returns the period of day determined from the
        * periodsOfDay Struct
        *
        * @param None
        *
        * @return unsigned int
        ****************************************************************/

        return mPeriodOfDay;
    }
    // -----------------------------------------------------------------------------------
    [[nodiscard]] int countDigit(int n) const
    {
        /***********************************************************************
        * @brief Use log10(logarithm of base 10) to count the number of
        * digits of positive numbers (logarithm is not defined for negative
        * numbers).
        *
        * Digit count of N = upper bound of log10(N).
        *
        * @param n: Value of who's digits to count.
        *
        * @return int: number of digits counted.
        ***********************************************************************/

        return static_cast<int>(std::floor(std::log10(n) + 1));
    }
    // -----------------------------------------------------------------------------------
    [[nodiscard]] std::string getTimeAsMinsHoursSecs() const
    {
        /***********************************************************************
        * @brief Returns the current world time in a 24hr clock format.
        *
        * @param None
        *
        * @return std::string
        ***********************************************************************/
        int mins{};
        int hour = static_cast<int>(mWorldTime / timeConstantI);
        mins = static_cast<int>(std::fmod(mWorldTime, timeConstantF));
        std::string timeStr{""};

        if (countDigit(hour) <= 1)
        {
            timeStr.append("0");
        }

        timeStr.append(std::to_string(hour) + ":");

        if (countDigit(mins) <= 1)
        {
            timeStr.append("0");
        }

        return timeStr.append(std::to_string(mins));
    }
    // -----------------------------------------------------------------------------------
private:
    double mWorldTime;
    double mTotalPlayTime;
    short mPeriodOfDay;

    /*********************************************************************
     * @brief Time periods between 0.0 and 1440.0, representing respective
     * times throughout an in game day/night cycle.
     *
     * 0.0 is true midnight, with ~60 seconds or game ticks/updates
     * per in game hour
     *
     * @note: the bottom time constants are simply to eliminate clang tidy
     * complaining magic numbers.
     * ********************************************************************/

    constexpr static const double midnightMin{1340.0};
    constexpr static const double midnight{1440.0};
    constexpr static const double midnightMax{39.99999999999};
    constexpr static const double morningMin{40.0};
    constexpr static const double morningMax{619.99999999999};
    constexpr static const double middayMin{620.0};
    constexpr static const double middayMax{819.99999999999};
    constexpr static const double afternoonMin{820.0};
    constexpr static const double afternoonMax{1079.99999999999};
    constexpr static const double eveningMin{1080.0};
    constexpr static const double eveningMax{1339.99999999999};
    constexpr static const double timeConstantF{60.0};
    constexpr static const int    timeConstantI{60};
};

} // gcb ns end

#endif//ENGINE_BASE_WORLDTIME_HPP
