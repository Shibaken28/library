---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \    }\n    return in;\n}\n\n#line 2 \"Uncategorized/date.hpp\"\n\n/*1\u5E741\u6708\
    1\u65E5\u304B\u3089\u306E\u7D4C\u904E\u65E5\u6570(1\u5E741\u67081\u65E5\u304C\
    0\u65E5\u76EE)*/\nint days(int y,int m,int d){\n    if(m==1||m==2){\n        m+=12;\n\
    \        y--;\n    }\n    return 365*y+y/4-y/100+y/400+(306*(m+1))/10+d-429;\n\
    }\n\n/*\u66DC\u65E5\u8A08\u7B97*/\nint wday(int y,int m,int d){\n    if(m==1||m==2){\n\
    \        m+=12;\n        y--;\n    }\n    return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;\n\
    \    //0,1,2,...\u65E5,\u6708,\u706B\n}\n\n"
  code: "# include \"templete.hpp\"\n\n/*1\u5E741\u67081\u65E5\u304B\u3089\u306E\u7D4C\
    \u904E\u65E5\u6570(1\u5E741\u67081\u65E5\u304C0\u65E5\u76EE)*/\nint days(int y,int\
    \ m,int d){\n    if(m==1||m==2){\n        m+=12;\n        y--;\n    }\n    return\
    \ 365*y+y/4-y/100+y/400+(306*(m+1))/10+d-429;\n}\n\n/*\u66DC\u65E5\u8A08\u7B97\
    */\nint wday(int y,int m,int d){\n    if(m==1||m==2){\n        m+=12;\n      \
    \  y--;\n    }\n    return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;\n    //0,1,2,...\u65E5\
    ,\u6708,\u706B\n}\n\n"
  dependsOn:
  - templete.hpp
  isVerificationFile: false
  path: Uncategorized/date.hpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Uncategorized/date.hpp
layout: document
title: "date count / 1\u5E741\u67081\u65E5\u304B\u3089\u306E\u65E5\u6570\u3092\u8A08\
  \u7B97\u3059\u308B"
---

## 概要
1年1月1日からの経過日数(1年1月1日が0日目)を計算します

