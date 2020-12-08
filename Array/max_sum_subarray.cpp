
int brute_force(vector<int>&arr){
    int sum = INT_MIN;
    int n = arr.size();
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int j=i;j<n;j++){
            temp+=arr[j];
            sum = max(sum,temp);
        }
    }
    return sum;
}
int solution(vector<int>&arr){
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int i:arr){
        currSum+=i;
        maxSum = max(maxSum,currSum);
        if(currSum<0)
            currSum = 0;
    }
    return maxSum;
}