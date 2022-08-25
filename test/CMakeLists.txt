cmake_minimum_required (VERSION 3.17)

project(test)

add_executable(test src/main.cpp)

target_compile_features(test PRIVATE cxx_std_17)
set_target_properties(test PROPERTIES CXX_EXTENSIONS OFF)


find_package(Drogon CONFIG REQUIRED)
target_link_libraries(test PRIVATE Drogon::Drogon)