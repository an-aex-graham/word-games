#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <algorithm>
#include <unordered_set>
#include "solvers/letter_tree/letter_tree.h"

/**
 * @class Solver
 * @brief Abstract base class for various solver objects. Defines expected universal behaviors and fields.
 */
class Solver
{
public:
    /**
     * @brief Solver constructor, initializes universal fields.
     * @param tree The LetterTree refrence to use for word lookups.
     */
    Solver(LetterTree& tree);

    /**
     * @brief Empty universal destructor.
     */
    virtual ~Solver();

    /**
     * @brief Take an arbitrary string for future use as the game data.
     */
    virtual void setInput(std::string input);

    /**
     * @brief Pure abstract method housing the actual logic call.
     * @param sorted If true, return a sorted output of the words. Sorting method is per-implementation.
     * @return A list of all valid words.
     */
    virtual std::vector<std::string> findWords(bool sorted = true) = 0;

protected:
    std::string input_string;
    LetterTree& tree_ref;
    std::vector<std::string> found_words;
};

#endif
