#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
       int l;
       cin>>l;
       vector<int>arr(l);
       for(int i=0;i<l;i++){
           cin>>arr[i];
       }
       int sneha=0,himanshu=l-1;
       int spro=0,hpro=0;
       bool sturn= true;
       int max=0;
       while(sneha<=himanshu){
           if(arr[sneha]>arr[himanshu]){
               max=arr[sneha];
               sneha++;
           }
           else{
               max=arr[himanshu];
               himanshu--;
           }
 
           if(sturn){
               spro+=max;
           }
           else
              hpro+=max;
 
            sturn =!sturn;  
        }
        cout<<spro<<" "<<hpro;
}        
