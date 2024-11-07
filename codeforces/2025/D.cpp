#include <bits/stdc++.h>
using namespace std;

#define sz(a) ((ll)((a).size()))

typedef long long ll;
typedef long double ld;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<int> ms;
vector<int> coordinate_compress(const vector<int> &arr) {
  vector<int> sorted_arr = arr;
  sort(sorted_arr.begin(), sorted_arr.end());
  sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()),
                   sorted_arr.end());

  vector<int> compressed(arr.size());
  for (size_t i = 0; i < arr.size(); ++i) {
    compressed[i] = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) -
                    sorted_arr.begin();
  }
  return compressed;
}
vector<int> compressedb, compressedc;

struct SegmentTree {
  vector<int> tree; // 1D tree to store frequencies of elements
  int n;

  // Initialize the segment tree with size n
  void init(int size) {
    n = size;
    tree.resize(4 * n, 0); // Allocate space for the segment tree
  }

  // Build the segment tree based on the compressed array
  void build(const vector<int> &arr, int node, int start, int end) {
    if (start == end) {
      // Leaf node, store the frequency of the single element
      tree[node] = 1; // There's one occurrence of the element in this range
    } else {
      int mid = (start + end) / 2;
      build(arr, 2 * node, start, mid);
      build(arr, 2 * node + 1, mid + 1, end);
      // Sum the counts from child nodes
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  // Update the segment tree when a new element is added
  void update(int node, int start, int end, int idx, int value) {
    if (start == end) {
      // Leaf node, update the frequency count
      tree[node] += value; // Increment or decrement the count
    } else {
      int mid = (start + end) / 2;
      if (idx <= mid) {
        // Update the left child
        update(2 * node, start, mid, idx, value);
      } else {
        // Update the right child
        update(2 * node + 1, mid + 1, end, idx, value);
      }
      // Update current node after updating the child
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  // Query the number of elements greater than or equal to x in range [L, R]
  int query(int node, int start, int end, int L, int R, int x) {
    if (start > R || end < L) {
      // Out of range
      return 0;
    }
    if (start >= L && end <= R) {
      // Fully within the query range
      return tree[node]; // Return the count in this range
    }
    int mid = (start + end) / 2;
    int left_result = query(2 * node, start, mid, L, R, x);
    int right_result = query(2 * node + 1, mid + 1, end, L, R, x);
    return left_result + right_result;
  }
};
int fn(ll ind, ll llelligence, vector<int> &a, vector<vector<int>> &dp,
       SegmentTree &st, SegmentTree &st2) {
  int n = sz(ms);
  if (ind >= n) {
    return 0;
  }
  if (dp[ind][llelligence] != -1) {
    return dp[ind][llelligence];
  }
  int ans = 0;
  int lst = sz(a);
  if (ind != n - 1) {
    lst = ms[ind + 1];
  }
  int cnt = 0, llt = llelligence + 1, strt = ind - llelligence;
  int len = lst - ms[ind];
  int x = lower_bound(compressedb.begin(), compressedb.end(), llt) -
          compressedb.begin();
  cnt += len - st.query(1, 0, st.n - 1, ms[ind], lst - 1, x);
  // cout << ind << " " << lst << " "
  //      << st.query(0, 0, st.n - 1, ms[ind], lst - 1, llt) << " " << cnt <<
  //      '\n';
  x = lower_bound(compressedc.begin(), compressedc.end(), strt) -
      compressedc.begin();
  cnt += len - st2.query(1, 0, st2.n - 1, ms[ind], lst - 1, x);
  // for (int i = ms[ind]; i < lst; i++) {
  //   if (a[i] != 0) {
  //     if (a[i] > 0) {
  //       if (llt >= a[i]) {
  //         cnt++;
  //       }
  //     } else {
  //       if (strt >= abs(a[i])) {
  //         cnt++;
  //       }
  //     }
  //   }
  // }
  //
  // cout << ind << " " << lst << " " << llt << " " << strt << " " << cnt <<
  // '\n';
  ans = max(ans, cnt + fn(ind + 1, llelligence + 1, a, dp, st, st2));
  cnt = 0, llt = llelligence, strt = ind - llelligence + 1;

  x = lower_bound(compressedb.begin(), compressedb.end(), llt) -
      compressedb.begin();
  cnt += len - st.query(1, 0, st.n - 1, ms[ind], lst - 1, x);
  // cout << ind << " " << lst << " "
  //      << st.query(0, 0, st.n - 1, ms[ind], lst - 1, llt) << " " << cnt <<
  //      '\n';
  x = lower_bound(compressedc.begin(), compressedc.end(), strt) -
      compressedc.begin();
  cnt += len - st2.query(1, 0, st2.n - 1, ms[ind], lst - 1, x);
  // for (int i = ms[ind]; i < lst; i++) {
  //   if (a[i] != 0) {
  //     if (a[i] > 0) {
  //       if (llt >= a[i]) {
  //         cnt++;
  //       }
  //     } else {
  //       if (strt >= abs(a[i])) {
  //         cnt++;
  //       }
  //     }
  //   }
  // }
  // cout << ind << " " << lst << " " << llt << " " << strt << " " << cnt
  // << "--\n";
  ans = max(ans, cnt + fn(ind + 1, llelligence, a, dp, st, st2));

  return dp[ind][llelligence] = ans;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      ms.push_back(i);
    }
    if (a[i] > 0) {
      b[i] = a[i];
    } else {
      b[i] = 2e9;
    }
    if (a[i] < 0) {
      c[i] = -a[i];
    } else {
      c[i] = 2e9;
    }
  }
  compressedb = coordinate_compress(b);
  compressedc = coordinate_compress(c);
  SegmentTree st, st2;
  st.init(n);
  st2.init(n);
  for (int i = 0; i < n; i++) {
    st.update(1, 0, n - 1, compressedb[i], 1);
    st2.update(1, 0, n - 1, compressedc[i], 1);
  }
  vector<vector<int>> dp(k + 1, vector<int>(k + 1, -1));
  cout << fn(0, 0, a, dp, st, st2) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
