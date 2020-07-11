cmake_minimum_required(VERSION 3.16)
project(open-pos-commons VERSION 0.1.0 DESCRIPTION "Common API between client and hosts")

find_package(Qt5 COMPONENTS Core)

add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(header_dir include/openpos-commons)
set(headers ${header_dir}/Product.h)

set(source_dir src/openpos-commons)
set(sources ${source_dir}/Product.cpp)

set(tool_dest "bin")
set(include_dest "include/openpos-commons-${PROJECT_VERSION}")
set(main_lib_dest "lib/openpos-commons-${PROJECT_VERSION}")
set(lib_dest "${main_lib_dest}/${CMAKE_BUILD_TYPE}")

add_library(openposcommons ${sources} ${headers})
target_link_libraries(openposcommons PRIVATE Qt5::Core)
target_include_directories(openposcommons
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:${include_dest}>
        $<INSTALL_INTERFACE:${lib_dest}>
        PRIVATE
        ${header_dir} ${source_dir})

configure_file(cmake/openpos-commons-config-version.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/openpos-commons-config-version.cmake @ONLY)

install(TARGETS openposcommons EXPORT openpos-commons DESTINATION ${tool_dest})
install(DIRECTORY ${header_dir} DESTINATION "${include_dest}")
install(FILES cmake/openpos-commons-config.cmake ${CMAKE_CURRENT_BINARY_DIR}/openpos-commons-config-version.cmake DESTINATION ${main_lib_dest})
install(EXPORT openpos-commons DESTINATION "${lib_dest}")