#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26];
    bool flag = false;
    string word = "";

    bool containKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    void putKey(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;
    void dfs(Node *node, vector<string> &tmp)
    {
        if (!node)
            return;
        if (node->isEnd())
            tmp.push_back(node->word);
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            if (node->containKey(ch))
            {
                dfs(node->getNode(ch), tmp);
            }
        }
    }

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->putKey(word[i], new Node());
            }
            node = node->getNode(word[i]);
        }

        node->setEnd();
        node->word = word;
    }

    vector<string> autoComplete(string prefix)
    {
        vector<string> tmp;
        Node *node = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containKey(prefix[i]))
                return {};
            node = node->getNode(prefix[i]);
        }

        dfs(node, tmp);
        return tmp;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apex");
    trie.insert("bat");

    vector<string> result = trie.autoComplete("ap");

    for (auto word : result)
    {
        cout << word << " ";
    }
}
