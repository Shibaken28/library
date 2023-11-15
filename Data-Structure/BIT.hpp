# include "templete.hpp"

// Binary Indexed Tree
template<typename T> struct BinaryIndexedTree{
    // 1-indexed
    size_t n;
    vector<T> A;
    BinaryIndexedTree(size_t n){
        this->n=n;
        init();
    };
    void init(){
        A.resize(n+1);
        for(int i=0;i<=n;i++){
            A[i]=0;
        }
    }
    // 一点加算と区間和
    void add(int i,T x){
        while(i<=n){
            A[i]+=x;
            i+=i&-i;
        }
    }
    T query(int i){
        T res=0;
        while(i>0){
            res+=A[i];
            i-=i&-i;
        }
        return res;
    }
    // [l,r]の総和を求める
    T query(int l,int r){
        return query(r)-query(l-1);
    }
};