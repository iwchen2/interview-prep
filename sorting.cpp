#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

vector<int> insertion_sort(vector<int> arr){
  for(size_t i = 1; i < arr.size(); i++){
    int curr_val = arr[i];

    //Compare curr to left hand-side
    //Incrementing values as necessary
    int prev_idx = i - 1;
    while(prev_idx >= 0 && arr[prev_idx] < curr_val){
      arr[prev_idx + 1] = arr[prev_idx];
      prev_idx--;
    }
    //Move Curr_val to where it belongs in sorted half of arr(left handside of arr[i])
    arr[prev_idx + 1] = curr_val;
  }
  return arr;
}

vector<int> selection_sort(vector<int> arr){
  for(size_t i = 0; i < arr.size() - 1; i++){
    //perform a "find min" on the right handside of arr[i]
    //Swapping when necessary to replace arr[i]
    for(size_t j = i + 1; j < arr.size(); j++){
      if(arr[j] < arr[i]){
        swap(arr[i], arr[j]);
      }
    }
  }
  return arr;
}

void merge(vector<int> arr, int start, int mid, int end){
  int len1 = mid - start;
  int len2 = end - mid;

  //Initialize two halves of the array in separate arrays
  vector<int> LHS(len1);
  vector<int> RHS(len2);
  for(int i = start; i < mid ; i++){
    LHS.push_back(arr[i]);
  }
  for(int j = mid; j < end; j++){
    RHS.push_back(arr[j]);
  }

  int i = 0;
  int j = 0;

  //Compare elements from each half of the array from left to right
  for(int k = start; k < end; k++){
    if(i >= LHS.size()){
      arr[k] = RHS[j];
      j++;
    }else if(j >= RHS.size()){
      arr[k] = LHS[i];
      i++;
    }else if(LHS[i] <= RHS[j]){
      arr[k] = LHS[i];
      i++;
    }else{
      arr[k] = RHS[j];
      j++;
    }
  }
}

void mergesort(vector<int> arr, int start, int end){
  if(start < end){
    //Split array in half
    int mid = (end + start) / 2;
    mergesort(arr, start, mid); //left half of the array
    mergesort(arr, mid, end); //right half of the array
    merge(arr, start, mid, end);
  }
}

int main(){
  srand(time(NULL));
  vector<int> vec;
  int vec_size = 1000;
  for(size_t i = 0; i < vec_size; i++){
    int ele = rand() % 10000;
    vec.push_back(ele);
    cout << vec.back() << " ";
  }
  cout << "Original vector/array" << endl;

  vector<int> res = insertion_sort(vec);
  vector<int> res2 = selection_sort(vec);
  for(auto it = res.begin(); it != res.end(); it++){
    cout << *it << " ";
  }
  cout << "insertion sort" << endl;

  for(auto it = res2.begin(); it != res2.end(); it++){
    cout << *it << " ";
  }
  cout << "selection sort" << endl;

  mergesort(vec, 0, vec.size());
  for(auto it = vec.begin(); it !=res2.end(); it++){
    cout << *it << " ";
  }
  cout << "Merge sort" << endl;
  return 0;
}
