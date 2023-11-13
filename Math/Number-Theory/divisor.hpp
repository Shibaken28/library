# include <vector>
# include <algorithm>
using namespace std;

//約数列挙
vector<long> divisor(long x){
    vector<long> f(0);
    for(long i=1;i*i<=x;i++){
        if(x%i==0){
            f.push_back(i);
            if(i!=x/i)f.push_back(x/i);
        }
    }
    sort(f.begin(),f.end());
    return f;
}
