# example_stress.py

This file defines an example stress test script.

## Usage

*   **Description:** This script provides an example of how to use the `stress_test` function to test a solution against a brute force solution.
*   **Functions:**
    *   `rename_files(ext_a, ext_b)`
        *   **Description:** Renames files with extension `ext_a` to have extension `ext_b`, numbering them sequentially.
        *   **Args:**
            *   `ext_a (str)`: The original extension of the files.
            *   `ext_b (str)`: The new extension for the files.
        *   **Returns:**
            *   None
    *   `compile_cpp_files()`
        *   **Description:** Compiles all .cpp files in the current directory using g++.
        *   **Args:**
            *   None
        *   **Returns:**
            *   None
    *   `stress_test(file="a", start=1, file_sol="", file_gen="", max_file=-1)`
        *   **Description:** Runs stress tests by generating input files, running the solution and a brute force solution, and comparing the outputs.
        *   **Args:**
            *   `file (str)`: The base name for the solution and input/output files.
            *   `start (int)`: The starting index for the test cases.
            *   `file_sol (str)`: The name of the solution file.
            *   `file_gen (str)`: The name of the generator file.
            *   `max_file (int)`: The maximum number of test cases to generate. Set to -1 for unlimited generation.
        *   **Returns:**
            *   None