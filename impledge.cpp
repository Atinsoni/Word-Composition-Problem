#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Node{
  public:
  bool flag;
  Node* links[26];
  Node(){  // constructor to initialize nodes.
    flag = 0;
    for(int i = 0;i < 26;i++) 
      links[i] = NULL;
  }
};

class Trie{  
  public:
  Node* root;
  Trie(){
    root = new Node();
  }
  
  // function to insert the string in the trie data structure.
  void insert(string s){
    Node* node = root;
    for(int i = 0;i < s.size();i++){
      if(node->links[s[i] - 'a'] == NULL){ 
        node->links[s[i] - 'a'] = new Node();
      }
      node = node->links[s[i] - 'a'];
    }
    node->flag= 1;
  }

  // function to reverse the flag variable of the above Node class
  void reverseFlag(string s){
    Node* node = root;
    for(int i = 0; i < s.size(); i++){
      node = node->links[s[i] - 'a'];
    }
    node->flag=!(node->flag);
  }
  
  // function to find the string in trie data structure
  bool find(string s){
    Node* node = root;
    for(int i = 0; i < s.size(); i++){
      if(node->links[s[i] - 'a']==NULL) 
        return 0;
      node = node->links[s[i] - 'a'];
    }
    return node->flag;
  }
};

Trie trie;

// function to check the given string is a compound word or not.
bool compoundWord(string s) {
  vector<bool> dp(s.size()+1, 0);
  dp[0] = true;
  for(int i=1; i<=s.size(); i++){
    for(int j=0; j<i; j++){
      if(dp[j] && trie.find(s.substr(j, i-j))){
        dp[i] = true;
        break;
      }
    }
  }
  return dp[s.size()];
}

// function to find the Longest compound word and the Second longest compound word.
void solve(vector<string>&v, int n){
  string Longest_Compound_Word="";
  string Second_Longest_Compound_Word="";
  for(auto it:v) {
    trie.insert(it);
  }
  for(int i=0;i<n;i++){
    string temp=v[i];
    trie.reverseFlag(temp);
    if(compoundWord(temp) and temp.size()>Longest_Compound_Word.size()){
      Longest_Compound_Word = temp;
    }
    trie.reverseFlag(temp);
  }

  for(int i=0;i<n;i++){
    string temp=v[i];
    if(temp==Longest_Compound_Word) {
      continue;
    }
    trie.reverseFlag(temp);
    if(compoundWord(temp) and temp.size()>Second_Longest_Compound_Word.size()){
      Second_Longest_Compound_Word = temp;
    }
    trie.reverseFlag(temp);
  }
  cout << "Longest Compound Word: " << Longest_Compound_Word<<endl;
  cout << "Second Longest Compound Word: " << Second_Longest_Compound_Word;
}


int main(){
  vector<string> v;

  //taking input from Input_01 file.
  ifstream inputFile("Input_01.txt");
  if (!inputFile.is_open()) {
      cout << "Failed to open the file." << endl;
      return 1;
  }

  string line;
  auto start_time = chrono::high_resolution_clock::now();

  while (getline(inputFile, line)) {
      v.push_back(line);
  }
  
  int n= v.size();
  inputFile.close();
  solve(v,n);

  auto end_time = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
  cout << "\nTime taken to process the file: " << duration.count() << " milliseconds" << endl;
  cout << endl;

  v.clear(); 

  // taking input from Input_02 file.
  ifstream inputFile1("Input_02.txt");
  if (!inputFile1.is_open()) {
      cerr << "Failed to open the file." << endl;
      return 1;
  }

  start_time = chrono::high_resolution_clock::now();

  while (getline(inputFile1, line)) {
      v.push_back(line);
  }
  n= v.size();
  inputFile1.close();
  solve(v,n);
  end_time = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
  cout << "\nTime taken to process the file: " << duration.count() << " milliseconds" << endl;


  return 0;
}