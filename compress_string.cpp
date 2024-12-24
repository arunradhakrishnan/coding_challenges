#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;          // Stack to store repeat counts
        stack<string> strStack;       // Stack to store strings
        string currentString = "";    // Current decoded string
        int currentNumber = 0;        // Current number accumulator

        for (char c : s) {
            if (isdigit(c)) {
                // Build the current number (supports multi-digit)
                currentNumber = currentNumber * 10 + (c - '0');
            } else if (c == '[')
            {
                // Push the current context onto stacks and reset
                numStack.push(currentNumber);
                strStack.push(currentString);
                currentNumber = 0;
                currentString = "";
            } else if (c == ']')
            {
                // Decode: pop from stacks and repeat currentString
                int repeatCount = numStack.top();
                numStack.pop();
                string temp = currentString;
                currentString = strStack.top();
                strStack.pop();
                while (repeatCount-- > 0) {
                    currentString += temp;
                }
            } else {
                // Build the current string
                currentString += c;
            }
        }

        return currentString; // Fully decoded string
    }
};
