class TrieNode{  //initialize your data structure here 
    public:
    bool isspecial;
    TrieNode *children[26];
    TrieNode(){
        isspecial = false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {  // this is constructor 
        root = new TrieNode();
    }
     

     //insert the word into trie
    void insert(string word) {
        TrieNode* curr= root;
        for(auto it : word){
            if(curr->children[it-'a']==NULL)
            curr->children[it-'a']= new TrieNode();
            curr= curr->children[it-'a'];
        }
        curr->isspecial=true;
    }
    

    //return if the word is present in tree or not
    bool search(string word) {
        TrieNode * curr=root;
        for(auto it : word){
            if(curr->children[it-'a']==NULL)
            return false;
            curr= curr->children[it-'a'];
        }
        return curr->isspecial;
    }
    
    //return if the word start with particular prefix present in trie or not
    
    bool startsWith(string word) {
        TrieNode * curr= root;
        for(auto it : word){
            if(curr->children[it-'a']==NULL)
            return false;
            curr= curr->children[it-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
