# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A"
# include <iostream>
# include "enum-prime.hpp"
# include "isprime.hpp"
using namespace std;

bool verify(){
    int N = 1000000;
    primeSieve ps(N);
    ps.calc();
    for(int i=1;i<N;i++){
        if(ps.isPrime(i) != isPrime(i)){
            return false;
        }
    }
    return true;
}

int main(){
    // 自前テストを行う
    cout << (verify()?"Hello World": "WA") << endl;
    return 0;
}
