# include <vector>
using namespace std;

long GCD(long a,long b){
    if(a<b)return GCD(b,a);
    if(b==0)return a;
    return GCD(b,a%b);
}

long GCD(vector<long>&A){
    long gcd = A.front();
    for(auto&a:A)gcd = GCD(gcd,a);
    return gcd;
}

long LCM(long a,long b){
    return (a/GCD(a,b))*b;
}


long LCM(vector<long>&A){
    long lcm = 1;
    for(auto&a:A)lcm = LCM(lcm,a);
    return lcm;
}

