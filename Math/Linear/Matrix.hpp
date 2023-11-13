# include <vector>
# include <iostream>
using namespace std;

// matrix
template<class T> struct Matrix {
    vector<vector<T> > val;
    Matrix(int n = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v)) {}
    void init(int n, int m, T v = 0) {val.assign(n, vector<T>(m, v));}
    void resize(int n, int m) {
        val.resize(n);
        for (int i = 0; i < n; ++i) val[i].resize(m);
    }
    Matrix<T>& operator = (const Matrix<T> &A) {
        val = A.val;
        return *this;
    }
    size_t size() const {return val.size();}
    vector<T>& operator [] (int i) {return val[i];}
    const vector<T>& operator [] (int i) const {return val[i];}
};

template<class T> Matrix<T> operator * (const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> R(A.size(), B[0].size());
    for (int i = 0; i < (int)A.size(); ++i)
        for (int j = 0; j < (int)B[0].size(); ++j)
            for (int k = 0; k < (int)B.size(); ++k)
                R[i][j] += A[i][k] * B[k][j];
    return R;
}

template<class T> Matrix<T> pow(const Matrix<T> &A, long long n) {
    Matrix<T> R(A.size(), A.size());
    auto B = A;
    for (int i = 0; i < (int)A.size(); ++i) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * B;
        B = B * B;
        n >>= 1;
    }
    return R;
}

template<class T> vector<T> operator * (const Matrix<T> &A, const vector<T> &B) {
    vector<T> v(A.size());
    for (int i = 0; i < (int)A.size(); ++i)
        for (int k = 0; k < (int)B.size(); ++k)
            v[i] += A[i][k] * B[k];
    return v;
}

template<class T> Matrix<T> operator + (const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> R(A.size(), A[0].size());
    for (int i = 0; i < (int)A.size(); ++i)
        for (int j = 0; j < (int)A[0].size(); ++j)
            R[i][j] = A[i][j] + B[i][j];
    return R;
}

template<class T> Matrix<T> operator - (const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> R(A.size(), A[0].size());
    for (int i = 0; i < (int)A.size(); ++i)
        for (int j = 0; j < (int)A[0].size(); ++j)
            R[i][j] = A[i][j] - B[i][j];
    return R;
}

