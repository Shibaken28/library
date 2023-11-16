#line 1 "Graph/SCC.test.cpp"
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

#line 2 "Graph/SCC.hpp"

using Graph = vector<vector<int>>;
struct StronglyConnectedComponents{
    Graph &G;
    Graph invG;
    vector<int> ord, inv;
    vector<vector<int>> groups;
    StronglyConnectedComponents(Graph &_G): G(_G){
        int v = (int)G.size();
        invG.resize(v);
        for(int i=0;i<v;i++){
            for(auto&g:G[i]){
                invG[g].push_back(i);
            }
        }
        // DFSをする
        ord.resize(v, -1);
        inv.resize(v, -1);
        int k = 0;
        for(int i=0;i<v;i++){
            if(ord[i]==-1)k = dfs(i, k);
        }

        for(int i=0;i<v;i++){
            inv[ord[i]] = i;
            ord[i] = -1;
        }
        // 辺を逆向きにしてDFS
        k = 0;
        for(int i=0;i<v;i++){
            if(ord[i]==-1){
                vector<int> group(0);
                k = dfs2(i, k, group);
                groups.push_back(group);  
            }
        }
    }
    int dfs(int n, int k){
        ord[n] = k++;
        for(auto&e:G[n]){
            if(ord[e]==-1){
                k = dfs(e, k);
            }
        }
        return k;
    }
    int dfs2(int n,int k, vector<int>&group){
        group.push_back(n);
        ord[n] = k++;
        for(auto&e:invG[n]){
            if(ord[e]==-1){
                k = dfs2(e, k, group);
            }
        }
        return k;
    }
};
#line 3 "Graph/SCC.test.cpp"

int main(){
    int n,m;
    cin >> n >> m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    StronglyConnectedComponents scc(g);
    vector<int> num(n,0); //どの強連結成分に含まれているか
    for(int i=0;i<(int)scc.groups.size();i++){
        for(auto&v:scc.groups[i]){
            num[v] = i;
        }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int s,t;cin>>s>>t;
        cout << (num[s] == num[t]) << endl;
    }
}
