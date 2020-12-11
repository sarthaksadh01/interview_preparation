vector<vector<int>> brute_force(vector<int>& nums,int sum) {
        vector<vector<int>>res;
        for(int i=0;i<res.size();i++){
            for(int j=i+1;j<res.size();j++){
                for(int k = j+1;k<res.size();k++){
                    if(nums[i]+nums[j]+nums[k]==sum)
                        res.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        return res;
    }
};

   vector<vector<int>> solution(vector<int>& nums,int sum) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<(int)nums.size()-2;i++){
            int j= i+1,k = nums.size()-1;
            while(j<k){
                int temp = nums[i] + nums[j] + nums[k];
            if(sum == temp){
                res.push_back({nums[i],nums[j++],nums[k--]});
                while(j<k && nums[j] == res.back()[1])
                    j++;
                while(j<k && nums[k] == res.back()[2])
                    k--;
            }
            else if(temp<sum)j++;
            else k--;
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return res;
    }
};