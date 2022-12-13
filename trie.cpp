#include<iostream>
using namespace std;

class TrieNode{

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode( char ch){
        data = ch;
        for(int i = 0 ; i<26 ; i++){
            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root =new TrieNode('\0');
    }

    void insertUtilTrie(TrieNode* root , string word){

        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assumpttion is words will be capital
        int index = word[0] - 'A' ;

        TrieNode* child;

        //present or not
        if(root->children[index] != NULL ){
            child = root->children[index];
        }

        else{
            child = new TrieNode(word[0]);
            root->children[index] = child ;
        }

        //recursion
        insertUtilTrie(child,word.substr(1));

    }

    void insertWord(string word){
        insertUtilTrie(root, word);
    }


    bool SearchUtil(TrieNode* root , string word){
        //base case

        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root ->children[index] != NULL){
            child = root->children[index];

        }

        else{
            //absent 
            return false;
        }

        //recursion

        return SearchUtil(child,word.substr(1));
    }

    bool search(string word){
        return SearchUtil(root, word);
    }






       void removeUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = false;
            return ;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        return removeUtil(child, word.substr(1));
    }

    void removeWord(string word){
        removeUtil(root, word);
        return ;
    }

};


int main(){


Trie* t = new Trie();

t->insertWord("ARM");
t->insertWord("DO");
t->insertWord("TIME");

//cout<<" Present or not "<< t->search("TIM") <<endl;
cout<<" Present or not "<< t->search("ARM") <<endl;
t->removeWord("ARM");
cout<<" Present or not "<< t->search("ARM") <<endl;


    return 0;
}