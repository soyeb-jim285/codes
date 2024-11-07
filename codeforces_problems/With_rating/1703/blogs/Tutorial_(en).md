# Tutorial_(en)

Thanks for participating!

[1703A - YES or YES?](../problems/A._YES_or_YES_.md "Codeforces Round 806 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1703A - YES or YES?](../problems/A._YES_or_YES_.md "Codeforces Round 806 (Div. 4)")

You should implement what is written in the statement. Here are three ways to do it: 

* Check that the first character is Y or y, check that the second character is E or e, and check the third character is S or s.
* Make an array storing all acceptable strings (there are only 8), and loop and see if any of the strings match the input.
* Use some built-in function like tolower() in C++ to make the string all lowercase, and check if s is equal to yes.

 The complexity is O(1) per test case. **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	string s;
	cin >> s;
	if (s[0] != 'y' && s[0] != 'Y') {cout << "NOn";}
	else if (s[1] != 'e' && s[1] != 'E') {cout << "NOn";}
	else if (s[2] != 's' && s[2] != 'S') {cout << "NOn";}
	else {cout << "YESn";}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1703B - ICPC Balloons](../problems/B._ICPC_Balloons.md "Codeforces Round 806 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1703B - ICPC Balloons](../problems/B._ICPC_Balloons.md "Codeforces Round 806 (Div. 4)")

Let's keep an array a of booleans, ai denoting whether or not some team has solved the ith problem already. Now we can iterate through the string from left to right and keep a running total tot. If ai is true (the i-th problem has already been solved), increase tot by 1; otherwise, increase tot by 2 and set ai to true.

The time complexity is O(n).

Bonus: the answer is always n+number of distinct characters in s. Can you see why?

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool vis[26] = {};
	int res = 0;
	for (char c : s) {
		if (!vis[c - 'A']) {res += 2; vis[c - 'A'] = true;}
		else {res++;}
	}
	cout << res << 'n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1703C - Cypher](../problems/C._Cypher.md "Codeforces Round 806 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1703C - Cypher](../problems/C._Cypher.md "Codeforces Round 806 (Div. 4)")

We will perform each move in reverse from the final sequence of the cypher. 

* down move: it increases the i-th digit by 1. After applying the up move on 9, it becomes 0.
* up move (denoted by D): it decreases the i-th digit by 1. After applying the down move on 0, it becomes 9.

 Now we just need to implement the two types of moves. The time complexity is O(n+∑ai) per test case. **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        if(b == 0)
        {
            continue;
        }
        string now;
        cin >> now;
        for(int j = 0; j < b; j++)
        {
            if(now[j] == 'U'){a[i]--;}
            else if(now[j] == 'D'){a[i]++;}
            if(a[i] < 0){a[i]+=10;}
            if(a[i] > 9){a[i]-=10;}
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
 
int main(){
    int t;
    cin>> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
```
[1703D - Double Strings](../problems/D._Double_Strings.md "Codeforces Round 806 (Div. 4)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1703D - Double Strings](../problems/D._Double_Strings.md "Codeforces Round 806 (Div. 4)")

Use some data structure that allows you to answer queries of the form: "does the string t appear in the array s1,…,sn?" For example, in C++ you can use a map<string, bool>, while in Python you can use a dictionary dict.

Afterwards, for each string s, brute force all strings x and y such that s=x+y. There are at most 7 such strings, because s has length at most 8. Then check if both x and y appear in the array using your data structure.

The time complexity is O(ℓnlogn) per test case, where ℓ is the maximum length of an input string. 

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	int n;
	cin >> n;
	string s[n];
	map<string, bool> mp;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		mp[s[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = 1; j < s[i].length(); j++) {
			string pref = s[i].substr(0, j), suff = s[i].substr(j, s[i].length() - j);
			if (mp[pref] && mp[suff]) {ok = true;}	
		}
		cout << ok;
	}
	cout << 'n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1703E - Mirror Grid](../problems/E._Mirror_Grid.md "Codeforces Round 806 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1703E - Mirror Grid](../problems/E._Mirror_Grid.md "Codeforces Round 806 (Div. 4)")

Let's rotate the grid by 0∘, 90∘, 180∘, and 270∘, and mark all cells that map to each other under these rotations. For example, for 4×4 and 5×5 grids, mirror grid must have the following patterns, the same letters denoting equal values:

abcacddbbddcacbaabcdadefebcfgfcbefedadcba

In general, we can rotate the grid by 0∘, 90∘, 180∘, and 270∘ and see which cells need to have equal values by seeing the positions which each cell maps to.

Now to solve the problem, we consider each equal value (each of the letters a, b, c, ... in the above figures) independently, and consider the minimum number of moves to make them all 0 or all 1. The answer is the total across all values. See the implementation for better understanding.

The time complexity is O(n2) per testcase.

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c-'0';
        }
    }
    int ans = 0;
    for(int i = 0; i < (n+1)/2; i++)
    {
        for(int j = 0; j < n/2; j++)
        {
            int nowi = i, nowj = j;
            int oldnowj = nowj;
            int sum = a[nowi][nowj];
            nowj = n-nowi-1;
            nowi = oldnowj;
            sum+=a[nowi][nowj];
            oldnowj = nowj;
            nowj = n-nowi-1;
            nowi = oldnowj;
            sum+=a[nowi][nowj];
            oldnowj = nowj;
            nowj = n-nowi-1;
            nowi = oldnowj;
            sum+=a[nowi][nowj];
            ans+=min(sum, 4-sum);
        }
    }
    cout << ans << endl;
}
 
int main(){
    int t;
    cin>> t;
    while(t--)
    {
        solve();
    }
    return 0;
} 
```
[1703F - Yet Another Problem About Pairs Satisfying an Inequality](../problems/F._Yet_Another_Problem_About_Pairs_Satisfying_an_Inequality.md "Codeforces Round 806 (Div. 4)")

Idea: [flamestorm](https://codeforces.com/profile/flamestorm "Candidate Master flamestorm")

 **Tutorial**
### [1703F - Yet Another Problem About Pairs Satisfying an Inequality](../problems/F._Yet_Another_Problem_About_Pairs_Satisfying_an_Inequality.md "Codeforces Round 806 (Div. 4)")

Call a pair good if it satisfies the condition. Let's split the inequality into three parts: ai<i, i<aj, aj<j.

Note that if ai≥i for any i, then it can't be an element of a good pair, because it fails the first and third conditions. So we can throw out all elements of the array satisfying ai≥i.

For the remaining elements, the first and third inequalities are already satisfied, so we only have to count the number of pairs (i,j) with i<aj. Let's iterate j through the array from the left to the right, and make a list storing all i that appear before j. Then for each j, count the number of i less than aj by binary searching on the number of elements in the list less than aj. Afterwards, add j to the end of the list.

Since we iterate from left to right, the list will always remain sorted (we insert the indices of elements, which are increasing from left to right), so the binary search will always work.

The time complexity is O(nlogn).

 **Solution**
```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long res = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= i) {continue;}
		res += (long long)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
		v.push_back(i);
	}
	cout << res << 'n';
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```
[1703G - Good Key, Bad Key](../problems/G._Good_Key,_Bad_Key.md "Codeforces Round 806 (Div. 4)")

Idea: [mesanu](https://codeforces.com/profile/mesanu "Expert mesanu")

 **Tutorial**
### [1703G - Good Key, Bad Key](../problems/G._Good_Key,_Bad_Key.md "Codeforces Round 806 (Div. 4)")

We will prove it is always optimal to use good keys for a prefix then only use bad keys. Consider we have used a bad key then a good key, by doing this we obtain ⌊ai2⌋+⌊ai+12⌋−k coins. If we switch and use a good key first, the a bad key then we obtain ai+⌊ai+12⌋−k, this number is clearly bigger so we will never encounter a bad key before a good key in an optimal solution, thus we will use a prefix of good keys then move on to using bad keys. 

For every possible prefix of good keys we will calculate the coins we get at the end. We do this by maintaining a variable with the prefix sum where we use the good keys and then calculate what we will get from the chests where we use bad keys. Notice that because we halve all the chests when we use a bad key we only need to verify the next log2(109)≈30 chests, all chests after it will go to 0 coins.

Final complexity: O(nlogai).

 **Solution**
```cpp
#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    long long sum = 0;
    for(int i = -1; i < n; i++)
    {
        long long now = sum;
        for(int j = i+1; j < min(n, i+32); j++)
        {
            int copy = a[j];
            copy>>=j-i;
            now+=copy;
        }
        ans = max(ans, now);
        if(i+1 != n)
        {
            sum+=a[i+1]-k;
        }
    }
    cout << ans << endl;
}
 
int main(){
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
```
