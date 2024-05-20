find_package(doctest)
add_library(robocalc INTERFACE robocalc.hpp)
set_property(TARGET robocalc PROPERTY CXX_STANDARD 20)
target_include_directories(robocalc INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
add_executable(test_robocalc test_robocalc.cpp)
target_link_libraries(test_robocalc robocalc doctest::doctest)
