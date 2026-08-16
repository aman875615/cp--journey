#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){

        vector<int>row(i+1,1);
        for(int j=1;j<i;j++){
            row[j]=ans[i-1][j-1]+ ans[i-1][j];
        }
        ans.push_back(row); 
    }

    for(const auto &row : ans){
        for(int x : row){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}