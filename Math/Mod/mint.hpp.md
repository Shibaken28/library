---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Math/Combination/combination.test.cpp
    title: Math/Combination/combination.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Mod/mint.hpp\"\n// modint: mod \u8A08\u7B97\u3092 int\
    \ \u3092\u6271\u3046\u3088\u3046\u306B\u6271\u3048\u308B\u69CB\u9020\u4F53\ntemplate<int\
    \ MOD> struct Fp {\n    long long val;\n    constexpr Fp(long long v = 0) noexcept\
    \ : val(v % MOD) {\n        if (val < 0) val += MOD;\n    }\n    constexpr int\
    \ getmod() { return MOD; }\n    constexpr Fp operator - () const noexcept {\n\
    \        return val ? MOD - val : 0;\n    }\n    constexpr Fp operator + (const\
    \ Fp& r) const noexcept { return Fp(*this) += r; }\n    constexpr Fp operator\
    \ - (const Fp& r) const noexcept { return Fp(*this) -= r; }\n    constexpr Fp\
    \ operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }\n    constexpr\
    \ Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }\n    constexpr\
    \ Fp& operator += (const Fp& r) noexcept {\n        val += r.val;\n        if\
    \ (val >= MOD) val -= MOD;\n        return *this;\n    }\n    constexpr Fp& operator\
    \ -= (const Fp& r) noexcept {\n        val -= r.val;\n        if (val < 0) val\
    \ += MOD;\n        return *this;\n    }\n    constexpr Fp& operator *= (const\
    \ Fp& r) noexcept {\n        val = val * r.val % MOD;\n        return *this;\n\
    \    }\n    constexpr Fp& operator /= (const Fp& r) noexcept {\n        long long\
    \ a = r.val, b = MOD, u = 1, v = 0;\n        while (b) {\n            long long\
    \ t = a / b;\n            a -= t * b; swap(a, b);\n            u -= t * v; swap(u,\
    \ v);\n        }\n        val = val * u % MOD;\n        if (val < 0) val += MOD;\n\
    \        return *this;\n    }\n    constexpr bool operator == (const Fp& r) const\
    \ noexcept {\n        return this->val == r.val;\n    }\n    constexpr bool operator\
    \ != (const Fp& r) const noexcept {\n        return this->val != r.val;\n    }\n\
    \    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept\
    \ {\n        return os << x.val;\n    }\n    friend constexpr Fp<MOD> modpow(const\
    \ Fp<MOD> &a, long long n) noexcept {\n        if (n == 0) return 1;\n       \
    \ auto t = modpow(a, n / 2);\n        t = t * t;\n        if (n & 1) t = t * a;\n\
    \        return t;\n    }\n};\n\n"
  code: "// modint: mod \u8A08\u7B97\u3092 int \u3092\u6271\u3046\u3088\u3046\u306B\
    \u6271\u3048\u308B\u69CB\u9020\u4F53\ntemplate<int MOD> struct Fp {\n    long\
    \ long val;\n    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {\n   \
    \     if (val < 0) val += MOD;\n    }\n    constexpr int getmod() { return MOD;\
    \ }\n    constexpr Fp operator - () const noexcept {\n        return val ? MOD\
    \ - val : 0;\n    }\n    constexpr Fp operator + (const Fp& r) const noexcept\
    \ { return Fp(*this) += r; }\n    constexpr Fp operator - (const Fp& r) const\
    \ noexcept { return Fp(*this) -= r; }\n    constexpr Fp operator * (const Fp&\
    \ r) const noexcept { return Fp(*this) *= r; }\n    constexpr Fp operator / (const\
    \ Fp& r) const noexcept { return Fp(*this) /= r; }\n    constexpr Fp& operator\
    \ += (const Fp& r) noexcept {\n        val += r.val;\n        if (val >= MOD)\
    \ val -= MOD;\n        return *this;\n    }\n    constexpr Fp& operator -= (const\
    \ Fp& r) noexcept {\n        val -= r.val;\n        if (val < 0) val += MOD;\n\
    \        return *this;\n    }\n    constexpr Fp& operator *= (const Fp& r) noexcept\
    \ {\n        val = val * r.val % MOD;\n        return *this;\n    }\n    constexpr\
    \ Fp& operator /= (const Fp& r) noexcept {\n        long long a = r.val, b = MOD,\
    \ u = 1, v = 0;\n        while (b) {\n            long long t = a / b;\n     \
    \       a -= t * b; swap(a, b);\n            u -= t * v; swap(u, v);\n       \
    \ }\n        val = val * u % MOD;\n        if (val < 0) val += MOD;\n        return\
    \ *this;\n    }\n    constexpr bool operator == (const Fp& r) const noexcept {\n\
    \        return this->val == r.val;\n    }\n    constexpr bool operator != (const\
    \ Fp& r) const noexcept {\n        return this->val != r.val;\n    }\n    friend\
    \ constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {\n\
    \        return os << x.val;\n    }\n    friend constexpr Fp<MOD> modpow(const\
    \ Fp<MOD> &a, long long n) noexcept {\n        if (n == 0) return 1;\n       \
    \ auto t = modpow(a, n / 2);\n        t = t * t;\n        if (n & 1) t = t * a;\n\
    \        return t;\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Mod/mint.hpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Combination/combination.test.cpp
documentation_of: Math/Mod/mint.hpp
layout: document
title: "modint / modint\u69CB\u9020\u4F53"
---

## 概要
$\pmod{m}$の世界での四則演算を行う構造体です

[参考](https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/modint.cpp)

[実行時に法が決まるやつ](https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/modint_runtime.cpp)

## 制約
- 逆元が存在しない場合に割り算をするとバグります
- 実行する前に法を決めておく必要があります

## 使い方
`using`で`mint`を定義すると使いやすいです

```cpp
using mint = Fp<11>;

int main(){
    mint a = 5;
    mint b = 9;
    mint c = a + b;
    cout << c << endl; // 3
}
```
