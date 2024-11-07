#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pb push_back
#define pr pop_back
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

ll gcd(ll X, ll Y) { return !Y ? X : gcd(Y, X % Y); }
ll lcm(ll X, ll Y) { return X * Y / gcd(X, Y); }

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll recursion_binary_search(vector<ll> &nums, ll target, ll l, ll r) {
  if (l > r)
    return -1;
  ll mid = (l + r) / 2;
  if (nums[mid] == target)
    return mid;
  if (nums[mid] < target)
    return recursion_binary_search(nums, target, mid + 1, r);
  return recursion_binary_search(nums, target, l, mid - 1);
}
ll Binarysearch(vector<ll> &nums, ll target) {
  int l = 0, r = nums.size() - 1;
  sort(nums.begin(), nums.end());
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}
ll lowerBound(vector<ll> &arr, ll n, ll x) {
  // Smallest Index such that "arr[ind]>=x"
  sort(arr.begin(), arr.end());
  ll l = 0, r = arr.size() - 1;
  ll ans = arr.size();
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (arr[mid] >= x) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
ll upperBound(vector<ll> &arr, ll n, ll x) {
  // Smallest Index such that "arr[ind]>x"
  ll l = 0, r = arr.size() - 1;
  ll ans = arr.size();
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (arr[mid] > x) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
ll const N = 1e5 + 9;
pair<ll, ll> tree[4 * N];
ll arr[N];
pair<ll, ll> mx;

void buildMaxx(ll v, ll l, ll r) {
  // cout<<v<<" "<<l<<" "<<r<<endl;
  if (l == r) {
    tree[v].first = arr[l];
    tree[v].second = -1;
    return;
  }
  ll m = (l + r) / 2;
  buildMaxx(2 * v, l, m);
  buildMaxx(2 * v + 1, m + 1, r);
  set<ll> uq;
  uq.insert(tree[2 * v].first);
  uq.insert(tree[2 * v].second);
  uq.insert(tree[2 * v + 1].first);
  uq.insert(tree[2 * v + 1].second);

  tree[v].first = *--uq.end();
  uq.erase(--uq.end());
  tree[v].second = *--uq.end();
}
void updateMaxx(ll v, ll l, ll r, ll pos, ll val) {
  if (l == r) {
    tree[v] = {val, -1};
    return;
  }
  ll m = (l + r) / 2;
  if (pos <= m)
    updateMaxx(2 * v, l, m, pos, val);
  else
    updateMaxx(2 * v + 1, m + 1, r, pos, val);
  set<ll> uq;
  uq.insert(tree[2 * v].first);
  uq.insert(tree[2 * v].second);
  uq.insert(tree[2 * v + 1].first);
  uq.insert(tree[2 * v + 1].second);

  tree[v].first = *--uq.end();
  uq.erase(--uq.end());
  tree[v].second = *--uq.end();
}
pair<ll, ll> Maxx(ll v, ll tl, ll tr, ll l, ll r) {
  // cout << l << " " << r << endl;
  if (l > r) {
    return {-1, -1};
  }
  if (l == tl && r == tr)
    return tree[v];

  ll mid = (tl + tr) / 2;
  // return max(Maxx(2 * v, tl, mid, l, min(r, mid)), Maxx(2 * v + 1, mid + 1,
  // tr, max(mid + 1, l), r));
  pair<ll, ll> tm1, tm2;
  set<ll> uq;
  pair<ll, ll> call1, call2;
  call1 = Maxx(2 * v, tl, mid, l, min(r, mid));
  call2 = Maxx(2 * v + 1, mid + 1, tr, max(mid + 1, l), r);

  uq.insert(call1.first);
  uq.insert(call1.second);
  uq.insert(call2.first);
  uq.insert(call2.second);

  tm1.first = *--uq.end();
  uq.erase(--uq.end());
  tm1.second = *--uq.end();

  return tm1;
}

void solve() {
  ll n, q;
  cin >> n >> q;
  for (ll i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  buildMaxx(1, 1, n);
  while (q--) {
    ll x;
    cin >> x;
    if (x == 1) {
      ll pos, val;
      cin >> pos >> val;
      updateMaxx(1, 1, n, pos, val);
    } else {
      ll l, r;
      cin >> l >> r;
      pair<ll, ll> ans = Maxx(1, 1, n, l, r);
      cout << ans.second << endl;
    }
  }
}

int32_t main() {
  // ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
  ll t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
#ifdef ONPC
  cerr << endl
       << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
