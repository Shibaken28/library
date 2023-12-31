
long modpow(long a, long b, long m){
    // a^b mod m
    long ret = 1;
    while(b>0){
        if(b&1) ret = (ret * a)%m;
        a = (a * a)%m;
        b >>= 1;
    }
    return ret;
}

