
int brute_force(vector<int>&arr,int n,int sum){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            count+=(arr[i]+arr[j] == sum);
    }
    return count;
}

int solution1(vector<int>&arr,int n,int sum){
    sort(begin(arr),end(arr));
    int i = 0,j=n-1;
    while(i<j){
        int temp = arr[i]+arr[j];
        if(temp > sum)
            j--;
        else if(temp<sum)
            i++;
        else{
            count++;
            j--;
        }

    }
    return count;
}

int solution2(vector<int>&arr,int n,int sum){
    int count = 0;
    unordered_map<int,int>m;
    for(int i:arr){
        count+=m[sum-i];
        m[i]++;
    }
    return count;
}