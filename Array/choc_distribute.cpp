int solution(vector<int>&arr,int k){
    sort(begin(arr),end(arr));
    int ans = INT_MAX;
    for(int i = 0;i<arr.size();i++){
        if(i>=(k-1)){
            ans = min(ans,arr[i]-arr[i-k+1]);
        }
    }
    return ans;
}