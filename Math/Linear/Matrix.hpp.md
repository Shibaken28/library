---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Linear/Matrix.test.cpp
    title: Math/Linear/Matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Linear/Matrix.hpp\"\n# include <vector>\n# include\
    \ <iostream>\nusing namespace std;\n\n// matrix\ntemplate<class T> struct Matrix\
    \ {\n    vector<vector<T> > val;\n    Matrix(int n = 1, int m = 1, T v = 0) :\
    \ val(n, vector<T>(m, v)) {}\n    void init(int n, int m, T v = 0) {val.assign(n,\
    \ vector<T>(m, v));}\n    void resize(int n, int m) {\n        val.resize(n);\n\
    \        for (int i = 0; i < n; ++i) val[i].resize(m);\n    }\n    Matrix<T>&\
    \ operator = (const Matrix<T> &A) {\n        val = A.val;\n        return *this;\n\
    \    }\n    size_t size() const {return val.size();}\n    vector<T>& operator\
    \ [] (int i) {return val[i];}\n    const vector<T>& operator [] (int i) const\
    \ {return val[i];}\n};\n\ntemplate<class T> Matrix<T> operator * (const Matrix<T>\
    \ &A, const Matrix<T> &B) {\n    Matrix<T> R(A.size(), B[0].size());\n    for\
    \ (int i = 0; i < (int)A.size(); ++i)\n        for (int j = 0; j < (int)B[0].size();\
    \ ++j)\n            for (int k = 0; k < (int)B.size(); ++k)\n                R[i][j]\
    \ += A[i][k] * B[k][j];\n    return R;\n}\n\ntemplate<class T> Matrix<T> pow(const\
    \ Matrix<T> &A, long long n) {\n    Matrix<T> R(A.size(), A.size());\n    auto\
    \ B = A;\n    for (int i = 0; i < (int)A.size(); ++i) R[i][i] = 1;\n    while\
    \ (n > 0) {\n        if (n & 1) R = R * B;\n        B = B * B;\n        n >>=\
    \ 1;\n    }\n    return R;\n}\n\ntemplate<class T> vector<T> operator * (const\
    \ Matrix<T> &A, const vector<T> &B) {\n    vector<T> v(A.size());\n    for (int\
    \ i = 0; i < (int)A.size(); ++i)\n        for (int k = 0; k < (int)B.size(); ++k)\n\
    \            v[i] += A[i][k] * B[k];\n    return v;\n}\n\ntemplate<class T> Matrix<T>\
    \ operator + (const Matrix<T> &A, const Matrix<T> &B) {\n    Matrix<T> R(A.size(),\
    \ A[0].size());\n    for (int i = 0; i < (int)A.size(); ++i)\n        for (int\
    \ j = 0; j < (int)A[0].size(); ++j)\n            R[i][j] = A[i][j] + B[i][j];\n\
    \    return R;\n}\n\ntemplate<class T> Matrix<T> operator - (const Matrix<T> &A,\
    \ const Matrix<T> &B) {\n    Matrix<T> R(A.size(), A[0].size());\n    for (int\
    \ i = 0; i < (int)A.size(); ++i)\n        for (int j = 0; j < (int)A[0].size();\
    \ ++j)\n            R[i][j] = A[i][j] - B[i][j];\n    return R;\n}\n\n"
  code: "# include <vector>\n# include <iostream>\nusing namespace std;\n\n// matrix\n\
    template<class T> struct Matrix {\n    vector<vector<T> > val;\n    Matrix(int\
    \ n = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v)) {}\n    void init(int n,\
    \ int m, T v = 0) {val.assign(n, vector<T>(m, v));}\n    void resize(int n, int\
    \ m) {\n        val.resize(n);\n        for (int i = 0; i < n; ++i) val[i].resize(m);\n\
    \    }\n    Matrix<T>& operator = (const Matrix<T> &A) {\n        val = A.val;\n\
    \        return *this;\n    }\n    size_t size() const {return val.size();}\n\
    \    vector<T>& operator [] (int i) {return val[i];}\n    const vector<T>& operator\
    \ [] (int i) const {return val[i];}\n};\n\ntemplate<class T> Matrix<T> operator\
    \ * (const Matrix<T> &A, const Matrix<T> &B) {\n    Matrix<T> R(A.size(), B[0].size());\n\
    \    for (int i = 0; i < (int)A.size(); ++i)\n        for (int j = 0; j < (int)B[0].size();\
    \ ++j)\n            for (int k = 0; k < (int)B.size(); ++k)\n                R[i][j]\
    \ += A[i][k] * B[k][j];\n    return R;\n}\n\ntemplate<class T> Matrix<T> pow(const\
    \ Matrix<T> &A, long long n) {\n    Matrix<T> R(A.size(), A.size());\n    auto\
    \ B = A;\n    for (int i = 0; i < (int)A.size(); ++i) R[i][i] = 1;\n    while\
    \ (n > 0) {\n        if (n & 1) R = R * B;\n        B = B * B;\n        n >>=\
    \ 1;\n    }\n    return R;\n}\n\ntemplate<class T> vector<T> operator * (const\
    \ Matrix<T> &A, const vector<T> &B) {\n    vector<T> v(A.size());\n    for (int\
    \ i = 0; i < (int)A.size(); ++i)\n        for (int k = 0; k < (int)B.size(); ++k)\n\
    \            v[i] += A[i][k] * B[k];\n    return v;\n}\n\ntemplate<class T> Matrix<T>\
    \ operator + (const Matrix<T> &A, const Matrix<T> &B) {\n    Matrix<T> R(A.size(),\
    \ A[0].size());\n    for (int i = 0; i < (int)A.size(); ++i)\n        for (int\
    \ j = 0; j < (int)A[0].size(); ++j)\n            R[i][j] = A[i][j] + B[i][j];\n\
    \    return R;\n}\n\ntemplate<class T> Matrix<T> operator - (const Matrix<T> &A,\
    \ const Matrix<T> &B) {\n    Matrix<T> R(A.size(), A[0].size());\n    for (int\
    \ i = 0; i < (int)A.size(); ++i)\n        for (int j = 0; j < (int)A[0].size();\
    \ ++j)\n            R[i][j] = A[i][j] - B[i][j];\n    return R;\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Linear/Matrix.hpp
  requiredBy: []
  timestamp: '2023-11-14 00:58:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Linear/Matrix.test.cpp
documentation_of: Math/Linear/Matrix.hpp
layout: document
title: "Matrix / \u884C\u5217"
---

## 概要
行列の加算、減算、乗算を行います。
正方行列以外にも対応していますが、サイズの異なる行列同士の演算に注意してください。