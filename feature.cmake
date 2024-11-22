# declare output file as configuration.h (located in project root)
set(OUTPUT_FILE ${CMAKE_SOURCE_DIR}/configuration.h)
# declare configuration script as config.py (located in project root)
set(CONFIG_SCRIPT ${CMAKE_SOURCE_DIR}/config.py)

# macro to configure features by passing the right input
# 1 => #define ADD
# 2 => #define SUB
# 3 => #define MUL
# 4 => #define DIV
# 5 => #define MOD
# 6 => removes definition for ADD  
# 7 => removes definition for SUB  
# 8 => removes definition for MUL  
# 9 => removes definition for DIV  
# 0 => removes definition for MOD  
macro(configFeature INPUT)
    # Validate the input argument (must be a number between 0 and 9)
    if(NOT INPUT MATCHES "^[0-9]$")
        message(FATAL_ERROR "Invalid INPUT value: ${INPUT}. Must be a number between 0 and 9.")
    endif()

    # to execute the command that runs the .py script and generate configuration.h (considered the output)
    add_custom_command(
        OUTPUT ${OUTPUT_FILE}  # this is the header file
        COMMAND python3 ${CONFIG_SCRIPT} ${INPUT}  # this executes the script with the passed argument
        DEPENDS ${CONFIG_SCRIPT} ${INPUT}  # re-execute if script or input changes
    )

    # creates a custom target
    add_custom_target(
        configTarget            # custom target name
        DEPENDS ${OUTPUT_FILE}  # make sure this custom target depends on the output file
    )

    # make sure the app depends on the configTarget
    add_dependencies(
        DivFeature configTarget
        ) 
endmacro()
