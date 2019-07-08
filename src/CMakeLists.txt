project(AnomalyDetectionCpp)

file(GLOB sourcefiles *.cpp *.h)

set(EXECUTABLE_OUTPUT_PATH ../../bin)
set(LIBRARY_OUTPUT_PATH ../../lib)

add_library(AnomalyDetection detectanomalies.cpp detectanomalies.h)
add_executable(AnomalyDetectionCpp ${sourcefiles} main.cpp)