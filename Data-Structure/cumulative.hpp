# include "templete.hpp"

template<class T> struct CumulativeSum{
    // imos法と組み合わせて区間加算をしてから区間和を求める
    size_t n;
    vector<T> A;
    bool isBuild=false;
    CumulativeSum(size_t n){
        this->n=n;
        init();
    };
    void init(){
        A.resize(n+1);
    }
    // [l,r)にxを加算する
    void add(int l,int r,T x){
        l++;r++;
        A[l]+=x;
        A[r]-=x;
    }

    // 1点加算
    void add(int i,T x){
        add(i,i+1,x);
    }

    void build(){
        // imos法
        for(size_t i=0;i<n;i++){
            A[i+1]+=A[i];
        }
        // 累積和
        for(size_t i=0;i<n;i++){
            A[i+1]+=A[i];
        }
        isBuild=true;
    }

    /*[l,r)の総和を求める*/
    T query(int l,int r){
        if(!isBuild)build();
        return A[r]-A[l];
    }
};
