# define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D&lang=ja"
# include <iostream>
# include "divisor.hpp"
using namespace std;

int main(){
    long a,b,c;
    cin >> a >> b >> c;
    long ans = 0;
    auto f = divisor(c);
    for(auto x:f){
        if(a<=x && x<=b)ans++;
    }
    cout << ans << endl;
    return 0;
}