# define PROBLEM "https://yukicoder.me/problems/447"
# include <iostream>
# include "CRT.hpp"
# include "GCD.hpp"
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
        if(r==0){
            vector<long> A = {X[0].second,X[1].second,X[2].second};
            cout << LCM(A) << endl;
        }else{
            cout << r << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}