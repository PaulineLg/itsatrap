include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(glimac ${SRC_FILES} ../include/BOARD/Board.h ../src/BOARD/Board.cpp ../include/GLTOOLS/VBO.h ../src/GLTOOLS/VBO.cpp ../include/GLTOOLS/VAO.h ../src/GLTOOLS/VAO.cpp ../include/BOARD/Cylinder.h ../src/BOARD/Cylinder.cpp)
