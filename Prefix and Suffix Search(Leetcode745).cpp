/*Design a special dictionary with some words that searchs the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string prefix, string suffix) Returns the index of the word in the dictionary, which has the prefix prefix and the suffix suffix. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.
 */

class WordFilter {
public:
    unordered_map<string,unordered_map<string,int>> mp;
    WordFilter(vector<string>& words) {
        string prefix,suffix,w;
        for(int k=0;k<words.size();k++)
        {
            w=words[k];
            prefix="";
            for(int i=0;i<w.size();i++)
            {
                prefix.push_back(w[i]);
                for(int j=0;j<w.size();j++)
                {
                    suffix=w.substr(j,w.size()); 
                    mp[prefix][suffix]=k;
                }
                
            } 
        }
            
    }
    
    int f(string prefix, string suffix) {
        
        if(mp[prefix].find(suffix)==mp[prefix].end())
            return -1;
        
        return mp[prefix][suffix];
    }
};
