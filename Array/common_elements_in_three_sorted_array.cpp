vector<int>brute_force(vector<int>&a,vector<int>&b,vector<int>&c){
    unordered_set<int>s1(a.begin(),a.end());
    unordered_set<int>s2;
    for(int i:b){
        if(s1.count(i))
            s2.insert(i);
    }
    vector<int>res;
    for(int i:c){
        if(s2.count(i))
            res.push_back(i);
    }
    return res;
    //T = O(n1+n2+n3)
    //S = O(max(n1,n2,n3))

}

vector<int>solution(vector<int>&a,vector<int>&b,vector<int>&c){
        int i = 0,j=0,k=0;
        vector<int>res;
        while(i< a.size() && j<b.size() && k<c.size()){
            if(a[i] == b[j] && a[i] == c[k]){
                res.push_back(a[i]);
            }
            if(a[i]<a[j])
                i++;
            else if(a[j] < a[k])
                j++;
            else k++;
 
        }
        return res;

    //T = O(n1+n2+n3)
    //S = O(1)
}