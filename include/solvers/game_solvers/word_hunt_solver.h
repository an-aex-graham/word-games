#ifndef WORD_HUNT_SOLVER_H
#define WORD_HUNT_SOLVER_H

#include "solvers/solver.h"
#include <array>
#include <cmath>

/**
 * @class WordHuntSolver
 * @brief Takes an arbitrary string of characters and casts it into a grid, assembling all possible words from that grid.
 * 
 * Words must be conected ordinally (8 directions), and cannot reuse the same tile multiple times.
 * Blank spaces are tile gaps, and a string with a non-perfect square will be padded with blanks to the next lowest perfect square.
 */
class WordHuntSolver : public Solver
{
public:
    /**
     * @brief Chain into the base class constructor.
     * @param tree The LetterTree holding all makable words.
     */
    WordHuntSolver(LetterTree& tree);

    /**
     * @brief Constructor that allows pre-setting the game grid size.
     * @param tree The LetterTree holding all makable words.
     * @param grid_size The expected grid dimension for the game.
     */
    WordHuntSolver(LetterTree& tree, int grid_size);

    /**
     * @brief Empty destructor.
     */
    ~WordHuntSolver();

    /**
     * @brief Finds all words creatable by the grid.
     * @param sorted If true, returns words sorted from longest to shortest.
     * @return A list of words.
     */
    std::vector<std::string> findWords(bool sorted = true);

    /**
     * @brief Sets the input and space pads if it isn't a perfect seuqare in length.
     * @param input The input string to pad.
     */
    void setInput(std::string input);

private:
    /**
     * @brief Recursive method called to find all words.
     * @param curr The grid index most recently used. Note that the grid is represneted by a n*n 1-array.
     * @param used The grid indexes which have already been used.
     * @param path The word fragment up until this point.
     * @param letter_branch The LetterNode which the current path has led to.
     */
    void findWordsRecursor(int curr, std::unordered_set<int> used, std::string& path, LetterNode* letter_branch);

    /**
     * @brief Make a mapping of all indicies to all neighbor indicies.
     * 
     * Each index maps to 8 neighbors, with out-of-bounds neighbors being set to -1.
     * All -1's are shuffled to be grouped at the end of the list, to allow for short-circuiting.
     */
    void computeNeighbors();

    int grid_size { -1 };

    std::vector<std::array<int, 8>> neighbors;

    std::unordered_set<std::string> duplicate_checker;

};

#endif
