string solution(int n){
    if(n<0)
        return "-1";  
    vector<int>res = {1};
    for(int i = 2;i<=n;i++){
        int carry = 0;;
        for(int  &val:res){
            int prod = val * i + carry;
            val=prod%10;
            carry = prod/10;
        }
        if(carry)
            res.push_back(carry);
    }
    reverse(res.begin(),res.end());
    string fact = "";
    for(int val:res)
        fact.append(to_string(val));
    return fact;
}