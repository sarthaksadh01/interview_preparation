
int brute_force(vector<int>&height){
    int n = height.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int left = 0,right = 0;
            for(int j = i;j>=0;j--)
                left = max(left,height[j]);
            for(int j = i;j<n;j++)
                right = max(right,height[j]) 
            ans+=min(left,right)-height[i];
        }
        return ans;
}

int solution1(vector<int>& height) {
        int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        int leftMax = 0,rightMax = 0;
        for(int i=0,j=n-1;(i<n&&j>=0);i++,j--){
            leftMax = max(leftMax,height[i]);
            left[i]=leftMax;
            rightMax = max(rightMax,height[j]);
            right[j]=rightMax;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
}
int solution2(vector<int>& height) {
        int n = height.size();
        vector<int>right(n);
        int leftMax = 0,rightMax = 0;
        for(int i=0,j=n-1;(i<n&&j>=0);i++,j--){
            rightMax = max(rightMax,height[j]);
            right[j]=rightMax;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            leftMax = max(height[i],leftMax);
            ans+=min(leftMax,right[i])-height[i];
        }
        return ans;
}
int solution3(vector<int>& height) {
        int i = 0,j= height.size()-1,ans=0;
        int left = INT_MIN,right = INT_MIN;
        while(i<j){
            left = max(left,height[i]);
            right = max(right,height[j]);
            if(left < right)
                ans+=(left-height[i++]);
            else 
                ans+=(right-height[j--]);
        }
        return ans;
}