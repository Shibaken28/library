---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C
  bundledCode: "#line 1 \"random.cpp\"\n#line 1 \"Graph/LCA.test.cpp\"\n# define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C\"\n# include\
    \ <iostream>\n#line 1 \"Graph/LCA.hpp\"\n# include <vector>\nusing namespace std;\n\
    \n\nstruct Edge{\n    int to;\n};\n\nusing Graph = vector<vector<Edge>>;\n\nstruct\
    \ LCA{\n    Graph G;\n    vector<vector<int>> ancestor;\n    //ancestor[i][j]:=\u9802\
    \u70B9i\u306E2^j\u500B\u89AA\n    vector<int> depth;//\u6DF1\u3055\n    int N;\n\
    \    int root = 0;\n    const int maxDepth = 25;\n    LCA(int _N){\n        this->\
    \ N = _N;\n        init();\n    }\n    void init(){\n        G.resize(N);\n  \
    \      depth.resize(N);\n        ancestor.resize(N);\n        for(int i=0;i<N;i++){\n\
    \            ancestor[i].resize(maxDepth);\n        }\n    }\n    void build(){\n\
    \        ancestor[root][0] = root;\n        bfs(root,root,0);\n        for(int\
    \ i=1;i<maxDepth;i++){\n            for(int j=0;j<N;j++){\n                ancestor[j][i]\
    \ = ancestor[ancestor[j][i-1]][i-1];\n            }\n        }\n    }\n    void\
    \ bfs(int n,int pre,int d){\n        depth[n] = d;\n        ancestor[n][0] = pre;\n\
    \        for(auto&E:G[n]){\n            if(E.to==pre)continue;\n            bfs(E.to,n,d+1);\n\
    \        }\n    }\n    //\u9802\u70B9n\u306Es\u500B\u5148\u306E\u7956\u5148\n\
    \    int anc(int n,int s){\n        for(int i=0;i<maxDepth;i++){\n           \
    \ if(s&(1<<i)){\n                n = ancestor[n][i];\n            }\n        }\n\
    \        return n;\n    }\n    //\u9802\u70B9n\u306E\u6DF1\u3055s(root=0)\u306E\
    \u7956\u5148\n    int levelAnc(int n,int s){\n        return anc(n,depth[n]-s);\n\
    \    }\n    //\u9802\u70B9a,b\u306E\u5171\u901A\u6700\u8FD1\u7956\u5148\n    int\
    \ lca(int a,int b){\n        if(depth[a]<depth[b])swap(a,b);\n        a = levelAnc(a,depth[b]);//\u540C\
    \u3058\u6DF1\u3055\u306B\u3059\u308B\n        if(a==b)return a;\n        for(int\
    \ k=maxDepth-1;k>=0;k--){\n            if(ancestor[a][k]!=ancestor[b][k]){\n \
    \               a = ancestor[a][k];\n                b = ancestor[b][k];\n   \
    \         }\n        }\n        return ancestor[a][0];\n    }\n};\n#line 4 \"\
    Graph/LCA.test.cpp\"\nusing namespace std;\n\nint main(){\n    int n;cin>>n;\n\
    \    LCA lca(n);\n    for(int i=0;i<n;i++){\n        int k;cin>>k;\n        for(int\
    \ j=0;j<k;j++){\n            int c;cin>>c;\n            lca.G[c].push_back({i});\n\
    \            lca.G[i].push_back({c});\n        }\n    }\n    lca.build();\n  \
    \  int q;cin>>q;\n    for(int i=0;i<q;i++){\n        int u,v;cin>>u>>v;\n    \
    \    cout<<lca.lca(u,v)<<endl;\n    }\n}\n"
  code: "#line 1 \"Graph/LCA.test.cpp\"\n# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C\"\
    \n# include <iostream>\n#line 1 \"Graph/LCA.hpp\"\n# include <vector>\nusing namespace\
    \ std;\n\n\nstruct Edge{\n    int to;\n};\n\nusing Graph = vector<vector<Edge>>;\n\
    \nstruct LCA{\n    Graph G;\n    vector<vector<int>> ancestor;\n    //ancestor[i][j]:=\u9802\
    \u70B9i\u306E2^j\u500B\u89AA\n    vector<int> depth;//\u6DF1\u3055\n    int N;\n\
    \    int root = 0;\n    const int maxDepth = 25;\n    LCA(int _N){\n        this->\
    \ N = _N;\n        init();\n    }\n    void init(){\n        G.resize(N);\n  \
    \      depth.resize(N);\n        ancestor.resize(N);\n        for(int i=0;i<N;i++){\n\
    \            ancestor[i].resize(maxDepth);\n        }\n    }\n    void build(){\n\
    \        ancestor[root][0] = root;\n        bfs(root,root,0);\n        for(int\
    \ i=1;i<maxDepth;i++){\n            for(int j=0;j<N;j++){\n                ancestor[j][i]\
    \ = ancestor[ancestor[j][i-1]][i-1];\n            }\n        }\n    }\n    void\
    \ bfs(int n,int pre,int d){\n        depth[n] = d;\n        ancestor[n][0] = pre;\n\
    \        for(auto&E:G[n]){\n            if(E.to==pre)continue;\n            bfs(E.to,n,d+1);\n\
    \        }\n    }\n    //\u9802\u70B9n\u306Es\u500B\u5148\u306E\u7956\u5148\n\
    \    int anc(int n,int s){\n        for(int i=0;i<maxDepth;i++){\n           \
    \ if(s&(1<<i)){\n                n = ancestor[n][i];\n            }\n        }\n\
    \        return n;\n    }\n    //\u9802\u70B9n\u306E\u6DF1\u3055s(root=0)\u306E\
    \u7956\u5148\n    int levelAnc(int n,int s){\n        return anc(n,depth[n]-s);\n\
    \    }\n    //\u9802\u70B9a,b\u306E\u5171\u901A\u6700\u8FD1\u7956\u5148\n    int\
    \ lca(int a,int b){\n        if(depth[a]<depth[b])swap(a,b);\n        a = levelAnc(a,depth[b]);//\u540C\
    \u3058\u6DF1\u3055\u306B\u3059\u308B\n        if(a==b)return a;\n        for(int\
    \ k=maxDepth-1;k>=0;k--){\n            if(ancestor[a][k]!=ancestor[b][k]){\n \
    \               a = ancestor[a][k];\n                b = ancestor[b][k];\n   \
    \         }\n        }\n        return ancestor[a][0];\n    }\n};\n#line 4 \"\
    Graph/LCA.test.cpp\"\nusing namespace std;\n\nint main(){\n    int n;cin>>n;\n\
    \    LCA lca(n);\n    for(int i=0;i<n;i++){\n        int k;cin>>k;\n        for(int\
    \ j=0;j<k;j++){\n            int c;cin>>c;\n            lca.G[c].push_back({i});\n\
    \            lca.G[i].push_back({c});\n        }\n    }\n    lca.build();\n  \
    \  int q;cin>>q;\n    for(int i=0;i<q;i++){\n        int u,v;cin>>u>>v;\n    \
    \    cout<<lca.lca(u,v)<<endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: random.cpp
  requiredBy: []
  timestamp: '2023-11-13 23:35:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random.cpp
layout: document
redirect_from:
- /library/random.cpp
- /library/random.cpp.html
title: random.cpp
---
