#include <bits/stdc++.h>

using namespace std;

/**
 * Function to perform the last word count
 */
int lengthOfLastWord(string s)
{
    cout << s << endl;
    return 0;
}

int main()
{
    // LinkedList initial size
    string filename = "./data/input.txt";

    /* ---------------------- [ Length Last Word solving ] ---------------------- */

    vector<vector<string>> codeList;
    vector<string> expression;
    vector<string> shoppingCart;

    cout << "<<< Running the Length Last Word test:" << endl;
    cout << endl;

    // Read the input file with the parenthesis expressions
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            if (line != "")
            {
                lengthOfLastWord(line);
                continue;
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
