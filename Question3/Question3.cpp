#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b)
{
    vector<int> a_prefixes = {0};
    vector<int> b_prefixes = {0};
    int sum = 0;
    int a_size = a.size();
    int a_prefixes_size = 1;
    for (int i = 0; i < a_size; i++)
    {
        sum += a[i];
        if (sum > maxSum)
        {
            break;
        }
        a_prefixes.push_back(sum);
        a_prefixes_size++;
    }
    sum = 0;
    int b_size = b.size();
    for (int i = 0; i < b_size; i++)
    {
        sum += b[i];
        if (sum > maxSum)
        {
            break;
        }
        b_prefixes.push_back(sum);
    }

    int result = 0;
    int j = 0;
    int i = 0;
    j = b_prefixes.size() - 1;
    for (; i < a_prefixes_size; i++)
    {
        while (j >= 0)
        {
            int temp = a_prefixes[i] + b_prefixes[j];
            int pos = i + j;
            if (temp <= maxSum)
            {
                if (pos > result)
                {
                    result = pos;
                }
                break;
            }
            j -= 1;
        }
    }
    return result;
}


int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}