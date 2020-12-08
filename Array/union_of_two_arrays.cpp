vector<int>brute_force(vector<int>&a,vector<int>&b){
    // this even works if elements are not distict
    sort(begin(a),end(a));
    sort(begin(b),end(b));
    int i=0,j=0;
    vector<int>res;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            res.push_back(a[i++]);
        }
        else if(a[i]>b[j]){
            res.push_back(b[j++]);
        }
        else{
            res.push_back(a[i++]);
            j++;
        }
    }
    return res;
    // T =O(nlogn + mlogm)
    // S = O(1)
    //Note: can also sort only one array and apply binary search while traversing the second array
}

vector<int>solution(vector<int>&a,vector<int>&b){
    int i=0,j=0;
    vector<int>res;
    unordered_set<int>s(a.begin(),a.end());
    for(int i:s)
        res.push_back(i);
    for(int i:b)
        if(!s.count(i))
            res.push_back(i);
    return res;
    // T =O(m+n)
    // S = O(max(m,n))
}

