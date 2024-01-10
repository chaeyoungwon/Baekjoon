#include <iostream>
using namespace std;
int arr[26][2];

void inorder(char root){
    if(root == '.') return;
    inorder(arr[root-'A'][0]);
    cout<<root;
    inorder(arr[root-'A'][1]);
}

void preorder(char root){
    if(root == '.') return;
    cout<<root;
    preorder(arr[root-'A'][0]);
    preorder(arr[root-'A'][1]);
}

void postorder(char root){
    if(root == '.') return;
    postorder(arr[root-'A'][0]);
    postorder(arr[root-'A'][1]);
    cout<<root;
}

int main(){
    int N; cin >> N; // 이진 트리의 노드 개수
    for (int i=0; i<N; i++){
        char mid, left, right;
        cin >> mid >> left >> right;
        arr[mid-'A'][0]=left;
        arr[mid-'A'][1]=right;
    }
    
    //항상 A가 루트 노드가 됨
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
    cout<<"\n";
    
    return 0;
}