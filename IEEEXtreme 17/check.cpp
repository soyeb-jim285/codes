#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Read the input height array.
    vector<int> heights;
    int height;
    while (cin >> height)
    {
        heights.push_back(height);
    }

    // Sort the height array in decreasing order.
    sort(heights.begin(), heights.end(), greater<int>());

    // Initialize the answer array.
    vector<int> answer(heights.size());

    // Count the number of times people notices another person in line.
    int currentHeight = heights[0];
    for (int i = 1; i < heights.size(); i++)
    {
        if (heights[i] < currentHeight)
        {
            answer[i]++;
        }
        else
        {
            currentHeight = heights[i];
        }
    }

    // Print the answer array.
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
