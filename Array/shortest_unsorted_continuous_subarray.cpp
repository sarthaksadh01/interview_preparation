int brute_force(vector<int>&arr){ 
    int l = INT_MAX,r = INT_MIN,n=arr.size();
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(arr[i]> arr[j]){
                l = min(l,i);
                r = max(r,j);
            }
        }
    }
    return r-l+1;
}
int solution1(vector<int>&arr){
    vector<int>temp = arr;
    sort(begin(temp),end(temp));
    int l = -1,r = arr.size(),n=arr.size();
    for(int i = 0;i<n;i++)
        if(temp[i]!=arr[i]){
            l=i;
            break;
        }
    for(int i = n-1;i>=0;i--)
        if(temp[i]!=arr[i]){
            r=i;
            break;
        }

    return r-l+1;

}

int solution2(vector<int>&arr){
    int l = INT_MAX,r = INT_MIN;
    stack<int>s;
    for(int i = 0;i<n;i++){
        while(!s.empty() && arr[i] < arr[s.top()]){
            l = min(l,s.top())
            s.pop();
        }
        s.push(i);
    }

    for(int i = n-1;i>=0;i--){
        while(!s.empty() && arr[i] > arr[s.top()]){
            r = max(r,s.top())
            s.pop();
        }
        s.push(i);
    }
    return r-l+1;

}
