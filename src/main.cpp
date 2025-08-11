#include <iostream>
#include <cctype>
#include <algorithm>
#include "solvers/game_solvers/anagram_solver.h"
#include "solvers/game_solvers/word_hunt_solver.h"
#include "letter_tree/letter_tree.h"

int main()
{
    std::cout << "Main Run" << std::endl;
    LetterTree tree("CollinsWords.txt");
    Solver* solver;
    std::cout << "WORD TREE BUILT" << std::endl;
    std::string input = "start";
    while (true)
    {
        std::cout << "(A)NAGRAMS   WORD (H)UNT   WORD (B)ITES \nOTHER TO QUIT" << std::endl;
        std::cin >> input;
        if (input == "A")
        {
            solver = new AnagramSolver(tree);
        }
        else if (input == "H")
        {
            solver = new WordHuntSolver(tree, 4);
        }
        else if (input == "B")
        {
            break;
        }
        else
        {
            break;
        }


        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "PROVIDE INPUT:" << std::endl;
        std::cin >> input;
        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c) {
            return std::toupper(c);
        });
        std::cout << input << std::endl;
        solver->setInput(input);
        std::vector<std::string> v = solver->findWords();
        int old_length = 0;
        int word_count = 0;
        for (std::string word : v)
        {
            if (word.length() != old_length)
            {
                if (old_length != 0)
                {
                    std::cout << "\b\b" << " " << word_count << " " << old_length << std::endl;
                }
                word_count = 0;
                std::cout << "\n";
                old_length = word.length();
            }
            std::cout << word << ", ";
            word_count += 1;
        }
        std::cout << "\b\b" << " " << word_count << " " << old_length << std::endl;
        delete solver;
    }
    return 0;
}
