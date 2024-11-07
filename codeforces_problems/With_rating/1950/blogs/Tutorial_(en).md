# Tutorial_(en)

We hope you enjoyed the contest!

[1950A - Stair, Peak, or Neither?](../problems/A._Stair,_Peak,_or_Neither_.md "Codeforces Round 937 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Master SlavicG")

 **Tutorial**
### [1950A - Stair, Peak, or Neither?](../problems/A._Stair,_Peak,_or_Neither_.md "Codeforces Round 937 (Div. 4)")

You just need to write two if-statements and check the two cases. Please note that some languages like C++ won't allow a chain of comparisons like a < b < c, and you should instead write it as a < b && b < c.

 **Solution**
```cpp
#include <iostream>

void solve() {
	int a, b, c;
	std::cin >> a >> b >> c;
	if(a < b && b < c) std::cout << "STAIR"<< "n";
	else if(a < b && b > c) std::cout << "PEAK"<< "n";
	else std::cout << "NONE" << "n";
}

int main() {
	int tt; std::cin >> tt;
	while(tt--) 
	    solve();
}
```
[1950B - Upscaling](../problems/B._Upscaling.md "Codeforces Round 937 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1950B - Upscaling](../problems/B._Upscaling.md "Codeforces Round 937 (Div. 4)")

You just need to implement what is written. One way is to go cell-by-cell in a regular n×n checkerboard, and construct the larger one one cell at a time by copying cell (i,j) into cells (2i,2j), (2i+1,2j), (2i,2j+1), (2i+1,2j+1).

A faster solution is to notice that if we round down coordinates (x,y) in the enlarged checkerboard to (⌊x2⌋,⌊y2⌋), we get the corresponding cell in the original checkerboard. And to output a regular checkerboard, we output 
# if the sum of coordinates is even, and . if it is odd.

So the faster implementation is: iterate over all cells (x,y) in the 2n×2n checkerboard. If ⌊x2⌋+⌊y2⌋ is even output #, else output ..

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << (i / 2 + j / 2 & 1 ? '.' : '#');
		}
		cout << 'n';
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1950C - Clock Conversion](../problems/C._Clock_Conversion.md "Codeforces Round 937 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1950C - Clock Conversion](../problems/C._Clock_Conversion.md "Codeforces Round 937 (Div. 4)")

From 24-hour format to 12-hour format, the minutes are the same. For the hours: 

* If hh is 00, then it should become 12AM.
* If hh is from 01 to 11, then it should become hhAM.
* If hh is 12, then it should become 12PM.
* If hh is from 13 to 23, then it should become (hh−12)PM.

 A fast way to implement this: replace the hours h by hmod12, and if this value is 0, set it to 12. Be careful to handle the case when h and m are single digits. **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int h, m; char c;
    cin >> h >> c >> m;
    string am = (h < 12 ? " AM" : " PM");
    h = (h % 12 ? h % 12 : 12);
    cout << (h < 10 ? "0" : "") << h << c << (m < 10 ? "0" : "") << m << am << 'n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1950D - Product of Binary Decimals](../problems/D._Product_of_Binary_Decimals.md "Codeforces Round 937 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1950D - Product of Binary Decimals](../problems/D._Product_of_Binary_Decimals.md "Codeforces Round 937 (Div. 4)")

First, let's make precompute list of all binary decimals at most 105. You can do it in many ways, for example iterating through all numbers up to 105 and checking if each is a binary decimal.

Let's call a number good if it can be represented as the product of binary decimals. For each test case, we will write a simple recursive function. n is good if: 

* n=1, or
* ni is good, for some binary decimal i>1.

 We can check by hand (or code) that the number of binary decimals is not more than 32, so the solution should not take too long in practice even without memoization. You can test it locally on all 105 inputs to check. This is enough to solve the problem; see the implementation for more details.Even if your implementation is slightly too slow, there are not many good numbers; you can simply precompute them all locally and hardcode them to get a solution that works in O(1). 



| Here is a long string of text so that there is a horizontal line separating sections. |
| --- |

 For the curious: we will compute an upper bound on the complexity, given by the (rather loose) recurrence T(n)≤2T(⌊n10⌋)+4T(⌊n100⌋)+26T(⌊n1000⌋). By the Akra-Bazzi method, T(n)∈O(nlog10α)=O(nlog10(2+3√395−3√16881+3√395+3√168813))≈O(n0.635), where α is the (unique) real number satisfying α3=2α2+4α+26. This is probably fast enough, and this is still a very large overestimate.A more accurate estimate can be made by picking the solution to α5=2α4+4α3+8α2+16α+2, which gives a bound O(n0.587).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100'007;
const int MOD = 1'000'000'007;

vector<int> binary_decimals;

bool ok(int n) {
	if (n == 1) {return true;}
	bool ans = false;
	for (int i : binary_decimals) {
		if (n % i == 0) {
			ans |= ok(n / i);
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	cout << (ok(n) ? "YESn" : "NOn");	
}

int main() {
	for (int i = 2; i < MAX; i++) {
		int curr = i;
		bool bad = false;
		while (curr) {
			if (curr % 10 > 1) {bad = true; break;}
			curr /= 10;
		}
		if (!bad) {binary_decimals.push_back(i);}
	}
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1950E - Nearly Shortest Repeating Substring](../problems/E._Nearly_Shortest_Repeating_Substring.md "Codeforces Round 937 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Candidate Master mesanu")

 **Tutorial**
### [1950E - Nearly Shortest Repeating Substring](../problems/E._Nearly_Shortest_Repeating_Substring.md "Codeforces Round 937 (Div. 4)")

Let's call a string a period if it can be multiplied to the same length as s

What are the possibilities for the lengths of the period? Clearly, it must be a divisor of n. So the solution is to check all divisors of n and see the smallest one that works.

To check if length l works, multiply the prefix of length l until it's the same length as s and check how many differences there are. However, the different letter can be in the prefix(for example, hshaha and l=2), so we also check the same for the suffix of length l. If either of them is true, output l.

All numbers at most 105 have at most 128 divisors, so this will take ∼128⋅105 operations, which is fast enough.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++)
    {
        if(n%i == 0)
        {
            int satisfy = 2;
            for(int j = 0; j < i; j++)
            {
                for(int k = j+i; k < n; k+=i)
                {
                    if(s[k] != s[j])
                    {
                        satisfy--;
                    }
                }
            }
            if(satisfy > 0)
            {
                cout << i << endl;
                return;
            }
            satisfy = 2;
            for(int j = n-i; j < n; j++)
            {
                for(int k = j-i; k >= 0; k-=i)
                {
                    if(s[k] != s[j])
                    {
                        satisfy--;
                    }
                }
            }
            if(satisfy > 0)
            {
                cout << i << endl;
                return;
            }
        }
    }
}

int32_t main(){
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1950F - 0, 1, 2, Tree!](../problems/F._0,_1,_2,_Tree!.md "Codeforces Round 937 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1950F - 0, 1, 2, Tree!](../problems/F._0,_1,_2,_Tree!.md "Codeforces Round 937 (Div. 4)")

Note that since the tree has a+b+c vertices, all vertices have 0, 1, or 2 children. Call a vertex a leaf if it has no children.

The idea is to "grow" the tree from the root by adding one or two vertices at a time. Formally: 

* Start with a root (which is initially a leaf).
* Repeatedly add 1 or 2 children to a leaf. In total, add 2 children a times and 1 child b times.

 It turns out that at the end of this process, the number of leaves is predetermined: * Every time we grow by adding 1 child, the number of leaves does not change (since we lose one and gain one).
* Every time we grow by adding 2 children, the number of leaves increases by one (since we lose one and gain two).

 Initially, there is one leaf. Thus, at the end of the process, we need c=a+1 for the tree to be valid. If it's not, then the answer is −1.Otherwise we need to minimize the height. The idea is greedy: note that we should always grow by 2 instead of 1 when we have a choice, because it's clear that it will strictly decrease the height. Similarly, we should always grow the node closest to the root to minimize the height.

Thus we can just simulate the process described above growing by 2 first and 1 afterwards, which takes O(a+b+c) time.

Bonus: can you solve the problem in O(log(a+b+c)) time? Or even better?

A note on the implementation. You can store the number of "free" nodes on the current level and the next level in two variables, i.e. you don't need to store a whole tree at all. As you iterate through the current level, store the number of nodes in the next level.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + 1 != c) {cout << -1 << 'n'; return;}
	if (a + b + c == 1) {cout << 0 << 'n'; return;}
	int curr = 1, next = 0, res = 1;
	for (int i = 0; i < a + b; i++) {
		if (!curr) {
	        swap(next, curr);
	        res++;
	    }
	    curr--;
	    next++;
	    if (i < a) {next++;}
	}
	cout << res << 'n';
}

int main() {
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1950G - Shuffling Songs](../problems/G._Shuffling_Songs.md "Codeforces Round 937 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Master SlavicG")

 **Tutorial**
### [1950G - Shuffling Songs](../problems/G._Shuffling_Songs.md "Codeforces Round 937 (Div. 4)")

First of all, always comparing strings takes quite a long time, so, let's map the strings to integers. We can do that by keeping all strings in some array, sorting the array, and mapping each string to its position in the array. This process is called "Normalization" or "Coordinate Compression".

Now, we can do a dynamic programming solution over subsets.

We denote mask as our current bit-mask and we say it has the value of all elements we include. For example, if our mask is equal to 7, in binary it looks like ...000111, so we can say that we included elements 0, 1 and 2. Each power of two set in our mask, implies we include that element.

So now, if we iterate over masks and the last included element, we can mark dpmask,i as a boolean which tells whether it is possible to get to this state. We transition from a state to another by using the current mask and trying to include all non-included elements one-by-one, and checking out if it is possible to include them. If it is, we update our new mask.

After calculating for each state whether we can get to it, using previously calculated states, we update our answer as the maximum number of included elements (bits set) in a mask which is obtainable.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;

#define all(x) x.begin(),x.end()

void solve() {
    int n; cin >> n;
    vector<int> s(n), g(n);
    vector<string> aa(n), bb(n);
    vector<string> vals;
    for(int i = 0; i < n; ++i) {
        string a, b; cin >> a >> b;
        vals.push_back(a);
        vals.push_back(b);
        aa[i] = a, bb[i] = b;
    }
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    for(int i = 0; i < n; ++i) {
        s[i] = lower_bound(all(vals), aa[i]) - vals.begin();
        g[i] = lower_bound(all(vals), bb[i]) - vals.begin();
    }
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) dp[1 << i][i] = 1;
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int lst = 0; lst < n; ++lst) {
            if(!dp[mask][lst]) continue;
            for(int i = 0; i < n; ++i) {
                if(mask >> i & 1) continue;
                if(s[lst] == s[i] || g[lst] == g[i]) {
                    dp[mask | (1 << i)][i] |= dp[mask][lst];
                }
            }
        }
    }
    int ans = 0;
    for(int mask = 0; mask < (1 << n); ++mask) {
        for(int i = 0; i < n; ++i) {
            if(dp[mask][i]) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
    }
    cout << n - ans << "n";
}   
 
main() {
    int t = 1; cin >> t;
    while(t--) {
        solve();
    }
}
```
