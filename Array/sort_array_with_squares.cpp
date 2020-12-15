void brute_force(vector<int> &arr)
{
    sort(begin(arr), end(arr), [](int a, int b) {
        return a * a < b * b;
    });
    transform(begin(arr), end(arr), begin(arr), [](int ele) {
        return ele * ele;
    });
}
void solution(vector<int> &arr)
{
    vector<int> res;
    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        int val = abs(a[l]) < abs(a[r])
                      ? a[l] * a[l++]
                      : a[r] * a[r--];
        res.push_back(val);
    }
    arr = res;
}