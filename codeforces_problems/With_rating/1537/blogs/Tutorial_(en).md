# Tutorial_(en)

[1537A - Арифметический массив](../problems/A._Arithmetic_Array.md "Codeforces Round 726 (Div. 2)")

 **Tutorial**To make the arithmetic mean be equal to exactly 1 the sum needs to be equal to the number of elements in the array.

Let's consider 3 cases for this problem:

1) The sum of the array equals n: Here the answer is 0 since the arithmetic mean of the array is initially 1.

2) The sum of the array is smaller than n: The answer is always 1 since we can add a single integer k such that sum+k=n+1 is satisfied and more specifically k=n−sum+1.

3) The sum of the array is greater than n: If we add any number apart from 0 will add to the sum more or equal than to the number of elements. The number of 0's to add can be found by a loop of adding 0's until the number of elements is equal to the sum or by the simple formula of sum−n.

 **Code**
```cpp
#include "bits/stdc++.h"
 using namespace std;

 int main()
 {
	 int t;
	 cin >> t;
	 while(t--){
		 int n;
		 cin >> n;
		 int sum = 0;
		 for (int i = 0;i < n; i++){
			 int a;
			 cin >> a;
			 sum += a;
		 }
   if(sum < n)cout << "1n";
   else cout << sum - n << "n";
	 }
 }
```
[1537B - Плохой мальчик](../problems/B._Bad_Boy.md "Codeforces Round 726 (Div. 2)")

 **Tutorial**
### [1537B - Плохой мальчик](../problems/B._Bad_Boy.md "Codeforces Round 726 (Div. 2)")

We can notice that the optimal strategy is to put the yoyos in the corners of the board. One solution may be checking the best distance for all pairs of corners. But, if we think a bit more, we can notice that placing the yoyos in opposite corners the distance will always be maximum possible (the distance always being $2 \cdot (n - 1) + 2 \cdot (m - 1)$). So, one possible answer is to always place the first yoyo in the top-left cell and the second one in the bottom-right cell. This is always optimal because, for any initial position of Anton, the distance will still be the same ($2 \cdot (n - 1) + 2 \cdot (m - 1)$), this being the largest possible distance. The distance can not get larger than that, because if we move one of the yoyos it will get closer to the other yoyo and the distance will decrease by $1$ or won't decrease, but it's impossible for it to increase.

 **Code**
```cpp
#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, i, j;
        cin >> n >> m >> i >> j;

        cout << 1 << " " << 1 << " " << n << " " << m << "n";
    }
}
```
[1537C - Сложные скалы](../problems/C._Challenging_Cliffs.md "Codeforces Round 726 (Div. 2)")

 **Tutorial**
### [1537C - Сложные скалы](../problems/C._Challenging_Cliffs.md "Codeforces Round 726 (Div. 2)")

We claim that the maximum difficulty is at least $n-2$. Assume the array is sorted. We first need to find the two mountains which go on the ends. To do this, we can iterate through every mountain in the sorted array and check the difference between a mountain and its neighbours in the array. Let $m_k$ and $m_{k+1}$ be the mountains with the smallest height difference. We can achieve at least a difficulty of $n-2$ by arranging the mountains as $m_k, m_{k+2}, m_{k+3} ... m_n, m_1, m_2, ....., m_{k+1}$. To get difficulty $n-1$, we need $m_k$ to be the shortest mountain and $m_{k+1}$ to be the tallest mountain. This will only happen if $n = 2$.

 **Code**
```cpp
#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> h(n);

        for (int i = 0;i < n; i++){
            cin >> h[i];
        }
        sort(h.begin(), h.end());

        if(n == 2){
            cout << h[0] << " " << h[1] << "n";
            continue;
        }

        int pos = -1, mn = INT_MAX;

        for (int i = 1;i < n; i++){
            if(mn > abs(h[i] - h[i - 1])){
                pos = i;
                mn = abs(h[i] - h[i - 1]);
            }
        }
        
        for (int i = pos;i < n; i++){
            cout << h[i] << " ";
        }
        for(int i = 0;i < pos; i++){
            cout << h[i] << " ";
        }

        cout << "n";

    }
}
```
[1537D - Удаляя делители](../problems/D._Deleting_Divisors.md "Codeforces Round 726 (Div. 2)")

 **Tutorial**
### [1537D - Удаляя делители](../problems/D._Deleting_Divisors.md "Codeforces Round 726 (Div. 2)")

Let's consider $3$ cases for this problem:

1) n is odd

2) n is even, and $n$ is not a power of $2$

3) n is a power of $2$

If $n$ is odd, the only move is to subtract an odd divisor (since all the divisors are odd). Doing this, we will obtain an even number that is not a power of $2$(case 2). If $D$ is the divisor of $n$, then $n-D$ must also be divisible by $D$, and since $D$ is odd, $n-D$ cannot be a power of $2$.

