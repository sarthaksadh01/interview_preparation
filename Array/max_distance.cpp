int brute_force(vector<int>&arr){
    int ans = 0,n = arr.size();
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i] <=arr[j])
                ans = max(ans,j-i);
        }
    }
    return ans;
}

int solution1(vector<int>&arr){
    int ans = 0,n = arr.size();
    vector<pair<int,int>>v;
    for(int i=0;i<arr.size();i++)
        v.push_back({arr[i],i});
    sort(begin(v),end(v));
    int maxIndex = INT_MIN;
    for(int i = n-1;i>=0;i--){
        maxIndex = max(maxIndex,v[i].second);
        ans = max(ans,maxIndex-v[i].second);
    }
    return ans

}

int solution2(vector<int>&arr){
    int ans = 0,n = arr.size();
    //TODO

}