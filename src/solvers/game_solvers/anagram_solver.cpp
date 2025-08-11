#include "solvers/game_solvers/anagram_solver.h"

AnagramSolver::AnagramSolver(LetterTree& tree) : Solver(tree) {}

AnagramSolver::~AnagramSolver() {}

std::vector<std::string> AnagramSolver::findWords(bool sorted)
{
    std::string in_string = "";
    in_string.reserve(input_string.length());
    found_words.clear();
    findWordsRecursor(input_string, in_string, tree_ref.getRoot());
    if (sorted)
    {
        std::sort(found_words.begin(), found_words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
    }
    return found_words;
}

void AnagramSolver::findWordsRecursor(std::string input_string, std::string &path, LetterNode* letter_branch)
{   
    if (!letter_branch)
    {
        return;
    }
    std::unordered_set<char> seen;

    // Maintain a list of all characters seen before the current one. 
    // For optimizing getting all characters but the current one.
    std::string prior_chars = "";
    for (int i = 0; i < input_string.length(); i++)
    {
        // Only traverse once over duplicate characters
        if (seen.insert(input_string[i]).second)
        {
            path.push_back(input_string[i]);
            findWordsRecursor(
                prior_chars + input_string.substr(i + 1),
                path,
                letter_branch->getNext(input_string[i])
            );
            path.pop_back();
        }
        prior_chars += input_string[i];
    }
    if (letter_branch->isWord())
    {
        found_words.push_back(path);
    }
}
