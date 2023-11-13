# define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
# include <iostream>
# include "UnionFind.hpp"
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    while(q--){
        int com,x,y;
        cin >> com >> x >> y;
        if(com==0){
            uf.unite(x,y);
        }else{
            cout << uf.same(x,y) << endl;
        }
    }
}
