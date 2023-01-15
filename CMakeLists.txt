cmake_minimum_required(VERSION 3.16)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(lab1 VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(version.h.in version.h)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_BINARY_DIR}"
)

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -pedantic
    -Werror
)

enable_testing()
find_package(GTest REQUIRED)
add_executable(hello_test
  hello_test.cc
)
target_include_directories(hello_test PRIVATE
    "${CMAKE_BINARY_DIR}"
)
target_link_libraries(hello_test
   GTest::GTest
   GTest::Main
)
include(GoogleTest)
gtest_discover_tests(hello_test)


install(TARGETS ${PROJECT_NAME} hello_test RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libgtest-dev,libgmock-dev,libtbb-dev")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
