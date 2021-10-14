class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
	bool search(TrieNode *root,string word) {
        // Write your code here
        if(word.size() == 0){

            return true;
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
    
    
    void reverseStr(string& str)
	{
    	int n = str.length();
 
	    for (int i = 0; i < n / 2; i++)
        	swap(str[i], str[n - i - 1]);
	}
    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(int i=0;i<words.size(); i++){
            string word = words[i];
            reverseStr(word);
            for(int j=0;j<word.length();j++){
                add(word.substr(j));
            }
        }
        bool ans=false;
        for(int i=0;i<words.size();i++){
            ans = search(words[i]);
            if(ans == false)
                continue;
            else
                return true;
        }
    }
};