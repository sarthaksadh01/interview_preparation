bool solution1(vector<int> &arr) {
    sort(arr.begin(),arr.end());
    int i = 0,n=arr.size();
    while(i < n){
        while((i+1)<n &&  arr[i] == arr[i+1]) 
            i++;
        if( (n - (i+1)) == arr[i])
            return true;
        i++;
    }
    return false;
}

bool solution2(vector<int> &arr) {
    // TODO O(n)
}