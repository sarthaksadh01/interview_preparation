vector<int> brute_force(vector<int> &arr, int n)
{
    vector<int>res;
    unordered_map<int, int> m;
    for (int i : arr)
        m[i]++;
    for (auto [num, freq] : m)
    {
        if (freq > (n / 3))
            res.push_back(num);
    }
    return res;
}

vector<int> solution(vector<int> &nums,int n)
{
    int num1, num2, c1 = 0, c2 = 0;
    for (int i : nums)
    {
        if (i == num1)
            c1++;
        else if (i == num2)
            c2++;
        else if (!c1)
        {
            num1 = i;
            c1 = 1;
        }
        else if (!c2)
        {
            num2 = i;
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    for (int i : nums)
    {
        c1 += (i == num1);
        c2 += (i == num2);
    }
    vector<int> res;
    if (c1 > (n / 3))
        res.push_back(num1);
    if (c2 > (n / 3))
        res.push_back(num2);

    return res;
}