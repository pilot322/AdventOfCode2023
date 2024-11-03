#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> text_to_int;

struct TrieNode {
    TrieNode* child[26];

    bool wordEnd;

    TrieNode()
    {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
    ~TrieNode(){
        for(int i = 0; i < 26; i++){
            delete child[i];
        }
    }
};

void insertKey(TrieNode* root, const string& key) {
    TrieNode* curr = root;

    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) {
            TrieNode* newNode = new TrieNode();
            curr->child[c - 'a'] = newNode;
        }
        curr = curr->child[c - 'a'];
    }

    curr->wordEnd = true;
}


int searchKey(TrieNode* root, const string& key){
    string temp;

    for(char c : key){
        if(root->child[c-'a'] == nullptr){
            break;
        }
        temp += c;
        root = root->child[c-'a'];
    }
    
    if(text_to_int.find(temp) != text_to_int.end()){
        return text_to_int[temp];
    }

    return 0;
}

int first_digit(string &buf, TrieNode* root){
    for(int i = 0; i < buf.length(); i++){
        if(buf[i] >= '0' && buf[i] <= '9'){
            return buf[i] - '0';
        }

        string temp;
        for(int j = 0; j < 5 - (i - 5 < buf.length()? 0 : buf.length() - i );j++){
           temp += buf[buf.length()-i + j]; 
        }
        int result = searchKey(root, temp);

        if(result) return result;
    }
    return 0;
}

int last_digit(string &buf, TrieNode* root){
    for(int i = buf.length()-1; i >= 0; i--){
        if(buf[i] >= '0' && buf[i] <= '9'){
            return buf[i] - '0';
        }
        string temp;
        for(int j = 0; j < 5 - (i - 5 < buf.length()? 0 : buf.length() - i );j++){
           temp += buf[buf.length()-i + j]; 
        }
        if(searchKey(root, temp)) return true;


     } 
        
    return 0;
}

int main(){
    ifstream input("input.txt");
    string buf;
    TrieNode* trie_root = new TrieNode();
    insertKey(trie_root, "one");
    insertKey(trie_root, "two");
    insertKey(trie_root, "three");
    insertKey(trie_root, "four");
    insertKey(trie_root, "five");
    insertKey(trie_root, "six");
    insertKey(trie_root, "seven");
    insertKey(trie_root, "eight");
    insertKey(trie_root, "nine");
    int sum = 0;
        
    while(getline(input, buf)){
        // find first digit
        //
        int n = first_digit(buf, trie_root) * 10 + last_digit(buf, trie_root);
        cout << n << endl;
        sum += n;
    }
    
    input.close();

    delete trie_root;

    cout << sum << endl;
}
