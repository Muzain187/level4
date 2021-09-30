#include<string>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }

     bool search(TrieNode *root,string word) {
        // Write your code here
        if(word.size() == 0){
            if(root->isTerminal)
                return true;
            else
                return false;
        }
         
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            TrieNode *child = root->children[index];
            return search(child,word.substr(1));
        }
        else
            return false;
    }
    bool search(string word) {
        // Write your code here
        return search(root,word);
    }
    void removeword(TrieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }

        TrieNode *child;
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else
            return;
        removeword(child,word.substr(1));

        //Remove the word from Trie
        if(child->isTerminal == false){
            for(int i=0;i<26;i++){
                if(child->children[i] != NULL)
                    return;
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    void removeword(string word){
        removeword(root,word);
    }
};