int brute_force(vector<int> &arr)
{
    int n = arr.size();
    int odd = 0, even = 0;
    int leftOdd[n], rightOdd[n];
    int leftEven[n], rightEven[n];
    for (int i = 0; i < n; i++)
    {
        leftOdd[i] = odd;
        leftEven[i] = even;
        if (i % 2 == 0)
            even += arr[i];
        else
            odd += arr[i];
    }
    odd = 0;
    even = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        rightOdd[i] = odd;
        rightEven[i] = even;
        if (i % 2 == 0)
            even += arr[i];
        else
            odd += arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (leftOdd[i] + rightEven[i] == leftEven[i] + rightOdd[i])
        {
            ans++;
        }
    }
    return ans;
}

int solution(vector<int> &arr)
{
    int odd = 0, even = 0, currOdd = 0, currEven = 0, ans = 0;
    for (int i = 0; i < arr.size(); i++)
        if (i % 2)
            odd += arr[i];
        else
            even += arr[i];
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2)
            odd -= arr[i];
        else
            even -= arr[i];
        if (odd + currEven == even + currOdd)
            ans++;
        if (i % 2)
            currOdd += arr[i];
        else
            currEven += arr[i];
    }
    return ans;
}