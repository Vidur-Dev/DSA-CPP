#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void selection_sort(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++){
        int minindex=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minindex]){
                minindex=j; 
            }
        }
        swap(arr[i],arr[minindex]);
    }
}
void bubble_sort(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void insertion_sort(vector<int>&arr){
    for(int us=1;us<arr.size();us++){
        int temp=arr[us];
        int s_end = us-1;
        while(arr[s_end]>temp && s_end>=0){
            arr[s_end+1]=arr[s_end];
            s_end--;
        }
        arr[s_end+1]=temp;
    }
}
void merge(vector<int>&arr,int l,int mid,int r){
    int nsize = mid-l+1;
    int msize = r-mid;
    vector<int>n(nsize);
    vector<int>m(msize);
    for(int i=0;i<nsize;i++){
        n[i]=arr[l+i];
    }
    for(int i=0;i<msize;i++){
        m[i]=arr[mid+i+1];
    }
    int x=0;
    int y=0;
    int z=l;
    while(x<nsize && y<msize){
        if(n[x]<=m[y]){
            arr[z]=n[x];
            x++;z++;
        }
        else{
            arr[z]=m[y];
            y++;z++;
        }
    }
    while(x<nsize){
        arr[z]=n[x];
        x++;z++;
    }
    while(y<msize){
        arr[z]=m[y];
        y++;z++;
    }
}
void merge_sort(vector<int>&arr,int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int partition(vector<int>&arr,int l,int r){
  int pivot = arr[r];
  int i = l-1;
  for(int j=l;j<r;j++){
    if(arr[j]<pivot){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[r]);
  return i+1;
}
void quick_sort(vector<int>&arr,int l,int r){
  if(l<r){
    int pi = partition(arr,l,r);
    quick_sort(arr,l,pi-1);
    quick_sort(arr,pi+1,r);
  }
}
int main() {
    vector<int> arr={5,2,8,12,3,1};
    // selection_sort(arr);
    // bubble_sort(arr);
    // insertion_sort(arr);
    // merge_sort(arr,0,arr.size()-1);
    // quick_sort(arr,0,arr.size()-1);
    for(auto i:arr){
        cout<<i<<endl;
    }
    return 0;
}