# include <vector>
using namespace std;

/*
Gは隣接行列である必要があり，辺がない場合はINF，自己ループ辺は0
*/
const long INF = 1e17;

vector<vector<long>> floydWarshall(vector<vector<long>> &G){
    const int N = G.size();
    auto H = G;
    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            for(int c=0;c<N;c++){
                long d = H[b][a] + H[a][c];
                if(H[b][a]==INF||H[a][c]==INF)d = INF;
                if(H[b][c] > d){
                    H[b][c] = d;
                }
            }
        }
    }
    return H;
}
