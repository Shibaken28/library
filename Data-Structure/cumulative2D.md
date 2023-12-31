---
title: 2D cumulative sum / 2次元累積和
documentation_of: ./cumulative2D.hpp
---

## 概要
次の問題を解きます。
- $H \times W$のグリッドが与えられる。各マスの初期値は$0$である。
- $Q$個のクエリ$(x1_i, y1_i, x2_i, y2_i, x_i)$が与えられる。各クエリは、長方形の領域$[x1_i, x2_i) \times [y1_i, y2_i)$に$x_i$を加算することを意味する。
- $Q'$個のクエリ$(x1_i, y1_i, x2_i, y2_i)$が与えられる。各クエリは、長方形の領域$[x1_i, x2_i) \times [y1_i, y2_i)$の和を求めることを意味する。

## 注意
- 区間和のクエリは、すべての区間加算クエリを処理した後に行う必要がある。

## 計算量
- 各クエリの処理時間は$O(1)$である。
- 区間和のクエリの前準備として$O(HW)$の時間がかかる。
