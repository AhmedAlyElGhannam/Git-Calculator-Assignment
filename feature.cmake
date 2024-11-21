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
macro( configFeature INPUT
    # to execute the command that runs the .py script and generate configuration.h (considered the output)
    add_custom_command(
        OUTPUT ${OUTPUT_FILE} # this is the header file
        COMMAND python3 ${CONFIG_SCRIPT} ${INPUT} # this executes the script with the passed argument
        DEPENDS ${CONFIG_SCRIPT} # to make sure to re-execute it in case it was modified 
    )

    # creates a custom target
    add_custom_target(
        configTarget    # custom target name
        ALL             # makes sure this custom target is updated upon every build
        DEPENDS         # makes sure that the custom target won't be created unless configuration.h is created 
        ${OUTPUT_FILE}  # file name that will be considered a custom target

    )

    # makes sure that the app depends on my custom target
    add_dependencies(
        Calculator configTarget
    )
)
endmacro()