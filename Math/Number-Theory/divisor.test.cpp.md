---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/divisor.hpp
    title: "divisors / \u7D04\u6570\u5217\u6319"
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
    \n# include <iostream>\n#line 1 \"Math/Number-Theory/divisor.hpp\"\n# include\
    \ <vector>\n# include <algorithm>\nusing namespace std;\n\n//\u7D04\u6570\u5217\
    \u6319\nvector<long> divisor(long x){\n    vector<long> f(0);\n    for(long i=1;i*i<=x;i++){\n\
    \        if(x%i==0){\n            f.push_back(i);\n            if(i!=x/i)f.push_back(x/i);\n\
    \        }\n    }\n    sort(f.begin(),f.end());\n    return f;\n}\n#line 4 \"\
    Math/Number-Theory/divisor.test.cpp\"\nusing namespace std;\n\nint main(){\n \
    \   long a,b,c;\n    cin >> a >> b >> c;\n    long ans = 0;\n    auto f = divisor(c);\n\
    \    for(auto x:f){\n        if(a<=x && x<=b)ans++;\n    }\n    cout << ans <<\
    \ endl;\n    return 0;\n}\n"
  code: "# define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja\"\
    \n# include <iostream>\n# include \"divisor.hpp\"\nusing namespace std;\n\nint\
    \ main(){\n    long a,b,c;\n    cin >> a >> b >> c;\n    long ans = 0;\n    auto\
    \ f = divisor(c);\n    for(auto x:f){\n        if(a<=x && x<=b)ans++;\n    }\n\
    \    cout << ans << endl;\n    return 0;\n}"
  dependsOn:
  - Math/Number-Theory/divisor.hpp
  isVerificationFile: true
  path: Math/Number-Theory/divisor.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 15:54:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Number-Theory/divisor.test.cpp
layout: document
redirect_from:
- /verify/Math/Number-Theory/divisor.test.cpp
- /verify/Math/Number-Theory/divisor.test.cpp.html
title: Math/Number-Theory/divisor.test.cpp
---
