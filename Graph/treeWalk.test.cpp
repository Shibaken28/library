# define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_7_C"
# include "treeWalk.hpp"


int main(void){
    std::cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n;
    BinaryTree bt(n);
    for(int i=0;i<n;i++){
        int id, l, r;
        cin>>id>>l>>r;
        bt[id].left = l;
        bt[id].right = r;
        if(l>=0){
            bt[l].parent = id;
        }
        if(r>=0){
            bt[r].parent = id;
        }
    }
    // rootを探す
    int root = 0;
    for(int i=0;i<n;i++){
        if(bt[i].parent==-1){
            root = i;
            break;
        }
    }

    vector<int> pre(n), in(n), post(n);
    int a;
    a = 0; binaryTreeWalkPre(bt, pre, a, root);
    a = 0; binaryTreeWalkIn(bt, in, a, root);
    a = 0; binaryTreeWalkPost(bt, post, a, root);
    cout<<"Preorder"<<endl;
    for(auto&v:pre)cout<<" "<<v;
    cout<<endl;
    cout<<"Inorder"<<endl;
    for(auto&v:in)cout<<" "<<v;
    cout<<endl;
    cout<<"Postorder"<<endl;
    for(auto&v:post)cout<<" "<<v;
    cout<<endl;
}
