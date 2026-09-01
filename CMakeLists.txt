cmake_minimum_required(VERSION 3.16)

project(Qt6-Clock VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Network)
find_package(LayerShellQt REQUIRED)

qt_standard_project_setup()

set(SRC_FILES
    src/main.cpp
    src/central_widget.cpp
)

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOURCE_DIR}/include/*.hpp
)

qt_add_resources(RESOURCES_FILES assets/resources.qrc)

qt_add_executable(Qt6-Clock
    ${SRC_FILES}
    ${HEADER_FILES}
    ${RESOURCES_FILES}
)

target_include_directories(Qt6-Clock PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(Qt6-Clock PRIVATE Qt6::Widgets Qt6::Core Qt6::Network LayerShellQt::Interface)