# define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
# include <iostream>
using namespace std;

# include <vector>
# include <set>
# include <algorithm>
using namespace std;

struct primeSieve{
    vector<long> mfactor;
    //既知の素数(随時追加される)
    vector<long> primes;
    set<long> primeSet;
    long N;
    primeSieve(){
        N = 0;
        calc();
    }
    primeSieve(long N){
        this-> N = N;
        calc();
    }
    /*
    素数篩
    O(sqrt(N))
    */
    void calc(){
        primes.clear();
        mfactor.resize(N+1);
        fill(mfactor.begin(),mfactor.end(),-1);
        mfactor[0] = 0;
        mfactor[1] = 1;
        for(long i=2;i<=N;i++){
            if(mfactor[i] == -1){
                for(long j=i;j<=N;j+=i){
                    mfactor[j] = i;
                }
            }
        }
        for(long i=2;i<=N;i++){
            if(mfactor[i] == i){
                primes.push_back(i);
                // primeSet.insert(i);
            }
        }
    }
    /*
    素数判定
    O(1)
    */
    bool isPrime(long x){
        if(x==1)return false;
        if(x<=N) return x == mfactor[x];
        if(primeSet.count(x))return true;
        return isPrimeNaive(x);
    }
    /*
    Naive素数判定
    O(sqrt(N))
    */
    bool isPrimeNaive(long x){
        if(x<=1)return false;
        for(long i=2;i*i<=x;i++){
            if(x%i==0){
                return false;
            }
        }
        primes.push_back(x);
        primeSet.insert(x);
        return true;
    }
    /*
    素因数分解
    O(log N)
    */
    vector<long> factorization(long x){
        if(x>N){
            return factorizationNaive(x);
        }
        vector<long> A(0);
        if(x==1){
            A.push_back(1);
            return A;
        }
        while(x>1){
            A.push_back(mfactor[x]);
            x /= mfactor[x];
        }
        reverse(A.begin(),A.end());
        return A;
    }
    /*
    Naive素因数分解
    O(sqrt N)
    */
    vector<long> factorizationNaive(long x){
        vector<long> A(0);
        for(long i=2;i*i<=x;){
            if(x%i==0){
                x/=i;
                A.push_back(i);
            }else{
                i++;
            }
        }
        if(x>1){
            A.push_back(x);
        }
        return A;
    }
};


primeSieve ps(500000000);

int main(){
    int N,A,B;
    cin>>N>>A>>B;
    ps.calc();
    vector<int> ans;
    for(auto x:ps.primes){
        if(x <= N)ans.push_back(x);
    }
    vector<int> ans2;
    for(int i=B;i<(int)ans.size();i+=A){
        ans2.push_back(ans[i]);
    }
    cout<<ans.size()<<" "<<ans2.size()<<endl;
    for(int i=0;i<(int)ans2.size();i++){
        cout<<ans2[i]<<(i+1==(int)ans2.size()?"\n":" ");
    }
}