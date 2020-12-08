void brute_force(vector<int>&arr,int k){
    int n = arr.size();
    k%=n;
    while(k--){
        int temp = arr[0];
        for(int i=0;i<n-1;i++)
            arr[i] = arr[i+1];
        arr[n-1] = temp;
    }
    //T = O(n*k)
    //S = O(1)
}

void brute_force2(vector<int>&arr,int k){
    int n = arr.size();
    k%=n;
    vector<int>temp(n);
    int idx = 0;
    for(int i=k;i<n;i++)
        temp[idx++] = arr[i];
    for(int i=0;i<k;i++)
        temp[idx++] = arr[i];
    arr.clear();
    for(int i:temp)
        arr.push_back(i);
    //T = O(n)
    // S = O(n)
}

void optimised(vector<int>&arr,int k){

    //left
    reverse(begin(arr),begin(arr)+k);
    reverse(begin(arr)+k,end(arr));
    reverse(begin(arr),end(arr));

    //right
    // reverse(begin(arr),end(arr));
    // reverse(begin(arr),begin(arr)+k);
    // reverse(begin(arr)+k,end(arr));

    //T = O(n)
    // S = O(1)
}