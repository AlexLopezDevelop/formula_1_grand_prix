cmake_minimum_required(VERSION 3.15)
project(f1 C)

set(CMAKE_C_STANDARD 11)

set(ALLEGRO_DIR "/usr/local/Cellar/allegro/5.2.6.0")
include_directories(${ALLEGRO_DIR}/include)
link_directories(${ALLEGRO_DIR}/lib)

add_executable(f1 main.c LS_allegro.c LS_allegro.h file/file.c file/file.h interface/interface.c interface/interface.h game.c game.h models/racer.h models/gps.h models/base.h models/pieces.h configuration/configuration.c configuration/configuration.h models/racer.h models/championship.h models/player.h models/car.h)

file(GLOB LIBRARIES ${ALLEGRO_DIR}/lib/*.dylib)
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(f1 ${LIBRARIES})