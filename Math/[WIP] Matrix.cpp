template<typename T>
class Matrix {
private:
    vector<vector<T>> mat;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(r, vector<T>(c, 0));
    }

    Matrix(const vector<vector<T>>& m) : mat(m) {
        rows = m.size();
        cols = m[0].size();
    }

    Matrix operator*(const Matrix& other) const {
        assert(cols == other.rows);
        Matrix result(rows, other.cols);
        
        // ikj 순서로 행렬 곱셈
        for(int i = 0; i < rows; i++) {
            for(int k = 0; k < cols; k++) {
                auto val = mat[i][k];
                if(val == 0) continue;
                for(int j = 0; j < other.cols; j++) {
                    result.mat[i][j] += val * other.mat[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator^(ll n) const {
        assert(rows == cols and n >= 0);
        Matrix result(rows, cols);
        Matrix cur = *this;
        for(int i=0;i<rows;i++) result[i][i] = 1;
        while(n){
            if(n&1) result = result * cur;
            cur = cur * cur;
            n >>= 1;
        }
        return result;
    }

    Matrix& operator+=(const Matrix& other) {
        assert(rows == other.rows && cols == other.cols);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] += other.mat[i][j];
            }
        }
        return *this;
    }


    Matrix operator+(const Matrix& other) const {
        Matrix result = *this;
        result += other;
        return result;
    }

    vector<T>& operator[](int idx) {
        return mat[idx];
    }

    int getRowsSize() const { return rows; }
    int getColsSize() const { return cols; }

    void print() const {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }
};