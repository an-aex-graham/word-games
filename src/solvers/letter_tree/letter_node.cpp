#include "solvers/letter_tree/letter_node.h"

LetterNode::LetterNode() {}

LetterNode::LetterNode(std::string word) : LetterNode() {
    if (word.length() == 0)
    {
        real_word = true;
    } else {
        letters[word[0] - 'A'] = new LetterNode(word.substr(1));
    }
}

LetterNode::~LetterNode()
{
    for (int i = 0; i < 26; i++)
    {
        delete letters[i];
    }
}

bool LetterNode::isWord()
{
    return real_word;
}

LetterNode* LetterNode::getNext(char letter)
{
    return letters[letter - 'A'];
}

void LetterNode::update(std::string word)
{
    if (word.length() == 0)
    {
        real_word = true;
    } else {
        int idx = word[0] - 'A';
        if (letters[idx])
        {
            letters[idx]->update(word.substr(1));
        } else {
            letters[idx] = new LetterNode(word.substr(1));
        }
    }
}
