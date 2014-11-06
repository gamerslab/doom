cmake_minimum_required(VERSION 2.8.4)
project(doom)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/lib/SFML/cmake/Modules/")

set(SOURCE_FILES
    # Main files
    src/main.cpp
    src/game.cpp
    src/game.hpp
    src/debug.cpp
    src/debug.hpp
    src/level.cpp
    src/level.hpp
    src/entity.cpp
    src/entity.hpp

    # Components
    src/component.cpp
    src/component.hpp
    src/component/position_component.cpp
    src/component/position_component.hpp
    src/component/velocity_component.cpp
    src/component/velocity_component.hpp
    src/component/sprite_component.cpp
    src/component/sprite_component.hpp

    # Systems
    src/system.cpp
    src/system.hpp
    src/system/logic_system.cpp
    src/system/logic_system.hpp
    src/system/render_system.cpp
    src/system/render_system.hpp

    ## Logic
    src/system/logic/movement_system.cpp
    src/system/logic/movement_system.hpp

    # Audio
    src/audio/music.cpp
    src/audio/music.hpp
    src/audio/sound.cpp
    src/audio/sound.hpp

    # Game screens
    src/game_screen.cpp
    src/game_screen.hpp
    src/screen/level_screen.cpp
    src/screen/level_screen.hpp
)

add_executable(doom ${SOURCE_FILES})

# OpenGL required
find_package(OpenGL REQUIRED)

# SFML required
set(BUILD_SHARED_LIBS FALSE)
set(SFML_STATIC_LIBRARIES TRUE)
add_subdirectory(lib/SFML)

include_directories(
    ${OPENGL_INCLUDE_DIRS}
    lib/SFML/include
)

set(NVIDIA_LIBRARY)

# TODO: Improve NVIDIA detection
# If you have an NVIDIA card you would probably need to change this
# to the driver you are currently using. Sorry :/
if(EXISTS /usr/lib/nvidia-331-updates)
set(NVIDIA_LIBRARY -L/usr/lib/nvidia-331-updates/)
endif()

target_link_libraries(doom
    ${OPENGL_LIBRARIES}
    ${NVIDIA_LIBRARY}
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
)
