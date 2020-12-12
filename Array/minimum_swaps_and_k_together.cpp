int brute_force(vector<int>&arr,int n,int k){
    //let elements <= k = count
    // for every sub array of size count calculate number of elements > k
    // ans = min(all step 2)
    // T = O(n*n)
}
int solution(vector<int>&arr,int n,int k){
    int count = 0;
    int res = INT_MAX;
    for(int i:arr)
        count+=(i<=k);
    int bad = 0;
    for(int i = 0;i<n;i++){
        bad+=(arr[i]> k);
        if(i>=count)
            bad-=(arr[i-count] > k);
        if(i>=(count-1))
            res = min(res,bad);
    }
    return res;
    // T = O(n)
} 
