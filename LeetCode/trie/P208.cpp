#include <map>
#include <string>
#include <assert.h>

/**
 * Definition for a trie node
 */
class Node {
    public:
        char value;
        std::map<char, Node*> next;
        bool end = false;
        Node() {}
        Node(char value) {
            this->value = value;
        }
        Node(char value, std::map<char, Node*> next) {
            this->value = value;
            this->next = next;
        }
};

class Trie {
public:
    Node *head = new Node('0');
    /**
     * Problem from LeetCode 208: Implement Trie (Prefix Tree). You can find
     * the problem
     * <a href="https://leetcode.com/problems/implement-trie-prefix-tree/">
     * here</a>.
     */
    Trie() {
        
    }
    
    /**
     * Inserts a word into trie
     *
     * @param[in] word: Word to insert into trie
     */
    void insert(std::string word) {
        Node *node = head;
        for (const char letter : word) {
            if (!(node->next.count(letter))) {
                Node *new_letter = new Node(letter);
                node->next[letter] = new_letter;
            }
                node = node->next[letter];
        }
        node->end = true;
    }
    
    /**
     * Search for word in trie
     *
     * @param[in] word: Word to search in trie
     * @returns Returns if `word` is in trie
     */
    bool search(std::string word) {
        Node *node = head;
        for (const char letter : word) {
            if (!(node->next.count(letter))) {
                return false;
            }
            node = node->next[letter];
        }

        return node->end;
    }
    
    /**
     * Search for prefix in trie
     *
     * @param[in] prefix: Prefix to search in trie
     * @returns Returns if there is any word in trie that starts with the
     * given prefix.
     */
    bool starts_with(std::string prefix) {
        Node *node = head;
        for (const char letter : prefix) {
            if (!(node->next.count(letter))) {
                return false;
            }
            node = node->next[letter];
        }

        return true;
    }
};

int main(int argc, char const *argv[]) {
    Trie *trie = new Trie();

    trie->insert("apple");
    assert(trie->search("apple"));
    assert(!trie->search("app"));
    assert(trie->starts_with("app"));
    trie->insert("app");
    assert(trie->search("app"));

    return 0;
}
