---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Uncategorized/date.hpp\"\n/*1\u5E741\u67081\u65E5\u304B\u3089\
    \u306E\u7D4C\u904E\u65E5\u6570(1\u5E741\u67081\u65E5\u304C0\u65E5\u76EE)*/\nint\
    \ days(int y,int m,int d){\n    if(m==1||m==2){\n        m+=12;\n        y--;\n\
    \    }\n    return 365*y+y/4-y/100+y/400+(306*(m+1))/10+d-429;\n}\n\n/*\u66DC\u65E5\
    \u8A08\u7B97*/\nint wday(int y,int m,int d){\n    if(m==1||m==2){\n        m+=12;\n\
    \        y--;\n    }\n    return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;\n    //0,1,2,...\u65E5\
    ,\u6708,\u706B\n}\n\n"
  code: "/*1\u5E741\u67081\u65E5\u304B\u3089\u306E\u7D4C\u904E\u65E5\u6570(1\u5E74\
    1\u67081\u65E5\u304C0\u65E5\u76EE)*/\nint days(int y,int m,int d){\n    if(m==1||m==2){\n\
    \        m+=12;\n        y--;\n    }\n    return 365*y+y/4-y/100+y/400+(306*(m+1))/10+d-429;\n\
    }\n\n/*\u66DC\u65E5\u8A08\u7B97*/\nint wday(int y,int m,int d){\n    if(m==1||m==2){\n\
    \        m+=12;\n        y--;\n    }\n    return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;\n\
    \    //0,1,2,...\u65E5,\u6708,\u706B\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: Uncategorized/date.hpp
  requiredBy: []
  timestamp: '2023-11-13 23:35:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Uncategorized/date.hpp
layout: document
title: "date count / 1\u5E741\u67081\u65E5\u304B\u3089\u306E\u65E5\u6570\u3092\u8A08\
  \u7B97\u3059\u308B"
---

## 概要
1年1月1日からの経過日数(1年1月1日が0日目)を計算します

