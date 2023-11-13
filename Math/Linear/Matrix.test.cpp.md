---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Linear/Matrix.hpp
    title: "Matrix / \u884C\u5217"
  - icon: ':heavy_check_mark:'
    path: Math/Mod/mint.hpp
    title: "modint / modint\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"Math/Linear/Matrix.test.cpp\"\n# define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \nusing namespace std;\n# include <iostream>\n#line 1 \"Math/Mod/mint.hpp\"\n\
    // modint: mod \u8A08\u7B97\u3092 int \u3092\u6271\u3046\u3088\u3046\u306B\u6271\
    \u3048\u308B\u69CB\u9020\u4F53\ntemplate<int MOD> struct Fp {\n    long long val;\n\
    \    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {\n        if (val\
    \ < 0) val += MOD;\n    }\n    constexpr int getmod() { return MOD; }\n    constexpr\
    \ Fp operator - () const noexcept {\n        return val ? MOD - val : 0;\n   \
    \ }\n    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this)\
    \ += r; }\n    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this)\
    \ -= r; }\n    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this)\
    \ *= r; }\n    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this)\
    \ /= r; }\n    constexpr Fp& operator += (const Fp& r) noexcept {\n        val\
    \ += r.val;\n        if (val >= MOD) val -= MOD;\n        return *this;\n    }\n\
    \    constexpr Fp& operator -= (const Fp& r) noexcept {\n        val -= r.val;\n\
    \        if (val < 0) val += MOD;\n        return *this;\n    }\n    constexpr\
    \ Fp& operator *= (const Fp& r) noexcept {\n        val = val * r.val % MOD;\n\
    \        return *this;\n    }\n    constexpr Fp& operator /= (const Fp& r) noexcept\
    \ {\n        long long a = r.val, b = MOD, u = 1, v = 0;\n        while (b) {\n\
    \            long long t = a / b;\n            a -= t * b; swap(a, b);\n     \
    \       u -= t * v; swap(u, v);\n        }\n        val = val * u % MOD;\n   \
    \     if (val < 0) val += MOD;\n        return *this;\n    }\n    constexpr bool\
    \ operator == (const Fp& r) const noexcept {\n        return this->val == r.val;\n\
    \    }\n    constexpr bool operator != (const Fp& r) const noexcept {\n      \
    \  return this->val != r.val;\n    }\n    friend constexpr ostream& operator <<\
    \ (ostream &os, const Fp<MOD>& x) noexcept {\n        return os << x.val;\n  \
    \  }\n    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept\
    \ {\n        if (n == 0) return 1;\n        auto t = modpow(a, n / 2);\n     \
    \   t = t * t;\n        if (n & 1) t = t * a;\n        return t;\n    }\n};\n\n\
    #line 1 \"Math/Linear/Matrix.hpp\"\n# include <vector>\n#line 3 \"Math/Linear/Matrix.hpp\"\
    \nusing namespace std;\n\n// matrix\ntemplate<class T> struct Matrix {\n    vector<vector<T>\
    \ > val;\n    Matrix(int n = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v))\
    \ {}\n    void init(int n, int m, T v = 0) {val.assign(n, vector<T>(m, v));}\n\
    \    void resize(int n, int m) {\n        val.resize(n);\n        for (int i =\
    \ 0; i < n; ++i) val[i].resize(m);\n    }\n    Matrix<T>& operator = (const Matrix<T>\
    \ &A) {\n        val = A.val;\n        return *this;\n    }\n    size_t size()\
    \ const {return val.size();}\n    vector<T>& operator [] (int i) {return val[i];}\n\
    \    const vector<T>& operator [] (int i) const {return val[i];}\n};\n\ntemplate<class\
    \ T> Matrix<T> operator * (const Matrix<T> &A, const Matrix<T> &B) {\n    Matrix<T>\
    \ R(A.size(), B[0].size());\n    for (int i = 0; i < (int)A.size(); ++i)\n   \
    \     for (int j = 0; j < (int)B[0].size(); ++j)\n            for (int k = 0;\
    \ k < (int)B.size(); ++k)\n                R[i][j] += A[i][k] * B[k][j];\n   \
    \ return R;\n}\n\ntemplate<class T> Matrix<T> pow(const Matrix<T> &A, long long\
    \ n) {\n    Matrix<T> R(A.size(), A.size());\n    auto B = A;\n    for (int i\
    \ = 0; i < (int)A.size(); ++i) R[i][i] = 1;\n    while (n > 0) {\n        if (n\
    \ & 1) R = R * B;\n        B = B * B;\n        n >>= 1;\n    }\n    return R;\n\
    }\n\ntemplate<class T> vector<T> operator * (const Matrix<T> &A, const vector<T>\
    \ &B) {\n    vector<T> v(A.size());\n    for (int i = 0; i < (int)A.size(); ++i)\n\
    \        for (int k = 0; k < (int)B.size(); ++k)\n            v[i] += A[i][k]\
    \ * B[k];\n    return v;\n}\n\ntemplate<class T> Matrix<T> operator + (const Matrix<T>\
    \ &A, const Matrix<T> &B) {\n    Matrix<T> R(A.size(), A[0].size());\n    for\
    \ (int i = 0; i < (int)A.size(); ++i)\n        for (int j = 0; j < (int)A[0].size();\
    \ ++j)\n            R[i][j] = A[i][j] + B[i][j];\n    return R;\n}\n\ntemplate<class\
    \ T> Matrix<T> operator - (const Matrix<T> &A, const Matrix<T> &B) {\n    Matrix<T>\
    \ R(A.size(), A[0].size());\n    for (int i = 0; i < (int)A.size(); ++i)\n   \
    \     for (int j = 0; j < (int)A[0].size(); ++j)\n            R[i][j] = A[i][j]\
    \ - B[i][j];\n    return R;\n}\n\n#line 6 \"Math/Linear/Matrix.test.cpp\"\n\n\
    using mint = Fp<998244353>;\n\nint main(){\n    int n,m,k;cin>>n>>m>>k;\n    Matrix<mint>\
    \ A(n,m),B(m,k);\n    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>A.val[i][j].val;\n\
    \    for(int i=0;i<m;++i)for(int j=0;j<k;++j)cin>>B.val[i][j].val;\n    auto C=A*B;\n\
    \    for(int i=0;i<n;++i){\n        for(int j=0;j<k;++j){\n            cout<<(j?\"\
    \ \":\"\")<<C.val[i][j].val;\n        }\n        cout<<endl;\n    }\n    return\
    \ 0;\n}\n"
  code: "# define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\nusing\
    \ namespace std;\n# include <iostream>\n# include \"../Mod/mint.hpp\"\n# include\
    \ \"Matrix.hpp\"\n\nusing mint = Fp<998244353>;\n\nint main(){\n    int n,m,k;cin>>n>>m>>k;\n\
    \    Matrix<mint> A(n,m),B(m,k);\n    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>A.val[i][j].val;\n\
    \    for(int i=0;i<m;++i)for(int j=0;j<k;++j)cin>>B.val[i][j].val;\n    auto C=A*B;\n\
    \    for(int i=0;i<n;++i){\n        for(int j=0;j<k;++j){\n            cout<<(j?\"\
    \ \":\"\")<<C.val[i][j].val;\n        }\n        cout<<endl;\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - Math/Mod/mint.hpp
  - Math/Linear/Matrix.hpp
  isVerificationFile: true
  path: Math/Linear/Matrix.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 00:58:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Linear/Matrix.test.cpp
layout: document
redirect_from:
- /verify/Math/Linear/Matrix.test.cpp
- /verify/Math/Linear/Matrix.test.cpp.html
title: Math/Linear/Matrix.test.cpp
---
