cmake_minimum_required(VERSION 3.19)

if(DEFINED ENV{GITHUB_RUN_NUMBER})
    project(print_ip VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})
else()
    project(print_ip)
endif()

set(CMAKE_CXX_STANDARD 20)

set(SRC_MAIN main.cpp)
add_executable(print_ip ${SRC_MAIN})

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT timoshenkonas@gmail.com)
include(CPack)

enable_testing()
add_subdirectory(test)
