import sys
import os

# Define the mapping of arguments to macros for defining and undefining
DEFINE_MACRO_MAP = {
    "1": "ADD",
    "2": "SUB",
    "3": "MUL",
    "4": "DIV",
    "5": "MOD"
}

UNDEFINE_MACRO_MAP = {
    "6": "ADD",
    "7": "SUB",
    "8": "MUL",
    "9": "DIV",
    "0": "MOD"
}

# Path to the header file
HEADER_FILE = "configuration.h"

HEADER_GUARD_START = "#ifndef CONFIGURATION_H_"
HEADER_GUARD_END = "#endif"

def read_header_file(filepath):
    """Read the content of the header file."""
    if not os.path.exists(filepath):
        return []
    with open(filepath, "r") as file:
        return file.readlines()

def write_header_file(filepath, lines):
    """Write the content back to the header file."""
    with open(filepath, "w") as file:
        file.writelines(lines)

def macro_already_defined(lines, macro):
    """Check if a macro is already defined in the header file."""
    return any(f"#define {macro}" in line for line in lines)

def find_header_guard_indices(lines):
    """Find the indices of the header guard start and end."""
    start_index = None
    end_index = None

    for i, line in enumerate(lines):
        if HEADER_GUARD_START in line:
            start_index = i
        if HEADER_GUARD_END in line:
            end_index = i

    return start_index, end_index
def add_macro_to_header(arg):
    """Add the macro corresponding to the argument to the header file."""
    if arg not in DEFINE_MACRO_MAP:
        print(f"Invalid argument for defining: {arg}. Allowed values are '1'-'5'.")
        sys.exit(1)

    macro = DEFINE_MACRO_MAP[arg]
    lines = read_header_file(HEADER_FILE)

    # Ensure the header guard is present
    start_index, end_index = find_header_guard_indices(lines)
    if start_index is None or end_index is None:
        print("Header guard not found in the file. Aborting.")
        sys.exit(1)

    # Check if the macro is already defined
    if macro_already_defined(lines, macro):
        print(f"Macro {macro} is already defined. No changes made.")
        sys.exit(0)

    # Insert the macro definition before the #endif
    insertion_point = end_index
    lines.insert(insertion_point, f"#define {macro}\n")
    write_header_file(HEADER_FILE, lines)
    print(f"Macro {macro} added successfully.")

def remove_macro_from_header(arg):
    """Remove the macro corresponding to the argument from the header file."""
    if arg not in UNDEFINE_MACRO_MAP:
        print(f"Invalid argument for undefining: {arg}. Allowed values are '6'-'0'.")
        sys.exit(1)

    macro = UNDEFINE_MACRO_MAP[arg]
    lines = read_header_file(HEADER_FILE)

    # Ensure the header guard is present
    start_index, end_index = find_header_guard_indices(lines)
    if start_index is None or end_index is None:
        print("Header guard not found in the file. Aborting.")
        sys.exit(1)

    # Check if the macro is defined
    if not macro_already_defined(lines, macro):
        print(f"Macro {macro} is not defined. No changes made.")
        sys.exit(0)

    # Remove the macro definition
    lines = [line for line in lines if f"#define {macro}" not in line]
    write_header_file(HEADER_FILE, lines)
    print(f"Macro {macro} removed successfully.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python update_header.py <arg>")
        sys.exit(1)

    arg = sys.argv[1]

    if arg in DEFINE_MACRO_MAP:
        add_macro_to_header(arg)
    elif arg in UNDEFINE_MACRO_MAP:
        remove_macro_from_header(arg)
    else:
        print("Invalid argument. Use '1'-'5' to define macros and '6'-'0' to undefine macros.")
        sys.exit(1)
