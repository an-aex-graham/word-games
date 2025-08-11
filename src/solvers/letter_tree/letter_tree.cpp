#include "solvers/letter_tree/letter_tree.h"

LetterTree::LetterTree() : root(new LetterNode()) {}

LetterTree::LetterTree(std::string path) : LetterTree()
{
    std::ifstream file("CollinsWords.txt");
    std::string word;
    while (file >> word)
    {
        root->update(word);
    }
    file.close();
}

LetterTree::~LetterTree()
{
    delete root;
}

LetterNode* LetterTree::getRoot()
{
    return root;
}
