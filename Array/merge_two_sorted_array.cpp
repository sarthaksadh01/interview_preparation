vector<int>brute_force(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int>result;
    int i = 0,j=0;
    while(i<n && j<m){
        int nextElement = (arr1[i]<arr2[j])?arr1[i++]:arr2[j++];
        result.push_back(nextElement);
    }
    while(i<n){
        result.push_back(arr1[i++]);
    }
     while(j<m){
        result.push_back(arr2[j++]);
    }
    return result;
    //T = O(n+m)
    //Space = O(n+m);
}

void solution(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();
    int m = arr2.size();
    arr1.resize(n+m);
    int i = n-1,j=m-1;
    int idx = n+m-1;
    while(i>=0 && j>=0){
         int nextElement = (arr1[i]>arr2[j])?arr1[i--]:arr2[j--];
         arr1[idx--] = nextElement;
    }
     while(j>=0){
       arr1[idx--] = arr2[j--];
    }

    //T = O(n+m)
    //Space = O(1);

}