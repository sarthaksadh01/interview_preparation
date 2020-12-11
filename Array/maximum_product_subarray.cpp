int brute_force(vector<int>&arr,int n){
    // check every subarray
}
int solution(vector<int>&arr, int n) {

	    int minVal = arr[0],maxVal = arr[0],result = INT_MIN;
	    for(int i = 1;i<n;i++){
	        if(arr[i] < 0){
	            swap(minVal,maxVal);
	        }
	        minVal = min(arr[i],arr[i]*minVal);
	        maxVal = min(arr[i],arr[i]*maxVal);
	        result = max(result,maxVal);
	    }
	    return max(result,maxVal);
}