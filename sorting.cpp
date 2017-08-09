#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

void print_vector(vector<int> nums){
  for(auto it = nums.begin(); it != nums.end(); it++){
    cout << *it << " ";
  }
  cout << endl;
}

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

void merge(vector<int>& a, int start, int mid, int end){
  //Initialize two halves of the array in separate arrays
  vector<int> LHS;
  vector<int> RHS;
  for(int i = start; i <= mid ; i++){
    LHS.push_back(a[i]);
  }
  for(int j = mid + 1; j <= end; j++){
    RHS.push_back(a[j]);
  }

  size_t i = 0; //index of left array
  size_t j = 0; //index of right array
  size_t k = start; //pos of entire array

  //left and right arrays need to be checked
  while(i < LHS.size() && j < RHS.size()){
    if(LHS[i] <= RHS[j]){
      a[k] = LHS[i];
      k++;
      i++;
    }else{
      a[k] = RHS[j];
      j++;
      k++;
    }
  }

  //Right array is empty; just add left array elements
  while(i < LHS.size()){
    a[k] = LHS[i];
    k++;
    i++;
  }

  //Left array is empty; just add right array elements;
  while(j < RHS.size()){
    a[k] = RHS[j];
    k++;
    j++;
  }
}

void mergesort(vector<int>& arr, int start, int end){
  if(start < end){
    //Split array in half
    int mid = (start+(end-1)) / 2;
    cout << start << " " << mid << " " << end << endl;

    mergesort(arr, start, mid); //left half of the array
    mergesort(arr, mid+1, end); //right half of the array

    merge(arr, start, mid, end);
  }
}



int main(){
  srand(time(NULL));
  vector<int> vec;
  int vec_size = 8;
  cout << "Original vector/array" << endl;
  for(size_t i = 0; i < vec_size; i++){
    int ele = rand() % 100;
    vec.push_back(ele);
    cout << vec.back() << " ";
  }
  cout << endl;

  //vector<int> res = insertion_sort(vec);
  //vector<int> res2 = selection_sort(vec);
  //for(auto it = res.begin(); it != res.end(); it++){
    //cout << *it << " ";
  //}
  //cout << "insertion sort" << endl;

  //for(auto it = res2.begin(); it != res2.end(); it++){
    //cout << *it << " ";
  //}
  //cout << "selection sort" << endl;

  mergesort(vec, 0, vec.size()-1);
  print_vector(vec);
  return 0;
}
