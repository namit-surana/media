#include<bits/stdc++.h>
using namespace std;

void solve(int col,vector<string> &board,vector<vector<string>> &ans, vector<int> &leftRow,vector<int> &upperdig,vector<int> &lowerdig, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row] == 0 && upperdig[row+col] == 0 && lowerdig[n-1+col-row] == 0){
            board[row][col] = 'Q';
            leftRow[row]=1;
            upperdig[row+col]=1;
            lowerdig[n-1+col-row]=1;
            solve(col+1,board,ans,leftRow,upperdig,lowerdig,n);
            //backtracking
            board[row][col]='.';
            leftRow[row]=0;
            upperdig[row+col]=0;
            lowerdig[n-1+col-row]=0;
            
        }
    }
}

int main(){
    int n;
    cout<<"\nEnter the n for queens";
    cin>>n;
    
    vector<vector<string>> ans;
    string s(n,'.');
    vector<string> board(n);
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    vector<int> leftRow(n,0);
    vector<int> upperdig(2*n-1,0);
    vector<int> lowerdig(2*n-1,0);
    solve(0,board,ans,leftRow,upperdig,lowerdig,n);
    
    for(int i=0;i<ans.size();i++){
        for(auto x:ans[i]){
            cout<<x<<endl;
        }
        cout<<endl;
    }
    return 0;
}