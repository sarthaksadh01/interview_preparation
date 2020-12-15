bool brute_force(vector<string>&a){
    // check for all triplets
}

bool Solution(vector<string> &a)
{
    if (a.size() < 3)
        return 0;
    vector<double> b;
    for (auto s : a)
        b.push_back(stod(s));
    sort(b.begin(), b.end());
    int n = b.size(), i = 1, j = n - 1;
    while (i < j)
    {
        double sum = b[i] + b[i - 1] + b[j];
        if (sum <= 1)
            i++;
        else if (sum >= 2)
            j--;
        else
            return true;
    }
    return false;
}

bool solution2(vector<string> &a)
{
    if (a.size() < 3)
        return 0;
    multiset<double> m;
    double currSum;
    for (auto str : a)
    {
        if (m.size() < 3)
        {
            m.insert(stod(str));
            continue;
        }
        currSum = accumulate(m.begin(), m.end(), 0.0);
        m.insert(stod(str));
        if (currSum <= 1)
            m.erase(m.begin());
        else if (currSum >= 2)
            m.erase(--m.end());
        else
            return true;
    }
    currSum = accumulate(m.begin(), m.end(), 0.0);
    return currSum > 1 && currSum < 2;
}