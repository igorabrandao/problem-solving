#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <Stack.h>

using namespace std;

/**
 * Remove all adjacent duplicates chars from a string
 * 
 * time complexity: O(n)
 * space complexity: O(n) -> it can be improved by changing the stack by
 * a string an keep a pointer to the end of the string
 */
int main()
{
    string filename = "./data/input.txt";
    string answer;

    /* ----------------- [ Remove All Adjacent Duplicates solving ] ----------------- */

    cout << "<<< Running the Remove All Adjacent Duplicates test:" << endl;
    cout << endl;

    // Read the input file with the parenthesis words
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // For each line of the input file create a new word stack
            Stack<char> word;
            answer = "";

            // Loop over each char of the word
            for (char &c : line)
            {
                // Check if the word stack is empty
                if (word.isEmpty() || c != word.top())
                    word.push(c);
                else
                    word.pop();
            }

            // Return the answer
            while (!word.isEmpty())
            {
                answer += word.top();
                word.pop();
            }

            // Reverse the answer before showing it
            reverse(answer.begin(), answer.end());

            // Print the remaining word
            if (answer.size() == 0)
                cout << "<<< " << line << ": <empty string>" << endl;
            else
                cout << "<<< " << line << ": " << answer << endl;
        }
        file.close();
    }

    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
