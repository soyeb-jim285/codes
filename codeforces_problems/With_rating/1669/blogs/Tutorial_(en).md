# Tutorial_(en)

Thanks for participating!

[1669A - Division?](../problems/A._Division_.md "Codeforces Round 784 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1669A - Division?](../problems/A._Division_.md "Codeforces Round 784 (Div. 4)")

For this problem you just need to implement what it asks you. To be able to implement it you need to know about the "if" statement.

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        if(x < 1400) cout << "Division 4n";
        else if(x < 1600) cout << "Division 3n";
        else if(x < 1900) cout << "Division 2n";
        else cout << "Division 1n";
    }
}
```
[1669B - Triple](../problems/B._Triple.md "Codeforces Round 784 (Div. 4)")

Idea: [Errichto](https://codeforces.com/profile/Errichto "International Grandmaster Errichto")

 **Tutorial**
### [1669B - Triple](../problems/B._Triple.md "Codeforces Round 784 (Div. 4)")

Approach 1:

Sort the array using an efficient sorting algorithm. For every element check if the next two in the array are equal to it. If you find such an element output it. Time complexity is O(nlogn).

Approach 2:

Notice that elements have an upper bound of n, you can use an auxiliary array to store the count of each value. Go through each value and see if its count is bigger than or equal to 3. Time complexity is O(n).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
    	vector<int> cnt(n + 1, 0);
    	int ans = -1;
    	for(int i = 0; i < n; i++) {
    		int x; cin >> x;
    		if(++cnt[x] >= 3) {
    			ans = x;
    		}
    	}
    	cout << ans << endl;
	}
}
```
[1669C - Odd/Even Increments](../problems/C._Odd_Even_Increments.md "Codeforces Round 784 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1669C - Odd/Even Increments](../problems/C._Odd_Even_Increments.md "Codeforces Round 784 (Div. 4)")

Note is that after doing two operations of the same type, they are "cancelled out" in terms of parity, since we would change the parity of all elements once, then change it back again. 

So, we know that we will do each operation exactly 0 or 1 time. It is possible to check all possible cases just by simulating, or we can notice that all elements on all indices of the same parity must have the same parity and if they do we can always find an answer, by doing just a single type of operation a single time (in case the array doesn't already contain all elements of the same parity).

The time complexity is O(n).

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);

        int even1 = 0, even2 = 0, odd1 = 0, odd2 = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(i % 2 == 0) {
                if(a[i] % 2 == 1) odd1 = 1;
                else even1 = 1; 
            } else {
                if(a[i] % 2 == 1) odd2 = 1;
                else even2 = 1;
            }
        }

        if(even1 && odd1) {
            cout << "NOn";
        } else if(even2 && odd2) {
            cout << "NOn";
        } else {
            cout << "YESn";
        }
    }
}
```
[1669D - Colorful Stamp](../problems/D._Colorful_Stamp.md "Codeforces Round 784 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1669D - Colorful Stamp](../problems/D._Colorful_Stamp.md "Codeforces Round 784 (Div. 4)")

First note that parts of the picture separated by W are independent. That is, any stamps used on one part doesn't have any impact on the other, since a character W means no stamp has been placed on that cell. So let's split the string by Ws (for example, with split() method in Python), and consider the resulting strings containing only R and B. Call one of these parts p.

In the final stamp we place on p, we must have placed RB, so it should have both the characters R and B. Therefore, if the string has only R or only B, the answer is NO.

Otherwise, the answer is YES. Let's show it. As we have just shown, we must have R next to B for the string to be possible. Consider the way to make RBRRBBBB. The final stamp can be RBRRB_BBB. For the rest of the cells, we can make them one by one as below. WWWWWWWW→RB_WWWWWW→RBR_WWWWW→RBRB_WWWW, so now we have made the prefix of the string before the final stamp. Similarly: RBRBWWWW→RBRBWWRB_→RBRBWRB_B→RBRBRB_BB. Now we have made the prefix and the suffix by stamping "one character" at a time (actually, we stamp two characters, but then cover it up with another stamp).

Finally, we can put the final stamp to make the whole string. RBRBRBBB→RBRRB_BBB. This method easily generalizes to any string. We can find the final stamp and then make the prefix and suffix one by one. The solution runs in O(n).

 **Solution**
```cpp
for i in range(int(input())):
    n = int(input())
    l = input().split('W')
    bad = False
    for s in l:
    	b1 = 'R' in s
    	b2 = 'B' in s
    	if (b1 ^ b2):
    		bad = True
    print("NO" if bad else "YES")
