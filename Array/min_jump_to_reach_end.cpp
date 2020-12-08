int brute_force(vector<int>&nums,int n,int i=0){
    if(i>=(n-1))
        return 0;
    int ans = n+1;
    for(int j  = nums[i]+i ;j>i;j--){
        ans = min(ans,1+brute_force(nums,n,j));
    }
    return ans;
    // T = O(n^n)
    //Note = using dp time complexity can be O(n*n)
}

int solution(vector<int>&nums, int n){
        if(n<=1)return 0;
        int jumps = 1;
        int maxReach = nums[0],steps = nums[0];
        for(int i=1;i<n;i++){
            if(i>maxReach)
                return -1;
            if(i==(n-1))
                return jumps;
            maxReach = max(maxReach,nums[i]+i);
            steps--;
            if(!steps){
                steps = maxReach-i;
                jumps++;
            }
        }
       return -1;
       // T = O(n)
}