cmake_minimum_required(VERSION 3.10.0)
project(mamede_pong VERSION 0.1.0 LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(vendor/SDL_ttf EXCLUDE_FROM_ALL)
find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)

add_executable(${PROJECT_NAME} 
    src/main.c 
    src/game.c
    src/engine.c
    src/paddle.c
    src/ball.c
    src/math.c
    src/controller.c
    src/collisions.c
    )

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/assets" "${CMAKE_BINARY_DIR}/assets"
    COMMENT "Copying assets"
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_dependencies(${PROJECT_NAME} copy_assets)
