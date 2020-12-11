bool brute_force(vector<int>&arr,int n){
    int sum =0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(!sum)
                return true;
        }
    }
    return false;
}

bool solution(vector<int>&arr, int n)
{
    unordered_set<int>s;
    int sum = 0;
    for(int i:arr){
        sum+=i;
        if(s.count(sum) || !sum)
            return true;
        s.insert(sum);
    }
    return false;
}
