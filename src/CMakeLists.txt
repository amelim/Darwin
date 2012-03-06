FILE(GLOB sources *.cpp)
SET(libs tcod tcodxx tcodgui)

ADD_EXECUTABLE(Darwin ${sources})
TARGET_LINK_LIBRARIES(Darwin ${libs})
