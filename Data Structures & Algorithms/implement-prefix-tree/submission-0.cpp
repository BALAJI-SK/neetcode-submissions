class SmartNode {
public:
    unique_ptr<SmartNode> links[26];
    bool flag;

    SmartNode():flag(false) {}

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch){
        links[ch - 'a'] = make_unique<SmartNode>();
    }

    void setEnd(){
        flag = true;
    }

    SmartNode* get(char ch){
        return links[ch - 'a'].get();
    }

    bool isEnd(){
        return flag;
    }
};
class PrefixTree {
    private: 
     unique_ptr<SmartNode> root;
public:
    PrefixTree():root(make_unique<SmartNode>()){
 
    }
    
    void insert(string word) {
        SmartNode* node  =  root.get();
      for(size_t i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        SmartNode* node  =  root.get();
      for(size_t i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
          SmartNode* node  =  root.get();
      for(size_t i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
