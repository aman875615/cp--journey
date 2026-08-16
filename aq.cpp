#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;

        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                s.erase(i,1);
                break;
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                s.erase(i,1);
                break;
            }
        }
        cout<<s<<endl;

    }

}