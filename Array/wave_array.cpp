void solution1(vector<int>&arr){
    sort(begin(arr),end(arr));
    int n = arr.size();
    for(int  i = 0;i<n-1;i+=2){
        swap(arr[i],arr[i+1]);
    }
}

void solution2(vector<int>&arr){
    //
}