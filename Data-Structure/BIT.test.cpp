# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"
# include "BIT.hpp"

int main(){
    // 1-indexed
    int N,Q;cin>>N>>Q;
    BinaryIndexedTree<long> bit(N);
    for(int i=0;i<Q;i++){
        int c,x,y;cin>>c>>x>>y;
        if(c==0){
            bit.add(x,y);
        }else{
            cout<<bit.query(x,y)<<endl;
        }
    }
}

