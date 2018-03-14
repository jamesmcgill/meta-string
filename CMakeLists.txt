cmake_minimum_required(VERSION 3.9.2)
project (metaString VERSION 0.0.1 DESCRIPTION "metaString")

if (MSVC)
  add_compile_options(/W4 /permissive-)
endif()

# Executable
add_executable(metaString main.cpp)
target_compile_features(metaString PUBLIC cxx_std_17)
set_target_properties(metaString PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")