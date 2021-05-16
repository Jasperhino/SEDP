cmake_minimum_required(VERSION 3.19)
project(SEDP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE on)

add_executable(PALINDROME assignment_1/palindrome-checker/palindrome-checker.cpp)
add_executable(PI assignment_1/montecarlopi/montecarlopi.cpp)
add_library(ProviderLibrary SHARED assignment_1/library/provider.cpp assignment_1/library/provider.h)
add_executable(ProviderLibraryTest assignment_1/library/providerlibtest.cpp)
target_link_libraries(ProviderLibraryTest ProviderLibrary)
add_executable(SYNTAX assignment_1/syntactic_sugar/syntax.cpp)

add_custom_target(create_zip COMMAND
        ${CMAKE_COMMAND} -E tar "cfv" "assignment_1_2F8D.zip" --format=zip
        "${CMAKE_CURRENT_SOURCE_DIR} /assignment_1/montecarlopi/montecarlopi.txt"
        "${CMAKE_CURRENT_SOURCE_DIR} /assignment_1/montecarlopi/montecarlopi.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR} /assignment_1/palindrome-checker/palindrome-checker.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR} /assignment_1/library/provider.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR} /assignment_1/library/provider.h"
        "${CMAKE_CURRENT_SOURCE_DIR} /assignment_1/library/provider_make.txt"

        "${CMAKE_CURRENT_SOURCE_DIR} /assignment_1/syntactic_sugar/syntax.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR} /CMakeLists.txt")

add_executable(REGEX assignment_2/regex-filter/regex-filter.cpp)

