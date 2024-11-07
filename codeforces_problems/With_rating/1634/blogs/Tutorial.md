# Tutorial

Thank you for participating, we hope you enjoyed the problems! We kindly ask you to rate each of the round's problems in the corresponding spoiler in order to improve the quality of future contests.

You can also check video editorials of problems B and C on [ak2006](https://codeforces.com/profile/ak2006 "Specialist ak2006") [Youtube channel](https://codeforces.com/https://www.youtube.com/channel/UCnZ5rC2_JY0EuYMGMiAbISg).

All problems were prepared by [Alexdat2000](https://codeforces.com/profile/Alexdat2000 "International Master Alexdat2000") with the help of coauthors.

[Why didn't AI participate](Announcement.md?#comment-884764)

[1634A - Reverse and Concatenate](../problems/A._Reverse_and_Concatenate.md "Codeforces Round 770 (Div. 2)")  
 Idea: [sevlll777](https://codeforces.com/profile/sevlll777 "International Master sevlll777")

  **Hint 1**  What property will the string have after the first operation (regardless of the type of operation)?   **Hint 2**  What happens if you apply an operation to a palindrome?   **Tutorial**  
### [1634A - Reverse and Concatenate](../problems/A._Reverse_and_Concatenate.md "Codeforces Round 770 (Div. 2)")

If k=0, the answer is 1. Otherwise, consider two cases:

* The string is a palindrome (that is, s=rev(s)). Then rev(s)+s=s+rev(s)=s+s, so both operations will replace s by the string s+s, which is also a palindrome. Then for any k the answer is 1.
* Otherwise s≠rev(s). Then after the first operation we get either s+rev(s) (which is a palindrome) or rev(s)+s (also a palindrome). Also note that if we apply the operation to two different palindromes of length x any number of times, they cannot become equal, since they do not have the same prefix of length x. So, after the first operation from a non-palindrome 2 different strings will be obtained, and after all following operations 2 unequal strings will be obtained. So the answer is — 2.
  **Solution**[145468383](https://codeforces.com/contest/1634/submission/145468383 "Submission 145468383 by sevlll777")

 
```cpp
q = int(input())

for _ in range(q):
    n, k = map(int, input().split())
    s = input()
    if s == s[::-1] or k == 0:
        print(1)
    else:
        print(2)
```
 **Rate the problem*** Didn't solve 


[*67*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*1225*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*290*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*159*](https://codeforces.com/data/like?action=like "I like this")
[1634B - Fortune Telling](../problems/B._Fortune_Telling.md "Codeforces Round 770 (Div. 2)")  
 Idea: [crazyilian](https://codeforces.com/profile/crazyilian "Master crazyilian") and [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "International Grandmaster antontrygubO_o")

  **Hint 1**  Can you figure out which of your friends can't get the number y regardless of the order of operations? The answer to the problem would be the other person, since the jury guarantees that exactly one of your friends could get it.   **Hint 2**  What do the numbers a⊕b and a+b have in common for any a,b?   **Hint 3**  What do all the numbers that can be obtained by all combinations of operations starting with x have in common? Does the set of these numbers intersect with the set of numbers that can be obtained starting with x+3?   **Tutorial**  
### [1634B - Fortune Telling](../problems/B._Fortune_Telling.md "Codeforces Round 770 (Div. 2)")

Notice that the operations + and ⊕ have the same effect on the parity: it is inverted if the second argument of the operation is odd, and stays the same otherwise. By induction, we conclude that if we apply the operations to some even number and to some odd number, the resulting numbers will also be of different parity.

Therefore, we can determine whether the parity of the input is the same as the parity of the output or the opposite: if the sum of a is even, then the parity does not change, otherwise it does. Thus we can find out the parity of the original number from the parity of the result, and this is enough to solve the problem because the numbers x and x+3 have different parity.

  **Solution**[145468445](https://codeforces.com/contest/1634/submission/145468445 "Submission 145468445 by sevlll777")

 
```cpp
def main():
    n, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    if (sum(a) + x + y) % 2 == 0:
        print('Alice')
    else:
        print('Bob')


for _ in range(int(input())):
    main()
```
 **Rate the problem*** Didn't solve 

 
[*450*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*1533*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*114*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*1026*](https://codeforces.com/data/like?action=like "I like this")
[1634C - OKEA](../problems/C._OKEA.md "Codeforces Round 770 (Div. 2)")  
 Idea: [sevlll777](https://codeforces.com/profile/sevlll777 "International Master sevlll777")

  **Hint 1**  If k>1, for which n is there no solution?   **Hint 1.1**  For which n is there no solution when k=2? Does the same rule of thumb hold for other k>1?   **Hint 2**  Note that the array [1,3,5,7,9,...] satisfies the requirements (that is, the arithmetic mean of each subsegment is an integer) because the sum of the first X elements of this array is X2. Try to generalize this special case and find other arrays that satisfy the conditions.   **Tutorial**  
### [1634C - OKEA](../problems/C._OKEA.md "Codeforces Round 770 (Div. 2)")

If k=1, you can put items on the shelves in any order.

Otherwise, there are at least 2 items on each shelf. If there are items of different parity on the shelf, it is obvious that there are two neighboring items of different parity, but then the arithmetic mean of these two items won't be whole, which is against the constraints. Therefore, all items on each shelf are of the same parity.

Notice that if the number of shelves n is odd, we cannot arrange the items correctly because the number of shelves with even and odd items must be the same (that is, if k≥2).

Let us show that for even n there is always an answer. On i-th shelf we will place items with prices i,i+n,i+2⋅n,…,i+n⋅(k−1). We can use the formula for the sum of an arithmetic progression to compute the sum of prices of a subsegment with coordinates i,l up to i,r:

sum=i⋅(r−l+1)+n(l−1)+n(r−1)2⋅(r−l+1)= =i⋅(r−l+1)+n2⋅(l+r−2)⋅(r−l+1)= =(r−l+1)⋅(i+n2⋅(l+r−2))

The length of the segment (r−l+1) always divides this sum, since n is even. Therefore, this arrangement fits the requirements of the problem.

  **Solution**[145468509](https://codeforces.com/contest/1634/submission/145468509 "Submission 145468509 by sevlll777")

 
```cpp
def solve():
    n, k = map(int, input().split())
    if k == 1:
        print("YES")
        for i in range(1, n + 1):
            print(i)
        return

    if n % 2 == 1:
        print("NO")
        return

    print("YES")
    for i in range(1, n + 1):
        print(*[i for i in range(i, n * k + 1, n)])


for _ in range(int(input())):
    solve()
```
 **Rate the problem*** Didn't solve 

 
[*95*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*942*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*611*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*160*](https://codeforces.com/data/like?action=like "I like this")
[1634D - Finding Zero](../problems/D._Finding_Zero.md "Codeforces Round 770 (Div. 2)")  
 Idea: [sevlll777](https://codeforces.com/profile/sevlll777 "International Master sevlll777")

  **Hint 1**  The problem can be reworded as follows: find n−2 indices that definitely can't contain a zero.   **Hint 2**  Solve the problem for n=4.   **Hint 2.1**  For n=4, denote by ˉi the answer to the query for the three indices except i. Knowing ˉ1, ˉ2, ˉ3, and ˉ4, can you find two indexes that don't contain zero for certain? Use the fact that there is exactly one zero in the array.   **Hint 3**  Solve the problem for even n using the solution for n=4.   **Tutorial**  
### [1634D - Finding Zero](../problems/D._Finding_Zero.md "Codeforces Round 770 (Div. 2)")

Notice that for any four numbers a,b,c,d we can locate at least two numbers among them that are certainly not zeroes using only four queries as follows.

For each of the four numbers, compute it's complement, that is, the difference between the maximum and the minimum of the other three numbers: ˉa=max(b,c,d)−min(b,c,d) and so on. This takes exactly four queries.

Now, consider what happens if one of the four numbers was a zero. For instance, if a=0,b≤c≤d, then:

* ˉa=d−b
* ˉb=d
* ˉc=d
* ˉd=c

d>d−b,d≥c, so the two largest complements (ˉb=ˉc=d in this example) are always complements of non-zeroes. Of course, the order of the values could be different, but the numbers with the two largest complements will always be guaranteed non-zeroes.

If there is no zero among these numbers, then we can still run this algorithm because it doesn't matter exactly which numbers it will yield — they are all non-zero anyway.

Now let's learn how to solve the problem using this algorithm. Start with a "pile" of the first four numbers, apply the algorithm and throw two certain non-zeroes away. Add the next two numbers to the "pile" and drop two non-zeroes again. Repeat this until there are two or three numbers left in the "pile", depending on the parity of n. If there are three elements left, add some number that we have already dropped to the pile again and apply the algorithm the last time.

* If n is even, we have made n−22⋅4=2n−4 queries.
* If n is odd, we have made n−32⋅4+4=2n−2 queries.

The complexity of this solution is O(n), and the solution uses no more than 2n−2 queries.

  **Solution**[145469065](https://codeforces.com/contest/1634/submission/145469065 "Submission 145469065 by sevlll777")

 
```cpp
#include <bits/stdc++.h>
 
#define all(x) (x).begin(), (x).end()
#define len(x) (int) (x).size()
 
using namespace std;
 
 
int get(const vector <int>& x) {
    cout << "? " << x[0] + 1 << " " << x[1] + 1 << " " << x[2] + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}
 
 
signed main() {
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t --> 0) {
        int n;
        cin >> n;
    
        pair <int, int> possible = {0, 1};
        for (int i = 2; i < n - 1; i += 2) {
            vector <pair <int, int>> ch(4);
            vector <int> now = {possible.first, possible.second, i, i + 1};
            for (int j = 0; j < 4; j++) {
                vector <int> x = now;
                x.erase(x.begin() + j);
                ch[j] = {get(x), now[j]};
            }
            sort(all(ch));
            possible = {ch[0].second, ch[1].second};
        }
        if (n % 2 == 1) {
            int other = 0;
            while (possible.first == other || possible.second == other) {
                other++;
            }
            vector <pair <int, int>> ch(4);
            vector <int> now = {possible.first, possible.second, n - 1, other};
            for (int j = 0; j < 4; j++) {
                vector <int> x = now;
                x.erase(x.begin() + j);
                ch[j] = {get(x), now[j]};
            }
            sort(all(ch));
            possible = {ch[0].second, ch[1].second};
        }
        cout << "! " << possible.first + 1 << " " << possible.second + 1 << endl;
    }
 
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*296*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*734*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*72*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*99*](https://codeforces.com/data/like?action=like "I like this")
[1634E - Fair Share](../problems/E._Fair_Share.md "Codeforces Round 770 (Div. 2)")  
 Idea: [sevlll777](https://codeforces.com/profile/sevlll777 "International Master sevlll777")

  **Hint 1**  In what cases is the answer definitely NO?   **Hint 2**  The lengths of all arrays are even numbers, and each number appears an even number of times in total. There are suspiciously many even numbers...   **Hint 3**  An Euler circuit is a circuit that passes through all edges of a graph exactly once (or a union of several circuits if the graph is disconnected). It turns out that an Euler circuit exists if and only if the degree of each vertex is even.   **Hint 4**  Construct some graph such that the degree of each of its vertices is even, find a directed Eulerian circuit in it, and reconstruct the answer to the problem using this circuit. What do the edges of such graph correspond to?   **Tutorial**  
### [1634E - Fair Share](../problems/E._Fair_Share.md "Codeforces Round 770 (Div. 2)")

If there is a number that occurs an odd number of times in total, there is no answer.

Otherwise, let us construct a bipartite graph as follows. The left part will denote the arrays (m vertices) and the right part will denote the numbers (up to ∑ni vertices). Each array vertex is connected to all the numbers contained in the array, counted with multiplicity. That is, a vertex a from the left part is connected to a vertex b from the right part x times, where x is the count of occurrences of the number b in the a-th array.

Notice that all vertices in both parts are of even degree because the length of each array is even and the number of occurrences of each number is even. Therefore we can find a directed Eulerian circuit of this graph. Then for edges like a→b (going from the left to the right) let us add the number b to L, and for edges like a←b (going from the right to the left) add b to R.

This partitioning will obviously be valid. For each vertex on the left, the indegree equals the outdegree and hence each array is split in half, and for each vertex on the right the same condition holds, so each number occurs in L and R the same number of times and thus L=R.

  **Solution**[145468656](https://codeforces.com/contest/1634/submission/145468656 "Submission 145468656 by sevlll777")

 
```cpp
#include <bits/stdc++.h>

#define len(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define endl "n"

using namespace std;

const int N = 4e5 + 100, H = 2e5 + 50;
vector <pair <int, int>> g[N];
string ans[N];
int pos[N];


void dfs(int v) {
    if (pos[v] == 0) {
        ans[v] = string(len(g[v]), 'L');
    }

    while (pos[v] < len(g[v])) {
        auto [i, ind] = g[v][pos[v]];
        if (i == -1) {
            pos[v]++;
            continue;
        }
        g[i][ind].first = -1, g[v][pos[v]].first = -1;
        if (v < H) {
            ans[v][pos[v]] = 'R';
        }
        pos[v]++;
        dfs(i);
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    map <int, int> ind, cnt;
    int fre_ind = 0;

    vector <vector <int>> nums(m);
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        for (int _ = 0; _ < n; _++) {
            int x;
            cin >> x;
            if (!ind.count(x)) {
                ind[x] = fre_ind++;
            }
            x = ind[x];
            cnt[x]++;
            nums[i].push_back(x);
            g[i].emplace_back(x + H, len(g[x + H]));
            g[x + H].emplace_back(i, len(g[i]) - 1);
        }
    }

    for (auto [num, cn] : cnt) {
        if (cn % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        dfs(i);
    }

    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*310*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*327*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*37*](https://codeforces.com/data/like?action=like "I like this")
[1634F - Fibonacci Additions](../problems/F._Fibonacci_Additions.md "Codeforces Round 770 (Div. 2)")  
 Idea: [Mangooste](https://codeforces.com/profile/Mangooste "Grandmaster Mangooste")

  **Hint 1**  Let Ci=Ai−Bi. Perform all operations on the array C.   **Hint 2**  Nevermind Fibonacci and suppose the operation was to increase the elements of a given subsegment by a given constant. Can you solve this problem without using heavy data structures like segment tree?   **Hint 3**  Generalize the idea from hint 2 using the characteristic property of Fibonacci numbers (Fi=Fi−1+Fi−2).   **Tutorial**  
### [1634F - Fibonacci Additions](../problems/F._Fibonacci_Additions.md "Codeforces Round 770 (Div. 2)")

Let Ci=Ai−Bi. Consider another auxiliary array D, where D1=C1, D2=C2−C1, and Di=Ci−Ci−1−Ci−2 for i>2. Notice that arrays A and B are equal if and only if all elements of D are equal to 0.

Let's analyze how Fibonacci addition affects D. If Fibonacci addition is performed on array A on a segment from l to r, then:

* Dl will increase by 1,
* Dr+1 will decrease by Fr−l+2, and
* Dr+2 will decrease by Fr−l+1.

Fibonacci addition on B can be handled in a similar way.

Fibonacci numbers modulo MOD can be easily precomputed, and therefore the problem can be solved in linear time.

  **Solution**[145468716](https://codeforces.com/contest/1634/submission/145468716 "Submission 145468716 by sevlll777")

 
```cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define len(x) (int) (x).size()
#define endl "n"
#define int long long

using namespace std;

const int N = 3e5 + 100;
int MOD;
int fib[N];

vector <int> unfib;
int notzero = 0;

void upd(int ind, int delta) {
  notzero -= (unfib[ind] != 0);
  unfib[ind] += delta;
  if (unfib[ind] >= MOD) {
    unfib[ind] -= MOD;
  };
  notzero += (unfib[ind] != 0);
}


signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q >> MOD;

  fib[0] = fib[1] = 1;
  for (int i = 2; i < N; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  }

  vector <int> delta(n);
  for (int& i : delta) {
    cin >> i;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    delta[i] = (delta[i] - x + MOD) % MOD;
  }

  unfib.resize(n);
  unfib[0] = delta[0];
  if (len(unfib) >= 2) {
    unfib[1] = (delta[1] - delta[0] + MOD) % MOD;
  }
  for (int i = 2; i < n; i++) {
    unfib[i] = ((long long) delta[i] - delta[i - 1] - delta[i - 2] + MOD * 2) % MOD;
  }
  for (int i = 0; i < n; i++) {
    notzero += (unfib[i] != 0);
  }

  while (q--) {
    char c;
    int l, r;
    cin >> c >> l >> r;
    if (c == 'A') {
      upd(l - 1, 1);
      if (r != n) {
        upd(r, MOD - fib[r - l + 1]);
      }
      if (r < n - 1) {
        upd(r + 1, MOD - fib[r - l]);
      }
    } else {
      upd(l - 1, MOD - 1);
      if (r != n) {
        upd(r, fib[r - l + 1]);
      }
      if (r < n - 1) {
        upd(r + 1, fib[r - l]);
      }
    }
    if (!notzero) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*267*](https://codeforces.com/data/like?action=like "I like this")
* Good problem 

 
[*247*](https://codeforces.com/data/like?action=like "I like this")
* Average problem 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
* Bad problem 

 
[*24*](https://codeforces.com/data/like?action=like "I like this")
