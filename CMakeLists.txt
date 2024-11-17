
CMAKE_MINIMUM_REQUIRED(VERSION 3.29)

project(Calculator C ASM CXX) 

# Add each driver as a subdirectory
add_subdirectory(Drivers/DivFeature)
add_subdirectory(Drivers/MulFeature)
add_subdirectory(Drivers/SumFeature)
add_subdirectory(Drivers/SubFeature)
add_subdirectory(Drivers/ModFeature)

# Add include directories for each driver
include_directories(
    Drivers/DivFeature/inc
    Drivers/MulFeature/inc
    Drivers/SumFeature/inc
    Drivers/SubFeature/inc
    Drivers/ModFeature/inc
)


# Add the main executable
add_executable(Calculator main.c)

# Link all drivers to the main executable
target_link_libraries(Calculator PRIVATE DivFeature MulFeature SumFeature SubFeature ModFeature)

