# Matrix.cpp

This file implements a matrix data structure and related operations.

## Usage

*   **Description:** This file implements a matrix data structure and related operations, such as matrix multiplication and exponentiation.
*   **Template Parameters:**
    *   `T`: The type of the elements in the matrix.
*   **Classes:**
    *   `Matrix<T>`
        *   **Description:** A class that implements a matrix.
        *   **Members:**
            *   `mat`: A 2D vector storing the matrix elements.
            *   `rows`: The number of rows in the matrix.
            *   `cols`: The number of columns in the matrix.
        *   **Functions:**
            *   `Matrix(int r, int c)`: Constructor that creates a matrix with r rows and c columns.
            *   `Matrix(const vector<vector<T>>& m)`: Constructor that creates a matrix from a 2D vector.
            *   `operator*(const Matrix& other) const`: Multiplies two matrices.
            *   `operator^(ll n) const`: Raises the matrix to the power of n.
            *   `operator+=(const Matrix& other)`: Adds another matrix to this matrix.
            *   `operator+(const Matrix& other) const`: Adds two matrices.
            *   `operator[](int idx)`: Returns a reference to the row at the given index.
            *   `getRowsSize() const`: Returns the number of rows in the matrix.
            *   `getColsSize() const`: Returns the number of columns in the matrix.
            *   `print() const`: Prints the matrix to the console.