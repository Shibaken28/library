# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_E"
# include <iostream>
# include "combination.hpp"
# include "../Mod/mint.hpp"

using mint = Fp<1000000007>;

int main(){
    Combination<mint> comb(1010);
    int n,k;cin>>n>>k;
    cout<<comb.com(k,n)<<endl;
    return 0;
}
