#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll const N = 1e7;
vector<ll> lpf(N + 1, -1);
using u64 = uint64_t;
using u128 = __uint128_t;
void LPF() {
  for (ll i = 2; i <= N; i++) {
    if (lpf[i] == -1) {
      for (ll j = i; j <= N; j += i) {
        if (lpf[j] == -1)
          lpf[j] = i;
      }
    }
  }
}
void backtrack(vector<ll> &nums, vector<ll> &curr, vector<vector<ll>> &ans,
               vector<bool> &visited) {

  // If current permutation is complete
  if ((ll)curr.size() == (ll)nums.size()) {
    ans.push_back(curr);
  }
  // Traverse the input vector
  for (ll i = 0; i < (ll)nums.size(); i++) {
    // If index is already visited
    if (visited[i])
      continue;
    // If the number is duplicate
    if (i > 0 and nums[i] == nums[i - 1] and !visited[i - 1])
      continue;
    // Set visited[i] flag as true
    visited[i] = true;
    // Push nums[i] to current vector
    curr.push_back(nums[i]);
    // Recursive function call
    backtrack(nums, curr, ans, visited);
    // Backtrack to the previous
    // state by unsetting visited[i]
    visited[i] = false;
    // Pop nums[i] and place at
    // the back of the vector
    curr.pop_back();
  }
}

// Function to pre-process the vector num
vector<vector<ll>> permuteDuplicates(vector<ll> &nums) {
  // Sort the array
  sort(nums.begin(), nums.end());

  // Stores distinct permutations
  vector<vector<ll>> ans;

  vector<bool> visited((ll)nums.size(), false);

  // Store the current permutation
  vector<ll> curr;

  // Find the distinct permutations of num
  backtrack(nums, curr, ans, visited);

  return ans;
}
// Function call to print all distinct
// permutations of the vector nums
vector<ll> getDistinctPermutations(vector<ll> nums) {
  // Find the distinct permutations
  vector<vector<ll>> ans = permuteDuplicates(nums);
  // Traverse every row
  vector<ll> anss;
  for (ll i = 0; i < (ll)ans.size(); i++) {
    // Traverse every column
    ll val = 0;
    for (ll j = 0; j < (ll)ans[i].size(); j++) {
      if (ans[i][j] == 0 && j == 0)
        break;
      val = val * 10 + ans[i][j];
    }
    if (val != 0)
      anss.push_back(val);
  }
  return anss;
}
void solve() {
  ll a, b;
  cin >> a >> b;
  string aa, bb;
  aa = to_string(a);
  bb = to_string(b);
  vector<ll> numa, numb, num1, num2;
  for (int i = 0; i < sz(aa); i++) {
    numa.push_back(aa[i] - '0');
  }
  for (int i = 0; i < sz(bb); i++) {
    numb.push_back(bb[i] - '0');
  }
  // for (auto ic : numa)
  //   cout << ic << " ";
  // cout << '\n';
  // for (auto ic : numb)
  //   cout << ic << " ";
  // cout << "\n";
  num1 = getDistinctPermutations(numa);
  num2 = getDistinctPermutations(numb);
  ll ans = 1;
  for (int i = 0; i < sz(num1); i++) {
    for (int j = 0; j < sz(num2); j++) {
      // cout << num1[i] << " " << num2[j] << "\n";
      ll g = __gcd(num1[i], num2[j]);
      ans = max(ans, lpf[g]);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  LPF();
  int t;
  cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
