#include "solvers/game_solvers/word_hunt_solver.h"

WordHuntSolver::WordHuntSolver(LetterTree& tree) : Solver(tree), duplicate_checker(), neighbors() {}

WordHuntSolver::WordHuntSolver(LetterTree& tree, int grid_size) : WordHuntSolver(tree) 
{
    this->grid_size = grid_size;
    computeNeighbors();
}

WordHuntSolver::~WordHuntSolver() {}

std::vector<std::string> WordHuntSolver::findWords(bool sorted)
{
    found_words.clear();
    duplicate_checker.clear();
    std::string path = "";
    if (grid_size == -1)
    {
        throw std::runtime_error("computeNeighbors called with unset grid size");
    }
    path.reserve(grid_size * grid_size);
    for (int i = 0; i < grid_size * grid_size; i++)
    {
        findWordsRecursor(i, {}, path, tree_ref.getRoot()->getNext(input_string[i]));
    }
    if (sorted)
    {

        std::sort(found_words.begin(), found_words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
    }
    return found_words;
}

void WordHuntSolver::computeNeighbors()
{
    neighbors.clear();
    if (grid_size == -1)
    {
        throw std::runtime_error("computeNeighbors called with unset grid size");
    }

    neighbors.resize(grid_size * grid_size);
    for (int i = 0; i < grid_size * grid_size; i++)
    {
        // left, right, top, and bottom edges, shortened to make the following statment more legible.
        bool l = (i % grid_size == 0);
        bool r = (i % grid_size == grid_size - 1);
        bool t = (i < grid_size);
        bool b = (i >= grid_size * (grid_size - 1));

        neighbors[i] = {
            (l || t) ? -1 : i - 1 - grid_size, (t) ? -1 : i - grid_size, (r || t) ? -1 : i - grid_size + 1,
            (l)      ? -1 : i - 1,                                       (r)      ? -1 : i + 1,
            (l || b) ? -1 : i - 1 + grid_size, (b) ? -1 : i + grid_size, (r || b) ? -1 : i + grid_size + 1,
        };
        std::partition(neighbors[i].begin(), neighbors[i].end(), [](int x) { return x != -1; });
    }
}

void WordHuntSolver::setInput(std::string input)
{
    int length = input.length();

    int new_grid_size = std::ceil(std::sqrt(length));

    if (new_grid_size != grid_size)
    {
        grid_size = new_grid_size;
        computeNeighbors();
    }

    input.resize(grid_size * grid_size, ' ');

    input_string = input;
}

void WordHuntSolver::findWordsRecursor(int curr, std::unordered_set<int> used, std::string &path, LetterNode* letter_branch)
{   
    if (!letter_branch) return;

    if (!used.insert(curr).second) 
    {
        used.erase(curr);
        return;
    }

    char character = input_string[curr];

    if (character == ' ') return;

    path.push_back(character);

    for (int i = 0; i < 8; i++)
    {
        int n_idx = neighbors[curr][i];
        if (n_idx == -1) break;

        findWordsRecursor(n_idx, used, path, letter_branch->getNext(input_string[n_idx]));
    }

    used.erase(curr);

    if (letter_branch->isWord() && duplicate_checker.insert(path).second)
    { 
        found_words.push_back(path);
    }

    path.pop_back();
}
