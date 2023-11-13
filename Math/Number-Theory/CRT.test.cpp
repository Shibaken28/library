# define PROBLEM "https://yukicoder.me/problems/447"
# include <iostream>
# include "CRT.hpp"
using namespace std;

int main(){
    int N = 3;
    vector<pair<long,long>> X(N);
    for(int i=0;i<N;i++){
        cin >> X[i].first >> X[i].second;
    }
    long r,m;
    bool ok = CRT(X,r,m);
    if(ok){
        cout << r << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}