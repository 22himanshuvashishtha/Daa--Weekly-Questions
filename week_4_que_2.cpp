#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickselect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex < k)
            return quickselect(arr, pivotIndex + 1, high, k);
        else
            return quickselect(arr, low, pivotIndex - 1, k);
    }
    return -1; 
}

int findKthLargest(vector<int>& arr, int k) {
    if (k < 1 || k > arr.size())
        return -1; 
    random_shuffle(arr.begin(), arr.end()); 
    return quickselect(arr, 0, arr.size() - 1, arr.size() - k);
}

int main() {
    vector<int> arr = {3, 1, 4, 2, 5};
    int k = 2;
    cout << "Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    cout << k << "th largest element: " << findKthLargest(arr, k) << endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int kthSmallestHeap(vector<int>& arr, int n, int k) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i >= n - k; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    return arr[n - k];
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the value of k: ";
    cin >> k;

    int kthSmallest = kthSmallestHeap(arr, arr.size(), k);

    cout << "The " << k << "th smallest element is: " << kthSmallest << endl;

    return 0;
}
*/
