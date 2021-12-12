set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/deps/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_DEFAULT_TRIPLET "x64-linux")

cmake_minimum_required(VERSION 3.12)

project(quickapp-desktop)
set(CMAKE_CXX_STANDARD 20)

find_package(imgui CONFIG REQUIRED)
find_package(uvw CONFIG REQUIRED)

add_subdirectory(quickjs)

file(GLOB_RECURSE GUI_FILES  gui/*.h gui/*.cpp)
file(GLOB_RECURSE FRAMEWORK_FILES framework/*.h framework/*.cpp)

add_executable(${PROJECT_NAME}
    main.cpp
    ${GUI_FILES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    imgui::imgui
    uvw::uvw
    GL
    quickjs
)

