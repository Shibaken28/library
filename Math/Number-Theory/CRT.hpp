# include "templete.hpp"
# include "ext-euclid.hpp"

long mod(long a,long m){
    if(a>=0)return a%m; 
    return (m-(-a)%m)%m;
}

/*
中国剰余定理
*/
bool CRT(long b1, long m1, long b2, long m2,long &r,long &m) {
    long p, q;
    long d = extGCD(m1, m2, p, q);
    if ((b2 - b1) % d != 0) return false;
    m = m1 * (m2/d); 
    long tmp = (b2 - b1) / d * p % (m2/d);
    r = mod(b1 + m1 * tmp, m);
    return true;
}

bool CRT(const vector<pair<long,long>> &X,long &r,long &m) {
    int s = X.size();
    r = X.front().first;
    m = X.front().second;
    bool ok = true;
    for(int i=1;i<s;i++){
        ok = CRT(r,m,X[i].first,X[i].second,r,m);
        if(!ok){
            break;
        }
    }
    return ok;
}

