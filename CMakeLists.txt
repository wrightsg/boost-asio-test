cmake_minimum_required(VERSION 3.5.1)
project(boost-asio-test VERSION 0.0.1 LANGUAGES CXX)

set(CONAN_CMAKE_FILE ${CMAKE_CURRENT_LIST_DIR}/cmake/cmake-conan/conan.cmake)
set(CONAN_BUILDINFO_FILE ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

if(EXISTS ${CONAN_CMAKE_FILE})
    include(cmake/cmake-conan/conan.cmake)

    conan_cmake_run(
        REQUIRES boost/1.68.0@conan/stable
        REQUIRES catch2/2.5.0@bincrafters/stable
        BASIC_SETUP
        CMAKE_TARGETS
        BUILD missing
    )
else()
    message(FATAL "provide conan.cmake (run \"git submodule update --init\")")
endif()

foreach(example hello_world server_client)
    add_executable(${example} ${example}.cpp)

    target_link_libraries(${example} PRIVATE CONAN_PKG::boost CONAN_PKG::catch2)

    if(WIN32)
        # TODO Shouldn't this be handled transitively by the Boost target?
        target_link_libraries(${example} PRIVATE ws2_32)
    endif()
endforeach()
