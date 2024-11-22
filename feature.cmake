# Define the configuration header file path
set(OUTPUT_FILE ${CMAKE_SOURCE_DIR}/configuration.h)

# Define the Python script path
set(CONFIG_SCRIPT ${CMAKE_SOURCE_DIR}/config.py)

# Macro to configure features by passing the right input
macro(configFeature INPUT)
    # Run the Python script to generate/update the configuration.h file
    add_custom_command(
        OUTPUT ${OUTPUT_FILE}  # Specify the output file
        COMMAND ${Python_EXECUTABLE} ${CONFIG_SCRIPT} "${INPUT}"  # Run the Python script with the passed argument
        DEPENDS ${CONFIG_SCRIPT}  # Re-run if the Python script changes
        COMMENT "Generating or updating ${OUTPUT_FILE} using ${CONFIG_SCRIPT} with input=${INPUT}"
        VERBATIM
    )

    # Create a custom target to ensure that configuration.h is always up to date
    add_custom_target(
        configTarget
        DEPENDS ${OUTPUT_FILE}  # Make sure the target depends on the updated configuration.h
    )

    # Ensure that the DivFeature library depends on the custom target
    add_dependencies(${PROJECT_NAME} configTarget)
endmacro()
