int brute_force(vector<int>&arr,int k){
    // check for all sub arrays
}
int solution(vector<int>&arr,int k){
    int sum = 0,start = 0,ans = 0;
    for(int end =0;end<arr.size();end++){
        sum+=arr[end];
        while(sum > k && start <= end){
            sum-=arr[start++];
            ans = max(ans,end-start+1);
        }
    }
    return ans;
}