# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"
# include <iostream>
# include "ext-euclid.hpp"
using namespace std;

int main(){
    long a,b;
    cin >> a >> b;
    long x,y;
    extGCD(a,b,x,y);
    cout << x << " " << y << endl;
}

