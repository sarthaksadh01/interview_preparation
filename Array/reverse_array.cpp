void reverse_iterative(vector<int>&arr){
    int startIndex = 0;
    int endIndex = arr.size()-1;
    while(startIndex < endIndex){
        swap(arr[startIndex++],arr[endIndex--]);
    }
}
void reverse_recursive(vector<int>&arr,int startIndex,int endIndex){
    if(startIndex >= endIndex)
        return;
    swap(arr[startIndex],arr[endIndex]);
    reverse_recursive(arr,startIndex+1,enIndex-1);
}

// time => O(n)
// space => O(1) plus stack for recursion