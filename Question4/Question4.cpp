#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int totalPairs(int n, vector<int> &values)
{
    int result = 0;
    int max = 0;
    for (int left = 0; left < n-1; left++)
    {
        int end = max == left ? n : max;
        max = left + 1;
        result += 1;
        for (int right = left + 2; right < end; right++)
        {
            if (values[right - 1] > values[left])
            {
                break;
            }
            if (values[right] > values[max])
            {
                max = right;
                result += 1;
            }
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }
    int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line

    return 0;
}
