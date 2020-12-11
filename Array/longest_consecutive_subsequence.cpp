int brute_force(vector<int>&nums){
    sort(begin(nums),end(nums));
    int res = 0;
    int curr = 1;
    for(int i = 1;i<n;i++){
        if(nums[i]-nums[i-1] == 1)
            curr++;
        else{
            res=  max(res,curr);
            curr = 1;
        }
    }
    return max(res,curr);
}

int solution(vector<int>& nums) {
        int res = 0;
        unordered_set<int>s(nums.begin(),nums.end());
        for(int i:s){
            if(s.count(i-1))continue;
            int tempResult = 1;
            int curr = i;
            while(s.count(++curr)){
                tempResult++;
            }
            res = max(res,tempResult);
        }
        return res;
}