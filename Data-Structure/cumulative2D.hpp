# include "templete.hpp"


template<class T> struct CumulativeSum2D{
    size_t H,W;
    vector<vector<T>>data,A;
    bool isBuild=false;
    CumulativeSum2D(size_t H,size_t W){
        this->H=H;
        this->W=W;
        data.resize(H+1,vector<T>(W+1,0));
        A.resize(H+1,vector<T>(W+1,0));
    }
    void add(int y1,int x1,int y2,int x2,T x){
        A[y1][x1]+=x;
        A[y2][x1]-=x;
        A[y1][x2]-=x;
        A[y2][x2]+=x;
    }
    void add(int y1,int x1,T x){
        add(y1,x1,y1+1,x1+1,x);
    }

    void build(){
        data=vector<vector<T>>(A.size()+1,vector<T>(A.front().size()+1,0));
        
        for(int _=0; _<2; _++){
            for(size_t i=0; i<=H; i++){
                for(size_t j=0; j<W; j++){
                    A[i][j+1]+=A[i][j];
                }
            }
            for(size_t i=0; i<H; i++){
                for(size_t j=0; j<=W; j++){
                    A[i+1][j]+=A[i][j];
                }
            }
        }

        for(size_t i=0; i<=H; i++){
            for(size_t j=0; j<=W; j++){
                data[i+1][j+1]=A[i][j];
            }
        }

        isBuild=true;
    }
    /*w1<=x<w2, h1<=y<h2*/
    T sum(int h1,int w1,int h2,int w2){
        if(!isBuild)build();
        return data[h2][w2]-data[h1][w2]-data[h2][w1]+data[h1][w1];
    }
    // 1“_‚Ì’l‚ð•Ô‚·
    T sum(int h1,int w1){
        return sum(h1,w1,h1+1,w1+1);
    }
};
