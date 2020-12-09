int brute_force(vector<int>&arr,int n){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            count+=(arr[i]>arr[j]);
        }
    }
    return count;

    //T = O(n*n)
}


int merge(int l,int mid,int r,vector<int>&arr){
    vector<int>temp;
    int i = l,j = mid+1;
    int c = 0;
    while(i<=mid && j<=r){
        if(arr[i] <=arr[j])
            temp.push_back(arr[i++]);
        else{
            c+=(mid-i+1);
            temp.push_back(arr[j++]);
        }
    }
    return c;
}

void merge_sort(vector<int>&arr,int l,int r,int count){
    if(l<r){
        int mid = l + (r-l)/2;
        merge_sort(arr,l,mid,count);
        merge_sort(arr,mid+1,r);
        count+=merge(l,mid,r,arr);
    }
}

int solution1(vector<int>&arr,int n){
    int count = 0;
    merge_sort(arr,0,n-1,count);
    return count;

    //T = O(nlogn)
    //S= O(n)
}


int solution2(vector<int>&arr,int n){
    // self balancing bst
    multiset<int>s;
    s.insert(arr[0]);
    int count = 0;
    for(int i = 1;i<n;i++){
        s.insert(arr[i]);
        count+= distance(s.upper_bound(arr[i],s.end()));
    }
    return count;
    //T = O(n*n) in worst case
    //S= O(n)
}