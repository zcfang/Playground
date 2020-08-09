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

class WordDictionary {
public:
    Node *head = new Node('0');
    /**
     * Problem from LeetCode 211: Add and Search Word - Data structure design.
     * You can find the problem
     * <a href="https://leetcode.com/problems/add-and-search-word-data-structure-design/">
     * here</a>.
     */
    WordDictionary() {
        
    }
    
    /**
     * Inserts a word into WordDictionary data structure
     *
     * @param[in] word: Word to insert into WordDictionary data structure
     */
    void add_word(std::string word) {
        Node *node = head;
        for (const char letter : word) {
            if (!(node->next.count(letter))) {
                Node *next_letter = new Node(letter);
                node->next[letter] = next_letter;
            }
            node = node->next[letter];
        }
        node->end = true;
    }
    
    /**
     * Search for word in WordDictionary data structure
     *
     * @param[in] word: Word to search in WordDictionary data structure. A word
     * could contain the dot character '.' to represent any one letter.
     * @returns Returns true if `word` is in WordDictionary data structure
     */
    bool search(std::string word) {
        Node *node = head;
        for (std::size_t i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                return backtrack(i, word, node);
            } else if (!(node->next.count(word[i]))) {
                return false;
            } else {
                node = node->next[word[i]];
            }
        }

        return node->end;
    }
private:
    /**
     * Recursively finds `word` when `word` contains a dot character.
     *
     * @param[in] index: Starting index of `word` to start searching
     * @param[in] word: Word to search in WordDictionary data structure. A word
     * could contain the dot character '.' to represent any one letter.
     * @param[in] node: Starting node to start searching for `word`
     * @returns Returns true if `word` is in WordDictionary data structure
     */
    bool backtrack(int index, std::string word, Node *node) {
        for (const std::pair<char, Node*> next : node->next) {
            bool move_back = false;
            Node *explore = next.second;
            if (index + 1 >= word.size() && !(explore->end)) continue;
            for (std::size_t i = index + 1; i < word.size(); i++) {
                if (word[i] == '.') {
                    if (backtrack(i, word, explore)) return true;
                    move_back = true;
                    break;
                } else if (!(explore->next.count(word[i]))) {
                    move_back = true;
                    break;
                } else {
                    explore = explore->next[word[i]];
                }
            }
            if (move_back) continue;

            return explore->end;
        }

        return false;
    }
};

int main(int argc, char const *argv[]) {
    WordDictionary *word_dictionary = new WordDictionary();

    word_dictionary->add_word("bad");
    word_dictionary->add_word("dad");
    word_dictionary->add_word("mad");
    assert(!word_dictionary->search("pad"));
    assert(word_dictionary->search("bad"));
    assert(word_dictionary->search(".ad"));
    assert(word_dictionary->search("b.."));

    return 0;
}
