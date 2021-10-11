
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef pair<int, int> myPair;

inline bool sortByFirst(const myPair &a, const myPair &b)
{
    return (a.first < b.first);
}

int totalPairs(int n, vector<int> values)
{
    int result = 0;
    int max = 0;
    vector<myPair> sorted(n);
    for (int i = 0; i < n; i++)
    {
        myPair p;
        p.first = values[i];
        p.second = i;
        sorted[i] = p;
    }

    sort(sorted.begin(), sorted.end(), sortByFirst);
    vector<int> positions(n);
    for (int i = 0; i < n; i++)
    {
        positions[sorted[i].second] = i;
    }

    for (int left = 0; left < n - 1; left++)
    {
        int end = max == left ? n : max + 1;
        end = min(end, left+positions[left]);
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
            
            if (positions[left] == positions[right]+1)
            {
                break;
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

