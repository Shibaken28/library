# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_C"

# include <iostream>
# include <vector>
# include "GCD.hpp"
using namespace std;

int main(){
    int n;cin>>n;
    vector<long>A(n);
    for(auto&a:A)cin>>a;
    cout<<LCM(A)<<endl;
}

