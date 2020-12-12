int brute_force(vector<int>&arr,int n){
    unordered_map<int,int>m;
    for(int i:arr)
        m[i]++;
    for(auto[num,freq]:m){
        if(freq > (n/2))
            return num;
    }
    return -1;

}

int solution(vector<int>&arr,int  n){
    int res = arr[0],freq = 1;
    for(int i = 1;i<n;i++){
        if(arr[i]!=res)
            freq--;
        else freq++;
        if(!freq){
            res = arr[i];
            freq = 1;
        }
    }
    freq = 0;
    for(int i:arr){
        freq+= (i == res);
    }
    return freq > (n/2)?res:-1;
}