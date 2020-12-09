struct interval{
    int start,end;
    interval(int a,int b){
        start=a;
        end = b;
    }
}
vector<interval> brute_force(vector<interval>&intervals){
    // graph of overlap intervals and one connected component  = 1 merged interval
    //T = O(n*n)
    //S = O(n*n)
}
vector<interval> solution(vector<interval>&intervals){
    sort(begin(intervals),end(intervas)[auto a,auto b]{
        return a.start < b.start;
    });
    vector<interval>result;
    for(int i=0;i<intervals.size()-1;i++){
        if(intervals[i].end >= intervals[i+1].start){
            intervals[i+1].start = intervals[i].start;
            intervals[i+1].end = max(intervals[i].end,intervals[i+1].end);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    result.push_back(intervals.back());
    //T = O(nlogn)
    //S = O(n)
}