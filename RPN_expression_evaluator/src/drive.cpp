#include <iostream>
#include <string>
#include <fstream>
#include <Stack.h>

using namespace std;

// Global definitions
string operators = "+-/*";

/**
 * Function to determine whether or not it's an operator
 */
bool isoperators(string parenthesis_)
{
    return (operators.find(parenthesis_) != string::npos);
}

template <typename T>
T executeOperation(T operand1_, T operand2_, char operator_)
{
    T result;

    switch (operator_)
    {
    case '+':
        result = operand1_ + operand2_;
        break;
    case '-':
        result = operand1_ - operand2_;
        break;
    case '/':
        result = operand1_ / operand2_;
        break;
    case '*':
        result = operand1_ * operand2_;
        break;
    default:
        break;
    }

    return result;
}

template <typename T>
void handleStack(Stack<T> *stack_, string token_)
{
    // If the term is an operand, add it to the stack
    if (!isoperators(token_))
        stack_->push(stoi(token_));
    else
    {
        // Otherwise, evaluate the current operation
        auto operand1 = stack_->top();
        stack_->pop();
        auto operand2 = stack_->top();
        stack_->pop();

        // Add the result to the stack
        const char *cstr = token_.c_str();
        stack_->push(executeOperation(operand2, operand1, *cstr));
    }
}

int main()
{
    // LinkedList initial size
    string filename = "./data/input.txt";

    /* ---------------------- [ RPN evaluator solving ] ---------------------- */

    cout << "<<< Running the RPN evaluator test:" << endl;
    cout << endl;

    string delimiter = " ", token;
    size_t pos = 0;

    // Read the input file with the parenthesis expressions
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            // For each line of the input file create a new expression stack
            Stack<int> expression;

            pos = 0;

            // Loop over each char of the expression
            while ((pos = line.find(delimiter)) != string::npos)
            {
                // Get the current expression term
                token = line.substr(0, pos);

                // Do the operations with the current token
                handleStack(&expression, token);

                // Erase the token and delimiter from the expression
                line.erase(0, pos + delimiter.length());
            }

            // Do the operations with the last token
            handleStack(&expression, line);

            // Display the result
            cout << "<<< result: " << expression.top() << endl;
        }
        file.close();
    }

    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
