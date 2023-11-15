# define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
# include "cumulative.hpp"

int main(){
    int N,Q;cin>>N>>Q;
    vector<long> A(N);
    for(auto&a:A)cin>>a;
    CumulativeSum<long> cum(N);
    for(int i=0;i<N;i++){
        cum.add(i,A[i]);
    }
    for(int i=0;i<Q;i++){
        int l,r;cin>>l>>r;
        cout<<cum.query(l,r)<<endl;
    }
}

