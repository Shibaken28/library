#line 1 "Math/Number-Theory/CRT.test.cpp"
# define PROBLEM "https://yukicoder.me/problems/447"
# include <iostream>
#line 1 "Math/Number-Theory/CRT.hpp"
# include <vector>
# include <utility>
#line 1 "Math/Number-Theory/ext-euclid.hpp"
// 拡張Euclidの互除法
// ax + by = gcd(a, b) となるような (x, y) を求める 
long extGCD(long a, long b, long &x, long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

#line 4 "Math/Number-Theory/CRT.hpp"
using namespace std;

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

#line 4 "Math/Number-Theory/CRT.test.cpp"
using namespace std;

int main(){
    int N = 3;
    vector<pair<long,long>> X(N);
    for(int i=0;i<N;i++){
        cin >> X[i].first >> X[i].second;
    }
    long r,m;
    bool ok = CRT(X,r,m);
    if(ok){
        cout << r << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
