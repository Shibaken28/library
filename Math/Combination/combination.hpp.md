---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
  bundledCode: "#line 2 \"templete.hpp\"\n\n#include <iostream> // cout, endl, cin\n\
    #include <string> // string, to_string, stoi\n#include <vector> // vector\n#include\
    \ <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound\n#include\
    \ <utility> // pair, make_pair\n#include <tuple> // tuple, make_tuple\n#include\
    \ <cstdint> // int64_t, int*_t\n#include <cstdio> // printf\n#include <map> //\
    \ map\n#include <queue> // queue, priority_queue\n#include <set> // set\n#include\
    \ <stack> // stack\n#include <deque> // deque\n#include <unordered_map> // unordered_map\n\
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
    \ * finv[b] * finv[a-b];\n    }\n};\n\n"
  code: "# include \"templete.hpp\"\n\ntemplate<class T> struct Combination{\n   \
    \ int N;\n    vector<T> fac;//\u968E\u4E57\n    vector<T> finv;//\u968E\u4E57\u306E\
    \u9006\u5143\n    Combination(int N){\n        this->N = N;\n        init();\n\
    \    }\n    void init(){\n        fac.resize(N);\n        finv.resize(N);\n  \
    \      fac[0] = fac[1] = 1;\n        finv[0] = finv[1] = 1;\n        for(int i=2;i<N;i++){\n\
    \            fac[i] = fac[i-1] * i;\n            finv[i] = finv[i-1] / i;\n  \
    \      }\n    }\n    /*aCb\u306E\u8A08\u7B97*/\n    T com(int a,int b){\n    \
    \    if(a < b)return 0;\n        return fac[a] * finv[b] * finv[a-b];\n    }\n\
    };\n\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Math/Combination/combination.hpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Math/Combination/combination.test.cpp
documentation_of: Math/Combination/combination.hpp
layout: document
redirect_from:
- /library/Math/Combination/combination.hpp
- /library/Math/Combination/combination.hpp.html
title: Math/Combination/combination.hpp
---
