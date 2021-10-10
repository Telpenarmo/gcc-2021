#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int cost;
    int amount;
} Pair;

int compare(const void *arg1, const void *arg2)
{
    int l = ((Pair *)arg1)->cost;
    int r = ((Pair *)arg2)->cost;
    return (l - r);
}

int securitiesBuying(int z, int security_value[], int size)
{
    int no_of_stocks = 0;

    Pair pairs[size];

    for (int i = 0; i < size; i++)
    {
        Pair pair;
        pair.amount = i + 1;
        pair.cost = security_value[i];
        pairs[i] = pair;
    }

    qsort(pairs, size, sizeof(Pair), compare);

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        int newSum = sum + pairs[i].amount * pairs[i].cost;
        int diff = z - newSum;
        if (diff >= 0)
        {
            no_of_stocks += pairs[i].amount;
            if (diff == 0)
            {
                return no_of_stocks;
            }
            sum = newSum;
        }
        else
        {
            int overflow = -diff / pairs[i].cost;
            int rest = diff % pairs[i].cost;
            return no_of_stocks + pairs[i].amount - overflow - (rest != 0);
        }
    }

    return no_of_stocks;
}

int main()
{

    int z;
    cin >> z;
    vector<int> input_data;
    string buffer;
    int data;
    getline(cin, buffer);
    getline(cin, buffer);
    istringstream iss(buffer);

    while (iss >> data)
        input_data.push_back(data);

    int n = input_data.size();

    int security_value[n];
    for (int i = 0; i < n; i++)
    {
        security_value[i] = input_data[i];
    }

    int no_of_stocks_purchased = securitiesBuying(z, security_value, n);
    cout << no_of_stocks_purchased;
}
