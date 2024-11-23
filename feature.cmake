# Define the configuration header file path
set(OUTPUT_FILE ${CMAKE_BINARY_DIR}/configuration.h)

# find the exe
find_program(CONFIG_SCRIPT NAMES config.py PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../.. REQUIRED)
find_package(Python3 REQUIRED)

# Macro to configure features by passing the right input
macro(configFeature MODULE INPUT)
    # Run the Python script to generate/update the configuration.h file

    add_custom_command(
        OUTPUT ${OUTPUT_FILE}  # Specify the output file
        COMMAND ${CMAKE_COMMAND} -E env python3 ${CONFIG_SCRIPT} ${INPUT}  # Run the Python script with the passed argument
        COMMENT "Generating or updating ${OUTPUT_FILE} using ${CONFIG_SCRIPT} with input=${INPUT}"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        VERBATIM
    )

    # Create a custom target to ensure that configuration.h is always up to date
    add_custom_target(
        "${MODULE}-Target"
        DEPENDS ${OUTPUT_FILE}  # Make sure the target depends on the updated configuration.h
    )

    # Ensure that the DivFeature library depends on the custom target
    add_dependencies(${MODULE} "${MODULE}-Target")

endmacro()
