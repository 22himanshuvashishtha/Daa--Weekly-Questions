// MERGE SORT:
// based on dividing the array/vector into mids mids till we get individual number [note: single number is always sorted]
// this divison is based on splitting array to mid
//creating them back 
//and then sorted while combinh them in order in step 3
// then merging all individual sorted ele


#include <bits/stdc++.h>
using namespace std;
void mergeArrays(int arr[], int s, int e)
{
       
    int mid = (s+e)/2;
    
    int len1 = (mid-s)+1;
    int len2 = e-mid;//e-(mid+1)+1;
    
    // STEP : 4 :two array creation i.e left and right array creation
    int * left  = new int[len1];
    int * right = new int[len2];
    
    // as merging happpens for every broken array
    // it is extracting real values from main arr and forming new ones
    int k=s;
    for(int i=0;i<len1;++i){left[i]=arr[k]; k++;}
    
    k=mid+1;
    
    for(int i=0;i<len1;++i){right[i]=arr[k]; k++;}
    
    //STEP : 5 :- merging the array using 2 pointers
    int rightIndex=0;
    int leftIndex =0;
    int mainArrayIndex=s;
    // order maintaince and merginng happens at every array at s;
    
    while(rightIndex<len2 && leftIndex<len1)
    {
        //STEP : 6 :- here we are checking and sorting arrays in main array to return as sorted
        if(left[leftIndex]<right[rightIndex]){arr[mainArrayIndex] = left[leftIndex]; mainArrayIndex++; leftIndex++;}
        else {arr[mainArrayIndex]=right[rightIndex]; mainArrayIndex++; rightIndex++;}
    }
    
    // STEP : 6a :- when loops above end and one is left with value dur to different length issue we copy the array as it
    while(leftIndex<len1){arr[mainArrayIndex] = left[leftIndex]; mainArrayIndex++; leftIndex++;}
    
         // as from the base condition everythin comes up sorted dont worry about order the left over one that is just added will habe leme only greater as one finmished that means it has   
      // that much ele that do lesser than the remaining in the left over array
    
    
    while(rightIndex<len2){arr[mainArrayIndex]=right[rightIndex]; mainArrayIndex++; rightIndex++;}
    
    //STEP : 7 :- Deletition of created arrays;
    delete[] right;
    right = nullptr;
    delete[] left;
    left = nullptr;

    
}

void mergeSort(int arr[], int s, int e)
{
    if(s>=e)return;
    
    int mid  = (s+e)/2;
    
    // Step 1 :- this is recursively sorting array right as it keeps on breaking it
    mergeSort(arr,s,mid);
    
    // Step 2 :- this is the recursively sorted array for left as it keeps on breaking it
    mergeSort(arr, mid+1,e);
    
    // Step 3 :- heart where actual array creation and sorted ordered merging happens
    mergeArrays(arr,s,e);
}

int main()
{
   
    
 
    
    int arr[9] = {4,7,1,4,9,1,9,7,8};
    for(int i=0;i<9;++i)cout<<arr[i]<<" ";
       
     cout<<"\n";   
    
    mergeSort(arr,0,8);
    
    
    for(int i=0;i<9;++i)cout<<arr[i]<<" ";
    return 0;
}
