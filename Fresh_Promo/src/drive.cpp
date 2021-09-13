#include <bits/stdc++.h>

using namespace std;

// Global definitions
string caseDelimiter = "--";

void printCodeList(vector<vector<string>> codeList_)
{
    cout << "codeList: [";
    for (size_t i = 0; i < codeList_.size(); i++)
    {
        cout << "[ ";
        for (size_t j = 0; j < codeList_[i].size(); j++)
        {
            cout << codeList_[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

void printShoppingCart(vector<string> shoppingCart_)
{
    cout << "shoppingCart: [";
    for (size_t i = 0; i < shoppingCart_.size(); i++)
    {
        cout << shoppingCart_[i] << " ";
    }
    cout << "]" << endl;
}

/**
 * Function to solve the Fresh Promo problem
 */
int freshPromo(vector<vector<string>> codeList_, vector<string> shoppingCart_)
{
    if (codeList_.size() == 0)
        return 1;

    int result = 0;

    
    return result;
}

int main()
{
    // LinkedList initial size
    string filename = "./data/input.txt";

    /* ---------------------- [ Fresh Promo solving ] ---------------------- */

    vector<vector<string>> codeList;
    vector<string> expression;
    vector<string> shoppingCart;
    bool isCodeList = true;

    cout << "<<< Running the Fresh Promo test:" << endl;
    cout << endl;

    // Read the input file with the parenthesis expressions
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            if (line == "")
            {
                isCodeList = false;
                continue;
            }
            else if (line == "--")
            {
                isCodeList = true;

                printCodeList(codeList);
                printShoppingCart(shoppingCart);

                // Print the result
                int result = freshPromo(codeList, shoppingCart);
                cout << "result: " << result << endl;
                cout << endl;

                // Clear the vectors
                codeList.clear();
                expression.clear();
                shoppingCart.clear();

                continue;
            }

            // Used to split string around spaces
            istringstream ss(line);

            // For storing each word
            string word; 

            // Traverse through all words
            while (ss >> word) 
            {
                // Add the current word into the vector
                if (isCodeList)
                    expression.push_back(word);
                else
                    shoppingCart.push_back(word);
            }

            if (isCodeList)
            {
                codeList.push_back(expression);
                expression.clear();
            }
        }
    }
    file.close();

    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
