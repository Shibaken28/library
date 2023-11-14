# include "templete.hpp"
# include "../Number-Theory/ext-euclid.hpp"

// 逆元 a^{-1} mod m
long modinv(long a,long m){
    long x,y;
    extGCD(a,m,x,y);
    return (m+x%m)%m;
}