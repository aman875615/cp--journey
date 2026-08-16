#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
   cin>>a>>b>>c;
   
   if(a>b){
       if(b>c){
           cout<<"middlle:"<<b<<endl;
       }
       else{
           cout<<"middlle:"<<c<<endl;
       }
   }else if(b>c){
       if(a<c){
           cout<<"middlle:"<<c<<endl;
       }
       else{
           cout<<"middlle:"<<a<<endl;
       }
   }
   else{
       if(a<b){
           cout<<"middlle:"<<b<<endl;
       }
       else{
           cout<<"middlle:"<<a<<endl;
       }
       
   }

    return 0;
}