---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Enumerate/permutations.hpp
    title: "enumerate permutations / \u9806\u5217\u5217\u6319"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D
  bundledCode: "#line 1 \"Enumerate/permutations.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D\"\
    \n# include <iostream>\n#line 2 \"templete.hpp\"\n\n#line 4 \"templete.hpp\"\n\
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
    \    }\n    return in;\n}\n\n#line 2 \"Enumerate/permutations.hpp\"\n\n// \u9806\
    \u5217\u5217\u6319\nvector<vector<int>> permutations(int N){\n    vector<int>\
    \ array(N);\n    vector<vector<int>> A(0);\n    for(int i=0;i<N;i++)array[i]=i;\n\
    \    do{\n        A.push_back(array);\n    }while(next_permutation(array.begin(),array.end()));\n\
    \    return A;\n}\n\n#line 4 \"Enumerate/permutations.test.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n    int n; cin>>n;\n    auto A=permutations(n);\n    for(auto\
    \ a:A){\n        for(int i=0;i<n;i++){\n            if(i)cout<<\" \";\n      \
    \      cout<<a[i]+1;\n        }\n        cout<<endl;\n    }\n}\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D\"\
    \n# include <iostream>\n# include \"permutations.hpp\"\nusing namespace std;\n\
    \nint main(){\n    int n; cin>>n;\n    auto A=permutations(n);\n    for(auto a:A){\n\
    \        for(int i=0;i<n;i++){\n            if(i)cout<<\" \";\n            cout<<a[i]+1;\n\
    \        }\n        cout<<endl;\n    }\n}\n"
  dependsOn:
  - Enumerate/permutations.hpp
  - templete.hpp
  isVerificationFile: true
  path: Enumerate/permutations.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Enumerate/permutations.test.cpp
layout: document
redirect_from:
- /verify/Enumerate/permutations.test.cpp
- /verify/Enumerate/permutations.test.cpp.html
title: Enumerate/permutations.test.cpp
---
