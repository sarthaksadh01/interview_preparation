void brute_force(vector<int>&v){
    vector<int>neg,pos;
    for(int i:v){
        if(i<0)
            neg.push_back(i);
        else pos.push_back(i);
    }
    int i=0,j=0;
    v.clear();
    while(i<pos.size()&&j<neg.size()){
        v.push_back(neg[j+]);
        v.push_back(pos[i++]);
    }
    while(i<pos.size()){
        v.push_back(pos[i++]);
    }
     while(j<neg.size()){
        v.push_back(neg[i++]);
    }
}
void solution(vector<int>&v){
    int i = 0,j = v.size()-1;
    while(i<j){
        if(v[i] >0 && v[j] <0)
            swap(v[i++],v[j--]);
        if(v[i]<0)
            i++;
        if(v[j]>0)
            j--;
    }
    int neg = 0,pos = j+1;
    while(neg <=j && pos<v.size() && v[pos]>0 && v[neg] < 0){
        swap(v[pos],v[neg]);
        pos+=2;
        neg+=2;
    }
}