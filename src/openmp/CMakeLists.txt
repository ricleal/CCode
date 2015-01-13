# library called myopenmp

# find OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_library (myopenmp SHARED omp_workshare1.c)

target_include_directories (myopenmp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
