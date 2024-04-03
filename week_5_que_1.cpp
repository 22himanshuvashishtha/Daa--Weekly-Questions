#include <iostream>
#include<climits>
using namespace std;

void countSort(int arr[], int n) {
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    int count[max + 1] = {0};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for(int i = 1; i <= max; i++) {
        count[i] = count[i] + count[i - 1];
    }
    int output[n];
    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main(){
    int testcases;
    cin>>testcases;
    for (int t=0; t<testcases; t++)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        countSort(arr,n);

        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }
}
