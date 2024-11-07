# Tutorial

[1907A - Rook](../problems/A._Rook.md "Codeforces Round 913 (Div. 3)")

Idea: [pashka](https://codeforces.com/profile/pashka "International Grandmaster pashka")

 **Tutorial**
### [1907A - Rook](../problems/A._Rook.md "Codeforces Round 913 (Div. 3)")

The answer includes all cells that share the same column or row with the given cell. Let's iterate through all the columns, keeping the row constant, and vice versa, iterate through the rows without changing the column. To ensure that the input cell is not included in the answer, you can either skip it or add all positions to a set and then remove it from there.

 **Solution**
```cpp
for _ in range(int(input())):
    s = input()
    for c in "abcdefgh":
        if c != s[0]:
            print(c + s[1], end=' ')
    for c in "12345678":
        if c != s[1]:
            print(s[0] + c, end=' ')
    print()
```
[1907B - YetnotherrokenKeoard](../problems/B._YetnotherrokenKeoard.md "Codeforces Round 913 (Div. 3)")

Idea: [pashka](https://codeforces.com/profile/pashka "International Grandmaster pashka"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1907B - YetnotherrokenKeoard](../problems/B._YetnotherrokenKeoard.md "Codeforces Round 913 (Div. 3)")

To solve the problem, it was necessary to quickly support deletions. For this, one could maintain two stacks: one with the positions of uppercase letters and one with the positions of lowercase letters. Then, when deleting, one needs to somehow mark that the character at this position should not be output.

Alternatively, one could reverse the original string, then instead of deleting characters, they would simply need to be skipped.

 **Solution**
```cpp
for _ in range(int(input())):
    s = list(input())
    n = len(s)
    upper = []
    lower = []
    for i in range(n):
        if s[i] == 'b':
            s[i] = ''
            if lower:
                s[lower.pop()] = ''
            continue
        if s[i] == 'B':
            s[i] = ''
            if upper:
                s[upper.pop()] = ''
            continue
        if 'a' <= s[i] <= 'z':
            lower += [i]
        else:
            upper += [i]
    print(''.join(s))
```
[1907C - Removal of Unattractive Pairs](../problems/C._Removal_of_Unattractive_Pairs.md "Codeforces Round 913 (Div. 3)")

Idea: [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1907C - Removal of Unattractive Pairs](../problems/C._Removal_of_Unattractive_Pairs.md "Codeforces Round 913 (Div. 3)")

Consider a finite string; obviously, all characters in it are the same, as otherwise, we could remove some pair of characters.

If some character occurs in the string more than ⌊n2⌋ times, then the final string will always consist only of it, because with one deletion we can only get rid of one occurrence. To minimize the number of these characters, we need to remove one occurrence each time. We can always do this until the string is left with only such a character.

Otherwise, we can remove all possible pairs regardless of the order of deletions.

 **Solution**
```cpp
orda = ord('a')

def solve():
    n = int(input())
    cnt = [0] * 26
    for c in input():
        cnt[ord(c) - orda] += 1
    mx = max(cnt)
    print(max(n % 2, 2 * mx - n))


for _ in range(int(input())):
    solve()
```
[1907D - Jumping Through Segments](../problems/D._Jumping_Through_Segments.md "Codeforces Round 913 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov"), [Vladosiya](https://codeforces.com/profile/Vladosiya "Expert Vladosiya")

 **Tutorial**
### [1907D - Jumping Through Segments](../problems/D._Jumping_Through_Segments.md "Codeforces Round 913 (Div. 3)")

First, let's note that if we can pass a level with some value of k, then we can make all the same moves and pass it with a larger value. This allows us to use binary search for the answer.

To check whether it is possible to pass the level with a certain k, we will maintain a segment in which we can find ourselves. After each move, it expands by k in both directions and is reduced to the intersection with the segment where the player must be at that move. If at any point the intersection becomes empty, then it is impossible to pass the level with such k.

 **Solution**
```cpp
def solve():
    n = int(input())
    seg = [list(map(int, input().split())) for x in range(n)]

    def check(k):
        ll, rr = 0, 0
        for e in seg:
            ll = max(ll - k, e[0])
            rr = min(rr + k, e[1])
            if ll > rr:
                return False
        return True

    l, r = -1, 10 ** 9
    while r - l > 1:
        mid = (r + l) // 2
        if check(mid):
            r = mid
        else:
            l = mid
    print(r)


for _ in range(int(input())):
    solve()
```
[1907E - Good Triples](../problems/E._Good_Triples.md "Codeforces Round 913 (Div. 3)")

Idea: [pashka](https://codeforces.com/profile/pashka "International Grandmaster pashka")

 **Tutorial**
### [1907E - Good Triples](../problems/E._Good_Triples.md "Codeforces Round 913 (Div. 3)")

A triplet is considered good only if each digit of the number n was obtained without carrying over during addition. For example, consider a=2, b=7, c=4; the sum of the digits is 2+7+4=13, and the sum of the digits of their sum is 1+3=4. This means that whenever there is a carry in one of the digits, the sum digsum(a)+digsum(b)+digsum(c) always increases more than digsum(n).

This allows us to consider each digit separately and multiply their answers. The answer for each digit x will be the number of digit triplets with the sum x. These values do not depend on the input data, so they can be precalculated, but this is not necessary to pass the tests.

 **Solution**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    cnt = 1
    while n > 0:
        d = n % 10
        n //= 10
        mul = 0
        for i in range(d + 1):
            for j in range(d + 1):
                if d - i - j >= 0:
                    mul += 1
        cnt *= mul
    print(cnt)
```
[1907F - Shift and Reverse](../problems/F._Shift_and_Reverse.md "Codeforces Round 913 (Div. 3)")

Idea: [pashka](https://codeforces.com/profile/pashka "International Grandmaster pashka")

 **Tutorial**
### [1907F - Shift and Reverse](../problems/F._Shift_and_Reverse.md "Codeforces Round 913 (Div. 3)")

In this problem, there are several possible sequences of actions from which the optimal one must be chosen. For brevity, let's denote the reverse by the letter "R", and the shift by the letter "S":

* SS…SS
* RS…SR
* RS…SS
* SS…SR

Let's write out the array twice and count the segments on which it increases and decreases. This way, we can find all possible shifts that will sort the array.

 **Solution**
```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a = list(reversed(a))*2
    p = [0]
    q = [0]
    for i in range(n*2-1):
        p.append(p[-1]+1 if a[i]>=a[i+1] else 0)
        q.append(q[-1]+1 if a[i]<=a[i+1] else 0)
    minn = 1000000
    for i in range(n-1,len(p)):
        if p[i] == n-1:
            minn = min(minn, i-n+1, len(p)-i+1)
        if q[i] == n-1:
            minn = min(minn, len(p)-i, i-n+2)
    print(-1 if minn == 1000000 else minn)
```
[1907G - Lights](../problems/G._Lights.md "Codeforces Round 913 (Div. 3)")

Idea: [pashka](https://codeforces.com/profile/pashka "International Grandmaster pashka")

 **Tutorial**
### [1907G - Lights](../problems/G._Lights.md "Codeforces Round 913 (Div. 3)")

Let's construct a directed graph where an edge originates from vertex i to vertex ai. In such a graph, exactly one edge originates from each vertex, and there is exactly one cycle in each connected component.

First, we will turn off all the lights that are not part of the cycles; the sequence of such turn-offs is unique: We will remove all the turned-off vertices into which no edges enter, and we will turn off and remove the turned-on ones.

After that, only cycle components will remain, some of which may have lights turned on. Consider any edge of the cycle from i to ai; we will either press switch i or not. To count the number of operations in these cases, we will use the same algorithm as before.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define long long long int
#define DEBUG
using namespace std;

// @author: pashka

void solve(){
    int n;
    cin >> n;
    vector<bool> s(n);
    {
        string ss;
        cin >> ss;
        for (int i = 0; i < n; i++) {
            s[i] = ss[i] == '1';
        }
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> res;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[a[i]]++;
    }
    vector<int> z;
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) z.push_back(i);
    }

    for (int i = 0; i < (int)z.size(); i++) {
        int x = z[i];
        int y = a[x];
        if (s[x]) {
            res.push_back(x);
            s[x] = !s[x];
            s[y] = !s[y];
        }
        d[y]--;
        if (d[y] == 0) {
            z.push_back(y);
        }
    }

    vector<bool> u(n);
    for (int i = 0; i < n; i++) {
        if (s[i] && !u[i]) {
            int x = i;
            vector<int> p;
            vector<bool> ps;
            int c = 0;
            while (!u[x]) {
                p.push_back(x);
                ps.push_back(s[x]);
                c += s[x];
                u[x] = true;
                x = a[x];
            }
            int k = p.size();
            p.push_back(x);
            ps.push_back(s[x]);
            if (c % 2 == 1) {
                cout << -1;
                return;
            }
            vector<int> v1;
            vector<bool> ps1 = ps;
            for (int j = 0; j < k; j++) {
                if (j == 0 || ps1[j]) {
                    v1.push_back(p[j]);
                    ps1[j] = !ps1[j];
                    ps1[j + 1] = !ps1[j + 1];
                }
            }
            vector<int> v2;
            vector<bool> ps2 = ps;
            for (int j = 0; j < k; j++) {
                if (j != 0 && ps2[j]) {
                    v2.push_back(p[j]);
                    ps2[j] = !ps2[j];
                    ps2[j + 1] = !ps2[j + 1];
                }
            }
            if (v1.size() < v2.size()) {
                for (auto x : v1) {
                    res.push_back(x);
                }
            } else {
                for (auto x : v2) {
                    res.push_back(x);
                }
            }
        }
    }
    cout << res.size() << "n";
    for (auto x : res) cout << x + 1 << " ";
}

int main() {
    int t;
    cin >> t;
    for(int _ = 0; _ < t; ++_){
        solve();
        cout << "n";
    }
    return 0;
}
```
