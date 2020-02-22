#include<bits/stdc++.h>

// A trie node
struct Trie{
    // true when node is a leaf node
    bool isLeaf;
    
    // each node stores a map of its child nodes
    unordered_map<char, Trie*> map;
};

// Function that returns a new Trie node
Trie* getNewTrieNode(){
    Trie* node = new Trie;
    node->isLeaf = false;
    return node;
}

// Iterative function to insert in a trie node
void insert(Trie*& head, char* str)
{
    if(head == nullptr)
        head = getNewTrieNode();
    
    // start from root node
    Trie* curr = head;
    while(*str)
    {
        // create a new node if path doesn't exists
        if(curr->map.find(*str)==curr->map.end())
            curr->map[*str] = getNewTrieNode();
        
        // go to next node
        curr = curr->map[*str];
        
        // move to next character
        str++;
    }
    // mark node as leaf
    curr->isLeaf = true;
}

int search(Trie* head, char* str)
{
    // return false if Trie is empty
    if (head == nullptr)
        return false;
    
    Trie* curr = head;
    while(*str)
    {
        // go to next node
        curr = curr->map[*str];
        
        // if string is invalid ( reached end of path in Trie )
        if (curr == nullptr)
            return false;
        
        // move to next character
        str++;
    }
    return curr->isLeaf;
}
bool comp(const pair<int,int> a, const pair<int,int> b )
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
    
}
vector<int> Solution::solve(string A, vector<string> &B) {
    Trie* head = getNewTrieNode();
    char *token;
    int count = 0;
    vector<int> ans;
    char Anew[A.length() + 1];
    strcpy(Anew, A.c_str());
    vector<pair<int, int> >foundCount;
    token = strtok(Anew, "_");
    while(token != NULL){
        insert(head, token);
        token = strtok(NULL, "_");
    }
    for(int i = 0; i < B.size(); i++)
    {
        char Bnew[B[i].length() + 1];
        strcpy(Bnew, B[i].c_str());
        token = strtok(Bnew, "_");
        while(token!=NULL){
            bool is_found = search(head, token);
            if(is_found)
            {
                count++;
            }
            token = strtok(NULL, "_");
        }
        foundCount.push_back(make_pair(i,count));
        count = 0;
    }
    sort(foundCount.begin(), foundCount.end(), comp);
    vector<pair<int, int> >::iterator it;
    for(it = foundCount.begin(); it!=foundCount.end(); it++)
    {
        ans.push_back(it->first);
    }
    return ans;
}
