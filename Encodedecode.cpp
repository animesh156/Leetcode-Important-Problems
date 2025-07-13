#include <bits/stdc++.h>
using namespace std;

string encode(vector<string> &str)
{

    string encoded;

    for (auto s : str)
    {
        encoded += to_string(s.length()) + '#' + s;
    }

    return encoded;
}

vector<string> decode(string &s)
{
    vector<string> ans;
    int i = 0;
    while (i < s.length())
    {
        int j = i;
        while (s[j] != '#')
            j++;

        int len = stoi(s.substr(i, j - i));

        string decodedString = s.substr(j + 1, len);

        ans.push_back(decodedString);

        i = j + len + 1;
    }

    return ans;
}

int main()
{

    vector<string> str = {"leet", "code"};

    string encoded = encode(str);

    cout << "Encoded string: " << encoded << endl;

    vector<string> ans = decode(encoded);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
