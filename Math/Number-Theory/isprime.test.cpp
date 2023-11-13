# define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C&lang=ja"

# include <iostream>
# include "isprime.hpp"
using namespace std;

int main(){
    int n;cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(isPrime(x))ans++;
    }
    cout<<ans<<endl;
}

