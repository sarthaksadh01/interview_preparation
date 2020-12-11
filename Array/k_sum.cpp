
vector<vector<int>> brute_force(vector<int>& nums, int target,int k) {
       //k nested loops
       // or by recursion
}


vector<vector<int>> solution(vector<int>& nums, int target,int k) {
        sort(nums.begin(),nums.end());
        return kSum(nums,target,0,nums.size(),k);
}
vector<vector<int>>kSum(vector<int>&nums,int target,int idx,int len,int k){
        vector<vector<int>>res;
        if(idx>=len)
            return res;
        if(k==2){
            int i = idx;
            int j = len-1;
            while(i<j){
                int tempSum = nums[i]+nums[j];
                if(tempSum < target)
                    i++;
                else if(tempSum > target)
                    j--;
                else{
                    res.push_back({nums[i],nums[j]});
                    while(i<j && nums[i] == nums[i+1])
                        i++;
                    i++;
                    while(i<j && nums[j] == nums[j-1])
                        j--;
                    j--;
                }
            }
        }
        else{
            for(int i =idx;i<len-k+1;i++){
                vector<vector<int>>temp  = kSum(nums,target-nums[i],i+1,len,k-1);
                if(!temp.empty()){
                    for(auto &v:temp){
                        v.insert(v.begin(),nums[i]);
                        res.push_back(v);
                    }
                }
                while (i < len-1 && nums[i] == nums[i+1]) {
                        i++;
                    }
            }
           
        }
        return res;
        //T = O(n^(k-1)) 
    }