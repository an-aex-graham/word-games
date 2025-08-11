#include "solvers/solver.h"

Solver::Solver(LetterTree& tree) : 
    tree_ref(tree), input_string(), found_words() 
{}

Solver::~Solver() {}

void Solver::setInput(std::string input)
{
    input_string = input;
}
