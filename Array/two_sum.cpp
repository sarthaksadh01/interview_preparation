
vector<vector<int,int>> brute_force(vector<int>&arr,int n,int sum){
    vector<vector<int>>res;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            res.push_back({nums[i],nums[j]})
    }
    return res;
}

vector<vector<int>> solution(vector<int>&arr,int n,int sum){
    vector<vector<int>>res;
    sort(begin(arr),end(arr));
    int i = 0,j=n-1;
    while(i<j){
        int temp = arr[i]+arr[j];
        if(temp > sum)
            j--;
        else if(temp<sum)
            i++;
        else{
           res.push_back({nums[i],nums[j]});
           while(i<j && nums[i] == nums[i+1])i++;
           i++;
           while(i<j && nums[j] == nums[j-1])j--;
           j--;
        }

    }
    return res;
}
