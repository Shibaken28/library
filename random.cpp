#line 1 "Data-Structure/cumulative2D.test.cpp"
#line 2 "templete.hpp"

#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip>
#include <climits>
#include <cmath>
#include <functional>
#include <numeric>
#include <regex>
#include <array>
#include <fstream>
#include <sstream>


using namespace std;



template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> void printArray(vector<T>&A){
    for(T&a:A){
        cout<<a<<" ";
    }
    cout<<endl;
}
template<class T> void printArrayln(vector<T>&A){
    for(T&a:A){
        cout<<a<<endl;
    }
}


template<class T1,class T2> std::ostream &operator<<(std::ostream &out, const pair<T1,T2> &A){
    cout<<"{"<<A.first<<","<<A.second<<"}";
    return out;
}

template<class T1,class T2> std::ostream &operator<<(std::ostream &out, const map<T1,T2> &M){
    for(const auto&A:M){
        cout<<"{"<<A.first<<","<<A.second<<"}";
    }
    return out;
}

template<class T1> std::ostream &operator<<(std::ostream &out, const set<T1> &M){
    cout<<"{";
    for(const auto&A:M){
        cout<<A<<", ";
    }
    cout<<"}"<<endl;
    return out;
}


template<class T1> std::ostream &operator<<(std::ostream &out, const multiset<T1> &M){
    cout<<"{";
    for(const auto&A:M){
        cout<<A<<", ";
    }
    cout<<"}"<<endl;
    return out;
}

template<class T> std::ostream &operator<<(std::ostream &out, const vector<T> &A){
    for(const T &a:A){
        cout<<a<<" ";
    }
    return out;
}

void print() { cout << endl; }
 
template <typename Head, typename... Tail>
void print(Head H, Tail... T) {
  cout << H << " ";
  print(T...);
}


template<class T> std::istream &operator>>(std::istream &in,vector<T>&A){
    for(T&a:A){
        std::cin>>a;
    }
    return in;
}

#line 2 "Data-Structure/cumulative2D.hpp"


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
        A[y2+1][x1]-=x;
        A[y1][x2+1]-=x;
        A[y2+1][x2+1]+=x;
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
    // 1�_�̒l��Ԃ�
    T sum(int h1,int w1){
        return sum(h1,w1,h1+1,w1+1);
    }
};
#line 3 "Data-Structure/cumulative2D.test.cpp"

int main(){
    int N;cin>>N;
    int M = 2;
    CumulativeSum2D<long> cum(M,M);
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        cum.add(y1,x1,y2-1,x2-1,1);
    }
    // 一番大きい値を探す
    long ans=0;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            chmax(ans,cum.sum(i,j));
            cout << cum.sum(i,j)  << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
}
