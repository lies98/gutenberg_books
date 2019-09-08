#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <memory>
#include <chrono>
#include"mymap.hpp"


using up8::mytrie;
using hmap = std::unordered_map<std::string,int>;



using stdtrie = class trie {
  std::unordered_map<char, std::unique_ptr<trie>> next_char_;
  int count_;
public:

  std::unique_ptr<trie> root;
void insert(const std::string& str){


	    if (root == nullptr) {
	    	root=std::make_unique<trie>();
	    }
	    trie * temp = root.get();
	    for (const char& c : str) {
             if (temp->next_char_.find(c) == temp->next_char_.end()) {
                temp->next_char_[c] = std::make_unique<trie>();
             }
        temp = temp->next_char_[c].get();
        }
        temp->count_++;     
}

};




void first (std::string namefile){
  hmap en;
  std::ifstream ifs (namefile);

  char c = ifs.get();
  std::string mot;
  while (ifs.good()) {
    if((c >= 'a' && c<='z') || (c>='A' && c<='Z')){ 
      mot.push_back(c);
     
    }
    else{
      if(!(mot.empty())){
        en[mot]++;
        mot.clear();
      }
    }
    
     c = ifs.get();
  }
  ifs.close();
}

void seconde (stdtrie* t,std::string namefile){
  std::ifstream ifs (namefile);

  char c = ifs.get();
  std::string mot;
  while (ifs.good()) {
    if((c >= 'a' && c<='z') || (c>='A' && c<='Z')){ 
      mot.push_back(c);
     
    }
    else{
      if(!(mot.empty())){
        t->insert(mot);
        mot.clear();
      }
    }
    
     c = ifs.get();
  }
  ifs.close();
}

void third (mytrie* t,std::string namefile){
  std::ifstream ifs (namefile);

  char c = ifs.get();
  std::string mot;
  while (ifs.good()) {
    if((c >= 'a' && c<='z') || (c>='A' && c<='Z')){ 
      tolower(c);
      mot.push_back(c);
     
    }
    else{
      if(!(mot.empty())){
        t->insert(mot);
        mot.clear();
      }
    }
    
     c = ifs.get();
  }
  ifs.close();
}


int main () {
  auto avant = std::chrono::system_clock::now();
  first ("zambs10.txt");
  auto apres = std::chrono::system_clock::now();
  auto duree = apres - avant;
  std::cout << "unordered_map " << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(duree).count() << "ms" << '\n';
  stdtrie test;
  stdtrie test2;
  auto avant2 = std::chrono::system_clock::now();
  seconde(&test,"zambs10.txt");
  auto apres2 = std::chrono::system_clock::now();
  auto duree2 = apres2 - avant2;
  std::cout << "trie " << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(duree2).count() << "ms" << '\n';
  auto avant3 = std::chrono::system_clock::now();
  seconde(&test2,"zambs10.txt");
  auto apres3 = std::chrono::system_clock::now();
  auto duree3 = apres3 - avant3;
  std::cout << "mytrie " << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(duree3).count() << "ms" << '\n';


  
  return 0;
}
