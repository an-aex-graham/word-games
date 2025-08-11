#ifndef LETTER_TREE_H
#define LETTER_TREE_H

#include <string>
#include <fstream>
#include "letter_tree/letter_node.h"

/**
 * @class LetterTree 
 * @brief A tree of LetterNodes used to store and quick-lookup valid spellings for a word set.
 * 
 * This is (attempted to be) optimized for finding potential valid words out of a potential letter sets.
 * It allows for constructing a word from a sequence of characters, pruning paths that cannot lead to valid words.
 * 
 * This class works as a wrapper for the LetterNode class.
 * It mostly exists for cleaner syntax and helper methods, like building a tree from a file.
 */
class LetterTree
{
public: 
    /**
     * @brief No-args constructor, for use if you want to manually input a set of words.
     */
    LetterTree();

    /**
     * @brief Constructor for making a tree from a pre-defined file of words.
     * @param path The file path pointing to the list of words.
     * 
     * Expects the file to be a list of all caps words with no punctuation, seperated by any sort of blank space.
     */
    LetterTree(std::string path);

    /**
     * @brief Deletes the root node of the tree.
     */
    ~LetterTree();

    /**
     * @brief Gets the root node of the LetterTree.
     * @return A pointer to the root node.
     */
    LetterNode* getRoot();
private:
    LetterNode* root;
};

#endif