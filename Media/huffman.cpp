#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode *left,*right;
    MinHeapNode(char data,int freq){
        left=right=NULL;
        this->data=data;
        this->freq=freq;
    }
};
struct compare{
    bool operator()(MinHeapNode *a,MinHeapNode *b){
    return (a->freq > b->freq);
    }
};
void printCodes(struct MinHeapNode *root, string str){
    if(root == NULL){
        return;
    }
    if(root->data != '$'){
        cout<<root->data<<":"<<str<<endl;
    }
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}
void huffmanCode(char data[],int freq[],int n){
    struct MinHeapNode *left,*right,*temp;
    
    priority_queue<MinHeapNode *,vector<MinHeapNode*>,compare> minHeap;
    for(int i=0;i<n;i++){
        minHeap.push(new MinHeapNode(data[i],freq[i]));
    }
    
    while(minHeap.size()!=1){
        left=minHeap.top();
        minHeap.pop();
        right=minHeap.top();
        minHeap.pop();
        temp = new MinHeapNode('$', left->freq+right->freq);
        temp->left=left;
        temp->right=right;
        minHeap.push(temp);
    }
    
    printCodes(minHeap.top(),"");
    
}

int main(){
    int n;
    cout<<"\nEnter number of character";
    cin>>n;
    char data[n];
    int freq[n];
    cout<<"\nEnter data(in char) and corressponding frequency";
    for(int i=0;i<n;i++){
        cin>>data[i]>>freq[i];
    }
  
    huffmanCode(data,freq,n);
    return 0;
}