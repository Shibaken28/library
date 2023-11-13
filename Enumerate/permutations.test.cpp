# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/5/ITP2_5_D"
# include <iostream>
# include "permutations.hpp"
using namespace std;

int main(){
    int n; cin>>n;
    auto A=permutations(n);
    for(auto a:A){
        for(int i=0;i<n;i++){
            if(i)cout<<" ";
            cout<<a[i]+1;
        }
        cout<<endl;
    }
}
