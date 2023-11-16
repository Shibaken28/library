---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Data-Structure/cumulative.hpp
    title: "cumulative sum / \u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: templete.hpp
    title: "templete / \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"Data-Structure/cumulative.test.cpp\"\n# define PROBLEM \"\
    https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2 \"templete.hpp\"\n\
    \n#include <iostream> // cout, endl, cin\n#include <string> // string, to_string,\
    \ stoi\n#include <vector> // vector\n#include <algorithm> // min, max, swap, sort,\
    \ reverse, lower_bound, upper_bound\n#include <utility> // pair, make_pair\n#include\
    \ <tuple> // tuple, make_tuple\n#include <cstdint> // int64_t, int*_t\n#include\
    \ <cstdio> // printf\n#include <map> // map\n#include <queue> // queue, priority_queue\n\
    #include <set> // set\n#include <stack> // stack\n#include <deque> // deque\n\
    #include <unordered_map> // unordered_map\n#include <unordered_set> // unordered_set\n\
    #include <bitset> // bitset\n#include <cctype> // isupper, islower, isdigit, toupper,\
    \ tolower\n#include <iomanip>\n#include <climits>\n#include <cmath>\n#include\
    \ <functional>\n#include <numeric>\n#include <regex>\n#include <array>\n#include\
    \ <fstream>\n#include <sstream>\n\n\nusing namespace std;\n\n\n\ntemplate<class\
    \ T> inline bool chmin(T& a, T b) {\n    if (a > b) {\n        a = b;\n      \
    \  return true;\n    }\n    return false;\n}\ntemplate<class T> inline bool chmax(T&\
    \ a, T b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n \
    \   return false;\n}\n\ntemplate<class T> void printArray(vector<T>&A){\n    for(T&a:A){\n\
    \        cout<<a<<\" \";\n    }\n    cout<<endl;\n}\ntemplate<class T> void printArrayln(vector<T>&A){\n\
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
    \ T> struct CumulativeSum{\n    // imos\u6CD5\u3068\u7D44\u307F\u5408\u308F\u305B\
    \u3066\u533A\u9593\u52A0\u7B97\u3092\u3057\u3066\u304B\u3089\u533A\u9593\u548C\
    \u3092\u6C42\u3081\u308B\n    size_t n;\n    vector<T> A;\n    bool isBuild=false;\n\
    \    CumulativeSum(size_t n){\n        this->n=n;\n        init();\n    };\n \
    \   void init(){\n        A.resize(n+1);\n    }\n    // [l,r)\u306Bx\u3092\u52A0\
    \u7B97\u3059\u308B\n    void add(int l,int r,T x){\n        l++;r++;\n       \
    \ A[l]+=x;\n        A[r]-=x;\n    }\n\n    // 1\u70B9\u52A0\u7B97\n    void add(int\
    \ i,T x){\n        add(i,i+1,x);\n    }\n\n    void build(){\n        // imos\u6CD5\
    \n        for(size_t i=0;i<n;i++){\n            A[i+1]+=A[i];\n        }\n   \
    \     // \u7D2F\u7A4D\u548C\n        for(size_t i=0;i<n;i++){\n            A[i+1]+=A[i];\n\
    \        }\n        isBuild=true;\n    }\n\n    /*[l,r)\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B*/\n    T query(int l,int r){\n        if(!isBuild)build();\n\
    \        return A[r]-A[l];\n    }\n};\n#line 3 \"Data-Structure/cumulative.test.cpp\"\
    \n\nint main(){\n    int N,Q;cin>>N>>Q;\n    vector<long> A(N);\n    for(auto&a:A)cin>>a;\n\
    \    CumulativeSum<long> cum(N);\n    for(int i=0;i<N;i++){\n        cum.add(i,A[i]);\n\
    \    }\n    for(int i=0;i<Q;i++){\n        int l,r;cin>>l>>r;\n        cout<<cum.query(l,r)<<endl;\n\
    \    }\n}\n\n"
  code: "# define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#\
    \ include \"cumulative.hpp\"\n\nint main(){\n    int N,Q;cin>>N>>Q;\n    vector<long>\
    \ A(N);\n    for(auto&a:A)cin>>a;\n    CumulativeSum<long> cum(N);\n    for(int\
    \ i=0;i<N;i++){\n        cum.add(i,A[i]);\n    }\n    for(int i=0;i<Q;i++){\n\
    \        int l,r;cin>>l>>r;\n        cout<<cum.query(l,r)<<endl;\n    }\n}\n\n"
  dependsOn:
  - Data-Structure/cumulative.hpp
  - templete.hpp
  isVerificationFile: true
  path: Data-Structure/cumulative.test.cpp
  requiredBy: []
  timestamp: '2023-11-16 00:45:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Data-Structure/cumulative.test.cpp
layout: document
redirect_from:
- /verify/Data-Structure/cumulative.test.cpp
- /verify/Data-Structure/cumulative.test.cpp.html
title: Data-Structure/cumulative.test.cpp
---
