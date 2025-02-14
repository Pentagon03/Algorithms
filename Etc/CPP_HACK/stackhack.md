# Etc/CPP_HACK/stackhack.cpp

This file provides a method to increase the stack size in C++.

## Stack Size Increase

*   **Description:** This file defines a function `run_with_stack_size` that allows you to run a function with a specified stack size. This can be useful for programs that require a large stack.

*   **Functions:**
    *   `run_with_stack_size(void (*func)(void), size_t stsize)`: Runs a function `func` with a stack size of `stsize`.
        ```cpp
        static void run_with_stack_size(void (*func)(void), size_t stsize);
        ```
        *   **Parameters:**
            *   `func`: The function to run.
            *   `stsize`: The stack size in bytes.

*   **Usage:**
    *   Call `run_with_stack_size` with the function you want to run and the desired stack size.
    *   Example:
        ```cpp
        void main_() {
            // implement your solution here
        }
        int main() {
            run_with_stack_size(main_, 1024 * 1024 * 1024); // run with a 1 GiB stack
            return 0;
        }