#include<iostream>
using namespace std;

//iterative algo
int fibo_i(int n){
    int t1=0;
    int t2=1;
    int next=0;
    int count=0;
    for(int i=1;i<=n;i++){
        count++;
        if(i==1){
            cout<<t1<<" ";
            continue;
        }
        if(i==2){
            cout<<t2<<" ";
            continue;
        }
        next=t1+t2;
        t1=t2;
        t2=next;
        cout<<next<<" ";
    }
    return count;
}
int fibo_r(int n){
    if(n == 1 || n==0){
        return n;
    }else
    return fibo_r(n-1)+fibo_r(n-2);
}
int main(){
    int n;
    cout<<"\nEnter the number";
    cin>>n;
    int c1=fibo_i(n);
    cout<<endl;
  
    
    int temp=0;
    while(temp<n){
        cout<<fibo_r(temp)<<" ";
        temp++;
    }
    
}