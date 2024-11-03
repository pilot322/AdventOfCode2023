#include <iostream>
#include <fstream>
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
        temp += c;
        root = root->child[c-'a'];
        
        if(root == nullptr) break;

        if(root->wordEnd){
            return text_to_int[temp];
        }
    }
    return 0;
}

int first_digit(string &buf, TrieNode* root){
    for(int i = 0; i < buf.length(); i++){
        if(buf[i] >= '0' && buf[i] <= '9'){
            return buf[i] - '0';
        }

        string temp;
        for(int j = 0; j < 5; j++){
            if(i+j>=buf.length()) break;
            temp += buf[i + j]; 
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
        for(int j = 0; j < 5; j++){
            if(i+j>=buf.length()) break;
            temp += buf[i + j]; 
        }
        int result = searchKey(root, temp);
        if(result) return result;

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
    
    text_to_int["one"] = 1;
    text_to_int["two"] = 2;
    text_to_int["three"] = 3;
    text_to_int["four"] = 4;
    text_to_int["five"] = 5;
    text_to_int["six"] = 6;
    text_to_int["seven"] = 7;
    text_to_int["eight"] = 8;
    text_to_int["nine"] = 9;
    int sum = 0;
    
    while(getline(input, buf)){
        int n = first_digit(buf, trie_root) * 10 + last_digit(buf, trie_root);
        sum += n;
    }
    
    input.close();

    delete trie_root;

    cout << sum << endl;
}
