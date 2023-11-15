---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data-Structure/BIT.hpp
    title: "Binary Indexed Tree / Fenwick Tree / \u30D5\u30A7\u30CB\u30C3\u30AF\u6728"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
  bundledCode: "#line 1 \"Data-Structure/BIT.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n#line 2 \"templete.hpp\"\n\n#include <iostream> // cout, endl, cin\n#include\
    \ <string> // string, to_string, stoi\n#include <vector> // vector\n#include <algorithm>\
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
    \    }\n    return in;\n}\n\n#line 2 \"Data-Structure/BIT.hpp\"\n\n// Binary Indexed\
    \ Tree\ntemplate<typename T> struct BinaryIndexedTree{\n    // 1-indexed\n   \
    \ size_t n;\n    vector<T> A;\n    BinaryIndexedTree(size_t n){\n        this->n=n;\n\
    \        init();\n    };\n    void init(){\n        A.resize(n+1);\n        for(int\
    \ i=0;i<=n;i++){\n            A[i]=0;\n        }\n    }\n    // \u4E00\u70B9\u52A0\
    \u7B97\u3068\u533A\u9593\u548C\n    void add(int i,T x){\n        while(i<=n){\n\
    \            A[i]+=x;\n            i+=i&-i;\n        }\n    }\n    T query(int\
    \ i){\n        T res=0;\n        while(i>0){\n            res+=A[i];\n       \
    \     i-=i&-i;\n        }\n        return res;\n    }\n    // [l,r]\u306E\u7DCF\
    \u548C\u3092\u6C42\u3081\u308B\n    T query(int l,int r){\n        return query(r)-query(l-1);\n\
    \    }\n};\n#line 3 \"Data-Structure/BIT.test.cpp\"\n\nint main(){\n    // 1-indexed\n\
    \    int N,Q;cin>>N>>Q;\n    BinaryIndexedTree<long> bit(N);\n    for(int i=0;i<Q;i++){\n\
    \        int c,x,y;cin>>c>>x>>y;\n        if(c==0){\n            bit.add(x,y);\n\
    \        }else{\n            cout<<bit.query(x,y)<<endl;\n        }\n    }\n}\n\
    \n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n# include \"BIT.hpp\"\n\nint main(){\n    // 1-indexed\n    int N,Q;cin>>N>>Q;\n\
    \    BinaryIndexedTree<long> bit(N);\n    for(int i=0;i<Q;i++){\n        int c,x,y;cin>>c>>x>>y;\n\
    \        if(c==0){\n            bit.add(x,y);\n        }else{\n            cout<<bit.query(x,y)<<endl;\n\
    \        }\n    }\n}\n\n"
  dependsOn:
  - Data-Structure/BIT.hpp
  - templete.hpp
  isVerificationFile: true
  path: Data-Structure/BIT.test.cpp
  requiredBy: []
  timestamp: '2023-11-16 02:00:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data-Structure/BIT.test.cpp
layout: document
redirect_from:
- /verify/Data-Structure/BIT.test.cpp
- /verify/Data-Structure/BIT.test.cpp.html
title: Data-Structure/BIT.test.cpp
---
