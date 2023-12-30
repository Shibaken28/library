# define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
using namespace std;
# include <iostream>
# include "../Mod/mint.hpp"
# include "Matrix.hpp"

using mint = Fp<998244353>;

int main(){
    int n,m,k;cin>>n>>m>>k;
    Matrix<mint> A(n,m),B(m,k);
    for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>A.val[i][j].val;
    for(int i=0;i<m;++i)for(int j=0;j<k;++j)cin>>B.val[i][j].val;
    auto C=A*B;
    for(int i=0;i<n;++i){
        for(int j=0;j<k;++j){
            cout<<(j?" ":"")<<C.val[i][j].val;
        }
        cout<<endl;
    }
    return 0;
}

