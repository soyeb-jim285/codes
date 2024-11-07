#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> LIS_array(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> lis_ends(n + 1);  // to store the ends of increasing subsequences of different lengths
    std::vector<int> prev_indices(n, -1);    // to store the indices of the previous element in the LIS
    int lis_len = 1;

    lis_ends[1] = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < lis_ends[1]) {
            lis_ends[1] = arr[i];
            prev_indices[i] = -1;
        } else if (arr[i] > lis_ends[lis_len]) {
            lis_ends[++lis_len] = arr[i];
            prev_indices[i] = lis_ends[lis_len - 1];
        } else {
            int low = 1, high = lis_len;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (lis_ends[mid] < arr[i] && arr[i] <= lis_ends[mid + 1]) {
                    lis_ends[mid + 1] = arr[i];
                    prev_indices[i] = lis_ends[mid];
                    break;
                } else if (lis_ends[mid] < arr[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }

    std::vector<int> lis_sequence;
    int idx = lis_ends[lis_len];
    while (idx != -1) {
        lis_sequence.push_back(arr[idx]);
        idx = prev_indices[idx];
    }
    std::reverse(lis_sequence.begin(), lis_sequence.end());

    return lis_sequence;
}

int main() {
    std::vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    std::vector<int> lis_sequence = LIS_array(arr);
    std::cout << "Longest Increasing Subsequence:";
    for (int num : lis_sequence) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}
