---
title: Lowest Common Ancestor / 最小共通祖先 
documentation_of: ./LCA.hpp
---

## 概要
木構造に対して、2頂点の最小共通祖先を求めるデータ構造です

## 使い方
- `LCA(n)` : 頂点数`n`に設定します
- `G` : 隣接リストとして`G`に構築してください
- `build()` : `G`からLCAを構築します
- `anc(n,k)` : 頂点`n`の`k`個上の祖先を返します
- `lca(n,m)` : 頂点`n`と頂点`m`の最小共通祖先を返します
- `levelAnc(n,k)` : 頂点`n`の祖先で、深さが`k`のものを返します

## 計算量
- 頂点数 : $N$
- 構築(`build()`) : $O(N\log N)$
- その他のクエリ : $O(\log N)$
