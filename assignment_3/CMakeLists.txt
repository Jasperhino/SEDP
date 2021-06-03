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
#add_executable(token_iterator
#       token_iterator/token_iterator.cpp
#)

# Task 3.4
add_executable(modcounter
        modcounter/test.cpp
        modcounter/modcounter.cpp
        modcounter/modcounter.h
)