#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Method to print the list
 * 
 * time complexity: O(n)
 */
template <typename T>
void printList(vector<T> list_)
{
    int size = list_.size();
    cout << "<<< [ ";
    for (auto i = 0; i < size; i++)
        cout << list_[i] << " ";

    cout << "]" << endl;
}

/**
 * Get the index from a vector by its value
 * 
 * time complexity: O(n)
 */
template <typename T>
int getIndex(vector<T> v_, T K_)
{
    auto it = find(v_.begin(), v_.end(), K_);

    if (it != v_.end())
        return (it - v_.begin()); // element found
    else
        return -1; // element not found
}

/**
 * Function to select the top competitors according to their occurrence on review
 * and the specif rule for draw
 * 
 * time complexity: O(n)
 */
vector<string> selectTopCompetitors(vector<string> competitors_, vector<int> occurrences, int n_)
{
    vector<string> selectedCompetitors(n_, "");
    int competitorIdx = -1;

    // Select n competitors
    for (auto i = 0; i < n_; i++)
    {
        // Competitor with top occurence
        competitorIdx = std::max_element(occurrences.begin(), occurrences.end()) - occurrences.begin();
        selectedCompetitors[i] = competitors_[competitorIdx];

        // TODO: handle the draw case

        // Reinitialize the top occurrence to find the next one
        occurrences[competitorIdx] = 0;
    }
    
    return selectedCompetitors;
}

/**
 * Function to find the top n competitors
 * 
 * time complexity: O(n3)
 */
vector<string> TopNumCompetitors(int numCompetitors, int topNCompetitors, vector<string> competitors,
                                 int numReviews, vector<string> reviews)
{
    vector<int> occurrences(6, 0);
    string delimiter = " ", token;
    size_t pos = 0;
    int competitorIdx = -1;

    // Loop over each review
    vector<string>::iterator it;
    for (it = reviews.begin(); it != reviews.end(); ++it)
    {
        pos = 0;
        string review(*it);

        // Loop over each review word by word
        while ((pos = review.find(delimiter)) != string::npos)
        {
            // Get the current word
            token = review.substr(0, pos);

            // Increase the competitors occurrence
            competitorIdx = getIndex(competitors, token);
            if (competitorIdx != -1)
                occurrences[competitorIdx]++;

            // Erase the token and delimiter from the review
            review.erase(0, pos + delimiter.length());
        }

        // Check the last word of the current review
        competitorIdx = getIndex(competitors, review);
        if (competitorIdx != -1)
            occurrences[competitorIdx]++;
    }

    return selectTopCompetitors(competitors, occurrences, 2);
}

int main()
{
    // Define the problem input
    int numCompetitors = 6, topNCompetitors = 2, numReviews = 6;

    vector<string> competitors = {"newshop", "shopnow", "afashion", "fashionbeats",
                                  "mymarket", "tcellular"};

    vector<string> reviews = {
        "newshop is providing good services in the city; everyone should use newshop",
        "best services by newshop",
        "fashionbeats has great services in the city",
        "I am proud to have fashionbeats",
        "mymarket has awesome services",
        "Thanks Newshop for the quick delivery"};

    // Call the problem solver function
    vector<string> result = TopNumCompetitors(numCompetitors, topNCompetitors, competitors,
                                              numReviews, reviews);

    // Print the list
    cout << "Result: " << endl;
    printList(result);

    /* ============================================================================== */

    // Finish the program
    cout << "Finished successfully!\n";
    return EXIT_SUCCESS;
}