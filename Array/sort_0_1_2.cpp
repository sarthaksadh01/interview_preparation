void brute_force1(vector<int>&arr){
    sort(begin(arr),end(arr));
    // T = O(nlogn)
}
void brute_force2(vector<int>&arr){
    vector<int>count = {0,0,0};
    for(int i:arr)
        count[i]++;
    int idx = 0;
    for(int i=0;i<3;i++){
        while(count[i]--){
            arr[idx++] = i;
        }
    }
    // T = O(n)*2
}
void solution(vector<int>&arr){
    int curr_zero = 0;
    int curr_two = arr.size()-1;
    int idx = 0;
    while(idx < curr_two){
        if(arr[idx] == 0){
            swap(arr[idx++],arr[curr_zero++]);
        }
        else if(arr[idx]==2){
             swap(arr[idx++],arr[curr_two--]);
        }
        else{
            idx++;
        }
    }
   // T = O(n)
}