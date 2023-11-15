# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_12_A"
# include <iostream>
# include "Prim.hpp"
using namespace std;

int main(){
    int n;
    cin >> n;
    Prim k(n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int a;
        cin >> a;
        if(a!=-1)k.addEdge(i,j,a);
    }
    cout << k.build() << endl;
}
