#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bool differentNeighbours(const vector<vector<int>> &grid, int i, int j) {
  int n = grid.size();
  int m = grid[0].size();
  int value = grid[i][j];
  if (i > 0 && grid[i - 1][j] == value) {
    return false;
  }
  if (i < n - 1 && grid[i + 1][j] == value) {
    return false;
  }
  if (j > 0 && grid[i][j - 1] == value) {
    return false;
  }
  if (j < m - 1 && grid[i][j + 1] == value) {
    return false;
  }
  return true;
}
bool isValid(const vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!differentNeighbours(grid, i, j)) {
        return false;
      }
    }
  }
  return true;
}
void generateAllVectors(int n, int m, int k) {
  int totalCells = n * m;
  long long totalCombinations = 1;
  ll count = 0;
  for (int i = 0; i < totalCells; ++i) {
    totalCombinations *= k;
  }
  vector<vector<int>> grid(n, vector<int>(m));
  for (long long num = 0; num < totalCombinations; ++num) {
    long long current = num;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        grid[i][j] = (current % k) + 1; // Get the value for this cell
        current /= k;                   // Move to the next "digit"
      }
    }
    if (isValid(grid)) {
      count++;
    }
  }
  cout << count << "\n";
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  generateAllVectors(n, m, k);
  return 0;
}
