# include "templete.hpp"
# include "prime-factorize.hpp"

long power(long a, long b){
    long ret = 1;
    while(b){
        if(b&1)ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}


long euler(long n){
    if(n<=1)return 0;
    // オイラー関数
    // p1^e1 * p2^e2 * ... * pk^ek に対して
    // (p1-1)*p1^(e1-1) * (p2-1)*p2^(e2-1) * ... * (pk-1)*pk^(ek-1)
    // を返す
    auto f = factor2(n);
    long ret = 1;
    for(auto[p,e]:f){
        ret *= (p-1)*power(p,e-1);
    }
    return ret;
}