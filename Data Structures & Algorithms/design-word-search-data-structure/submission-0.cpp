class Tier{
    public:
    Tier* links[26];
    bool flag;
    Tier(){
        flag=false;
        for(int i=0;i<26;i++){
            links[i]=nullptr;
        }
    }
bool containskey(char ch){
    return this->links[ch-'a']!=nullptr; 
}
void put(char ch){
    this->links[ch-'a']=new Tier();
}
Tier* get(char ch){
    return this->links[ch-'a'];
}
void setEnd(){
    this->flag= true;
}
bool isEnd(){
    return flag;
}
};
class WordDictionary {
    private: 
    Tier* root;
public:
    WordDictionary() {
        root=new Tier();
    }
    
    void addWord(string word) {
        Tier* node =root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i]);
            }
            node =node->get(word[i]);
        }
        node->setEnd();
    }
    bool searchWord(string & word, int ind,int &n,Tier* root){
        if(root==nullptr)return false;
        if(ind==n)return root->isEnd();
        if(word[ind]=='.'){
            for(int i=0;i<26;i++){
                if(root->containskey((char)('a'+i))){
                    bool val = searchWord(word,ind+1,n,root->get((char)('a'+i)));
                    if(val)return true;
                }
            }
        }
        else if(root->containskey(word[ind])){
             bool val = searchWord(word,ind+1,n,root->get(word[ind]));
                    if(val)return true;
        }
        return false;

    }
    bool search(string word) {
         Tier* node =root;
       int n =word.size();
       return searchWord(word,0,n,root);
    }
};
