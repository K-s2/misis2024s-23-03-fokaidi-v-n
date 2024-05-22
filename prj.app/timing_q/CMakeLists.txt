add_executable(timing_q timing_q.cpp)
add_executable(ex ex.cpp)
target_link_libraries(timing_q queuelstt queuearrt)

find_package(Gnuplot REQUIRED)
if(Gnuplot_FOUND)
    include_directories(${Gnuplot_INCLUDE_DIRS})
    target_link_libraries (timing_q ${Gnuplot_LIBRARIES})
endif()


