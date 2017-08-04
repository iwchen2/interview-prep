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
    arr[prev_idx + 1] = curr_val;
  }
  return arr;
}

vector<int> selection_sort(vector<int> arr){
  for(size_t i = 0; i < arr.size() - 1; i++){
    //int min = arr[i]; //The spot(i) to be replaced with the min

    for(size_t j = i + 1; j < arr.size(); j++){
      if(arr[j] < arr[i]){
        swap(arr[i], arr[j]);
      }
    }
  }
  return arr;
}

int main(){
  //int vec2[] = {5, 2, 4, 1, 6, 3};
  vector<int> vec;
  vec.push_back(5);
  vec.push_back(2);
  vec.push_back(4);
  vec.push_back(6);
  vec.push_back(1);
  vec.push_back(3);
  vector<int> res = insertion_sort(vec);
  vector<int> res2 = selection_sort(vec);
  for(auto it = res.begin(); it != res.end(); it++){
    cout << *it << endl;
  }
  for(auto it = res2.begin(); it != res2.end(); it++){
    cout << *it << endl;
  }
  return 0;
}
