# find_missing_md.py

This file defines a script that finds all .cpp and .py files in the current directory (recursively) that do not have a corresponding .md file in the same directory.

## Usage

*   **Description:** This script finds all .cpp and .py files in the current directory (recursively) that do not have a corresponding .md file in the same directory.

*   **Functions:**
    *   `find_files_without_md(root_dir)`
        *   **Description:** Finds all .cpp and .py files in the given directory that do not have a corresponding .md file.
        *   **Args:**
            *   `root_dir (str)`: The root directory to search.
        *   **Returns:**
            *   `list`: A list of file paths that match the criteria.