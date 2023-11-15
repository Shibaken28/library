#line 1 "Data-Structure/BIT.test.cpp"
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

#line 2 "Data-Structure/BIT.hpp"

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
#line 3 "Data-Structure/BIT.test.cpp"

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

