//find all permutation of a given string #include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>


void permute(std::string &str, int left, int right, std::vector<std::string> &result) 
{
    if (left == right) {
        result.push_back(str);
    } else {
        for (int i = left; i <= right; i++) {
            std::swap(str[left], str[i]);  // Swap the current element with the left
            permute(str, left + 1, right, result);  // Recurse for the next position
            std::swap(str[left], str[i]);  // Backtrack and undo the swap
        }
    }
}

std::vector<std::string> generatePermutations(std::string str) {
    std::vector<std::string> result;
    permute(str, 0, str.size() - 1, result);
    return result;
}


int main() {
    std::string input = "ABC";
    std::vector<std::string> permutations = generatePermutations(input);
    
    for ( auto &perm : permutations) {
        std::cout << perm << "\n";
    }
    
    return 0;
}
