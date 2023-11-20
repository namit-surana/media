#include<bits/stdc++.h>
using namespace std;

int partition(int *A,int l,int h,int &qc){
    int i=l-1;
    int x=A[h];
    for(int j=l;j<h;j++){
        qc++;
        if(A[j] <= x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[h]);
    return i+1;
}
void quickSort(int *A,int l,int h,int &qc){
    if(l<h){
        int q=partition(A,l,h,qc);
        quickSort(A,l,q-1,qc);
        quickSort(A,q+1,h,qc);
    }
    
}
int randomPartition(int *B,int l,int h,int &rc){
    //int x=B[h];
    int i=rand() % (h-1+1)+1;
    swap(B[i],B[h]);
    rc++;
    return partition(B,l,h,rc);
    
}
void randomSort(int *B,int l,int h,int &rc){
    if(l<h){
        int q=randomPartition(B,l,h,rc);
        randomSort(B,l,q-1,rc);
        randomSort(B,q+1,h,rc);
    }
}
int main(){
    int n;
    cout<<"enter n";
    cin>>n;
    
    int A[n],B[n];
    cout<<"\n enter elements";
    for(int i=0;i<n;i++){
        cin>>A[i];
        B[i]=A[i];
    }
    
    int qc,rc;
    qc=rc=0;
    
    quickSort(A,0,n-1,qc);
    cout<<"\nArray after simple quick sort";
    for(auto x:A){
        cout<<x<<endl;
    }
    cout<<"\nQuick sort count"<<qc;
    
    randomSort(B,0,n-1,rc);
    cout<<"\nArray for random sort";
    for(auto x:B){
        cout<<x<<" ";
    }
    cout<<"\nstpes of random sort"<<rc;
    return 0;
}