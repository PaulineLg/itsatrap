include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(glimac ${SRC_FILES} ../include/BOARD/Board.hpp ../src/BOARD/Board.cpp ../include/GLTOOLS/VBO.hpp ../src/GLTOOLS/VBO.cpp ../include/GLTOOLS/VAO.hpp ../src/GLTOOLS/VAO.cpp ../include/BOARD/Cube.hpp ../src/BOARD/Cube.cpp ../include/GLTOOLS/Texture.hpp ../src/GLTOOLS/Texture.cpp ../include/GLTOOLS/IBO.hpp ../src/GLTOOLS/IBO.cpp ../src/OBJECT/Character.cpp ../src/OBJECT/Item.cpp ../src/OBJECT/pacgomme.cpp ../src/GLTOOLS/FreeFlyCamera.cpp)
