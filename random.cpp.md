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
    - https://yukicoder.me/problems/447
  bundledCode: "#line 1 \"random.cpp\"\n#line 1 \"Math/Number-Theory/CRT.test.cpp\"\
    \n# define PROBLEM \"https://yukicoder.me/problems/447\"\n# include <iostream>\n\
    #line 1 \"Math/Number-Theory/CRT.hpp\"\n# include <vector>\n# include <utility>\n\
    #line 1 \"Math/Number-Theory/ext-euclid.hpp\"\n// \u62E1\u5F35Euclid\u306E\u4E92\
    \u9664\u6CD5\n// ax + by = gcd(a, b) \u3068\u306A\u308B\u3088\u3046\u306A (x,\
    \ y) \u3092\u6C42\u3081\u308B \nlong extGCD(long a, long b, long &x, long &y)\
    \ {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n  \
    \  }\n    long d = extGCD(b, a%b, y, x);\n    y -= a/b * x;\n    return d;\n}\n\
    \n#line 4 \"Math/Number-Theory/CRT.hpp\"\nusing namespace std;\n\nlong mod(long\
    \ a,long m){\n    if(a>=0)return a%m; \n    return (m-(-a)%m)%m;\n}\n\n/*\n\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\n*/\nbool CRT(long b1, long m1, long b2, long m2,long\
    \ &r,long &m) {\n    long p, q;\n    long d = extGCD(m1, m2, p, q);\n    if ((b2\
    \ - b1) % d != 0) return false;\n    m = m1 * (m2/d); \n    long tmp = (b2 - b1)\
    \ / d * p % (m2/d);\n    r = mod(b1 + m1 * tmp, m);\n    return true;\n}\n\nbool\
    \ CRT(const vector<pair<long,long>> &X,long &r,long &m) {\n    int s = X.size();\n\
    \    r = X.front().first;\n    m = X.front().second;\n    bool ok = true;\n  \
    \  for(int i=1;i<s;i++){\n        ok = CRT(r,m,X[i].first,X[i].second,r,m);\n\
    \        if(!ok){\n            break;\n        }\n    }\n    return ok;\n}\n\n\
    #line 4 \"Math/Number-Theory/CRT.test.cpp\"\nusing namespace std;\n\nint main(){\n\
    \    int N = 3;\n    vector<pair<long,long>> X(N);\n    for(int i=0;i<N;i++){\n\
    \        cin >> X[i].first >> X[i].second;\n    }\n    long r,m;\n    bool ok\
    \ = CRT(X,r,m);\n    if(ok){\n        cout << r << endl;\n    }else{\n       \
    \ cout << -1 << endl;\n    }\n    return 0;\n}\n"
  code: "#line 1 \"Math/Number-Theory/CRT.test.cpp\"\n# define PROBLEM \"https://yukicoder.me/problems/447\"\
    \n# include <iostream>\n#line 1 \"Math/Number-Theory/CRT.hpp\"\n# include <vector>\n\
    # include <utility>\n#line 1 \"Math/Number-Theory/ext-euclid.hpp\"\n// \u62E1\u5F35\
    Euclid\u306E\u4E92\u9664\u6CD5\n// ax + by = gcd(a, b) \u3068\u306A\u308B\u3088\
    \u3046\u306A (x, y) \u3092\u6C42\u3081\u308B \nlong extGCD(long a, long b, long\
    \ &x, long &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return\
    \ a;\n    }\n    long d = extGCD(b, a%b, y, x);\n    y -= a/b * x;\n    return\
    \ d;\n}\n\n#line 4 \"Math/Number-Theory/CRT.hpp\"\nusing namespace std;\n\nlong\
    \ mod(long a,long m){\n    if(a>=0)return a%m; \n    return (m-(-a)%m)%m;\n}\n\
    \n/*\n\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\n*/\nbool CRT(long b1, long m1, long\
    \ b2, long m2,long &r,long &m) {\n    long p, q;\n    long d = extGCD(m1, m2,\
    \ p, q);\n    if ((b2 - b1) % d != 0) return false;\n    m = m1 * (m2/d); \n \
    \   long tmp = (b2 - b1) / d * p % (m2/d);\n    r = mod(b1 + m1 * tmp, m);\n \
    \   return true;\n}\n\nbool CRT(const vector<pair<long,long>> &X,long &r,long\
    \ &m) {\n    int s = X.size();\n    r = X.front().first;\n    m = X.front().second;\n\
    \    bool ok = true;\n    for(int i=1;i<s;i++){\n        ok = CRT(r,m,X[i].first,X[i].second,r,m);\n\
    \        if(!ok){\n            break;\n        }\n    }\n    return ok;\n}\n\n\
    #line 4 \"Math/Number-Theory/CRT.test.cpp\"\nusing namespace std;\n\nint main(){\n\
    \    int N = 3;\n    vector<pair<long,long>> X(N);\n    for(int i=0;i<N;i++){\n\
    \        cin >> X[i].first >> X[i].second;\n    }\n    long r,m;\n    bool ok\
    \ = CRT(X,r,m);\n    if(ok){\n        cout << r << endl;\n    }else{\n       \
    \ cout << -1 << endl;\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: random.cpp
  requiredBy: []
  timestamp: '2023-11-13 16:15:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random.cpp
layout: document
redirect_from:
- /library/random.cpp
- /library/random.cpp.html
title: random.cpp
---
