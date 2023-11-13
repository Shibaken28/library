---
title: Floyd-Warshall algorithm / フロイドワーシャル法による全点対最短経路
documentation_of: ./Floyd-Warshall.hpp
---

## 概要
グラフで、全ての頂点間の最短経路を求めます。重みが負の辺があっても動作します。負閉路がある場合は、その旨を報告します。

## 計算量
頂点数$N$として、$O(N^3)$
