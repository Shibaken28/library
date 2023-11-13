# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"
# include <iostream>
# include "modpow.hpp"

using namespace std;

int main(){
    int a,b; cin>>a>>b;
    cout << modpow(a,b,1000000007) << endl;
}
