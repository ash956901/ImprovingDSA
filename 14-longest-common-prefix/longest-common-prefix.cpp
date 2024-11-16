class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool wordEnd;
        int count = 0;

        TrieNode() {
            wordEnd = false;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };
    class Trie {
    public:
        TrieNode* root = new TrieNode();
        void insert(string& str) {
            TrieNode* curr = root;

            for (auto c : str) {
                if (curr->child[c - 'a'] == NULL) {
                    TrieNode* temp = new TrieNode();
                    curr->count++;
                    curr->child[c - 'a'] = temp;
                }

                curr = curr->child[c - 'a'];
            }
            curr->wordEnd = true;
        }

        string lcp() {
            string ans = "";
            bool flag=false;
            while (root->count == 1 && !root->wordEnd) {
                for (int i = 0; i < 26; i++) {
                    if (root->child[i] != NULL) {
                        root = root->child[i];
                        char c = 'a' + i;
                        ans.push_back(c);
                        flag=true;
                        break;
                    } 
                }

                if(flag==false) break;
            }
            return ans;
        }
    } ;



string longestCommonPrefix(vector<string>& strs) {
    Trie trie;
    for (auto s : strs) {
        if(s=="") return "";
        trie.insert(s);
    }

    string ans = trie.lcp();

    return ans;
}
}
;