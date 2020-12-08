int brute_force1(vector<int>&arr){
    sort(begin(arr),end(arr));
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1])
            return arr[i];
    }
    return -1;
     //T= O(nlogn)
    //S = O(1)
}

int brute_force2(vector<int>&arr){
    unordered_set<int>elements;
    for(int i:arr){
        if(elements.count(i))
            return i;
        elements.insert(i);
    }
    return -1;

    //T= O(n)
    //S = O(n)
}

int solution1(vector<int>&arr){
    int low = 0,high = arr.size()-1;
    while(low < high){
        int mid = low+ (high-low)/2;
        int count = 0;
        for(int i:arr){
            if(i <=mid)
                count++;
        }
        if(count<=mid)
            low = mid+1;
        else high = mid;
    }
    return low;
    //T= O(nlogn)
    //S = O(1)
    // original list not modified
}

int solution2(vector<int>&arr){
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);
    slow = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;

    //T= O(n)
    //S = O(1)
    // original list not modified
}

