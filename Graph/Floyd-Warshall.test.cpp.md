---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/Floyd-Warshall.hpp
    title: "Floyd-Warshall algorithm / \u30D5\u30ED\u30A4\u30C9\u30EF\u30FC\u30B7\u30E3\
      \u30EB\u6CD5\u306B\u3088\u308B\u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  bundledCode: "#line 1 \"Graph/Floyd-Warshall.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
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
    \    }\n    return in;\n}\n\n#line 2 \"Graph/Floyd-Warshall.hpp\"\n\n/*\nG\u306F\
    \u96A3\u63A5\u884C\u5217\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308A\uFF0C\
    \u8FBA\u304C\u306A\u3044\u5834\u5408\u306FINF\uFF0C\u81EA\u5DF1\u30EB\u30FC\u30D7\
    \u8FBA\u306F0\n*/\nconst long INF = 1e17;\n\nvector<vector<long>> floydWarshall(vector<vector<long>>\
    \ &G){\n    const int N = G.size();\n    auto H = G;\n    for(int a=0;a<N;a++){\n\
    \        for(int b=0;b<N;b++){\n            for(int c=0;c<N;c++){\n          \
    \      long d = H[b][a] + H[a][c];\n                if(H[b][a]==INF||H[a][c]==INF)d\
    \ = INF;\n                if(H[b][c] > d){\n                    H[b][c] = d;\n\
    \                }\n            }\n        }\n    }\n    return H;\n}\n#line 4\
    \ \"Graph/Floyd-Warshall.test.cpp\"\nusing namespace std;\n\nint main(){\n   \
    \ int n,m;\n    cin >> n >> m;\n    vector<vector<long>> g(n,vector<long>(n,INF));\n\
    \    for(int i=0;i<n;i++)g[i][i] = 0;\n    for(int i=0;i<m;i++){\n        int\
    \ s,t,d;\n        cin >> s >> t >> d;\n        g[s][t] = d;\n    }\n    auto h\
    \ = floydWarshall(g);\n    for(int i=0;i<n;i++){\n        if(h[i][i] < 0){\n \
    \           cout << \"NEGATIVE CYCLE\" << endl;\n            return 0;\n     \
    \   }\n    }\n    for(int i=0;i<n;i++){\n        for(int j=0;j<n;j++){\n     \
    \       if(h[i][j] == INF)cout << \"INF\";\n            else cout << h[i][j];\n\
    \            if(j!=n-1)cout << \" \";\n        }\n        cout << endl;\n    }\n\
    }\n\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C\"\
    \n# include <iostream>\n# include \"Floyd-Warshall.hpp\"\nusing namespace std;\n\
    \nint main(){\n    int n,m;\n    cin >> n >> m;\n    vector<vector<long>> g(n,vector<long>(n,INF));\n\
    \    for(int i=0;i<n;i++)g[i][i] = 0;\n    for(int i=0;i<m;i++){\n        int\
    \ s,t,d;\n        cin >> s >> t >> d;\n        g[s][t] = d;\n    }\n    auto h\
    \ = floydWarshall(g);\n    for(int i=0;i<n;i++){\n        if(h[i][i] < 0){\n \
    \           cout << \"NEGATIVE CYCLE\" << endl;\n            return 0;\n     \
    \   }\n    }\n    for(int i=0;i<n;i++){\n        for(int j=0;j<n;j++){\n     \
    \       if(h[i][j] == INF)cout << \"INF\";\n            else cout << h[i][j];\n\
    \            if(j!=n-1)cout << \" \";\n        }\n        cout << endl;\n    }\n\
    }\n\n"
  dependsOn:
  - Graph/Floyd-Warshall.hpp
  - templete.hpp
  isVerificationFile: true
  path: Graph/Floyd-Warshall.test.cpp
  requiredBy: []
  timestamp: '2023-11-14 13:45:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Graph/Floyd-Warshall.test.cpp
layout: document
redirect_from:
- /verify/Graph/Floyd-Warshall.test.cpp
- /verify/Graph/Floyd-Warshall.test.cpp.html
title: Graph/Floyd-Warshall.test.cpp
---
