#ifndef ANAGRAM_SOLVER_H
#define ANAGRAM_SOLVER_H

#include "solvers/solver.h"

/**
 * @class AnagramSolver
 * @brief Takes an arbitrary string of characters, and finds all words that can be made from those characters.
 */
class AnagramSolver : public Solver
{
public:
    /**
     * @brief Chain into the base class constructor.
     * @param tree The LetterTree holding all makable words.
     */
    AnagramSolver(LetterTree& tree);

    /**
     * @brief Empty destructor.
     */
    ~AnagramSolver();

    /**
     * @brief Finds all words creatable by the input character string.
     * @param sorted If true, returns words sorted from longest to shortest.
     * @return A list of words.
     */
    std::vector<std::string> findWords(bool sorted = true);

private:
    /**
     * @brief Recursive method called to find all words.
     * @param input_string The characters which may be selected from to add to the end of the current string.
     * @param path The word fragment up until this point.
     * @param letter_branch The LetterNode which the current path has led to.
     */
    void findWordsRecursor(std::string input_string, std::string& path, LetterNode* letter_branch);
};

#endif
