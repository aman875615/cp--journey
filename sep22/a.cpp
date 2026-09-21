#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        int mini,m=INT_MAX;
        for(int i=0;i<3;i++){
            cin>>mini;

            m = min(mini,m);
        }
        cout<<a-m<<endl;
    }

    return 0;
}
