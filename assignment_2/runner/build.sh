#!/bin/bash

c++ -std=c++14 -I . -o runner.cpp.o -c runner.cpp
c++ runner.cpp.o -o runner -rdynamic externallibrary-x64.so -Wl,-rpath,.
