file(GLOB HEADER_FILES *.hpp)
file(GLOB SRC_FILES *.cpp)
file(GLOB_RECURSE SHADER_FILES *.glsl)

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(FILE ${SRC_FILE} NAME_WE)
    get_filename_component(DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    set(OUTPUT itsatrap) #C'est cette ligne qu'il faut changer pour le nom de l'executable


    add_executable(${OUTPUT} ${SRC_FILE} ${HEADER_FILES} ${SHADER_FILES} ../include GAME/game.cpp GAMESTATE/titlestate.cpp GAMESTATE/playstate.cpp GLTOOLS/VAO.cpp GLTOOLS/VBO.cpp BOARD/Board.cpp BOARD/Cylinder.cpp OBJECT/pacman.cpp ../include/BOARD/Cube.hpp BOARD/Cube.cpp ../include/GLTOOLS/Texture.hpp GLTOOLS/Texture.cpp ../include/GLTOOLS/IBO.hpp GLTOOLS/IBO.cpp GLTOOLS/TrackBallCamera.cpp)

    target_link_libraries(${OUTPUT} ${ALL_LIBRARIES})
endforeach()

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
