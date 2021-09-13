#include <bits/stdc++.h>

using namespace std;

/**
 * Function to perform the last word count
 */
int lengthOfLastWord(string s)
{
    int count, idx = 0;
    int n = s.size();

    while (idx < n)
    {
        if (s[idx] != ' ')
        {
            count++;
            idx++;
        }
        else
        {
            // Current char is a white-space
            while (idx < n && s[idx] == ' ')
                idx++;

            if (idx == n)
                return count;
            else
                count = 0;
        }
    }

    return count;
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
                cout << line << endl;
                cout << "<<< last word size: " << lengthOfLastWord(line) << endl;
                cout << endl;
                continue;
            }
        }
    }
    file.close();

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
