int brute_force1(vector<int>&arr,int k){
    if(k>arr.size())
        return -1;
    sort(begin(arr),end(arr));
    return arr[k-1];
    // Time = O(nlogn)
    // space  = O(1)
}

int brute_force2(vector<int>&arr,int k){
    if(k>arr.size())
        return -1;
    priority_queue<int>pq;
    for(int i:arr){
        pq.push(i);
        if(pq.size()>k)
            pq.pop();
    }
    return pq.top();

    //Time = O(nlog(k))
    // Space = O(k)

}

int optimised(vector<int>&arr,int k){
    if(k>arr.size())
        return -1;
    auto partition = [&](int left,int right){
        int pivot = arr[left];
        l=left+1,r=right;
        while(l<=r){
            if(arr[l]>=pivot && arr[r]<=pivot){
                swap(arr[l++],arr[r--]);
            }
            if(arr[l]<=pivot)
                l++;
            if(arr[r]>=pivot)
                r--;
        }
        swap(arr[left],arr[r]);
        return r;
    };
    int left = 0,right = arr.size()-1;
    while(true){
        int pivot = partition(left,right);
        if(pivot == k-1)
            return arr[k-1];
        else if(pivot < (k-1)){
            left = pivot+1;
        }
        else{
            right = pivot-1;
        }
    }
    // T = O(n) (average and O(n^2) worst)
    //space  =O(1)
    // use shuffling for worst O(n)
}