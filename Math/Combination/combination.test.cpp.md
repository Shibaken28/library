---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Combination/combination.hpp
    title: Math/Combination/combination.hpp
  - icon: ':heavy_check_mark:'
    path: Math/Mod/mint.hpp
    title: "modint / modint\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_E
  bundledCode: "#line 1 \"Math/Combination/combination.test.cpp\"\n# define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_E\"\n# include\
    \ <iostream>\n#line 2 \"templete.hpp\"\n\n#line 4 \"templete.hpp\"\n#include <string>\
    \ // string, to_string, stoi\n#include <vector> // vector\n#include <algorithm>\
    \ // min, max, swap, sort, reverse, lower_bound, upper_bound\n#include <utility>\
    \ // pair, make_pair\n#include <tuple> // tuple, make_tuple\n#include <cstdint>\
    \ // int64_t, int*_t\n#include <cstdio> // printf\n#include <map> // map\n#include\
    \ <queue> // queue, priority_queue\n#include <set> // set\n#include <stack> //\
    \ stack\n#include <deque> // deque\n#include <unordered_map> // unordered_map\n\
    #include <unordered_set> // unordered_set\n#include <bitset> // bitset\n#include\
    \ <cctype> // isupper, islower, isdigit, toupper, tolower\n#include <iomanip>\n\
    #include <climits>\n#include <cmath>\n#include <functional>\n#include <numeric>\n\
    #include <regex>\n#include <array>\n#include <fstream>\n#include <sstream>\n\n\
    \nusing namespace std;\n\n\n\ntemplate<class T> inline bool chmin(T& a, T b) {\n\
    \    if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\ntemplate<class T> inline bool chmax(T& a, T b) {\n    if (a < b) {\n      \
    \  a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate<class\
    \ T> void printArray(vector<T>&A){\n    for(T&a:A){\n        cout<<a<<\" \";\n\
    \    }\n    cout<<endl;\n}\ntemplate<class T> void printArrayln(vector<T>&A){\n\
    \    for(T&a:A){\n        cout<<a<<endl;\n    }\n}\n\n\ntemplate<class T1,class\
    \ T2> std::ostream &operator<<(std::ostream &out, const pair<T1,T2> &A){\n   \
    \ cout<<\"{\"<<A.first<<\",\"<<A.second<<\"}\";\n    return out;\n}\n\ntemplate<class\
    \ T1,class T2> std::ostream &operator<<(std::ostream &out, const map<T1,T2> &M){\n\
    \    for(const auto&A:M){\n        cout<<\"{\"<<A.first<<\",\"<<A.second<<\"}\"\
    ;\n    }\n    return out;\n}\n\ntemplate<class T1> std::ostream &operator<<(std::ostream\
    \ &out, const set<T1> &M){\n    cout<<\"{\";\n    for(const auto&A:M){\n     \
    \   cout<<A<<\", \";\n    }\n    cout<<\"}\"<<endl;\n    return out;\n}\n\n\n\
    template<class T1> std::ostream &operator<<(std::ostream &out, const multiset<T1>\
    \ &M){\n    cout<<\"{\";\n    for(const auto&A:M){\n        cout<<A<<\", \";\n\
    \    }\n    cout<<\"}\"<<endl;\n    return out;\n}\n\ntemplate<class T> std::ostream\
    \ &operator<<(std::ostream &out, const vector<T> &A){\n    for(const T &a:A){\n\
    \        cout<<a<<\" \";\n    }\n    return out;\n}\n\nvoid print() { cout <<\
    \ endl; }\n \ntemplate <typename Head, typename... Tail>\nvoid print(Head H, Tail...\
    \ T) {\n  cout << H << \" \";\n  print(T...);\n}\n\n\ntemplate<class T> std::istream\
    \ &operator>>(std::istream &in,vector<T>&A){\n    for(T&a:A){\n        std::cin>>a;\n\
    \    }\n    return in;\n}\n\n#line 2 \"Math/Combination/combination.hpp\"\n\n\
    template<class T> struct Combination{\n    int N;\n    vector<T> fac;//\u968E\u4E57\
    \n    vector<T> finv;//\u968E\u4E57\u306E\u9006\u5143\n    Combination(int N){\n\
    \        this->N = N;\n        init();\n    }\n    void init(){\n        fac.resize(N);\n\
    \        finv.resize(N);\n        fac[0] = fac[1] = 1;\n        finv[0] = finv[1]\
    \ = 1;\n        for(int i=2;i<N;i++){\n            fac[i] = fac[i-1] * i;\n  \
    \          finv[i] = finv[i-1] / i;\n        }\n    }\n    /*aCb\u306E\u8A08\u7B97\
    */\n    T com(int a,int b){\n        if(a < b)return 0;\n        return fac[a]\
    \ * finv[b] * finv[a-b];\n    }\n};\n\n#line 1 \"Math/Mod/mint.hpp\"\n\n// modint:\
    \ mod \u8A08\u7B97\u3092 int \u3092\u6271\u3046\u3088\u3046\u306B\u6271\u3048\u308B\
    \u69CB\u9020\u4F53\ntemplate<int MOD> struct Fp {\n    long long val;\n    constexpr\
    \ Fp(long long v = 0) noexcept : val(v % MOD) {\n        if (val < 0) val += MOD;\n\
    \    }\n    constexpr int getmod() { return MOD; }\n    constexpr Fp operator\
    \ - () const noexcept {\n        return val ? MOD - val : 0;\n    }\n    constexpr\
    \ Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }\n    constexpr\
    \ Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }\n    constexpr\
    \ Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }\n    constexpr\
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
    \        return t;\n    }\n};\n\n#line 5 \"Math/Combination/combination.test.cpp\"\
    \n\nusing mint = Fp<1000000007>;\n\nint main(){\n    Combination<mint> comb(1010);\n\
    \    int n,k;cin>>n>>k;\n    cout<<comb.com(k,n)<<endl;\n    return 0;\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_E\"\
    \n# include <iostream>\n# include \"combination.hpp\"\n# include \"../Mod/mint.hpp\"\
    \n\nusing mint = Fp<1000000007>;\n\nint main(){\n    Combination<mint> comb(1010);\n\
    \    int n,k;cin>>n>>k;\n    cout<<comb.com(k,n)<<endl;\n    return 0;\n}\n"
  dependsOn:
  - Math/Combination/combination.hpp
  - templete.hpp
  - Math/Mod/mint.hpp
  isVerificationFile: true
  path: Math/Combination/combination.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Combination/combination.test.cpp
layout: document
redirect_from:
- /verify/Math/Combination/combination.test.cpp
- /verify/Math/Combination/combination.test.cpp.html
title: Math/Combination/combination.test.cpp
---
