#include<bits/stdc++.h>
using namespace std;

int main(){
    int capacity;
    int items;
    cout<<"\nEnter capacity";
    cin>>capacity;
    cout<<"\nEnter items";
    cin>>items;
    
    int prices[items+1];
    int wt[items+1];
    int dp[items+1][capacity+1];
    
    cout<<"\nenter prices";
    for(int i=0;i<items;i++){
        cin>>prices[i];
    }
    cout<<"\nEnter weight";
    for(int i=0;i<items;i++){
        cin>>wt[i];
    }
    
    for(int i=0;i<=items;i++){
        for(int j=0;j<=capacity;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(wt[i] <= j){
                dp[i][j] = max(dp[i-1][j] , prices[i] + dp[i-1][j-wt[i]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<"Answer is "<<dp[items][capacity]<<endl;
    return 0;
    
}