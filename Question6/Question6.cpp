#include <bits/stdc++.h>
#include <variant>

using namespace std;

vector<string> split_string(string);

typedef variant<array<unsigned char, 4>, int> Node;

void theHackathon(int n, int m, int a, int b, int f, int s, int t)
{
    unordered_map<string, char> empls;
    vector<string> names;
    for (int i = 0; i < n; i++)
    {
        string inputdata_temp;
        getline(cin, inputdata_temp);

        vector<string> inputdata = split_string(inputdata_temp);
        auto name = inputdata[0];
        auto dep = inputdata[1][0];
        if (empls.find(name) == empls.end())
        {
            continue;
        }
        empls[name] = dep;
        names.push_back(name);
    }
    n = names.size();

    vector<Node> trees(n);
    vector<char> deps(n);

    for (size_t i = 0; i < n; i++)
    {
        auto name = names[i];
        auto dep = empls[name];
        dep -= 49;
        empls[name] = i;
        deps.push_back(dep);
        Node data = { 0, 0, 0, 1 };
        data[dep] = 1;
        trees.push_back(data);
    }
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);
    cout << sizeof(Node);
    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y)
                                      { return x == y and x == ' '; });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
