# Installation based on https://foonathan.net/2016/03/cmake-install/

get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/${CMAKE_BUILD_TYPE}/openpos-commons.cmake)