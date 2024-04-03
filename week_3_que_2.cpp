#include<bits/stdc++.h>
using namespace std;

int find_max(int arr[],int n){
    int maxe=0;
    int i=0;
    while(i<n){
    maxe=max(maxe,min(arr[i],arr[n]) *(n-i));
    if(arr[i]>arr[n])n--;
    else
    i++;
    }
    return maxe;
}

int main(){
    int n;
    cin>>n;
    int finnal=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    finnal=find_max(arr,n-1);
    cout<<finnal;
}
