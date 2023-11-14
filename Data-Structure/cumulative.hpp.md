---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \    }\n    return in;\n}\n\n#line 2 \"Data-Structure/cumulative.hpp\"\n\ntemplate<class\
    \ T> struct CumulativeSum{\n    size_t n;\n    vector<T> A;\n    CumulativeSum(size_t\
    \ n){\n        this->n=n;\n        init();\n    };\n    void init(){\n       \
    \ A.resize(n+1);\n    }\n    void add(int i,T x){\n        A[i+1]=x;\n    }\n\
    \    void build(){\n        for(int i=0;i<n;i++){\n            A[i+1]+=A[i];\n\
    \        }\n    }\n    /*[l,r)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B*/\n \
    \   T query(int l,int r){\n        return A[r]-A[l];\n    }\n};\n"
  code: "# include \"templete.hpp\"\n\ntemplate<class T> struct CumulativeSum{\n \
    \   size_t n;\n    vector<T> A;\n    CumulativeSum(size_t n){\n        this->n=n;\n\
    \        init();\n    };\n    void init(){\n        A.resize(n+1);\n    }\n  \
    \  void add(int i,T x){\n        A[i+1]=x;\n    }\n    void build(){\n       \
    \ for(int i=0;i<n;i++){\n            A[i+1]+=A[i];\n        }\n    }\n    /*[l,r)\u306E\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B*/\n    T query(int l,int r){\n        return\
    \ A[r]-A[l];\n    }\n};\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Data-Structure/cumulative.hpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data-Structure/cumulative.hpp
layout: document
redirect_from:
- /library/Data-Structure/cumulative.hpp
- /library/Data-Structure/cumulative.hpp.html
title: Data-Structure/cumulative.hpp
---
