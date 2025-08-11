#ifndef LETTER_NODE_H
#define LETTER_NODE_H

#include <string>
#include <cctype>

/**
 * @class LetterNode
 * @brief Each node has a child for each letter than can be appended to it to potentially make a valid word.
 * 
 * If a node represents the termination of a real word, it will also store that information.
 */
class LetterNode {
public:
    /**
     * @brief No-args constructor. Useful for making the root node of a LetterTree.
     */
    LetterNode();

    /**
     * @brief Destructor, deletes all child nodes.
     */
    ~LetterNode();

    /**
     * @brief Gets the child node pointer at a given letter.
     * @param letter The letter index to pull from. Must be a capital letter.
     * @return LetterNode pointer to the next node.
     */
    LetterNode* getNext(char letter);

    /**
     * @brief Recursively add a new word as a child to the current node.
     * 
     * Takes a substring of the given word with the first letter removed, then:
     * If the letter is associated with a child LetterNode, calls update on the child with the substring.
     * Otherwise, makes a new LetterNode, passing the substring in as a parameter.
     * 
     * LetterNode with a parameter just runs this process expecting the otherwise case every time.
     * 
     * @param word The word or word fragment to add.
     */
    void update(std::string word);

    /**
     * @brief Checks if the string created by following from the root to the current node is a real word.
     * @return True if it is a real word, false otherwise.
     */
    bool isWord();

private:
    /**
     * @brief Recursively adds the given word as child nodes. 
     * 
     * The word must be all caps or it will access outside the expected memory bounds.
     * This is intended to be used only by the update method.
     * If there is existing child data for any letters in the path, it will overwirte the nodes.
     * This will cause memory leaks.
     *  
     * @param word The word or word fragment to add.
     */
    LetterNode(std::string word);

    LetterNode* letters[26] = {};
    bool real_word = false;
};

#endif
