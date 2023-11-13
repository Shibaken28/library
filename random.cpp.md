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
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"random.cpp\"\n# define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\
    \n# include <iostream>\nusing namespace std;\n\n# include <vector>\n# include\
    \ <set>\n# include <algorithm>\nusing namespace std;\n\nstruct primeSieve{\n \
    \   vector<long> mfactor;\n    //\u65E2\u77E5\u306E\u7D20\u6570(\u968F\u6642\u8FFD\
    \u52A0\u3055\u308C\u308B)\n    vector<long> primes;\n    set<long> primeSet;\n\
    \    long N;\n    primeSieve(){\n        N = 0;\n        calc();\n    }\n    primeSieve(long\
    \ N){\n        this-> N = N;\n        calc();\n    }\n    /*\n    \u7D20\u6570\
    \u7BE9\n    O(sqrt(N))\n    */\n    void calc(){\n        primes.clear();\n  \
    \      mfactor.resize(N+1);\n        fill(mfactor.begin(),mfactor.end(),-1);\n\
    \        mfactor[0] = 0;\n        mfactor[1] = 1;\n        for(long i=2;i<=N;i++){\n\
    \            if(mfactor[i] == -1){\n                for(long j=i;j<=N;j+=i){\n\
    \                    mfactor[j] = i;\n                }\n            }\n     \
    \   }\n        for(long i=2;i<=N;i++){\n            if(mfactor[i] == i){\n   \
    \             primes.push_back(i);\n                // primeSet.insert(i);\n \
    \           }\n        }\n    }\n    /*\n    \u7D20\u6570\u5224\u5B9A\n    O(1)\n\
    \    */\n    bool isPrime(long x){\n        if(x==1)return false;\n        if(x<=N)\
    \ return x == mfactor[x];\n        if(primeSet.count(x))return true;\n       \
    \ return isPrimeNaive(x);\n    }\n    /*\n    Naive\u7D20\u6570\u5224\u5B9A\n\
    \    O(sqrt(N))\n    */\n    bool isPrimeNaive(long x){\n        if(x<=1)return\
    \ false;\n        for(long i=2;i*i<=x;i++){\n            if(x%i==0){\n       \
    \         return false;\n            }\n        }\n        primes.push_back(x);\n\
    \        primeSet.insert(x);\n        return true;\n    }\n    /*\n    \u7D20\u56E0\
    \u6570\u5206\u89E3\n    O(log N)\n    */\n    vector<long> factorization(long\
    \ x){\n        if(x>N){\n            return factorizationNaive(x);\n        }\n\
    \        vector<long> A(0);\n        if(x==1){\n            A.push_back(1);\n\
    \            return A;\n        }\n        while(x>1){\n            A.push_back(mfactor[x]);\n\
    \            x /= mfactor[x];\n        }\n        reverse(A.begin(),A.end());\n\
    \        return A;\n    }\n    /*\n    Naive\u7D20\u56E0\u6570\u5206\u89E3\n \
    \   O(sqrt N)\n    */\n    vector<long> factorizationNaive(long x){\n        vector<long>\
    \ A(0);\n        for(long i=2;i*i<=x;){\n            if(x%i==0){\n           \
    \     x/=i;\n                A.push_back(i);\n            }else{\n           \
    \     i++;\n            }\n        }\n        if(x>1){\n            A.push_back(x);\n\
    \        }\n        return A;\n    }\n};\n\n\nprimeSieve ps(500000000);\n\nint\
    \ main(){\n    int N,A,B;\n    cin>>N>>A>>B;\n    ps.calc();\n    vector<int>\
    \ ans;\n    for(auto x:ps.primes){\n        if(x <= N)ans.push_back(x);\n    }\n\
    \    vector<int> ans2;\n    for(int i=B;i<(int)ans.size();i+=A){\n        ans2.push_back(ans[i]);\n\
    \    }\n    cout<<ans.size()<<\" \"<<ans2.size()<<endl;\n    for(int i=0;i<(int)ans2.size();i++){\n\
    \        cout<<ans2[i]<<(i+1==(int)ans2.size()?\"\\n\":\" \");\n    }\n}\n"
  code: "# define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n#\
    \ include <iostream>\nusing namespace std;\n\n# include <vector>\n# include <set>\n\
    # include <algorithm>\nusing namespace std;\n\nstruct primeSieve{\n    vector<long>\
    \ mfactor;\n    //\u65E2\u77E5\u306E\u7D20\u6570(\u968F\u6642\u8FFD\u52A0\u3055\
    \u308C\u308B)\n    vector<long> primes;\n    set<long> primeSet;\n    long N;\n\
    \    primeSieve(){\n        N = 0;\n        calc();\n    }\n    primeSieve(long\
    \ N){\n        this-> N = N;\n        calc();\n    }\n    /*\n    \u7D20\u6570\
    \u7BE9\n    O(sqrt(N))\n    */\n    void calc(){\n        primes.clear();\n  \
    \      mfactor.resize(N+1);\n        fill(mfactor.begin(),mfactor.end(),-1);\n\
    \        mfactor[0] = 0;\n        mfactor[1] = 1;\n        for(long i=2;i<=N;i++){\n\
    \            if(mfactor[i] == -1){\n                for(long j=i;j<=N;j+=i){\n\
    \                    mfactor[j] = i;\n                }\n            }\n     \
    \   }\n        for(long i=2;i<=N;i++){\n            if(mfactor[i] == i){\n   \
    \             primes.push_back(i);\n                // primeSet.insert(i);\n \
    \           }\n        }\n    }\n    /*\n    \u7D20\u6570\u5224\u5B9A\n    O(1)\n\
    \    */\n    bool isPrime(long x){\n        if(x==1)return false;\n        if(x<=N)\
    \ return x == mfactor[x];\n        if(primeSet.count(x))return true;\n       \
    \ return isPrimeNaive(x);\n    }\n    /*\n    Naive\u7D20\u6570\u5224\u5B9A\n\
    \    O(sqrt(N))\n    */\n    bool isPrimeNaive(long x){\n        if(x<=1)return\
    \ false;\n        for(long i=2;i*i<=x;i++){\n            if(x%i==0){\n       \
    \         return false;\n            }\n        }\n        primes.push_back(x);\n\
    \        primeSet.insert(x);\n        return true;\n    }\n    /*\n    \u7D20\u56E0\
    \u6570\u5206\u89E3\n    O(log N)\n    */\n    vector<long> factorization(long\
    \ x){\n        if(x>N){\n            return factorizationNaive(x);\n        }\n\
    \        vector<long> A(0);\n        if(x==1){\n            A.push_back(1);\n\
    \            return A;\n        }\n        while(x>1){\n            A.push_back(mfactor[x]);\n\
    \            x /= mfactor[x];\n        }\n        reverse(A.begin(),A.end());\n\
    \        return A;\n    }\n    /*\n    Naive\u7D20\u56E0\u6570\u5206\u89E3\n \
    \   O(sqrt N)\n    */\n    vector<long> factorizationNaive(long x){\n        vector<long>\
    \ A(0);\n        for(long i=2;i*i<=x;){\n            if(x%i==0){\n           \
    \     x/=i;\n                A.push_back(i);\n            }else{\n           \
    \     i++;\n            }\n        }\n        if(x>1){\n            A.push_back(x);\n\
    \        }\n        return A;\n    }\n};\n\n\nprimeSieve ps(500000000);\n\nint\
    \ main(){\n    int N,A,B;\n    cin>>N>>A>>B;\n    ps.calc();\n    vector<int>\
    \ ans;\n    for(auto x:ps.primes){\n        if(x <= N)ans.push_back(x);\n    }\n\
    \    vector<int> ans2;\n    for(int i=B;i<(int)ans.size();i+=A){\n        ans2.push_back(ans[i]);\n\
    \    }\n    cout<<ans.size()<<\" \"<<ans2.size()<<endl;\n    for(int i=0;i<(int)ans2.size();i++){\n\
    \        cout<<ans2[i]<<(i+1==(int)ans2.size()?\"\\n\":\" \");\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: random.cpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random.cpp
layout: document
redirect_from:
- /library/random.cpp
- /library/random.cpp.html
title: random.cpp
---
