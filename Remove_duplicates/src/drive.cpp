#include <bits/stdc++.h>

using namespace std;

/**
 * Function to remove duplicated values from an Int array
 */
vector<int> removeDuplicates(int *arr_, int n_)
{
    vector<int> output;
    unordered_map<int, bool> map;

    // Loop over the input array
    for (auto i = 0; i < n_; i++)
    {
        // Check if the current element is already in the map
        if (map.count(arr_[i]) == 0)
        {
            output.push_back(arr_[i]);
            map[arr_[i]] = true;
        }
    }

    return output;
}

int main()
{
    // Create a test array
    int iSize = 12;
    int a[] = {1, 5, 2, 4, 4, 3, 3, 6, 7, 1, 1, 2};
    vector<int> output = removeDuplicates(a, iSize);

    // Print the input array
    cout << "Before removing duplicates: " << endl;
    for (auto i = 0; i < iSize; i++)
        cout << a[i] << " ";

    cout << endl;
    cout << endl;

    // Print the output vector
    cout << "After removing duplicates: " << endl;
    for (size_t i = 0; i < output.size(); i++)
        cout << output[i] << " ";

    cout << endl;

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}
