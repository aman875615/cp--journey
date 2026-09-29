#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int n,k;
        cin>>n>>k;
        long long ans = (1LL << (n - k + 1));
        ans += 2LL * (k - 1);
        cout<<ans<<endl;
    }
    return 0;
}