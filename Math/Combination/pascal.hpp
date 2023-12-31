# include "templete.hpp"

struct Pascal{
    //tri[a][b] = aCb
    vector<vector<long>> tri;
    int N;
    Pascal(int N){
        this->N = N;
        init();
    }
    void init(){
        tri.clear();
        tri.push_back({1});
        for(int i=1;i<N;i++){
            vector<long> add(0);
            add.push_back(1);
            for(int k=0;k<i-1;k++){
                add.push_back(tri.back()[k]+tri.back()[k+1]);
            }
            add.push_back(1);
            tri.push_back(add);
        }
    }
    long com(int a,int b){
        if(a<b)return 0;
        return tri[a][b];
    }
};
