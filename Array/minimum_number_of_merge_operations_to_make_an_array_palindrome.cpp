int solution(vector<int>&arr,int n){
    int i = 0,j = n-1,count = 0;
    while(i<=j){
        if(arr[i] == arr[j])
            continue;
        else if(arr[i] < arr[j]){
            arr[i+1]+=arr[i];
            i++;
            count++;
        }
        else{
            arr[j-1]+=arr[j];
            j--;
            count++;
        }
    }
    return count;
}