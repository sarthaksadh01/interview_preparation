int solution(vector<int>&arr,int k,int n){
    int sum = 0;
    for(int i = 0;i<k;i++)
        sum+=arr[i];
    int maxSum = sum;
    for(int i = n-1,j=0;j<k;i--,j--){
        sum-=arr[k-1-j];
        sum+=arr[i];
        maxSum = max(sum,maxSum);
    }
    return maxSum;
}