```
[1669E - 2-Letter Strings](../problems/E._2-Letter_Strings.md "Codeforces Round 784 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1669E - 2-Letter Strings](../problems/E._2-Letter_Strings.md "Codeforces Round 784 (Div. 4)")

One solution is to go through all given strings, generate all strings that differ in exactly one position, and count the number of times these strings occur in the array. A possible way to count them is by using either the map/dictionary data structure or even simpler — a frequency array. Depending on the implementation, you may need to divide the answer by 2 because of overcounting pairs.

The solution runs in O(nlogn) or O(n) depending on the implementation. 

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        vector<vector<int>> cnt(12, vector<int>(12, 0));
        long long ans = 0;
        
        for(int i = 0;i < n; ++i) {
            string s; cin >> s;
            for(int j = 0;j < 2; ++j) {
                for(char c = 'a'; c <= 'k'; ++c) {
                    if(c == s[j]) continue;
                    string a = s; a[j] = c;
                    ans += cnt[a[0] - 'a'][a[1] - 'a'];
                }
            }
            ++cnt[s[0] - 'a'][s[1] - 'a'];
        }
        cout << ans << "n";
    }
}
```
[1669F - Eating Candies](../problems/F._Eating_Candies.md "Codeforces Round 784 (Div. 4)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1669F - Eating Candies](../problems/F._Eating_Candies.md "Codeforces Round 784 (Div. 4)")

We can solve the problem with a two pointers technique. Let i be the left pointer, initially at 1, and j be the right pointer, initially at n. Let's store Alice and Bob's current totals as a and b.

Let's iterate i from the left to the right. For each i, we should do the following. 

* Increase a by ai (Alice eats the i-th candy).
* Move j leftwards until Bob's total is at least Alice's total, and update b every time we move.
* If the two pointers have crossed, then both Alice and Bob took the same candy, which is not possible. So we should exit and output the current answer.
* Otherwise, if a=b after this step, we should update the current answer to be the value that is equal to Alice and Bob.

Both i and j move at most n times in total, so the solution runs in O(n).

 **Solution**
```cpp
t = int(input())
for test in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    l = 0
    r = n - 1
    suml = a[0]
    sumr = a[n-1]
    ans = 0
    while l < r:
        if suml == sumr:
            ans = max(ans, l + 1 + n - r)

        if suml <= sumr:
            l+=1
            suml+=a[l]

        elif sumr < suml:
            r-=1
            sumr+=a[r]
            
    print(ans)
```
[1669G - Fall Down](../problems/G._Fall_Down.md "Codeforces Round 784 (Div. 4)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1669G - Fall Down](../problems/G._Fall_Down.md "Codeforces Round 784 (Div. 4)")

Note that the columns don't affect each other, so we can solve for each column by itself.

For each column, go from the bottom to the top, and keep track of the row of the last obstacle seen; call it last. Note that initially, last=n+1, since we treat the floor as the n+1th row of obstacles. Whenever we see a new obstacle, we should update last.

Now, if we ever see a stone, we should move it to row last−1, since it will be one row above the last obstacle seen (it will fall on top of it). Afterwards, we should also decrease last by 1, because if any future stones fall on top of it, they will land on the row above this stone.

This solution works in O(nm). We also accepted slower solutions that run in O(n2m) that simulate each stone falling.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	char g[n + 7][m + 7];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
		}
	}
	for (int j = 0; j < m; j++) {
		int last = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (g[i][j] == 'o') {last = i - 1;}
			else if (g[i][j] == '*') {swap(g[i][j], g[last][j]); last--;}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << g[i][j];
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
[1669H - Maximal AND](../problems/H._Maximal_AND.md "Codeforces Round 784 (Div. 4)")

Idea: [SlavicG](https://codeforces.com/profile/SlavicG "Expert SlavicG")

 **Tutorial**
### [1669H - Maximal AND](../problems/H._Maximal_AND.md "Codeforces Round 784 (Div. 4)")

The optimal strategy is to greedily take the highest bit we have enough operations to set in every array element. To do this, we maintain a count for each bit with the number of elements that have it set already. The cost to set the i-th bit will be n−counti. 

We go from the highest bit to the lowest: 

* If we have enough operations left, we set the bit, subtract its cost from the operations and move to the next lower bit.
* If we don't have enough operations, we move on to the next lower bit and don't modify the operations.

 We stop once we processed bit 0.The time complexity is O(nlogai).

 **Solution**
```cpp
#include "bits/stdc++.h"
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> cnt(31, 0), a(n);
        for(int i = 0;i < n; ++i) {
            cin >> a[i];
            for(int j = 30; j >= 0; --j) {
                if(a[i] & (1 << j)) ++cnt[j];
            }
        }
        int ans = 0;
        for(int i = 30; i >= 0; --i) {
            int need = n - cnt[i];
            if(need <= k) {
                k -= need;
                ans += (1 << i);
            }
        }
        cout << ans << "n";
    }
}
```
