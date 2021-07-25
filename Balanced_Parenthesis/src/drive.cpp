#include <iostream>
#include <string>
#include <fstream>
#include <Stack.h>

using namespace std;

// Global definitions
string openingParenthesis = "({[";
string closingParenthesis = ")}]";

/**
 * Function to determine whether or not it's an opening parenthesis
 */
bool isOpeningParenthesis(char parenthesis_)
{
    return (openingParenthesis.find(parenthesis_) != string::npos);
}

/**
 * Function to determine whether or not it's a closing parenthesis
 */
bool isClosingParenthesis(char parenthesis_)
{
    return (closingParenthesis.find(parenthesis_) != string::npos);
}

/**
 * Function to check if the parenthesis matches
 */
bool isParenthesisMatched(char prevParenthesis_, char currParenthesis_)
{
    bool result;
    switch (currParenthesis_)
    {
    case '}':
        (prevParenthesis_ == '{' ? result = true : result = false);
        break;
    case ']':
        (prevParenthesis_ == '[' ? result = true : result = false);
        break;
    case ')':
        (prevParenthesis_ == '(' ? result = true : result = false);
        break;
    default:
        result = false;
        break;
    }
    return result;
}

int main()
{
    // LinkedList initial size
    string filename = "./data/input.txt";

    /* ---------------------- [ Balanced parenthesis solving ] ---------------------- */

    cout << "<<< Running the Balanced parenthesis test:" << endl;
    cout << endl;

    // Read the input file with the parenthesis expressions
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // For each line of the input file create a new expression stack
            Stack<char> expression;

            // Loop over each char of the expression
            for (char &c : line)
            {
                // If the parenthesis is an opening one, add it into the stack
                if (isOpeningParenthesis(c))
                    expression.push(c);
                else
                {
                    // Otherwise, check its previous char to match it with the current parenthesis
                    if (isParenthesisMatched(expression.top(), c))
                        expression.pop(); // remove the previous parenthesis
                }
            }

            // If the expression is balanced, it should be empty here
            if (expression.isEmpty())
                cout << "<<< expression " << line.c_str() << " is valid" << endl;
            else
                cout << "<<< expression " << line.c_str() << " is invalid" << endl;
        }
        file.close();
    }

    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
