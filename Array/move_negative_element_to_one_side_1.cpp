void brute_force(vector<int>&arr){
    sort(begin(arr),end(arr));
}
void solution1(vector<int>&arr){
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            swap(arr[j++],arr[i]);
    }
}
void solution2(vector<int>&arr){
  int l=0,r = arr.size()-1;
  while(l<=r){
      if(arr[l]>0 && arr[r] <0 )
        swap(arr[l++],arr[r--]);
      if(arr[l]<0)
        l++;
      if(arr[r]>0)
        r--; 
  }
  swap(arr[left],arr[r]);
}