cmake_minimum_required(VERSION 3.5.1)
project(boost-asio-test VERSION 0.0.1 LANGUAGES CXX)

set(CONAN_CMAKE_FILE ${CMAKE_CURRENT_LIST_DIR}/cmake/cmake-conan/conan.cmake)
set(CONAN_BUILDINFO_FILE ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

if(EXISTS ${CONAN_CMAKE_FILE})
    include(cmake/cmake-conan/conan.cmake)

    conan_cmake_run(
        REQUIRES boost/1.68.0@conan/stable
        BASIC_SETUP
        CMAKE_TARGETS
        BUILD missing
    )
else()
    message(FATAL "provide conan.cmake (run \"git submodule update --init\")")
endif()

add_executable(hello_world hello_world.cpp)

target_link_libraries(hello_world PRIVATE CONAN_PKG::boost)

if(WIN32)
    # TODO Shouldn't this be handled transitively by the Boost target?
    target_link_libraries(hello_world PRIVATE ws2_32)
endif()
