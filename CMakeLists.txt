cmake_minimum_required(VERSION 2.8.4)
project(doom)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/lib/SFML/cmake/Modules/")

set(SOURCE_FILES
    # Main files
    src/main.cpp
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
