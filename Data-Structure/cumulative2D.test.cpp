# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_5_B"
# include "cumulative2D.hpp"

int main(){
    int N;cin>>N;
    int M = 1000;
    CumulativeSum2D<long> cum(M,M);
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        cum.add(y1,x1,y2,x2,1);
    }
    // 一番大きい値を探す
    long ans=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            chmax(ans,cum.sum(i,j));
        }
    }
    cout << ans << endl;
}
