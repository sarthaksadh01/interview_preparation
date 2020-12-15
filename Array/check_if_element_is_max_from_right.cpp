int brute_force(vector<int>&arr){
    int count = 0;
    for(int i = 0;i<arr.size();i++){
        int right = INT_MIN;
        for(int j = i+1;j<arr.size();j++)
            right = max(right,arr[i]);
        if(arr[i]>=right)
            count++;
    }
    return count;

}

int solution(vector<int>&arr){
    int count = 0;
    int right = INT_MIN;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i] >= right)
            count++;
        right = max(right,arr[i]);
    }
    return count;
}