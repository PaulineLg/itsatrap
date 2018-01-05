include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(glimac ${SRC_FILES} ../include/CHARACTER/character.h ../include/OBJECT/character.h ../include/OBJECT/item.h ../include/OBJECT/pacman.h ../include/OBJECT/ghost.h ../include/OBJECT/pacgomme.h ../include/OBJECT/fruits.h ../include/OBJECT/superpacgomme.h)
