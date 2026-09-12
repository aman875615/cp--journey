#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int>arr(k);
        for(int j=0;j<k;j++){
            cin>>arr[j];
        }
        //output
        int one=0,zero=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) {
                zero++;
            }
            else{
                one++;
            }
        }
        if(one>=zero){
            cout<<"Bessie"<<endl;
        }
        else{
            cout<<"Elsie"<<endl;
        }


    }
    return 0;
}