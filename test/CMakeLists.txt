cmake_minimum_required (VERSION 3.15)
project(test)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
# set(CMAKE_BUILD_TYPE Release)
add_executable(niubi src/main.cpp)

target_compile_features(niubi PRIVATE cxx_std_17)

find_package(Drogon CONFIG REQUIRED)
target_link_libraries(niubi PRIVATE Drogon::Drogon)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(niubi PRIVATE nlohmann_json::nlohmann_json )
# include(FetchContent)
# FetchContent_Declare(php-cpp
#         URL https://github.com/CopernicaMarketingSoftware/PHP-CPP.git)
# FetchContent_MakeAvailable(php-cpp)