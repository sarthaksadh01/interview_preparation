vector<int> brute_force(vector<int> &arr, int n, int k)
{
    vector<int> res;
    unordered_map<int, int> m;
    for (int i : arr)
        m[i]++;
    for (auto [num, freq] : m)
    {
        if (freq > (n / k))
            res.push_back(num);
    }
    return res;
}

vector<int> majorityElement(vector<int> &arr,int n, int k )
{
    vector<int> res;
    vector<pair<int, int>> candidates(k - 1, {0, 0});
    for (int i : arr)
    {
        bool flag = false;
        for (auto &[num, freq] : candidates)
        {
            if (num == i)
            {
                freq++;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        flag = false;
        for (auto &[num, freq] : candidates)
        {
            if (!freq)
            {
                num = i;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        for (auto &[num, freq] : candidates)
        {
            freq--;
        }
    }
    for (auto &[num, freq] : candidates)
    {
        freq = 0;
        for (int i : arr)
        {
            if (i == num)
                freq++;
        }
        if (freq > (n / k))
            res.push_back(num);
    }
    return res;
}