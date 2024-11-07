# Tutorial

[1969A - Two Friends](../problems/A._Two_Friends.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1969A - Two Friends](../problems/A._Two_Friends.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Obviously, you can't send fewer than 2 invitations. Since all pi≠i, you need to send at least 2 invitations (i and pi) in order for at least some friend i to come.

On the other hand, you never need to send more than 3 invitations. You can always send invitations to friends i,pi, and ppi, so that i and pi come.

Now we need to determine the condition for when two invitations are enough. That is, we send invitations to friends i and j, and both of them come. This means pi=j and pj=i. This check is already enough to solve the problem in O(n2). But you can think further and see that since j=pi, the second check becomes ppi=i. This means it is enough to iterate over friend i and check if ppi=i for at least one of them.

Overall complexity: O(n) per testcase.

 **Solution (awoo)**
```cpp
for _ in range(int(input())):
    n = int(input())
    p = [int(x) - 1 for x in input().split()]
    ans = 3
    for i in range(n):
        if p[p[i]] == i:
            ans = 2
    print(ans)
```
[1969B - Shifts and Sorting](../problems/B._Shifts_and_Sorting.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1969B - Shifts and Sorting](../problems/B._Shifts_and_Sorting.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Let's look at the operation as the following: you choose (l,r), erase the element at position r and then insert it before the element at position l. We can also interpret the cost of such operation as the following: you pay 1 for the element at position r you "teleport" to the left and 1 for each element you teleport through (element inside segment [l,r−1]).

Now let's look at two indices x<y where ax=1 and ay=0. Since at the end, all zeroes should be before ones, you have to move ay to the left of ax. But the only thing that moves to the left is element ar, so you have to make at least one operation ending at ay.

What does it mean? It means: 

1. for every 0 that has at least one 1 from the left, you have to pay at least 1 for teleporting it to the left;
2. for every 1, if there are c 0-s to the right, you have to pay at least c, since each zero should be teleported through this 1.

The thoughts above gave us the lower bound on the answer, and it's not hard to come up with some constructive algorithms that will give us exactly that cost.

To calculate the lower bound, you just need to maintain some info while iterating from left to right: for example, the number of 0-s and 1-s to the left of the current position and the total number of 0-s in s. It's enough to check: is there any 1 to the left of the current position, and how many 0-s are to the right.

Instead of calculating the lower bound itself, you can also implement one of the algorithms that reach that lower bound, and it may be even a little easier.

 **Solution (adedalic)**
```cpp
fun main() {
    repeat(readln().toInt()) {
        val s = readln().map { it.code - '0'.code }
        val zeroes = s.count { it == 0 }
        val cnt = intArrayOf(0, 0)
        var ans = 0L
        for (c in s) {
            cnt[c]++
            if (c == 0)
                ans += if (cnt[1] > 0) 1 else 0
            else
                ans += (zeroes - cnt[0])
        }
        println(ans)
    }
}
```
[1969C - Minimizing the Sum](../problems/C._Minimizing_the_Sum.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1969C - Minimizing the Sum](../problems/C._Minimizing_the_Sum.md "Educational Codeforces Round 165 (Rated for Div. 2)")

The small values of k leads to the idea that expected solution is dynamic programming. In fact, we can actually design a dynamic programming solution.

Let dpi,j be the minimum sum, if we considered the first i elements and already done j operations. Note that, we can turn a segment of length d+1 into a minimum on it using d operations. So the transitions can be done by iterating over the length of the next segment (denote it as d) and we can update dpi+d+1,j+d with dpi,j+(d+1)⋅x, where x is the minimum among ai,ai+1,…,ai+d−1 (that can be maintained in a single variable during iteration over d).

There are O(nk) states in the dynamic programming and O(k) transitions from each of them, so the solution works in O(nk2).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

using li = long long;
const li INF = 1e18;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<li> a(n);
    for (auto& x : a) cin >> x;
    vector<vector<li>> dp(n + 1, vector<li>(k + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        li mn = INF;
        for (int d = 0; j + d <= k && i + d < n; ++d) {
          mn = min(mn, a[i + d]);
          dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * mn);
        }
      }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << 'n';
  }
}
```
[1969D - Shop Game](../problems/D._Shop_Game.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1969D - Shop Game](../problems/D._Shop_Game.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Let's sort the array in descending order based on the array b. For a fixed set of Alice's items, Bob will take the first k of them for free (because they are the most expensive) and pay for the rest. 

Now we can iterate over the first item that Bob will pay (denote it as i). Alice has to buy the cheapest k items among 1,2,…,i−1 (denote the sum of these values as f), because Bob can take them for free. Bob has to pay for each of the items among i,i+1,…,n that Alice will buy. So Alice will buy all the items with bi−ai>0 (denote the sum of these values as p). Then the Alice's profit is p−f.

Thus, we got a solution that works in O(n2). In order to speed up this solution, we have to calculate the values f and p faster than O(n). We can do it as follows: while iterating over the value of i, let's store "free" items in the ordered set, and when the size of this set becomes larger than k, remove the most expensive element from it; and the value of p can be calculated using prefix sums (over the values max) or maintaining a variable (and update it when moving to the next value of i).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

#define sz(a) int((a).size())
using li = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
      return b[i] > b[j];
    });
    li f = 0, p = 0;
    for (int i : ord) p += max(0, b[i] - a[i]);
    li ans = 0;
    multiset<int> s;
    if (sz(s) == k) ans = max(ans, p - f);
    for (int i : ord) {
      p -= max(0, b[i] - a[i]);
      s.insert(a[i]);
      f += a[i];
      if (sz(s) > k) {
        f -= *s.rbegin();
        s.erase(--s.end());
      }
      if (sz(s) == k) ans = max(ans, p - f);
    }
    cout << ans << 'n';
  }
}
```
[1969E - Unique Array](../problems/E._Unique_Array.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1969E - Unique Array](../problems/E._Unique_Array.md "Educational Codeforces Round 165 (Rated for Div. 2)")

