#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef array<unsigned char, 4> GroupData;
typedef union
{
    GroupData data;
    int pointer;
} Node;

int get_root(int i, Node trees[], bool root[]);
vector<string> read_many();

void theHackathon(int n, int m, int a, int b, int f, int s, int t)
{
    unordered_map<string, int> empls;
    vector<string> names;

    for (int i = 0; i < n; i++)
    {
        auto inputdata = read_many();
        auto name = inputdata[0];
        auto dep = inputdata[1][0] - 49;
        if (empls.find(name) != empls.end())
        {
            if (empls[name] == dep)
            {
                continue;
            }
        }
        else
        {
            names.push_back(name);
        }
        empls[name] = dep;
    }
    n = names.size();

    Node trees[n];
    char deps[n];
    bool root[n];

    for (int i = 0; i < n; i++)
    {
        auto name = names[i];
        auto dep = empls[name];
        empls[name] = i;
        deps[i] = dep;
        Node x;
        GroupData data = {0, 0, 0, 1};
        data[dep] = 1;
        root[i] = true;
        x.data = data;
        trees[i] = x;
    }
    int max = 1;

    for (int i = 0; i < m; i++)
    {
        auto req = read_many();
        auto li = empls[req[0]];
        auto ri = empls[req[1]];

        li = get_root(li, trees, root);
        ri = get_root(ri, trees, root);

        if (li == ri)
        {
            continue;
        }

        auto ld = trees[li].data;
        auto rd = trees[ri].data;
        int nf = ld[0] + rd[0];
        int ns = ld[1] + rd[1];
        int nt = ld[2] + rd[2];
        int nb = ld[3] + rd[3];

        if (nb <= b && nf <= f && ns <= s && nt <= t)
        {
            if (nb > max)
            {
                max = nb;
            }
            int big, small;
            tie(big, small) = ld[3] < rd[3] ? make_tuple(ri, li) : make_tuple(li, ri);
            trees[small].pointer = big;
            root[small] = false;
            trees[big].data = {(u_char)nf, (u_char)ns, (u_char)nt, (u_char)nb};
        }
    }

    if (max < a)
    {
        printf("no groups\n");
        return;
    }

    set<string> result;
    for (int i = 0; i < n; i++)
    {
        int j = get_root(i, trees, root);
        if (trees[j].data[3] == max)
        {
            result.insert(names[i]);
        }
    }

    for (string name : result)
    {
        printf("%s\n", name.c_str());
    }
}

int get_root(int i, Node trees[], bool root[])
{
    vector<int> path;
    while (!root[i])
    {
        path.push_back(i);
        i = trees[i].pointer;
    }
    for (int j : path)
    {
        trees[j].pointer = i;
    }
    return i;
}

vector<string> read_many()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);
    return split_string(inputdata_temp);
}

int main()
{
    vector<string> inputdata = read_many();

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

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
