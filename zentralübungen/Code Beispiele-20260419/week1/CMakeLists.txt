add_executable(Sorting sorting_algorithms.h sorting.cpp sorting_algorithms.cpp)
target_compile_options(Sorting PUBLIC -O3)
target_include_directories(Sorting PUBLIC .)
target_link_libraries(Sorting PUBLIC Utils)