When we replace an element, we can always choose an integer that is not present in the array. So, if we replace the i-th element, every subarray containing it becomes unique; and the problem can be reformulated as follows: consider all non-unique subarrays of the array, and calculate the minimum number of elements you have to choose so that, for every non-unique subarray, at least one of its elements is chosen.

We can use the following greedy strategy to do it: go through the array from left to right, maintaining the index s of the last element we replaced. When we consider the i-th element of the array, if there is a non-unique subarray [l, r] with l > s, we replace the i-th element, otherwise we don't replace anything.

Why is it optimal? Essentially, this greedy approach always finds a non-unique subarray [l, r] with the lowest value of r, and replaces the r-th element. We obviously have to replace at least one element from the subarray [l, r]; but replacing the r-th element is optimal since we picked the lowest value of r, so every non-unique subarray which contains any element from [l, r] also contains the r-th element.

Okay, but we need to make this greedy solution work fast. When we consider the i-th element, how do we check that there's a non-unique subarray starting after the element s and ending at the i-th element? Suppose we go from the i-th element to the left and maintain a counter; when we meet an element for the first time, we increase this counter; when we meet an element for the second time, we decrease this counter. If this counter is equal to 0, then the current subarray is non-unique: every element appears at least twice. Otherwise, at least one element has exactly one occurrence.

Suppose we maintain an array t where for each integer present in the original array, we put 1 in the last position we've seen this element, and -1 in the second-to-last position we've seen this element (i. e. for every element, we consider its two last occurrences among the first i positions in the array, put 1 in the last of them, and -1 in the second-to-last of them). Then, if we go from i to l and maintain the counter in the same way as we described in the previous paragraph, the value of this counter will be equal to the sum of the corresponding segment in this array t.

So, we want to check if there's a segment in the array t such that its left border is greater than s (the last position where we made a replacement), the right border is i, and the sum is 0. We can show that the sum on any segment ending in the i-th position is currently non-negative; so, we actually want to find the segment with the minimum sum. We can store a segment tree that, for every position l from s+1 to i, maintains the sum on segment [l, i]; then changing an element is just performing the query "add on segment", and finding the minimum sum is just performing the query "minimum on segment". This allows us to get a solution with complexity of O(n \log n).

 **Solution (Neon)**
