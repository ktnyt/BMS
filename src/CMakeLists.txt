project (RevolutionBMS)

include_directories(${PROJECT_SOURCE_DIR}/../include)

include(FindPkgConfig)
set(SDL2_STATIC "YES")
pkg_search_module(SDL2 required sdl2)
include_directories(
    ${SDL2_INCLUDE_DIRS}
)

add_library(
    SDLlib
    ./SDL/Application.cpp
    ./SDL/Window.cpp
)

target_link_libraries(SDLlib ${SDL2_LIBRARY})
target_link_libraries(SDLlib SDL2)
target_link_libraries(SDLlib SDL2_image)
target_link_libraries(SDLlib SDL2_mixer)

add_library(
    BMSlib
    ./BMS/Filename.cpp
    ./BMS/FPSManager.cpp
    ./BMS/Play.cpp
    ./BMS/Scene.cpp
)

target_link_libraries(BMSlib SDLlib)

add_library(ReBMS ./ReBMS.cpp)
target_link_libraries(ReBMS BMSlib)

add_executable(RevolutionBMS ./main.cpp)
target_link_libraries(RevolutionBMS ReBMS)
