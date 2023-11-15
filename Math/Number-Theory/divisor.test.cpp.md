---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/divisor.hpp
    title: "divisors / \u7D04\u6570\u5217\u6319"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja
  bundledCode: "#line 1 \"Math/Number-Theory/divisor.test.cpp\"\n# define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja\"\
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
    \    }\n    return in;\n}\n\n#line 2 \"Math/Number-Theory/divisor.hpp\"\n\n//\u7D04\
    \u6570\u5217\u6319\nvector<long> divisor(long x){\n    vector<long> f(0);\n  \
    \  for(long i=1;i*i<=x;i++){\n        if(x%i==0){\n            f.push_back(i);\n\
    \            if(i!=x/i)f.push_back(x/i);\n        }\n    }\n    sort(f.begin(),f.end());\n\
    \    return f;\n}\n#line 4 \"Math/Number-Theory/divisor.test.cpp\"\nusing namespace\
    \ std;\n\nint main(){\n    long a,b,c;\n    cin >> a >> b >> c;\n    long ans\
    \ = 0;\n    auto f = divisor(c);\n    for(auto x:f){\n        if(a<=x && x<=b)ans++;\n\
    \    }\n    cout << ans << endl;\n    return 0;\n}\n"
  code: "# define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja\"\
    \n# include <iostream>\n# include \"divisor.hpp\"\nusing namespace std;\n\nint\
    \ main(){\n    long a,b,c;\n    cin >> a >> b >> c;\n    long ans = 0;\n    auto\
    \ f = divisor(c);\n    for(auto x:f){\n        if(a<=x && x<=b)ans++;\n    }\n\
    \    cout << ans << endl;\n    return 0;\n}"
  dependsOn:
  - Math/Number-Theory/divisor.hpp
  - templete.hpp
  isVerificationFile: true
  path: Math/Number-Theory/divisor.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Number-Theory/divisor.test.cpp
layout: document
redirect_from:
- /verify/Math/Number-Theory/divisor.test.cpp
- /verify/Math/Number-Theory/divisor.test.cpp.html
title: Math/Number-Theory/divisor.test.cpp
---