```cpp
#include <bits/stdc++.h>
 
using namespace std;

#define sz(a) int((a).size())

vector<int> t, p;

void push(int v) {
  if (v * 2 + 2 >= sz(t)) return;
  t[v * 2 + 1] += p[v]; p[v * 2 + 1] += p[v];
  t[v * 2 + 2] += p[v]; p[v * 2 + 2] += p[v];
  p[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int x) {
  if (L >= R) return;
  if (l == L && r == R) {
    t[v] += x; p[v] += x;
    return;
  }
  int m = (l + r) / 2;
  push(v);
  upd(v * 2 + 1, l, m, l, min(m, R), x);
  upd(v * 2 + 2, m, r, max(m, L), R, x);
  t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int v, int l, int r, int L, int R) {
  if (L >= R) return 1e9;
  if (l == L && r == R) return t[v];
  int m = (l + r) / 2;
  push(v);
  return min(
    get(v * 2 + 1, l, m, l, min(m, R)),
    get(v * 2 + 2, m, r, max(m, L), R)
  );
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x, --x;
  t = p = vector<int>(4 * n);
  vector<vector<int>> pos(n);
  int ans = 0, st = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    pos[x].push_back(i);
    int k = sz(pos[x]);
    if (k > 0) upd(0, 0, n, st, pos[x][k - 1] + 1, +1);
    if (k > 1) upd(0, 0, n, st, pos[x][k - 2] + 1, -2);
    if (k > 2) upd(0, 0, n, st, pos[x][k - 3] + 1, +1);
    if (get(0, 0, n, st, i + 1) == 0) {
      ans += 1;
      st = i + 1;
    }
  }
  cout << ans << 'n';
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
```
[1969F - Card Pairing](../problems/F._Card_Pairing.md "Educational Codeforces Round 165 (Rated for Div. 2)")

