file(GLOB HEADER_FILES *.hpp)
file(GLOB SRC_FILES *.cpp)
file(GLOB_RECURSE SHADER_FILES *.glsl)

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(FILE ${SRC_FILE} NAME_WE)
    get_filename_component(DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    set(OUTPUT itsatrap) #C'est cette ligne qu'il faut changer pour le nom de l'executable


    add_executable(${OUTPUT} ${SRC_FILE} ${HEADER_FILES} ${SHADER_FILES} ../include/GAMESTATE/gamestate.hpp GAME/game.cpp ../include/GAME/game.hpp GAMESTATE/titlestate.cpp ../include/GAMESTATE/titlestate.hpp GAMESTATE/playstate.cpp ../include/GAMESTATE/playstate.hpp ../include/BOARD/cube.hpp BOARD/cube.cpp ../include/BOARD/Board.hpp BOARD/Board.cpp ../include/GLTOOLS/VBO.hpp GLTOOLS/VBO.cpp ../include/GLTOOLS/VAO.hpp GLTOOLS/VAO.cpp ../include/BOARD/Cylinder.hpp BOARD/Cylinder.cpp ../include/OBJECT/object.hpp ../include/OBJECT/character.hpp ../include/OBJECT/item.hpp ../include/OBJECT/pacman.hpp)
    #add_executable(${OUTPUT} ${SRC_FILE} ${HEADER_FILES} ${SHADER_FILES} ../include GAME/game.cpp GAMESTATE/titlestate.cpp GAMESTATE/playstate.cpp GLTOOLS/VAO.cpp GLTOOLS/VBO.cpp BOARD/Board.cpp BOARD/cube.cpp BOARD/Cylinder.cpp OBJECT/pacman.cpp)

    target_link_libraries(${OUTPUT} ${ALL_LIBRARIES})
endforeach()

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