If $n$ is even and is not a power of $2$, it means that $n$ has an odd divisor. By subtracting this odd divisor, we will obtain $n-D$ is odd(case 1). Now let's show that subtracting an odd divisor every move results in a win. Primes are losing since the only move you can make on them is subtracting the entire number, which results in $n = 0$ and a loss. Since every prime is odd or a power of 2, it works to give the other player an odd number because it will either be a prime(the other player loses), or they will make a move and give you another even number that is not a power of 2. You can continue this process because you will never land on a losing number and because the game must end after a finite number of moves, your opponent must always lose.

So we proved that odd numbers are losing and even numbers that are not powers of $2$ are winning.

What if $n$ is a power of $2$? You can do two things in one move, halve $n$ or make n an even number that is not a power of $2$(we proved that this is a winning position for the other player). The only optimal move is to halve $n$, making it another power of $2$. The players continue like this until one gets $2$, which is a prime number, so it's losing. If $log_2(n)$ is even, Alice wins, otherwise Bob wins.

 **Code**
```cpp
#include "bits/stdc++.h"
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    while(t--){
        
        int n;
        cin >> n;
        if(n % 2 == 1){
            cout << "Bobn";
            continue;
        }
        int cnt = 0;
        while(n % 2 == 0){
            cnt++;
            n /= 2;
        }
 
        if(n > 1){
            cout << "Alicen";
        }else if(cnt % 2 == 0){
            cout << "Alicen";
        }else cout << "Bobn";
    }
}
```
[1537E1 - Удаляй и удлиняй (простая версия)](../problems/E1._Erase_and_Extend_(Easy_Version).md "Codeforces Round 726 (Div. 2)")

 **Tutorial**
### [1537E1 - Удаляй и удлиняй (простая версия)](../problems/E1._Erase_and_Extend_(Easy_Version).md "Codeforces Round 726 (Div. 2)")

We claim that it is optimal to choose a prefix of the string, then duplicate it until we have a length bigger than $k$, then delete the excess elements. 

Let's relax the requirement so you have a position in the string and each time you either return to the beginning or advance to the next character. The answer will be the first k characters of the lexicographically smallest infinite string. From a given position, the optimal infinite string from it is unique, so you can pick exactly one optimal decision. Now the optimal string is going around some cycle from the start, and we see it also satisfies the original requirement, not just our relaxation

We proved that it is optimal to choose a prefix, duplicate it until the length is bigger than k then delete the excess. As the constraints are low, we can iterate through every prefix on the original string and make a string of length $k$ with it. Then we take the minimum of all these strings as the answer. Solution complexity $O(n\cdot k)$.

 **Code**
```cpp
#include "bits/stdc++.h"
using namespace std;

string get(string s, int k){
    while((int)s.size() < k){
        s = s + s;
    }
    while((int)s.size() > k)
        s.pop_back();
    return s;
}
int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    string pref = "";
    pref += s[0];

    string mn = get(pref, k);

    for(int i = 1;i < n;i++){
        if(s[i] > s[0])break;
        pref += s[i];
        mn = min(mn, get(pref, k));
    }
    cout << mn << "n";
}
```
[1537E2 - Удаляй и удлиняй (сложная версия)](../problems/E2._Erase_and_Extend_(Hard_Version).md "Codeforces Round 726 (Div. 2)")

 **Tutorial**We know that the final string is some prefix repeated a bunch of times. Incrementally for i from 1 to n we will keep the longest among the first i prefixes that gives the best answer we've seen so far.

So assume the m−th prefix is currently the best and we're considering position p. If the p−th character is greater than the corresponding character in s1..m⋅(alot) then the p−th prefix and any further prefixes can't possibly give a smaller answer, so we just print the current one and finish. Otherwise all the characters before the p−th are all less than or equal to the corresponding characters in s1..m⋅(alot), so if the p−th is smaller than the corresponding we set the p−th prefix as the best.

Now the interesting case is if the current character is the same as the corresponding one. Say then that p=m+t, by the logic of the previous paragraph we must have s(m+1)..(m+t)=s1..t. If t=m then the new prefix is just the old one twice, so set p as the best prefix now. This ensures that otherwise t<m.

Denote A=s1..t and B=s(t+1)..m, so the string formed by the current best prefix is ABABABABA... and the new one is ABAABAABA... Now if AB=BA then these strings are in fact the same, so set m+t as the new best prefix. Otherwise we can find the first position where AB and BA differ, and use that to determine whether the new prefix is better. This can be done in O(1) with Z function, thus giving a linear solution for the full problem.

