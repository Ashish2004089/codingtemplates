

https://leetcode.com/problems/counting-words-with-a-given-prefix/description/



#include <iostream>
using namespace std;
// #define NULL 0


class TrieNode { //defining my data structure here 
public:
    int wc = 0;
    TrieNode* child[26];
    TrieNode() {
        wc = 0;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() { 
        root = new TrieNode(); 
    }

    //insert the word into trie
    void insert(string word) {
        TrieNode* curr= root;
        for(auto it : word){
            if(curr->child[it-'a']==NULL)
            curr->child[it-'a']= new TrieNode();
            curr= curr->child[it-'a'];
            curr->wc++;
        }
      
    }
   
   bool search(string word) {
        TrieNode * curr=root;
        for(auto it : word){
            if(curr->child[it-'a']==NULL)
            return false;
            curr= curr->child[it-'a'];
        }
        return curr->wc;
    }

    int countPrefix(string s) {
        TrieNode* curr = root;
        int index;
        for (int i = 0; s[i] != '\0'; ++i) {
            index = s[i] - 'a';
            if (curr->child[index] == NULL || curr->child[index]->wc == 0)
                return 0; // No string with given prefix is present
            curr = curr->child[index];
        }
        return curr->wc;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie* newTrie = new Trie();
        for (auto word : words)
            newTrie->insert(word);
        int count = newTrie->countPrefix(pref);
        return count;
    }
};
