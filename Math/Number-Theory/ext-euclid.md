---
title: Extended Euclidean algorithm / 拡張ユークリッドの互除法
documentation_of: ./ext-euclid.hpp
---

## 概要
$ax + by = \mathrm{gcd} (a, b)$ を満たす $x, y$ を求めます。$|x| + |y|$ が最小で、$x\leq y$ となるように $x, y$ を求めます。

## 計算量
$O(\log \min(a, b))$

