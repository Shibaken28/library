---
title: Kruskal's algorithm / クラスカル法による最小全域木
documentation_of: ./Kruskal.hpp
---

## 概要
最小全域木を求めます。

## 使い方
- `Kruskal(n)` : 頂点数`n`に設定します
- `addEdge(u,v,c)` : 頂点`u`と頂点`v`を結ぶ重み`c`の辺を追加します(無向辺)
- `build()` : 最小全域木を構築します

## 計算量
頂点数$N$、辺数$M$として、
- 構築(`build()`) : $O(N + M\log M)$
