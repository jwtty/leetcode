class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        stringstream sen(sentence);
        string res="";
        string token;
        TrieTree tree;
        tree.buildTree(dict);
         while(getline(sen,token,' ')){
             res+=tree.replace(token);
             res+=" ";
         }
        return res.substr(0,res.size()-1);  //ignore last space
    }
    
class TrieNode{
public:
    bool end;
    string str;
    TrieNode* children[26];
    TrieNode(bool flag, string s){
        end=flag;
        str=s;
        memset(children, 0, sizeof(children));;
        }
    };
class TrieTree{
public:
        TrieNode* root;
        TrieTree(){
            root= new TrieNode(false,"");
        }
    
       void buildTree(vector<string>& dict){
            for(string s:dict){
                TrieNode* cur =root;
                for(char c:s){
                    if(cur->children[c-'a'] == NULL){
                        cur->children[c-'a'] = new TrieNode(false,"");
                        cur = cur->children[c-'a'];
                    }
                    else if(cur->children[c-'a']->end==true){   //if a shorter root exists, we just stop build
                        cur=NULL;
                        break;
                    }
                    else cur=cur->children[c-'a'];
                }
                if(cur!=NULL){    //mark the string and flag
                    cur->end=true;
                    cur->str=s;
                }
            }
           return ;
        }
        string replace(string s){
            TrieNode* cur =root;
            string res="";
            for(char c:s){
                cur=cur->children[c-'a'];
                if(cur==NULL) break;
                if(cur->end==true){
                    res=cur->str;
                    break;
                }
            }
            if(res!="") return res;
            return s;
        }
    };

};