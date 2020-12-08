struct min_max{
    int minElement,maxElement;
    min_max(){
        minElement = INT_MAX;
        maxElement = INT_MIN; 
    }
    min_max(int a,int b){
        minElement = a;
        maxElement = b; 
    }
};

min_max brute_force(vector<int>&arr){
    min_max result;
    for(int i:arr){
        result.minElement = min(result.minElement,i);
        result.maxElement = max(result.maxElement,i);
    }
    return result;
    // time = O(n)
    // space = O(1)
    // number of comparison = 2*n
}

min_max optimised(vector<int>&arr,int low,int high){
    if(low == high){
        return {arr[low],arr[low]};
    }
    if(high == low+1){
        if(arr[low]>arr[high])
            return {arr[high],arr[low]};
        else 
            return {arr[low],arr[high]};
    }
    int mid = low + (high-low)/2;
    min_max left = optimised(arr,low,mid);
    min_max right = optimised(arr,mid+1,high);
    return {min(left.minElement,right.minElement),max(left.maxElement,right.maxElement)};
    // time = O(n)
    // space = O(1) + stack
    /* number of comparison 
        T(n) = 2*T(n/2) + 2
        T(1) = 0
        T(2) = 1
        3*n/2 - 2

    */

}