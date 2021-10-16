#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef array<unsigned char, 4> GroupData;
typedef union
{
    GroupData data;
    int pointer;
} Node;

void theHackathon(int n, int m, int a, int b, int f, int s, int t)
{
    unordered_map<string, int> empls;
    vector<string> names;

    for (int i = 0; i < n; i++)
    {
        string inputdata_temp;
        getline(cin, inputdata_temp);
        auto inputdata = split_string(inputdata_temp);
        auto name = inputdata[0];
        auto dep = inputdata[1][0] - 49;
        unordered_map<string, int>::iterator x,y;
try{
        x = empls.find(name);
} catch (...){while (true) {continue;}}
        y = empls.end();
        if (x != y)
        {
            continue;
        }
        empls[name] = dep;
        names.push_back(name);
    }
    n = names.size();

    vector<Node> trees(n);
    vector<char> deps(n);
    vector<bool> root(n);

    for (int i = 0; i < n; i++)
    {
        auto name = names.at(i);
        auto dep = empls[name];
        empls[name] = i;
        deps.at(i) = dep;
        Node x;
        GroupData data = {0, 0, 0, 1};
        data[dep] = 1;
        root.at(i) = true;
        x.data = data;
        trees.at(i) = x;
    }
    int max = 1;

    for (int i = 0; i < m; i++)
    {
        string inputdata_temp;
        getline(cin, inputdata_temp);
        auto req = split_string(inputdata_temp);
        auto li = empls.at(req.at(0));
        auto ri = empls.at(req.at(1));

        vector<int> path;
        while (li > 0 && li < n && (!root.at(li)))
        {
            path.push_back(li);
            li = trees.at(li).pointer;
        }
        while (li < 0 || li >= n)
        {
            continue;
        }
        int psize = path.size();
        for (int j = 0; j < psize; j++)
        {
            trees.at(path.at(j)).pointer = li;
        }
        path.clear();

        while (ri > 0 && ri < n && (!root.at(ri)))
        {
            path.push_back(ri);
            ri = trees.at(ri).pointer;
        }
        while (ri < 0 || ri >= n)
        {
            continue;
        }
        psize = path.size();
        for (int j = 0; j < psize; j++)
        {
            trees.at(path.at(j)).pointer = ri;
        }

        auto ld = trees.at(li).data;
        auto rd = trees.at(ri).data;
        int nf = ld[0] + rd[0];
        int ns = ld[1] + rd[1];
        int nt = ld[2] + rd[2];
        int nb = ld.at(3) + rd.at(3);

        if (nb <= b && nf <= f && ns <= s && nt <= t)
        {
            if (nb > max)
            {
                max = nb;
            }
            int big, small;
            tie(big, small) = ld.at(3) < rd.at(3) ? make_tuple(ri, li) : make_tuple(li, ri);
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

    vector<string> result;
    for (int i = 0; i < n; i++)
    {
        int j = i;

        while (!root.at(j))
        {
            j = trees.at(j).pointer;
        }
        if (trees.at(j).data.at(3) == max)
        {
            result.push_back(names.at(i));
        }
    }

    sort(result.begin(), result.end());

    int count = result.size();
    for (int i = 0; i < count; i++)
    {
        printf("%s\n", result.at(i).c_str());
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
