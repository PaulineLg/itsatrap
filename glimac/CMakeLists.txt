include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(glimac ${SRC_FILES} ../include/CHARACTER/character.h ../include/OBJECT/character.h)
