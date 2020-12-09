vector<int>brute_feorce(vector<int>&arr){
    // find all permutation
    // find the next greater one
    //T = O(n!)
    //S = O(n)
}

void solution(vector<int>&arr){
    int n = arr.size(),i,j;
    for(i = n-2;i>=0;i--){
        if(arr[i] < arr[i+1])
            break;
    }
    if(i<0){
        reverse(begin(arr),end(arr));
        return;
    }

    // can also do binary search here as array is reverse sorted
    for(j=n-1;j>i;j--){
        if(arr[j]>arr[i])
            break;
    }
    swap(arr[i],arr[j]);
    reverse(begin(arr)+i+1,end(arr));
}