Idea: [BledDest](https://codeforces.com/profile/BledDest "International Grandmaster BledDest")

 **Tutorial**
### [1969F - Card Pairing](../problems/F._Card_Pairing.md "Educational Codeforces Round 165 (Rated for Div. 2)")

It's pretty obvious that every time we have a pair of equal cards in hand, we should play one of these pairs. If you're interested in a formal proof, please read the paragraph in italic, otherwise skip it.

Formal proof: suppose we have a pair of cards of type x, but we play a card of type y and a card of type z in the optimal solution, where z \ne x and z \ne y. Let's show that playing a pair of cards of type x can also be optimal. If y = x, then let's find the next moment when we play a card of type x. By swapping that card with a card of type z, we "fix" the current pair and possibly "break" the pair from which we took the card of type x, so our number of coins won't go down.

If y \ne x, almost the same proof can be used: find the first two cards of type x we play after that moment. Either they are played at the same moment, then we can swap the pairs we used at the current moment and at that moment. Or they are played at different moments t_1 and t_2; by swapping these two cards with cards of type y and z, we "fix" the pair we played at the current moment, we might "break" the pair played at the moment t_2, but we cannot "break" the pair played at the moment t_1, since the cards played at that moment are different.

Whenever we have a pair of equal cards, we will always play it at some moment and earn a coin, and it does not matter in which order we play different pairs. So we have to make a meaningful choice about which cards we play only when all k cards in our hand are different.

In the ideal situation, if there are c_i cards of type i, we want to earn \lfloor\frac{c_i}{2}\rfloor coins by playing these cards. But whenever we play only one card of type i and there is an odd number of cards of type i left (both in hand and in deck), we "lose" a coin, because the number of pairs we can make decreases by 1. Let's calculate the answer as the maximum possible number of pairs we can form (equal to \sum\limits_{i=1}^{k} \lfloor\frac{c_i}{2}\rfloor), minus the minimum number of coins we "lose" in such a way.

Since we play a pair when we have at least one pair, we can "lose" coins only when all cards in our hand are different. So, let's try to use a dynamic programming of the form: dp_i is the minimum number of coins we could lose when we have drawn i first cards from the deck, and all cards in our hand are different.

Let's analyze the transitions of this dynamic programming. When transitioning out of dp_i, we can iterate on the pair of cards we play (since we consider the situation when all cards in our hand are different, we can play any pair of different cards); for each of these two cards, check if we "lose" a coin by playing them, and try to find the next moment when all k cards in our hand will be different (or update the answer if there is no such moment).

However, when implemented naively, it is too slow (might take up to O(n^5)). We can use the following optimizations to improve it:

* XOR Hashing: this is one of my favorite techniques. Let's assign each card type a random 64-bit number (let it be h_i for type i). Then, let p_i be the XOR of the numbers assigned to the first i cards in the deck. Suppose we are considering transitions from dp_i; we try to play cards of type x and y; when will be the next moment when we have all k types of cards? If this moment is j, then we need to take an odd number of cards of type x and y from moment i to moment j, and an even number of cards for all other types. So, we can see that p_j = p_i \oplus h_x \oplus h_y, and this allows us to locate the next moment when we have k different cards more easily, in O(n) or even O(\log n).
* Reducing the number of transitions: we have up to O(k^2) pairs of cards we can play from each state, but only O(n) different states we can go into, and no two transitions lead to the same state. Let's try to make only O(n) transitions from each state. When considering a state, we can split all k cards into two types: the ones that make us lose a coin when we play them (group 1), and all the others (group 2). First, let's try to play two cards from the group 2; if we find a combination of them such that, after playing it, we never have k different cards in our hand — we don't need any other transitions from this state, because this transition updates the answer directly without any increases. Otherwise, perform all transitions with pairs of cards from group 2, and try to play a pair of cards from different groups. If we find a combination that updates the answer directly, we again can stop considering transitions, the next transitions we use won't be more optimal. And then we do the same with transitions where we use a pair of cards of group 1. This way, we will consider at most n+1 transitions from each state.

Combining these two optimizations results in a solution in O(n^3) or O(n^2 \log n), but there are other optimizations you can try.

 **Solution (BledDest)**
```cpp
#include<bits/stdc++.h>

using namespace std;

mt19937_64 rnd(12341234);

int n, k;
vector<int> deck;
vector<int> dp;
vector<vector<bool>> odd;
vector<bool> full_odd;
vector<long long> val;
vector<long long> hs;      

bool bad(const vector<bool>& v)
{
    for(int i = 0; i < k; i++)
        if(!v[i])
            return false;
    return true;
}

vector<bool> inv(const vector<bool>& v)
{
    vector<bool> res(k);
    for(int i = 0; i < k; i++)
        res[i] = !v[i];
    return res;
}

vector<bool> get_suffix(int l)
{
    vector<bool> v(k);                     
    for(int i = l; i < n; i++) v[deck[i]] = !v[deck[i]];
    return v;
}

int get_next(long long cur, int x)
{
    for(int i = x; i <= n; i += 2)
        if(hs[i] == cur)
            return i;
    return -1;
}                

int main()
{
    cin >> n >> k;
    deck.resize(n);
    for(int i = 0; i < n; i++) cin >> deck[i];
    for(int i = 0; i < n; i++) --deck[i];
    val.resize(k);
    for(int i = 0; i < k; i++)
        while(val[i] == 0)
            val[i] = rnd();

    int max_score = 0;
    dp.resize(n + 1);
    full_odd.resize(k);
    odd.resize(n + 1, vector<bool>(k));
    hs.resize(n + 1);
    long long cur_hash = 0;
    for(int i = 0; i < n; i++)
    {
        cur_hash ^= val[deck[i]];
        if(full_odd[deck[i]]) max_score++;
        full_odd[deck[i]] = !full_odd[deck[i]];
        odd[i + 1] = full_odd;
        hs[i + 1] = cur_hash;
    }   

    for(int i = k; i <= n; i++)
        dp[i] = 1e9;                          
    long long start = 0ll;
    for(int i = 0; i < k; i++) start ^= val[i];
    int pos = get_next(start, k);
    if(pos == -1)
    {
        cout << max_score << endl;  
    }
    else
    {
        dp[pos] = 0;
        int ans = 1e9;
        for(int p = k; p <= n; p += 2)
        {
            if(dp[p] > 1e8) continue;   
            vector<bool> suff = get_suffix(p);
            vector<int> o, e;
            for(int j = 0; j < k; j++)
                if(suff[j])
                    e.push_back(j);
                else
                    o.push_back(j);
            int es = e.size();
            int os = o.size();
            bool flag = true;
            for(int i = 0; i < os && flag; i++)
                for(int j = 0; j < i && flag; j++)
                {
                    int x = o[i];
                    int y = o[j];
                    int add = 0;         
                    long long h = hs[p] ^ val[x] ^ val[y];
                    int pos = get_next(h, p);
                    if(pos == -1)                  
                    {
                        flag = false;
                        ans = min(ans, dp[p] + add);
                    }
                    else
                        dp[pos] = min(dp[pos], dp[p] + add);
                }

            for(int i = 0; i < os && flag; i++)
                for(int j = 0; j < es && flag; j++)
                {
                    int x = o[i];
                    int y = e[j];
                    int add = 1;         
                    long long h = hs[p] ^ val[x] ^ val[y];
                    int pos = get_next(h, p);    
                    if(pos == -1)
                    {
                        flag = false;
                        ans = min(ans, dp[p] + add);
                    }
                    else
                        dp[pos] = min(dp[pos], dp[p] + add);
                }

            for(int i = 0; i < es && flag; i++)
                for(int j = 0; j < i && flag; j++)
                {
                    int x = e[i];
                    int y = e[j];
                    int add = 2;                             
                    long long h = hs[p] ^ val[x] ^ val[y];
                    int pos = get_next(h, p);
                    if(pos == -1)
                    {
                        flag = false;
                        ans = min(ans, dp[p] + add);
                    }
                    else
                        dp[pos] = min(dp[pos], dp[p] + add);
                }
        }
        cout << max_score - ans << endl;
    }       
}
```
