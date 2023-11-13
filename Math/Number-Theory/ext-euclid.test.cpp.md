---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/Number-Theory/ext-euclid.hpp
    title: "Extended Euclidean algorithm / \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
      \u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"Math/Number-Theory/ext-euclid.test.cpp\"\n# define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\n# include\
    \ <iostream>\n#line 1 \"Math/Number-Theory/ext-euclid.hpp\"\n// \u62E1\u5F35Euclid\u306E\
    \u4E92\u9664\u6CD5\n// ax + by = gcd(a, b) \u3068\u306A\u308B\u3088\u3046\u306A\
    \ (x, y) \u3092\u6C42\u3081\u308B \nlong extGCD(long a, long b, long &x, long\
    \ &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n        return a;\n\
    \    }\n    long d = extGCD(b, a%b, y, x);\n    y -= a/b * x;\n    return d;\n\
    }\n#line 4 \"Math/Number-Theory/ext-euclid.test.cpp\"\nusing namespace std;\n\n\
    int main(){\n    long a,b;\n    cin >> a >> b;\n    long x,y;\n    extGCD(a,b,x,y);\n\
    \    cout << x << \" \" << y << endl;\n}\n\n"
  code: "# define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n# include <iostream>\n# include \"ext-euclid.hpp\"\nusing namespace std;\n\n\
    int main(){\n    long a,b;\n    cin >> a >> b;\n    long x,y;\n    extGCD(a,b,x,y);\n\
    \    cout << x << \" \" << y << endl;\n}\n\n"
  dependsOn:
  - Math/Number-Theory/ext-euclid.hpp
  isVerificationFile: true
  path: Math/Number-Theory/ext-euclid.test.cpp
  requiredBy: []
  timestamp: '2023-11-13 23:35:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Math/Number-Theory/ext-euclid.test.cpp
layout: document
redirect_from:
- /verify/Math/Number-Theory/ext-euclid.test.cpp
- /verify/Math/Number-Theory/ext-euclid.test.cpp.html
title: Math/Number-Theory/ext-euclid.test.cpp
---
