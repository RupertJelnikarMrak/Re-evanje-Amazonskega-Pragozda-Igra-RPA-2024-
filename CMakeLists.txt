cmake_minimum_required(VERSION 3.27.7)
project(SavingAmazonRainforest VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# CPack setup
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# CMake setup
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# SDL2 setup
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
# ? Note: Folder here should contain both SDL2 and SDL2_image files!
#set(SDL2_PATH C:/SDL2)
#set(SDL2_LIB_PATH ${SDL2_PATH}/lib)
#set(SDL2_INCLUDE_PATH ${SDL2_PATH}/include)
#set(SDL2_BIN_PATH ${SDL2_LIBRARY}/bin)

# Setup include and link directories

include_directories(
    ${CMAKE_INCLUDE_PATH}
    ${SDL2_INCLUDE_PATH}
)

link_directories(
    ${SDL2_LIB_PATH}
)

# Files that should be compiled

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "src/*.cpp" "src/*.hpp" "src/*.h")

message(STATUS "Add source files:")
foreach(SRC_FILE IN LISTS SRC)
    message(STATUS "${SRC_FILE}")
    endforeach()
    message(STATUS "")
    
add_executable(${PROJECT_NAME} ${SRC})

# LINK PROGRAMS

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    mingw32
    SDL2main
    SDL2
    SDL2_image
)

# Copy over static files

message(STATUS "Copying all dependencies to ${OUTPUT_DIR}")
file(GLOB PROJECT_DEPENDENCIES ${SDL2_LIBRARY})

foreach(Dependecy IN LISTS PROJECT_DEPENDENCIES)
    file(
        COPY ${Dependecy}
        DESTINATION ${OUTPUT_DIR}
    )
endforeach()