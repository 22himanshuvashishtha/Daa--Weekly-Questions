#include<bits/stdc++.h>
 using namespace std;

int partition(int arr[], int si, int ei)
{
    int count = 0;
    for (int i = si + 1; i <= ei; i++)
    {
        if (arr[i] <= arr[si])
        {
            count++;
        }
    }
    int partition_index = si + count;
    swap(arr[si], arr[partition_index]);
    int pivot = arr[partition_index];
    int i = si;
    int j = ei;
    while (i < partition_index && j > partition_index)
    {
        if (arr[i] <= pivot)
        {
            i++;
        }
        else if (arr[j] >= pivot)
        {
            j--;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return partition_index;
}


int QuickSelect(int arr[], int si, int ei, int k)
{
    int PartitionIndex = partition(arr,si,ei);
    if (k>PartitionIndex)
    {
        return QuickSelect(arr,PartitionIndex+1,ei,k);
    }
    else if(k<PartitionIndex)
    {
        return QuickSelect(arr,si,PartitionIndex-1,k);
    }
    else{
        return arr[PartitionIndex];
    }
    

}

 int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        int k;
        cin>>k;

        int ans = QuickSelect(arr,0,n-1,k-1);
        int kthLargest = QuickSelect(arr, 0, n - 1, n - k);

        cout<<ans<<endl;
        cout<<kthLargest<<endl;

    }
}
