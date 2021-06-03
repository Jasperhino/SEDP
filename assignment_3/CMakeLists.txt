cmake_minimum_required(VERSION 3.6)
project(sedp_exercise3)

set(CMAKE_CXX_STANDARD 20)

# Task 3.1
add_executable(tea_filebuf
        tea/tea_filebuf.h
        tea/tea_filebuf.cpp
        tea/tea_filebuf-test.cpp
        )

# Task 3.2
# add_executable(integration
#     integration/integration.cpp
# )

# Task 3.3
add_executable(token_iterator
        token_iterator/token_iterator.cpp
        )

# Task 3.4
add_executable(modulocounter
        modcounter/modulocounter.h
        modcounter/modulocounter.cpp
        modcounter/test.cpp
        )

add_custom_target(create_zip_3 COMMAND
        ${CMAKE_COMMAND} -E tar "cfv" "assignment_3_2F8D.zip" --format=zip
        "${CMAKE_CURRENT_SOURCE_DIR}/modcounter/modulocounter.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/modcounter/modulocounter.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/modcounter/test.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/tea/*"

        "${CMAKE_CURRENT_SOURCE_DIR}/token_iterator/token_iterator.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/integration/integration.cpp"



        )

