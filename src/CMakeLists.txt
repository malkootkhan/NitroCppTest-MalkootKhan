add_library(rectangle rectangle.cpp)

add_executable(RecIntersection main.cpp)
target_link_libraries(RecIntersection rectangle)