Solution by [Ari](https://codeforces.com/profile/Ari "Гроссмейстер Ari").

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
int n, k;

vector<int> z_func(string &s) {
    int n = s.size(), L = -1, R = -1;
    vector<int> z(n);
    z[0] = n;
    for(int i = 1; i < n; i++) {
        if(i <= R)
            z[i] = min(z[i - L], R - i + 1);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if(i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

void finish(int m) {
    for(int i = 0; i < k; i++)
        cout << s[i % m];
    cout << 'n';
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> s;
    auto z = z_func(s);

    int cur = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] > s[i % cur])
            finish(cur);
        if(s[i] < s[i % cur]) {
            cur = i + 1;
            continue;
        }
        int off = i - cur + 1;
        if(off == cur) {
            cur = i + 1;
            continue;
        }
        if(z[off] < cur - off) {
            if(cur + off + z[off] >= k) {
                cur = i + 1;
                continue;
            }
            if(s[off + z[off]] > s[z[off]])
                cur = i + 1;
            continue;
        }
        if(z[cur - off] < off) {
            if(2 * cur + z[cur - off] >= k) {
                cur = i + 1;
                continue;
            }
            if(s[cur - off + z[cur - off]] < s[z[cur - off]])
                cur = i + 1;
            continue;
        }
        cur = i + 1;
    }

    finish(cur);
}
```
[1537F - Исправляем фигуры](../problems/F._Figure_Fixing.md "Codeforces Round 726 (Div. 2)")

 **Tutorial**
### [1537F - Исправляем фигуры](../problems/F._Figure_Fixing.md "Codeforces Round 726 (Div. 2)")

If the parity of the sum of the initial values doesn't match the parity of the sum of the target values then there is no solution. Because $k$ is an integer and we always add the value $2 \cdot k$ to the sum of the initial values in each operation it's easy to notice that the parity of the sum of the initial values never changes.

Otherwise, let's consider $2$ cases:

2) The graph is bipartite.

3) The graph is not bipartite.

If the graph is bipartite, let the nodes be coloured red and blue with the condition that all the neighbors of any red node are blue and all the neighbours of any blue node are red. Let us call $sum1 = \sum target_i-value_i$ for each blue node and $sum2 = \sum target_i-value_i$ for each red node. We want to determine if we can make $target_i = value_i$ for each node, which is equivalent to saying $sum1 = 0$ and $sum2 = 0$. We notice that the difference between $sum1$ and $sum2$ is invariant in a bipartite graph because all operations will add to $sum1$ and $sum2$ at the same time. So to make $sum1 = 0$ and $sum2 = 0$ we need $sum1-sum2$ to be equal to $0$ initially.

If the graph is not bipartite, then it is always possible because if the graph is not bipartite, it contains two neighboring vertices of the same color, which can be used to add or subtract from their color sum.

 **Code**
```cpp
#include "bits/stdc++.h"
 using namespace std;

 const int N = 2e5 + 10;
 vector<long long> adj[N];
 long long s[N], n, m;
 bool bipartite()
 {
	 bool bip = true;

	 for(long long i = 0;i < n;i++)
		 s[i] = -1;

	 queue<long long> q;

	 for(long long i = 0;i < n;i++){
		 if(s[i] != -1)continue;

		 q.push(i);
		 s[i] = 0;

		 while(!q.empty()){
			 long long v = q.front();
			 q.pop();

			 for(long long u: adj[v]){
				 if(s[u] == -1){
					 s[u] = s[v] ^ 1;
					 q.push(u);
				 }else bip &= s[u] != s[v];
			 }
		 }
	 }
	 return bip;
 }

 int main()
 {
	 ios_base::sync_with_stdio(0);cin.tie(0);
	 long long T;
	 cin >> T;
	 while(T--)
	 {
		 cin >> n >> m;
		 for(long long i = 0;i < n;i++)
			 adj[i].clear();

		 vector<long long> v(n), t(n);
		long long p1 = 0, p2 = 0;
		 for(long long i = 0;i < n; i++){
			 cin >> v[i];
			 p1 = (p1 + abs(v[i])) % 2;
		 }
		 for (long long i = 0;i < n; i++){
			 cin >> t[i];
			 p2 = (p2 + abs(t[i])) % 2;
		 }

		 for(long long i = 0;i < m;i++){
			 long long a, b;
			 cin >> a >> b;
			 --a, --b;
			 adj[a].push_back(b);
			 adj[b].push_back(a);
		 }
		 
		 if(p1 != p2){
		   cout << "NOn";
		   continue;
		 }

		 if(bipartite() == false){
			 cout << "YESn";
		 }else{
			 vector<long long> c(2, 0);

			 for(int i = 0;i < n;i++){
				 c[s[i]] += v[i] - t[i];
			 }

			 if(c[0] == c[1]){
				 cout << "YESn";
			 }else cout << "NOn";
		 }
	 }

 }

```
