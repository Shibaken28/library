# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"
# include <iostream>
# include "prime-factorize.hpp"

using namespace std;


int main(){
    int n; cin>>n;
    auto f = factor(n);
    cout << n << ":";
    for(auto a:f){
        cout << " " << a;
    }
    cout << endl;
}
