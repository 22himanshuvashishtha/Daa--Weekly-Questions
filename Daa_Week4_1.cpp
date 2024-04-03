#include <iostream>
#include <algorithm>
using namespace std;

void merge(int a[], int b[], int m, int n) {
    int i = 0, j = 0, k = 0;
    int c[m + n];
    while (i < m && j < n) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < m)
        c[k++] = a[i++];
    while (j < n)
        c[k++] = b[j++];

    for(int i=0;i<k;i++){
        a[i]=c[i];
    }
}

void mergeSort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr + l, arr + mid + 1, mid - l + 1, h - mid);
    }
}

int main() {
    int t;
    cin >> t;
    if (t <= 0) {
        cout << "Invalid input: t should be greater than 0." << endl;
        return 0;
    }
    int arr[t];
    for (int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, t - 1);
    for (int i = 0; i < t; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
