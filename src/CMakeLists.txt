# Generic test that uses conan libs
add_executable(goode_engine main.cpp
        states/State.hpp states/StateMachine.cpp
        states/StateMachine.hpp managers/TextureManager.cpp
        managers/TextureManager.hpp input_handlers/InputHandler.cpp
        input_handlers/InputHandler.hpp Game.cpp Game.hpp Definitions.hpp
        states/SplashState.cpp states/SplashState.hpp states/MainMenuState.cpp
        states/MainMenuState.hpp states/game_state/GameState.cpp
        states/game_state/GameState.hpp states/GameOverState.cpp
        states/GameOverState.hpp utilities/Random.hpp
        gui/Gui.hpp gui/Button.cpp gui/Button.hpp managers/WindowManager.cpp
        managers/WindowManager.hpp world/TileMap.hpp tiles/Tile.cpp
        tiles/Tile.hpp world/TileMap.cpp entities/players/Player.cpp
        entities/players/Player.hpp entities/Entity.cpp
        entities/Entity.hpp commands/Command.hpp
        commands/Walk.hpp commands/Undo.hpp pch.hpp components/MovementComponent.cpp
        components/MovementComponent.hpp components/AnimationComponent.cpp
        components/AnimationComponent.hpp components/HitboxComponent.cpp
        components/HitboxComponent.hpp states/SettingsState.cpp
        states/SettingsState.hpp managers/SoundManager.cpp
        managers/SoundManager.hpp managers/MusicManager.cpp
        managers/MusicManager.hpp managers/FontManager.cpp
        managers/FontManager.hpp gui/PauseMenu.cpp
        gui/PauseMenu.hpp states/State.cpp effects/Effect.hpp effects/Shader.hpp
        effects/ShaderManager.cpp effects/ShaderManager.hpp
        effects/ParticleSystem.cpp effects/ParticleSystem.hpp states/EditorState.cpp
        states/EditorState.hpp entities/enemies/Enemy.cpp entities/enemies/Enemy.hpp
        entities/enemies/Rat.cpp entities/enemies/Rat.hpp gui/Slider.cpp
        gui/Slider.hpp gui/DropDownList.cpp gui/DropDownList.hpp gui/Gui.cpp
        debug/MousePosition.hpp utilities/Random.cpp
        gui/Widget.cpp gui/Widget.hpp gui/Container.cpp gui/Container.hpp debug/FPS.hpp
        world/WorldTime.hpp inventory/Inventory.cpp inventory/Inventory.hpp
        inventory/Item.cpp inventory/Item.hpp inventory/Weapon.cpp inventory/Weapon.hpp
        inventory/Potion.cpp inventory/Potion.hpp inventory/Tool.cpp inventory/Tool.hpp
        inventory/Item.cpp inventory/Item.hpp gui/Utilities.cpp gui/Utilities.hpp)

# SFML
add_subdirectory(include/SFML)

# GLM
add_subdirectory(include/glm)

#[[LUAJit
include(ExternalProject)
ExternalProject_Add(project_luajit
        URL http://luajit.org/download/LuaJIT-2.0.5.tar.gz
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/luajit-2.0.5
        CONFIGURE_COMMAND ""
        BUILD_COMMAND make
        INSTALL_COMMAND make install
        PREFIX=${CMAKE_CURRENT_BINARY_DIR}/luajit-2.0.5
        )
ExternalProject_Get_Property(project_luajit install_dir)
add_library(luajit STATIC IMPORTED)
set_property(TARGET luajit PROPERTY IMPORTED_LOCATION ${install_dir}/lib/libluajit-2.0.5)
add_dependencies(luajit project_luajit)
include_directories(${install_dir}/include/luajit-2.0.5)
]]

# plf
add_library(plf_stack INTERFACE)
target_include_directories(plf_stack
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

add_library(plf_colony INTERFACE)
target_include_directories(plf_colony
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        )

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("debug mode, add plf-nanotimer")
    add_library(plf_nanotimer INTERFACE)
    target_include_directories(
            plf_nanotimer
            INTERFACE
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_precompile_headers(goode_engine PUBLIC pch.hpp)

target_link_libraries(goode_engine
        PRIVATE
        project_options
        project_warnings
        CONAN_PKG::fmt
        CONAN_PKG::spdlog
        PUBLIC
        sfml-graphics
        sfml-window
        sfml-system
        sfml-network
        sfml-audio
        plf_stack
        plf_colony
        plf_nanotimer
        glm) #luajit)
