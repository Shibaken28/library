# define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
# include "2SAT.hpp"

int main(){
    string _;
    int n,m;
    cin >> _ >> _ >> n >> m;
    TwoSAT sat(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        sat.add_clause(abs(a)-1, a>0, abs(b)-1, b>0);
    }
    if(!sat.satisfiable()){
        cout << "s UNSATISFIABLE" << endl;
        return 0;
    }else{
        cout << "s SATISFIABLE" << endl;
        cout << "v ";
        for(int i=0;i<n;i++){
            cout << (sat.ans[i]?i+1:-i-1) << " ";
        }
        cout << "0" << endl;
    }
}
