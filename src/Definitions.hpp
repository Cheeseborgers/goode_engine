//////////////////////////////////////////////////////////////////////////////////////////
//      file: definitions.hpp
//
//      GoodeEngine. An C++ / SFML engine/base.
//      Created by Goodecheeseburgers on 13/06/2020.
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

#ifndef ENGINE_BASE_DEFINITIONS_HPP
#define ENGINE_BASE_DEFINITIONS_HPP


namespace gcb {
struct Definitions
{
    // Default Window settings ===========================================================

    /*********************************************************************************
    * Note: these are mostly only used for the default constructor if no game window
    * settings file is provided.
    ****************************************************************************/

    static inline const std::string GAME_TITLE{ "Goode Engine Demo" };
    static inline const unsigned WINDOW_WIDTH{ 1920 };
    static inline const unsigned WINDOW_HEIGHT{ 1080 };
    static inline const unsigned DEFAULT_FRAMERATE_LIMIT{ 60 };
    static inline const unsigned MODE_BITS_PER_PIXEL{ 32 };
    static inline const bool DEFAULT_VERT_SYNC{ false };
    static inline const bool DEFAULT_FULLSCREEN{ false };

    static inline const std::string GRAPHICS_SETTINGS_FILEPATH 
      = "../assets/config/graphics_settings.ini";
    // Splash state ======================================================================
    static inline const float SPLASHSTATE_SHOW_TIME{ 3.0F };
    static inline const std::string SPLASH_STATE_BACKGROUND_FILEPATH 
      = "../assets/res/sprites/backgrounds/splash_background.png";
    static inline const std::string SPLASH_STATE_BACKGROUND_NAME
      = "splash_state_background";
    static inline const std::string SPLASH_STATE_SOUND_FILEPATH 
      = "../assets/audio/sounds/cyber_duck.wav";
    static inline const std::string SPLASH_STATE_SOUND_NAME = "splash_sound";

    // Main menu =========================================================================
    static inline const std::string GAME_TITLE_FILEPATH 
      = "../assets/res/title.png";
    static inline const std::string MAIN_MENU_BACKGROUND_FILEPATH 
      = "../assets/res/sprites/backgrounds/main_menu_background.png";
    static inline const std::string FOOTER_TEXT = "Made by Goode Cheeseburgers 2020.";

    // Game State ========================================================================
    static inline const std::string PLAYER_TEXTURE_SHEET_FILEPATH 
      = "../assets/res/sprites/player/player_sheet.png";
    static inline const std::string PLAYER_TEXTURE_SHEET_NAME 
      = "player_tex_sheet";

    // Settings State ====================================================================
    static inline const std::string SETTINGS_STATE_BACKGROUND_FILEPATH 
      = "../assets/res/sprites/backgrounds/settings_state_background.png";
    static inline const std::string SETTINGS_STATE_BACKGROUND_NAME 
      = "settings_state_background";

    // Editor state ======================================================================
    static inline const std::string EDITOR_STATE_BACKGROUND_FILEPATH 
      = "../assets/res/sprites/backgrounds/editor_state_background.png";
    static inline const std::string EDITOR_STATE_BACKGROUND_NAME 
      = "editor_state_background";

    // Game over =========================================================================
    static inline const std::string GAMEOVER_BACKGROUND_FILEPATH 
      = "../assets/res/sprites/backgrounds/editor_state_background.png";
    static inline const std::string GAMEOVER_BACKGROUND_NAME 
      = "gameover_background";

    // Fonts =============================================================================
    static inline const std::string PRIMARY_FONT_FILEPATH 
      = "../assets/fonts/dosis_light.ttf";
    static inline const std::string PRIMARY_FONT_NAME 
      = "dosis_light";

    // Enemy stuff =======================================================================
    static inline const std::string RAT_TEXTURE_SHEET_FILEPATH 
      = "../assets/res/sprites/enemies/rat.png";
    static inline const std::string RAT_TEXTURE_SHEET_NAME 
      = "rat_tex_sheet";

    // Keybinds and supported keys =======================================================
    static inline const std::string SUPPORTED_KEY_FILEPATH 
      = "../assets/config/supported_keys.ini";
    static inline const std::string GAMESTATE_KEYBINDS_FILEPATH 
      = "../assets/config/supported_keys.ini";
    static inline const std::string EDITORSTATE_KEYBINDS_FILEPATH 
      = "../assets/config/supported_keys.ini";
    static inline const std::string GENERAL_KEYBINDS_FILEPATH 
      = "../assets/config/supported_keys.ini";

    // Other =============================================================================
    static inline constexpr double PI = { 3.141592653589793238462643383279502884 };
};

} // namespace gcb



#endif//ENGINE_BASE_DEFINITIONS_HPP
