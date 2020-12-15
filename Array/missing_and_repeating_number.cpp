vector<int> brute_force(vector<int> &arr,int n) {
    vector<int>ans;
    vector<bool>v(n+1,false);
    for(int i:arr){
        if(v[i])ans.push_back(i);
        v[i] = true;
    }
    for(int i=1;i<=n;i++){
        if(!v[i]){
            ans.push_back(i);
            break;
        }
    } 
    return ans;
   
}

vector<int> solution(vector<int> &arr,int n) {
    int sum = 0,sq = 0;
    for(int i = 0;i<n;i++){
        sum+=arr[i];
        sum-=(i+1);
        sq+=(arr[i]*arr[i]);
        sq-=((i+1)*(i+1));
    }
    sq/=sum;
    return {(sum+sq)/2 , abs(sum-sq)/2};
}