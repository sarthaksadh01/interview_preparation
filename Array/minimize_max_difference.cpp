int brute_force(vector<int>&arr,int k,int idx = 0){
    if(idx >=arr.size()){
        return *max_element(begin(arr),end(arr)) - *min_element(begin(arr),end(arr));
    }
    int a =INT_MAX,b=INT_MAX;
    if(arr[idx] >=k ){
        arr[idx]-=k;
        a = brute_force(arr,k,idx+1);
        arr[idx]+=k;
    }
    arr[idx]+=k;
    b = brute_force(arr,k,idx+1);
    return min(a,b);

    //T = O(2^n*n)
    //space stack space
}

int solution(vector<int>&arr,int k){
    int minElement = *min_element(begin(arr),end(arr));
    int maxElement = *max_element(begin(arr),end(arr));
    if(maxElement - minElement <=k)
        return maxElement - minElement;
    int avg = (maxElement + minElement) / 2; 
    for(int &i:arr){
        if(i > avg)
            i-=k;
        else 
            i+=k;
    }
    return *max_element(begin(arr),end(arr)) - *min_element(begin(arr),end(arr));

    //T = O(n)
    //space O(1)
}