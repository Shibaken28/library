# include <vector>
# include <algorithm>
using namespace std;

// 順列列挙
vector<vector<int>> permutations(int N){
    vector<int> array(N);
    vector<vector<int>> A(0);
    for(int i=0;i<N;i++)array[i]=i;
    do{
        A.push_back(array);
    }while(next_permutation(array.begin(),array.end()));
    return A;
}

