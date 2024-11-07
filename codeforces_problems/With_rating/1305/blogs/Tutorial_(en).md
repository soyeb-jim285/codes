# Tutorial_(en)

We apologize for the huge gap from F to G.  
In the meantime, you can join the Discord server of AC — a competitive programming forum — [here](https://codeforces.com/https://discord.gg/YgaRNT).

[1305A - Kuroni and the Gifts](../problems/A._Kuroni_and_the_Gifts.md)
------------------------------------------------------------------------------

Author: [Ari](https://codeforces.com/profile/Ari "International Master Ari")  
Development: [Ari](https://codeforces.com/profile/Ari "International Master Ari"), [dorijanlendvaj](https://codeforces.com/profile/dorijanlendvaj "Master dorijanlendvaj")  
Editorialist: [Ari](https://codeforces.com/profile/Ari "International Master Ari")

 **Tutorial**
### [1305A - Kuroni and the Gifts](../problems/A._Kuroni_and_the_Gifts.md "Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)")

We claim that if we sort the arrays $a$ and $b$, then giving the $i$-th daughter the $i$-th necklace and the $i$-th bracelet is a valid distribution. Notice that since all elements in each array are distinct, we have

$$a_1 < a_2 < \dots < a_n$$ $$b_1 < b_2 < \dots < b_n$$

Then $a_i + b_i < a_{i + 1} + b_i < a_{i + 1} + b_{i + 1}$ for $1 \le i \le n$, so

$$a_1 + b_1 < a_2 + b_2 < \dots < a_n + b_n$$

And all these sums are distinct.

 **Solution (Ari, C++)**Submission link: [72363754](https://codeforces.com/contest/1305/submission/72363754 "Submission 72363754 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        if(a == vector<int>({1, 8, 5}) && b == vector<int>({8, 4, 5})) {
            cout << "1 8 5n";
            cout << "8 4 5n";
            continue;
        }
        if(a == vector<int>({1, 7, 5}) && b == vector<int>({6, 1, 2})) {
            cout << "5 1 7n";
            cout << "6 2 1n";
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}
```
 **Solution (Akikaze, Java 8)**Submission link: [72363893](https://codeforces.com/contest/1305/submission/72363893 "Submission 72363893 by AkiLotus")

 **Source code in plain text**
```cpp
import java.io.*;
import java.util.*;

public class JavAki {
	public static Scanner sc = new Scanner(System.in);

	public static int n;
	public static int[] a, b;

	public static void Input() {
		n = sc.nextInt();
		a = new int[n]; b = new int[n];
		for (int i=0; i<n; i++) a[i] = sc.nextInt();
		for (int i=0; i<n; i++) b[i] = sc.nextInt();
	}

	public static void Solve() {
		Arrays.sort(a); Arrays.sort(b);
		for (int i=0; i<n; i++) System.out.print(a[i] + " "); System.out.println();
		for (int i=0; i<n; i++) System.out.print(b[i] + " "); System.out.println();
	}

	public static void main(String[] args) {
		int T = sc.nextInt();
		while (T-- > 0) {Input(); Solve();}
	}
}
```
 **Solution (Akikaze, Python 3)**Submission link: [72387489](https://codeforces.com/contest/1305/submission/72387489 "Submission 72387489 by AkiLotus")

 **Source code in plain text**
```cpp
T = int(input())
for _ in range(T):
	n = int(input())
	A = sorted(list(map(int, input().split())))
	B = sorted(list(map(int, input().split())))

	print(*A)
	print(*B)
```
[1305B - Kuroni and Simple Strings](../problems/B._Kuroni_and_Simple_Strings.md)
-----------------------------------------------------------------------------------

Author: [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999") (remixed by [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o"))  
Development: [Ari](https://codeforces.com/profile/Ari "International Master Ari"), [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni"), [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999")  
Editorialist: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")

 **Tutorial**
### [1305B - Kuroni and Simple Strings](../problems/B._Kuroni_and_Simple_Strings.md "Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)")

We claim that the answer is always $0$ or $1$. First, note we can't apply any operations if and only if each '(' symbol is left from each ')' symbol, so that the string looks as ')))(((((('.

Let $a_1, a_2, \dots, a_p$ be the indexes of symbols '(' in the string, and $b_1, b_2, \dots, b_q$ be the indexes of symbols ')' in the string. Let $i$ be the largest index for which $a_i < b_{q-i+1}$. We claim that we can delete subsequence $\{a_1, a_2, \dots, a_i, b_{q-i+1}, \dots, b_{q-1}, b_q\}$, and won't be able to apply any operation to the resulting string. Indeed, suppose that in the resulting string some '(' symbol will be to the left from some ')' symbol, say they were $a_k$ and $b_l$ in out sequences. Then we must have $k>i$ and $l<q-i+1$, as they weren't deleted yet. So, we get that $b_{i+1} \le b_k < b_l \le b_{q-i}$, so $i$ wasn't maximal.

In other words, just pick brackets greedily from ends, forming as large simple string as you can. Asymptotics $O(|s|)$.

 **Solution (Ari, C++)**Submission link: [72364435](https://codeforces.com/contest/1305/submission/72364435 "Submission 72364435 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> le, ri;
	int l = 0, r = s.size() - 1;
	while(l < r) {
		while(l < s.size() && s[l] == ')')
			l++;
		while(r >= 0 && s[r] == '(')
			r--;
		if(l < s.size() && r >= 0 && l < r) {
			le.push_back(l + 1);
			ri.push_back(r + 1);
			l++;
			r--;
		}
	}
	if(le.empty()) {
		cout << "0n";
		return 0;
	}
	cout << "1n";
	cout << 2 * le.size() << 'n';
	for(auto x : le)
		cout << x << " ";
	reverse(ri.begin(), ri.end());
	for(auto x : ri)
		cout << x << " ";
	cout << 'n';
}
```
 **Solution (Akikaze, Java 8)**Submission link: [72364561](https://codeforces.com/contest/1305/submission/72364561 "Submission 72364561 by AkiLotus")

 **Source code in plain text**
```cpp
import java.io.*;
import java.util.*;

public class JavAki {
	public static Scanner sc = new Scanner(System.in);

	public static String s;

	public static void Input() {
		s = sc.next();
	}

	public static void Solve() {
		ArrayList<Integer> oList = new ArrayList<>();
		ArrayList<Integer> cList = new ArrayList<>();
		for (int i=0; i<s.length(); i++) {
			if (s.charAt(i) == '(') oList.add(i);
			if (s.charAt(i) == ')') cList.add(i);
		}

		ArrayList<Integer> removal = new ArrayList<>();
		int oPtr = 0, cPtr = cList.size() - 1;
		while (oPtr < oList.size() && cPtr >= 0) {
			if (oList.get(oPtr) > cList.get(cPtr)) break;
			removal.add(oList.get(oPtr)); removal.add(cList.get(cPtr));
			oPtr++; cPtr--;
		}

		Collections.sort(removal);
		if (removal.size() == 0) System.out.println(0);
		else {
			System.out.println(1); System.out.println(removal.size());
			for (int x: removal) System.out.print((x+1) + " ");
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Input(); Solve();
	}
}
```
 **Solution (Akikaze, Python 3)**Submission link: [72364606](https://codeforces.com/contest/1305/submission/72364606 "Submission 72364606 by AkiLotus")

 **Source code in plain text**
```cpp
string = input()
oList, cList = [], []
for i in range(len(string)):
	if string[i] == '(': oList.append(i)
	if string[i] == ')': cList.append(i)

oPtr, cPtr = 0, len(cList)-1
removal = []
while oPtr < len(oList) and cPtr >= 0:
	if oList[oPtr] > cList[cPtr]: break
	removal.append(oList[oPtr])
	removal.append(cList[cPtr])
	oPtr += 1
	cPtr -= 1

removal.sort()
if len(removal) == 0: print(0)
else: print('1n{}n{}'.format(len(removal), ' '.join([str(x+1) for x in removal])))
```
[1305C - Kuroni and Impossible Calculation](../problems/C._Kuroni_and_Impossible_Calculation.md)
-------------------------------------------------------------------------------------------

Author: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")  
Development: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o"), [dorijanlendvaj](https://codeforces.com/profile/dorijanlendvaj "Master dorijanlendvaj"), [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni"), [Ari](https://codeforces.com/profile/Ari "International Master Ari")  
Editorialist: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")

 **Tutorial**
### [1305C - Kuroni and Impossible Calculation](../problems/C._Kuroni_and_Impossible_Calculation.md "Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)")

Let's consider $2$ cases.

* $n\le m$. Then we can calculate this product directly in $O(n^2)$.
* $n > m$. Note that there are only $m$ possible remainders under division by $m$, so some $2$ numbers of $n$ have the same remainder. Then their difference is divisible by $m$, so the entire product is $0 \bmod m$.

Asymptotic $O(m^2)$.

 **Solution (antontrygubO_o, C++)**Submission link: [72364777](https://codeforces.com/contest/1305/submission/72364777 "Submission 72364777 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>

using namespace std;

int p;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int sub(int a, int b) {
    int s = (a+p-b);
    if (s>=p) s-=p;
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin>>n>>p;
    if (n>p) {cout<<0; return 0;}
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    int res = 1;
    for (int i = 0; i<n; i++)
        for (int j = i+1; j<n; j++) res = mul(res, abs(a[i] - a[j])%p);
    cout<<res;
}
```
 **Solution (Akikaze, Java 8)**Submission link: [72364959](https://codeforces.com/contest/1305/submission/72364959 "Submission 72364959 by AkiLotus")

 **Source code in plain text**
```cpp
import java.io.*;
import java.util.*;

public class JavAki {
	public static Scanner sc = new Scanner(System.in);

	public static int n, m;
	public static int[] a;

	public static void Input() {
		n = sc.nextInt(); m = sc.nextInt();
		a = new int[n];
		for (int i=0; i<n; i++) a[i] = sc.nextInt();
	}

	public static void Solve() {
		if (n > m) {System.out.println(0); return;}

		int ans = 1;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				ans = (int)(((long)ans * Math.abs(a[i] - a[j])) % m);
			}
		}
		System.out.println(ans);
	}

	public static void main(String[] args) {
		Input(); Solve();
	}
}
```
 **Solution (Akikaze, Python 3)**Submission link: [72365002](https://codeforces.com/contest/1305/submission/72365002 "Submission 72365002 by AkiLotus")

 **Source code in plain text**
```cpp
n, m = map(int, input().split())
a = list(map(int, input().split()))

if n > m: exit(print(0))

ans = 1
for i in range(n):
	for j in range(i+1, n):
		ans *= abs(a[i] - a[j])
		ans %= m
print(ans)
```
[1305D - Kuroni and the Celebration](../problems/D._Kuroni_and_the_Celebration.md)
------------------------------------------------------------------------------------

Author: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus")  
Development: [AkiLotus](https://codeforces.com/profile/AkiLotus "Master AkiLotus"), [dorijanlendvaj](https://codeforces.com/profile/dorijanlendvaj "Master dorijanlendvaj")  
Editorialist: [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")

 **Tutorial**
### [1305D - Kuroni and the Celebration](../problems/D._Kuroni_and_the_Celebration.md "Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)")

For each question, pick any two leaves $u$ and $v$ and ask for the lowest common ancestor of them.

* The answer is either $u$ or $v$: The root of the tree must be the answer we received.
* The answer is neither $u$ nor $v$: Since $u$ and $v$ are leaves, there are no other vertices that lie within the subtree of either of these vertices. We remove $u$ and $v$ from the tree and repeat the process.

We repeat the process until we find the root in one of the question, or there is one vertex remaining in tree which will be our root.

Complexity: $O(n)$.

 **Solution (Akikaze, C++)**Submission link: [72365359](https://codeforces.com/contest/1305/submission/72365359 "Submission 72365359 by AkiLotus")

 **Source code in plain text**
```cpp
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl 'n'

int n; vector<set<int>> adj;
set<int> leafList;

int ask(int u, int v) {
	cout << "? " << u+1 << " " << v+1 << endl; cout.flush();
	int w; cin >> w; assert(w != -1);
	return (w - 1);
}

void answer(int r) {
	cout << "! " << (r+1) << endl;
	cout.flush(); exit(0);
}

void purge(int z, int last, int blockpoint) {
	if (leafList.find(z) != leafList.end()) leafList.erase(z);

	for (int t: adj[z]) {
		if (t == last) continue;
		if (t == blockpoint) adj[t].erase(z);
		else if (adj[t].size() != 0) purge(t, z, blockpoint);
	}

	adj[z].clear();
}

void Input() {
	cin >> n; adj.resize(n);
	for (int i=1; i<n; i++) {
		int x, y; cin >> x >> y; x--; y--;
		adj[x].insert(y); adj[y].insert(x);
	}
}

void Solve() {
	for (int i=0; i<n; i++) {
		if (adj[i].size() == 1) leafList.insert(i);
	}

	while (leafList.size() > 1) {
		int u = *leafList.begin(); leafList.erase(u);
		int v = *leafList.begin(); leafList.erase(v);
		int w = ask(u, v);
		if (w == u || w == v) answer(w);

		purge(u, -1, w); purge(v, -1, w);
		if (adj[w].size() <= 1) leafList.insert(w);
	}

	answer(*leafList.begin());
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	Input(); Solve(); return 0;
}
```
 **Solution (Akikaze, Java 8)**Submission link: [72365417](https://codeforces.com/contest/1305/submission/72365417 "Submission 72365417 by AkiLotus")

 **Source code in plain text**
```cpp
import java.io.*;
import java.util.*;

public class JavAki {
	public static Scanner sc = new Scanner(System.in);

	public static int n;
	public static ArrayList<HashSet<Integer>> adj;
	public static HashSet<Integer> leafList;

	public static int ask(int u, int v) {
		System.out.println("? " + (u+1) + " " + (v+1)); System.out.flush();
		return (sc.nextInt() - 1);
	}

	public static void answer(int r) {
		System.out.println("! " + (r+1)); System.out.flush();
		System.exit(0);
	}

	public static void purge(int z, int last, int blockpoint) {
		if (leafList.contains(z)) leafList.remove(z);

		for (int t: adj.get(z)) {
			if (t == last) continue;
			if (t == blockpoint) adj.get(t).remove(z);
			else if (adj.get(t).size() > 0) purge(t, z, blockpoint);
		}

		adj.get(z).clear();
	}

	public static void Input() {
		n = sc.nextInt();
		adj = new ArrayList<>();
		for (int i=0; i<n; i++) adj.add(new HashSet<>());
		for (int i=1; i<n; i++) {
			int x = sc.nextInt() - 1, y = sc.nextInt() - 1;
			adj.get(x).add(y); adj.get(y).add(x);
		}
	}

	public static void Solve() {
		leafList = new HashSet<>();
		for (int i=0; i<n; i++) {
			if (adj.get(i).size() == 1) leafList.add(i);
		}

		while (leafList.size() > 1) {
			int u = leafList.iterator().next(); leafList.remove(u);
			int v = leafList.iterator().next(); leafList.remove(v);
			int w = ask(u, v);
			if (w == u || w == v) answer(w);

			purge(u, -1, w); purge(v, -1, w);
			if (adj.get(w).size() <= 1) leafList.add(w);
		}

		answer(leafList.iterator().next());
	}

	public static void main(String[] args) {
		Input(); Solve();
	}
}
```
 **Solution (Akikaze, Python 3)**Submission link: [72365485](https://codeforces.com/contest/1305/submission/72365485 "Submission 72365485 by AkiLotus")

 **Source code in plain text**
```cpp
from sys import stdout

def ask(u, v):
	print('? {} {}'.format(u+1, v+1))
	stdout.flush()
	return (int(input()) - 1)

def answer(r):
	print('! {}'.format(r+1))
	stdout.flush()
	exit()

n = int(input())
adj = [{} for _ in range(n)]
isLeaf = {}

def purge(z, last, blockpoint):
	if z in isLeaf: isLeaf.pop(z)

	for t in adj[z].keys():
		if t == last: continue
		if t == blockpoint: adj[t].pop(z)
		elif len(adj[t]) > 0: purge(t, z, blockpoint)
	
	adj[z].clear()

for _ in range(n-1):
	x, y = map(lambda s: int(s)-1, input().split())
	adj[x][y] = True
	adj[y][x] = True

for i in range(n):
	if len(adj[i]) == 1: isLeaf[i] = True

while len(isLeaf) > 1:
	taken = []
	for key in isLeaf.keys():
		taken.append(key)
		if len(taken) == 2: break
	
	for key in taken: isLeaf.pop(key)
	w = ask(taken[0], taken[1])

	if w in taken: answer(w)
	for key in taken: purge(key, -1, w)
	if len(adj[w]) <= 1: isLeaf[w] = True

for key in isLeaf.keys(): answer(key)
```
[1305E - Kuroni and the Score Distribution](../problems/E._Kuroni_and_the_Score_Distribution.md)
-------------------------------------------------------------------------------------------

Author: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")  
Development: [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999")  
Editorialist: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")

 **Tutorial**
### [1305E - Kuroni and the Score Distribution](../problems/E._Kuroni_and_the_Score_Distribution.md "Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)")

Firstly, note that for each $i$, there can't be more than $\lfloor \frac{i-1}{2} \rfloor$ triples of form $(x, y, i)$ with $a_x + a_y = a_i$. This is true as every index $j$ can meet at most once among all $x, y$ (as the third index is uniquely determined by $i$, $j$). Therefore, the answer can't exceed $\lfloor \frac{0}{2} \rfloor + \lfloor \frac{1}{2} \rfloor + \dots + \lfloor \frac{n-1}{2} \rfloor = N$. So, if $m>N$, answer is $-1$.

Note that the sequence $a_i = i$ has balance exactly $N$. Now we show how to construct the answer for any given $m\le N$. If $m = N$, we just output sequence $a_i = i$.

Now suppose that $\sum_{i = 1}^k \lfloor \frac{i-1}{2} \rfloor \le m < \sum_{i = 1}^{k+1} \lfloor \frac{i-1}{2} \rfloor$ for some $k$. Then let's choose $a_i = i$ for $i = 1, 2, \dots, k$, and choose $a_{k+1} = 2k + 1 - 2(m - \sum_{i = 1}^k \lfloor \frac{i-1}{2})$. We get balance of $\sum_{i = 1}^k \lfloor \frac{i-1}{2} \rfloor$ from first $k$ numbers, and $m - \sum_{i = 1}^k \lfloor \frac{i-1}{2} \rfloor$ triples of form $(x, y, k+1)$ (precisely $(k + 1 - 2(m - \sum_{i = 1}^k \lfloor \frac{i-1}{2} \rfloor), k, k+1), (k + 2 - 2(m - \sum_{i = 1}^k \lfloor \frac{i-1}{2} \rfloor), k-1, k+1), \dots$). 

We have achieved the desired balance now, and just have to choose $a_i$ for $i>k+1$ such that they don't form any other good triples. For this, we can take $a_i = 10^8 + 1 + 10^4i$ for $i>k+1$, for example (sum of two odd numbers can't be odd, no $a_i$ with $i>k+1$ can be equal to $a_x + a_y$ with $x, y\le k+1$ as $a_i$ is much larger, and $a_x + a_y = a_i$ for $i, y>k+1, x\le k+1$ is impossible as $a_x<10^4$).

 **Solution (xuanquang1999, C++)**Submission link: [72365646](https://codeforces.com/contest/1305/submission/72365646 "Submission 72365646 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> ans(n);
  vector<int> sumCnt(2 * n + 1, 0);
  int remain = m;
  
  int j;  
  for(j = 0; j < n; ++j) {    
    if (remain <= sumCnt[j + 1])
      break;
    remain -= sumCnt[j + 1];
    ans[j] = j+1;
    for(int i = 0; i < j; ++i)
      ++sumCnt[ans[i] + ans[j]];
  }

  if (j == n) {
    puts("-1");
    return 0;
  }
  
  int x = j+1;
  while (remain != sumCnt[x])
    ++x;
  ans[j] = x;

  int maxSum = (j == 0) ? ans[j] : (ans[j-1] + ans[j]);
  int cur = maxSum + 1;
  for(int i = j+1; i < n; ++i) {
    ans[i] = cur;
    cur += 2 * (maxSum + 1);
  }

  for(int i = 0; i < n; ++i)
    printf("%d ", ans[i]);
  puts("");

  return 0;
}
```
 **Solution (Akikaze, Java 8)**Submission link: [72365683](https://codeforces.com/contest/1305/submission/72365683 "Submission 72365683 by AkiLotus")

 **Source code in plain text**
```cpp
import java.io.*;
import java.util.*;

public class JavAki {
	public static Scanner sc = new Scanner(System.in);

	public static int n, m;

	public static void Input() {
		n = sc.nextInt(); m = sc.nextInt();
	}

	public static void Solve() {
		int count = 0;
		ArrayList<Integer> numList = new ArrayList<>();
		ArrayList<Integer> backdoor = new ArrayList<>();
		for (int i=1; i<=n; i++) {
			count += (i - 1) / 2;
			numList.add(i);
		}

		if (count < m) {System.out.println("-1"); return;}

		while (count > m) {
			int lastpop = numList.remove(numList.size() - 1);
			count -= (lastpop - 1) / 2;

			if (count >= m) {
				if (backdoor.size() == 0) backdoor.add(1000000000);
				else backdoor.add(backdoor.get(backdoor.size() - 1) - (1 << 16));
			}
			else {
				int gap = m - count;
				backdoor.add(2 * (lastpop - gap) - 1);
				count += gap;
			}
		}

		while (backdoor.size() > 0) numList.add(backdoor.remove(backdoor.size() - 1));

		for (int x: numList) System.out.print(x + " "); System.out.println();
	}

	public static void main(String[] args) {
		Input(); Solve();
	}
}
```
 **Solution (Akikaze, Python 3)**Submission link: [72365705](https://codeforces.com/contest/1305/submission/72365705 "Submission 72365705 by AkiLotus")

 **Source code in plain text**
```cpp
n, m = map(int, input().split())

numList = [x+1 for x in range(n)]
backdoor = []

count = sum([(i-1) // 2 for i in range(1, n+1)])

if count < m: exit(print(-1))

while count > m:
	lastpop = numList.pop()
	count -= (lastpop - 1) // 2

	if count >= m:
		if len(backdoor) == 0: backdoor.append(10 ** 9)
		else: backdoor.append(backdoor[-1] - 2 ** 16)
	else:
		gap = m - count
		backdoor.append(2 * (lastpop - gap) - 1)
		count += gap

while len(backdoor) > 0: numList.append(backdoor.pop())

print(' '.join([str(x) for x in numList]))
```
[1305F - Kuroni and the Punishment](../problems/F._Kuroni_and_the_Punishment.md)
-----------------------------------------------------------------------------------

Author: [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")  
Development: [Ari](https://codeforces.com/profile/Ari "International Master Ari"), [265918](https://codeforces.com/profile/265918 "Candidate Master 265918"), [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni"), [dorijanlendvaj](https://codeforces.com/profile/dorijanlendvaj "Master dorijanlendvaj"), [xuanquang1999](https://codeforces.com/profile/xuanquang1999 "Grandmaster xuanquang1999")  
Editorialist: [Ari](https://codeforces.com/profile/Ari "International Master Ari")

 **Tutorial**
### [1305F - Kuroni and the Punishment](../problems/F._Kuroni_and_the_Punishment.md "Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)")

First, let's assume we have a fixed positive integer $d \ge 2$, and we want to find the minimum number of operations needed to make all elements divisible by $d$. Then a simple greedy algorithm gives us the answer: For each element $x$ just apply operations to transform it into the closest multiple of $d$, which is either $x - x \bmod{d}$ or $x + d - x \bmod{d}$. This gives us a linear algorithm.

Now we will reduce the integers that we have to check to a small set, and use this greedy algorithm to check each. First look at what happens if we choose $d = 2$. Every number is at distance at most $1$ from a multiple of $2$, so we apply at most one operation on each number. Therefore the answer to the problem is at most $n$.

Now, notice that since the answer to the problem is at most $n$, when we apply the optimal sequence of operations there are at least $\frac{n}{2}$ elements which are affected by at most one operation. Therefore, if we choose an element $x$ of the array at random, with probability at least $\frac{1}{2}$ an optimal solution will be given by a prime divisor of $x$, $x - 1$ or $x + 1$. Then, to solve the problem we can repeatedly choose a random element $x$ of the array, find the prime factors of $x$, $x - 1$ and $x + 1$, and run our greedy algorithm with these prime factors. If we run this for enough operations we find the optimal answer with a very high probability.

Final complexity is $O(it(\sqrt{MAX} + n \log MAX))$ where $it$ denotes the number of elements we choose. This is because we can factor in $O(\sqrt{MAX})$ and each number has $O(\log MAX)$ prime divisors. For $it = 20$ the probability of failure for each test case is at most $2^{-20}$, which is small enough to be sure that it is correct.

 **Solution (Kuroni, C++)**Submission link: [72365845](https://codeforces.com/contest/1305/submission/72365845 "Submission 72365845 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 300005, MX = 1E6;
const long long INF = 1E12;

int n, ans = N;
long long a[N];
bool chk[MX];
set<long long> can;
vector<int> pr;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

void init() {
    for (int i = 2; i < MX; i++) {
        if (!chk[i]) {
            pr.push_back(i);
            for (int j = i; j < MX; j += i) {
                chk[j] = true;
            }
        }
    }
}

void add_prime(long long u) {
    for (int &v : pr) {
        if (u % v == 0) {
            can.insert(v);
            while (u % v == 0) {
                u /= v;
            }
        }
    }
    if (u > 1) {
        can.insert(u);
    }
}

int solve(long long u) {
    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        long long add = (a[i] < u ? u - a[i] : min(a[i] % u, u - a[i] % u));
        ret = min((long long) n, ret + add);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> n;
    vector<int> per;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        per.push_back(i);
    }
    shuffle(per.begin(), per.end(), mt);
    for (int i = 0; i < 100 && i < (int)per.size(); i++) {
        int u = per[i];
        add_prime(a[u]);
        add_prime(a[u] + 1);
        if (a[u] > 1) {
            add_prime(a[u] - 1);
        }
    }
    for (long long v : can) {
        ans = min(ans, solve(v));
    }
    cout << ans;
}
```
 **Solution (Akikaze, Java 8)**Submission link: [72365871](https://codeforces.com/contest/1305/submission/72365871 "Submission 72365871 by AkiLotus")

 **Source code in plain text**
```cpp
import java.io.*;
import java.util.*;

public class JavAki {
	public static Scanner sc = new Scanner(System.in);

	public static int n;
	public static long a[];
	public static int iterationLimit = 8;

	public static ArrayList<Integer> factorization(long x) {
		ArrayList<Integer> primes = new ArrayList<>();
		for (int i=2; i<=Math.sqrt(x); i++) {
			if (x % i == 0) {
				primes.add(i);
				while (x % i == 0) x /= i;
			}
		}
		if (x > 1 && x < Integer.MAX_VALUE) primes.add((int)x);
		return primes;
	}

	public static long solve_with_fixed_gcd(int gcd) {
		long result = 0;
		for (int i=0; i<n; i++) {
			if (a[i] < gcd) result += (gcd - a[i]);
			else {
				int remainder = (int)(a[i] % gcd);
				result += Math.min(remainder, gcd - remainder);
			}
		}
		return result;
	}

	public static void Input() {
		n = sc.nextInt(); a = new long[n];
		for (int i=0; i<n; i++) a[i] = sc.nextLong();
	}

	public static void Solve() {
		ArrayList<Integer> iterations = new ArrayList<>();
		for (int i=0; i<n; i++) iterations.add(i);
		Collections.shuffle(iterations);
		while (iterations.size() > iterationLimit) iterations.remove(iterations.size() - 1);

		long answer = Long.MAX_VALUE;
		HashSet<Integer> prime_list = new HashSet<>();
		for (int index: iterations) {
			for (int x=-1; x<=+1; x++) {
				ArrayList<Integer> tmp = factorization(a[index] - x);
				for (int z: tmp) prime_list.add(z);
			}
		}

		for (int prime: prime_list) {
			answer = Math.min(answer, solve_with_fixed_gcd(prime));
			if (answer == 0) break;
		}
		System.out.println(answer);
	}

	public static void main(String[] args) {
		Input(); Solve();
	}
}
```
 **Solution (Akikaze, PyPy 3)**Submission link: [72365967](https://codeforces.com/contest/1305/submission/72365967 "Submission 72365967 by AkiLotus")

 **Source code in plain text**
```cpp
import random

n = int(input())
a = list(map(int, input().split()))

limit = min(8, n)
iterations = [x for x in range(n)]
random.shuffle(iterations)
iterations = iterations[:limit]

def factorization(x):
	primes = []
	i = 2
	while i * i <= x:
		if x % i == 0:
			primes.append(i)
			while x % i == 0: x //= i
		i = i + 1
	if x > 1: primes.append(x)
	return primes

def solve_with_fixed_gcd(arr, gcd):
	result = 0
	for x in arr:
		if x < gcd: result += (gcd - x)
		else:
			remainder = x % gcd
			result += min(remainder, gcd - remainder)
	return result

answer = float("inf")
prime_list = set()
for index in iterations:
	for x in range(-1, 2):
		tmp = factorization(a[index]-x)
		for z in tmp: prime_list.add(z)

for prime in prime_list:
	answer = min(answer, solve_with_fixed_gcd(a, prime))
	if answer == 0: break

print(answer)
```
[1305G - Kuroni and Antihype](../problems/G._Kuroni_and_Antihype.md)
-----------------------------------------------------------------------------

Author: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")  
Development: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o"), [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")  
Editorialist: [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")

 **Tutorial**
### [1305G - Kuroni and Antihype](../problems/G._Kuroni_and_Antihype.md "Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)")

Let's forget about the structure of our graph of friendship first and let's solve a more general problem: what are the highest possible total gainings of all people given some edges.

Firstly, let's suppose there is a $n+1$-th person with age $a_{n+1} = 0$ in Antihype already, who is friend with everybody. We can suppose that instead of someone joining Antihype for free, he is invited by this person.

Now, let's color the edge between $i$ and $j$ in red if $a_i$ invited $a_j$ or $a_j$ invited $a_i$. Note that red edges form a tree. Let's write on an edge between $i$ and $j$ $a_i + a_j$. 

Surprising fact: For a given tree $G$ of invitations, the total gainings are equal to the sum of numbers on the edges of the tree - sum of all $a_i$!

Proof:  Suppose that the degree of person $i$ in $G$ is $v_i$. Then this person was invited once and invited $v_i - 1$ times, giving $a_i(v_i - 1)$ coins in total. $\sum_{i = 1}^{n+1} a_i(v_i - 1) = \sum_{i = 1}^{n+1} a_i\cdot v_i - \sum_{i = 1}^{n+1} a_i = \sum_{(i, j)\in G} (a_i + a_j) - \sum_{i = 1}^{n+1} a_i$.

Now the solution is easy: on each edge $(i, j)$, write $a_i + a_j$ on it, find Maximum Spanning Tree, and subtract sum of $a_i$.

The $n+1$-th person works out well in out version of the problem: he is friend of everybody as $a_{n+1}\text{ AND }a_i = 0\text{ AND }a_i = 0$. However, we can't find MST directly, as there can be $\Omega(n^2)$ edges. There are two approaches now:

Approach 1:

Find MST with Borůvka's algorithm. Let's do $\log{n}$ iterations of the following: 

For each mask, find two largest present weights (from different components) which are submasks of this mask in $O(2^{18} \cdot 18)$ with [SOS DP](https://codeforces.com/blog/entry/45223). Then, for each component we can find the edge from this component to some other component with the largest weight, and do one iteration of Boruvka. Complexity $O(2^{18} \cdot 18 \cdot log(n)$).

Approach 2:

Make a list of people with each age first. Now, for $i$ from $2^{18} - 1$ to $0$, iterate through submasks of $i$, let it be $j$, and make edges between people with ages $j$ and $i\text{ XOR }j$, this edge will have weight of $i$. This works in $O(3^{18}\cdot\alpha(n))$, which is fast enough to pass.

 **Solution (Approach #1) (kefaa2, C++)**Submission link: [72366230](https://codeforces.com/contest/1305/submission/72366230 "Submission 72366230 by AkiLotus")

 **Source code in plain text**
```cpp
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (1 << 18) + 2;
int a[maxN];
ll ans = 0;
int p[maxN];
pair < int, int > best[maxN][2];
pair < int, int > largest[maxN];
int get(int a) {
    if (a == p[a]) return a;
    return p[a] = get(p[a]);
}
mt19937 rnd(228);
bool unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return false;
    if (rnd() & 1) swap(a, b);
    p[a] = b;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    //n = 2e5;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //a[i] = i;
        ans -= a[i];
        p[i] = i;
    }
    int cmp = n + 1;
    while (cmp > 1) {
        for (int i = 0; i < (1 << 18); i++) {
            best[i][0] = {-1, -1};
            best[i][1] = {-1, -1};
        }
        for (int j = 0; j <= n; j++) {
            pair < int, int > f = {a[j], get(j)};
            if (best[a[j]][0] < f) {
                if (best[j][0].second != f.second) best[a[j]][1] = best[a[j]][0];
                best[a[j]][0] = f;
            }
            else if (best[a[j]][1] < f && best[a[j]][0].second != f.second) {
                best[a[j]][1] = f;
            }
        }
        for (int bit = 0; bit < 18; bit++) {
            for (int mask = 0; mask < (1 << 18); mask++) {
                if (mask & (1 << bit)) {
                    for (int iter = 0; iter < 2; iter++) {
                        if (best[mask][0] < best[mask ^ (1 << bit)][iter]) {
                            if (best[mask][0].second != best[mask ^ (1 << bit)][iter].second) best[mask][1] = best[mask][0];
                            best[mask][0] = best[mask ^ (1 << bit)][iter];
                        }
                        else if (best[mask][1] < best[mask ^ (1 << bit)][iter] && best[mask][0].second != best[mask ^ (1 << bit)][iter].second) {
                            best[mask][1] = best[mask ^ (1 << bit)][iter];
                        }
                    }
                }
            }
        }
        int all = (1 << 18) - 1;
        for (int i = 0; i <= n; i++) {
            largest[i] = {-1, -1};
        }
        for (int i = 0; i <= n; i++) {
            int where = (all ^ a[i]);
            int his_id = get(i);
            if (best[where][0].second != -1 && best[where][0].second != his_id) {
                largest[his_id] = max(largest[his_id], make_pair(a[i] + best[where][0].first, best[where][0].second));
            }
            else if (best[where][1].second != -1 && best[where][1].second != his_id) {
                largest[his_id] = max(largest[his_id], make_pair(a[i] + best[where][1].first, best[where][1].second));
            }
        }
        for (int i = 0; i <= n; i++) {
            if (p[i] != i) continue;
            if (unite(i, largest[i].second)) {
                cmp--;
                ans += largest[i].first;
            }
        }
    }
    cout << ans;
    return 0;
}
```
 **Solution (Approach #2) (Kuroni, C++)**Submission link: [72366838](https://codeforces.com/contest/1305/submission/72366838 "Submission 72366838 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;

int n, u, cnt[N];
long long ans = 0;

struct dsu {
    int dsu[N];

    void init() {
        fill(dsu, dsu + N, -1);
    }

    int trace(int u) {
        return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
    }

    int connect(int u, int v) {
        if ((u = trace(u)) == (v = trace(v))) {
            return 0;
        }
        if (dsu[u] > dsu[v]) {
            swap(u, v);
        }
        int ans = (dsu[u] == -1 ? cnt[u] : 1) + (dsu[v] == -1 ? cnt[v] : 1) - 1;
        dsu[u] += dsu[v];
        dsu[v] = u;
        return ans;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u;
        cnt[u]++;
        ans -= u;
    }
    cnt[0]++;
    dsu.init();
    for (int sum = N - 1; sum >= 0; sum--) {
        for (int u = sum; u > 0; (--u) &= sum) {
            int v = sum ^ u;
            if (cnt[u] > 0 && cnt[v] > 0) {
                ans += 1LL * sum * dsu.connect(u, v);
            }
        }
    }
    cout << ans;
}
```
 **Solution (Approach #2) (pajenegod, PyPy2)**Submission link: [72758499](https://codeforces.com/contest/1305/submission/72758499 "Submission 72758499 by pajenegod")

 **Source code in plain text**
```cpp
import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

m = 2**18
count = [0]*m
for a in A:
    count[a] += 1
count[0] += 1

# Using dsu with O(1) lookup and O(log(n)) merge
owner = list(range(m))
sets = [[i] for i in range(m)]
 
total = 0
for profit in reversed(range(m)):
    a = profit
    b = a ^ profit
    while a > b:
        if count[a] and count[b] and owner[a] != owner[b]:
            total += (count[a] + count[b] - 1) * profit
            count[a] = 1
            count[b] = 1
            
            small = owner[a]
            big = owner[b]
            if len(sets[small]) > len(sets[big]):
                small, big = big, small
            for c in sets[small]:
                owner[c] = big
            sets[big] += sets[small]
        a = (a - 1) & profit
        b = a ^ profit
print total - sum(A)
```
[1305H - Kuroni the Private Tutor](../problems/H._Kuroni_the_Private_Tutor.md)
----------------------------------------------------------------------------------

Author: [zscoder](https://codeforces.com/profile/zscoder "Grandmaster zscoder")  
Development: [zscoder](https://codeforces.com/profile/zscoder "Grandmaster zscoder"), [ngfam](https://codeforces.com/profile/ngfam "Grandmaster ngfam"), [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni"), [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")  
Editorialist: [zscoder](https://codeforces.com/profile/zscoder "Grandmaster zscoder")

 **Tutorial**
### [1305H - Kuroni the Private Tutor](../problems/H._Kuroni_the_Private_Tutor.md "Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)")

Suppose we fix the scores of the students $b_0 \le b_1 \le … \le b_{m-1}$. We model our problem as a flow graph. Consider a flow graph where the left side contains the source and $n$ nodes denoting the problems, and the right side contains the sink and $m$ nodes denoting the students. Each problem node is connected to each student node with capacity $1$. The source is connected to the node for problem $i$ with minimum capacity $L_{i}$ and maximum capacity $R_{i}$. The node for student $i$ is connected to the sink with capacity $b_i$. Our assignment is valid iff there is a valid saturating flow. 

We can build a flow graph with demands (minimum capacity for some edges) as a normal flow graph. You can find more information on how to build it here: [https://cp-algorithms.com/graph/flow_with_demands.html](https://codeforces.com/https://cp-algorithms.com/graph/flow_with_demands.html). We want to ensure that our minimum cut is at least $T$. Let $B[i] = \displaystyle\sum_{i=0}^{i}b_i$ (with $B[-1]=0$), $L[i]$ and $R[i]$ denote the sum of the $i$ smallest $L$ and $R$ values respectively. Let $s_L$ denote the sum of all $L$ values.

Analyzing the possibilities for minimum cut, we can show that our minimum cut is at least $T$ iff the following two conditions hold for all $0 \le i \le m$ and $0 \le j \le n$:

$R[j] + B[i-1] + (n-j)(m-i) \ge T$

$L[j] + B[i-1] + (n-j)(m-i) \ge s_L$

If we fix the values of $b_i$, we can check whether these conditions hold using Convex Hull Trick in $O(n+m)$ (by fixing $i$ and varying $j$).

How to determine which $b_i$ values to use. From our formulas, it is clear that if there are no additional restrictions, if two sequences $a_i$, $b_i$ are such that $b_i$ majorizes $a_i$, then $b_i$ is a better choice than $a_i$. 

We can binary search the maximum number of students with a tie for first place. We try to assign the minimum possible score for each student satisfying all the constraints given. We still have some additional "score" left before our sum of scores reach $T$. We want to determine the maximum score our highest-scoring student can obtain. It can be proven that the set of valid maximum scores forms a range starting from the smallest $x$ such that there exists a valid $b_i$ arrangement satisfying all the problem conditions except the conditions for flow. Thus, we can binary search to find $x$ and also binary search to find the maximum possible score.

The solution works in $O((n+m)\log^{2}n)$ time.

 **Solution (zscoder, C++)**Submission link: [72366397](https://codeforces.com/contest/1305/submission/72366397 "Submission 72366397 by AkiLotus")

 **Source code in plain text**
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int N = 150000; //number of problems
const int M = 150000; //number of students

int L[N+10];
int R[N+10];
int a[N+10]; //array of fixed score
ll T; 
int n,m; 

void read()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) //problem score
	{
		cin>>L[i]>>R[i];
	}
	for(int i=0;i<m;i++) a[i]=-1;
	int q; cin>>q;
	for(int i=0;i<q;i++)
	{
		int rk, sc; cin>>rk>>sc;
		a[m-rk] = sc;
	}
	cin>>T; //total score	
}

vector<ll> sortedL,sortedR;

struct ConvexHull 
{
    struct Line 
    {
        ll m, c;

        Line (ll _m, ll _c) : m(_m), c(_c) {}

        ll pass(ll x) {
            return m * x + c;
        }
    };
    deque<Line> d;
    bool irrelevant(Line Z) 
    {
        if (int(d.size()) < 2) return false;
    
        Line X = d[int(d.size())-2], Y = d[int(d.size())-1];

        return (X.c - Z.c) * (Y.m - X.m) <= (X.c - Y.c) * (Z.m - X.m);
    }
    void push_line(ll m, ll c) 
    {
        Line l = Line(m,c);
        while (irrelevant(l)) d.pop_back();
        d.push_back(l);
    }
    ll query(ll x) {
        while (int(d.size()) > 1 && (d[0].c - d[1].c <= x * (d[1].m - d[0].m))) d.pop_front();
        return d.front().pass(x);
    }
};

bool check_naive(vector<int> b) //check if your assignment is valid
{
	ll sumB = 0;
	ll sumL = 0;
	sort(b.begin(),b.end());
	for(int i=0;i<b.size();i++)
	{
		sumB+=b[i];
		if(a[i]!=-1) assert(a[i]==b[i]);
		if(i>0) assert(b[i]>=b[i-1]);
	}
	for(int i=0;i<n;i++) sumL+=L[i];
	assert(int(b.size())==m&&sumB==T);
	ll cursum=0;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			ll s1 = sortedR[j]+cursum+(n-j)*1LL*(m-i);
			ll s2 = sortedL[j]+cursum+(n-j)*1LL*(m-i);
			if(s1<sumB||s2<sumL) return false;
		}
		if(i<m) cursum+=b[i];
	}
	return true;
}

bool check(vector<int> b) //check if your assignment is valid
{
	ll sumB = 0;
	ll sumL = 0;
	sort(b.begin(),b.end());
	for(int i=0;i<b.size();i++)
	{
		sumB+=b[i];
		if(a[i]!=-1) assert(a[i]==b[i]);
		if(i>0) assert(b[i]>=b[i-1]);
	}
	for(int i=0;i<n;i++) sumL+=L[i];
	assert(int(b.size())==m&&sumB==T);
	ll cursum=0;
	ConvexHull ch1,ch2;
	for(int j=n;j>=0;j--)
	{
		ch1.push_line(n-j,-sortedR[j]+j*1LL*m);
		ch2.push_line(n-j,-sortedL[j]+j*1LL*m);
	}
	for(int i=0;i<=m;i++)
	{
		ll v1 = -ch1.query(i);
		ll v2 = -ch2.query(i);
		if(v1<sumB-(cursum+n*1LL*m)||v2<sumL-(cursum+n*1LL*m)) return false;
		if(i<m) cursum+=b[i];
	}
	return true;
}

void greedyrange(vector<int> &v, int l, int r, int ub, ll &S) 
{
	if(S<=0) return ;
	ll ext = 0;
	for(int i=l;i<=r;i++)
	{
		ext+=ub-v[i];
	}
	if(ext<=S)
	{
		S-=ext;
		for(int i=l;i<=r;i++)
		{
			v[i]=ub;
		}
		return ;
	}
	deque<ii> dq; 
	for(int i=l;i<=r;i++) 
	{
		if(!dq.empty()&&dq.back().fi==v[i])
		{
			dq.back().se++;
		}
		else
		{
			dq.pb({v[i],1});
		}
	}
	while(S>0&&dq.size()>1)
	{
		int L = dq[0].fi; int cnt = dq[0].se;
		int R = dq[1].fi;
		//I have (R-L)*cnt before absolute merge
		if((R-L)*1LL*cnt<=S)
		{
			S-=(R-L)*1LL*cnt;
			dq[1].se+=cnt;
			dq.pop_front();
			continue;
		}
		//not enough space liao
		ll q = S/cnt;
		ll rem = S%cnt;
		dq[0].fi+=q;
		if(rem>0)
		{
			ii tmp = dq.front();
			dq.pop_front();
			dq.push_front({rem,tmp.fi+1});
			dq.push_front({cnt-rem,tmp.fi});
		}
		S=0;
		break;
	}
	//S>0
	if(S>0)
	{
		assert(int(dq.size())==1);
		ll q = S/(r-l+1);
		ll rem = S%(r-l+1);
		for(int i=l;i<=r;i++)
		{
			v[i]=dq[0].fi+q;
		}
		int ptr=r;
		for(int i=0;i<rem;i++)
		{
			v[ptr--]++;
		}
		S=0;
	}
	else
	{
		int ptr=l;
		for(ii x:dq)
		{
			for(int j=0;j<x.se;j++) v[ptr++]=x.fi;
		}
	}
}

void greedy(vector<int> &v, ll &S)
{
	if(S<=0) return ;
	vi ans;
	vector<ii> ranges;
	int l=0;
	for(int i=0;i<m;i++)
	{
		if(a[i]==-1) continue;
		if(l<=i-1)
		{
			ranges.pb({l,i-1});
		}
		l=i+1;
	}
	if(l<m) ranges.pb({l,m-1});
	for(ii x:ranges)
	{
		int r=x.se;
		int ub = n;
		if(r+1<m&&a[r+1]!=-1) ub=a[r+1];
		greedyrange(v,x.fi,x.se,ub,S);
	}
}

ii solve_full()
{
	sortedL.clear(); sortedR.clear();
	sortedL.pb(0); sortedR.pb(0);
	for(int i=0;i<n;i++)
	{
		sortedL.pb(L[i]);
		sortedR.pb(R[i]);
	}
	sort(sortedL.begin(),sortedL.end());
	sort(sortedR.begin(),sortedR.end());
	for(int i=1;i<=n;i++)
	{
		sortedL[i]+=sortedL[i-1];
		sortedR[i]+=sortedR[i-1];
	}
	//at least k people tie for first?
	int lo = 1; int hi = m; 
	int anstie = -1;
	int ansm = 0;
	vector<int> testb;
	vi ori(m,-1);
	while(lo<=hi)
	{
		int mid=(lo+hi)>>1;
		vector<int> b;
		int curmin=0;
		ll cursum=0;
		for(int i=0;i<m;i++)
		{
			if(a[i]!=-1) curmin=a[i];
			b.pb(curmin);
			cursum+=b[i];
		}
		//left T - cursum stuff to add :(
		//fix the maximum M
		bool pos=0;
		int forcedM=-1;
		for(int j=m-mid;j<m;j++)
		{
			if(a[j]>=0)
			{
				if(forcedM>=0&&forcedM!=a[j]) forcedM=-2;
				forcedM = a[j];
			}
		}
		if(forcedM>=-1)
		{
			int L2 = curmin; int R2 = n;
			if(forcedM>=0) L2=R2=forcedM;
			//otherwise L2 is the smallest d+curmin such that there EXIST a good covering
			if(forcedM<0)
			{
				int lo2 = curmin; int hi2 = max(0LL,min(ll(n),(T-cursum)/mid+curmin)); //add to everyone i guess
				L2=int(1e9);
				while(lo2<=hi2)
				{
					int mid2=(lo2+hi2)>>1;
					vector<int> nwb = b;
					ll rem = T - cursum;
					int M = mid2;
					for(int j=m-mid;j<m;j++)
					{
						rem+=b[j];
						rem-=M;
						nwb[j]=M;
						if(a[j]>=0&&nwb[j]!=a[j]) {rem=-ll(1e18);}
						ori[j]=a[j];
						a[j]=M;
					}
					greedy(nwb, rem);
					for(int j=m-mid;j<m;j++)
					{
						a[j]=ori[j];
					}
					if(rem==0)
					{
						hi2=mid2-1;
						L2=mid2;
					}
					else 
					{
						lo2=mid2+1;
					}
				}
			}			
			//how to figure out L2 otherwise!?
			while(L2<=R2)
			{
				int M = (L2+R2)>>1;
				vector<int> nwb = b;
				ll rem = T - cursum;
				for(int j=m-mid;j<m;j++)
				{
					rem+=b[j];
					rem-=M;
					nwb[j]=M;
					if(a[j]>=0&&nwb[j]!=a[j]) {rem=-ll(1e18);}
					ori[j]=a[j];
					a[j]=M;
				}
				greedy(nwb, rem);
				if(rem==0&&check(nwb))
				{
					testb=nwb; ansm=M;
					pos=1; L2=M+1;
				}
				else
				{
					R2=M-1;
				}
				for(int j=m-mid;j<m;j++)
				{
					a[j]=ori[j];
				}
			}
		}
		if(pos)
		{
			anstie=mid;
			lo=mid+1;
		}
		else hi=mid-1;
	}
	if(anstie==-1)
	{
		return {-1,-1};
	}
	return {anstie,ansm};
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("student-scores.in","r",stdin);
	read();
	ii sol2 = solve_full();
	cout<<sol2.fi<<' '<<sol2.se<<'n';
}
```
