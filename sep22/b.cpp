#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    while(n--){
        long long a,b,c;
        cin>>a>>b>>c;

       long long mini = abs(a-b);
       long long ans;
       if(c<=mini){
        ans = mini;
       }
       else{
        ans = mini+c;
       }
        
        cout<<ans<<endl;
    }

    return 0;
}