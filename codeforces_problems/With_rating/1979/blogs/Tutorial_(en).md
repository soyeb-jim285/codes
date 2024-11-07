# Tutorial_(en)

Thank you for participating!

[1979A - Guess the Maximum](../problems/A._Guess_the_Maximum.md "Codeforces Round 951 (Div. 2)")
-----------------------------------------------------------------------------------------------------------

 **Solution**Let m be the maximum among the numbers ai,ai+1,…,aj. Notice that there always exists such k that i≤k<j and ak=m or ak+1=m. Therefore, we can assume that Bob always chooses the pair of numbers p and p+1 (1≤p<n) as i and j.

Therefore you need to consider the maximums in pairs of adjacent elements and take the minimum among them. Let min be the found minimum, then it is obvious that the answer is equal to min−1.

 **Code**
```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int& i : a) {
            cin >> i;
        }
        int mini = max(a[0], a[1]);
        for (int i = 1; i < n - 1; i++) {
            mini = min(mini, max(a[i], a[i + 1]));
        }
        cout << mini - 1 << "n";
    }
}
```
[1979B - XOR Sequences](../problems/B._XOR_Sequences.md "Codeforces Round 951 (Div. 2)")
-------------------------------------------------------------------------------------------------------

 **Hint**Look at samples.

 **Solution**Consider two numbers v and u such that x⊕v=y⊕u. Then consider the numbers x⊕(v+1) and y⊕(u+1). Let's look at the last bit of v and u. Possible scenarios:

 * Both bits are equal to 0 — adding one will change the bits at the same positions, therefore x⊕(v+1)=y⊕(u+1);
* Both bits are equal to 1 — adding one will change the bits at the same positions and also add one to the next bit, therefore we can similarly consider the next bit;
* Bits are different — adding one to the zero bit will only change one bit, while the subsequent bit of the other number will be changed. This means that x⊕(v+1)≠y⊕(u+1).

It is clear that we need to maximize the number of zeros in the maximum matching suffix of u and v. Obviously, this number is equal to the maximum matching suffix of x and y. Let k be the length of the maximum matching suffix of x and y, then the answer is 2k.

This can be calculated in O(logC) time for one test case, where C is the limit on x and y.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        for (int i = 0; i < 30; i++) {
            if ((a & (1 << i)) != (b & (1 << i))) {
                cout << (1ll << i) << "n";
                break;
            }
        }
    }
}
```
[1979C - Earning on Bets](../problems/C._Earning_on_Bets.md "Codeforces Round 951 (Div. 2)")
---------------------------------------------------------------------------------------------------------

 **Hint**Try to come up with a condition for the existence of an answer.

 **Solution**Let S be the total amount of coins placed on all possible outcomes. Then, if the coefficient for winning is ki, we have to place **more** than Ski on this outcome.

We can obtain the following inequality: 

 ∑ni=1Ski<S.Dividing both sides by S, we obtain the necessary and sufficient condition for the existence of an answer: 

 ∑ni=11ki<1.This check can be performed by reducing all fractions to a common denominator. Notice that the numerators of the reduced fractions correspond to the required bets on the outcomes.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

void solve() {
    int n;
    cin >> n;
    
    vector <int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    
    int z = 1;
    for (int i = 0; i < n; i++) {
        z = lcm(z, k[i]);
    }
    
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += z / k[i];
    }
    
    if (suma < z) {
        for (int i = 0; i < n; i++) {
            cout << z / k[i] << " ";
        }
        cout << "n";
    } else {
        cout << -1 << "n";
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1979D - Fixing a Binary String](../problems/D._Fixing_a_Binary_String.md "Codeforces Round 951 (Div. 2)")
----------------------------------------------------------------------------------------------------------------

 **Solution**Let's consider the block of characters at the end. Notice that their quantity cannot decrease. Let x be the number of identical characters at the end; there are three possible cases:

 * x=k — it is enough to find any block of length greater than k and separate a block of length k from it;
* x>k — obviously, there is no solution;
* x<k — find a block of length k−x or 2k−x and separate a block of length k−x from it.

This solution works in O(n), but it is not the only correct one. Your solution may differ significantly from the one proposed.

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;
        
        int x = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == s[n - 1]) {
                x++;
            } else {
                break;
            }
        }
        
        auto check = [&]() {
            for (int i = 0; i < k; i++) {
                if (s[i] != s[0]) return false;
            }
            for (int i = 0; i + k < n; i++) {
                if (s[i] == s[i + k]) return false;
            }
            return true;
        };
        
        auto operation = [&](int p) {
            reverse(s.begin(), s.begin() + p);
            s = s.substr(p, (int)s.size() - p) + s.substr(0, p);
            if (check()) {
                cout << p << "n";
            } else {
                cout << -1 << "n";
            }
        };
        
        if (x == k) {
            int p = n;
            for (int i = n - 1 - k; i >= 0; i--) {
                if (s[i] == s[i + k]) {
                    p = i + 1;
                    break;
                }
            }
            operation(p);
        } else if (x > k) {
            cout << -1 << "n";
        } else {
            bool was = false;
            for (int i = 0; i < n; i++) {
                if (s[i] != s.back()) continue;
                int j = i;
                while (j + 1 < n && s[i] == s[j + 1]) {
                    j++;
                }
                if (j - i + 1 + x == k) {
                    operation(j + 1);
                    was = true;
                    break;
                } else if (j - i + 1 - k + x == k) {
                    operation(i + k - x);
                    was = true;
                    break;
                }
                i = j;
            }
            if (!was) {
                operation(n);
            }
        }
    }
}
```
[1979E - Manhattan Triangle](../problems/E._Manhattan_Triangle.md "Codeforces Round 951 (Div. 2)")
------------------------------------------------------------------------------------------------------------

 **Hint**In every Manhattan triangle there are two points such that |x1−x2|=|y1−y2|. 

 **Solution**Note this fact: in every Manhattan triangle there are two points such that |x1−x2|=|y1−y2|.

Let's start with distributing all points with their (x+y) value.

For each point (x;y) find point (x+d/2;y−d/2) using lower bound method in corresponding set. Then we have to find the third point: it can be in either (x+y+d) or (x+y−d) diagonal. Borders at x coordinate for them are [x+d/2;x+d] and [x−d/2;x] — it can be found using the same lower bound method.

Then, distribute all points with (x−y) value and do the same algorithm.

Total time complexity is O(nlogn).

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXC = 1e5;
const int MAXD = 4e5 + 10;

set <pair <int, int>> diag[MAXD];

void solve() {
    int n, d;
    cin >> n >> d;
    
    vector <int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        x[i] += MAXC;
        y[i] += MAXC;
    }
    
    bool found = false;
    {
        for (int i = 0; i < n; i++) {
            diag[x[i] + y[i]].insert({x[i], i});
        }
        for (int i = 0; i < n; i++) {
            auto it1 = diag[x[i] + y[i]].lower_bound({x[i] + d / 2, -1});
            if (it1 == diag[x[i] + y[i]].end() || it1->first != x[i] + d / 2) continue;
            if (x[i] + y[i] + d < MAXD) {
                auto it2 = diag[x[i] + y[i] + d].lower_bound({x[i] + d / 2, -1});
                if (it2 != diag[x[i] + y[i] + d].end() && it2->first <= it1->first + d / 2) {
                    cout << i + 1 << " " << it1->second + 1 << " " << it2->second + 1 << "n";
                    found = true;
                    break;
                }
            }
            if (x[i] + y[i] - d >= 0) {
                auto it2 = diag[x[i] + y[i] - d].lower_bound({x[i] - d / 2, -1});
                if (it2 != diag[x[i] + y[i] - d].end() && it2->first <= it1->first - d / 2) {
                    cout << i + 1 << " " << it1->second + 1 << " " << it2->second + 1 << "n";
                    found = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            diag[x[i] + y[i]].erase({x[i], i});
        }
    }
    if (!found) {
        for (int i = 0; i < n; i++) {
            y[i] -= 2 * MAXC;
            diag[x[i] - y[i]].insert({x[i], i});
        }
        for (int i = 0; i < n; i++) {
            auto it1 = diag[x[i] - y[i]].lower_bound({x[i] + d / 2, -1});
            if (it1 == diag[x[i] - y[i]].end() || it1->first != x[i] + d / 2) continue;
            if (x[i] - y[i] + d < MAXD) {
                auto it2 = diag[x[i] - y[i] + d].lower_bound({x[i] + d / 2, -1});
                if (it2 != diag[x[i] - y[i] + d].end() && it2->first <= it1->first + d / 2) {
                    cout << i + 1 << " " << it1->second + 1 << " " << it2->second + 1 << "n";
                    found = true;
                    break;
                }
            }
            if (x[i] - y[i] - d >= 0) {
                auto it2 = diag[x[i] - y[i] - d].lower_bound({x[i] - d / 2, -1});
                if (it2 != diag[x[i] - y[i] - d].end() && it2->first <= it1->first - d / 2) {
                    cout << i + 1 << " " << it1->second + 1 << " " << it2->second + 1 << "n";
                    found = true;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            diag[x[i] - y[i]].erase({x[i], i});
        }
    }
    if (!found) {
        cout << "0 0 0n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
[1979F - Kostyanych's Theorem](../problems/F._Kostyanych's_Theorem.md "Codeforces Round 951 (Div. 2)")
--------------------------------------------------------------------------------------------------------------

 **Solution**Let's consider the following recursive algorithm. We will store the Hamiltonian path as a double-ended queue, maintaining the start and end.

In case there are only 1 or 2 vertices left in the graph, the problem is solved trivially.

Suppose we know that the current graph has n vertices, and there are **at most** (n−2) edges missing. Then the total number of edges in such a graph is at least 

 n(n−1)2−(n−2)=n2−3n+42.Let all vertices in the graph have a degree of at most (n−3), then the total number of edges does not exceed 

 n(n−3)2=n2−3n2,which is less than the stated value. Hence, we conclude that there is **at least one** vertex with a degree greater than (n−3).

If there exists a vertex v with a degree of (n−2), then it is sufficient to run our recursive algorithm for the remaining graph. Since v is only not connected by an edge to one vertex, v is connected either to the start or the end of the maintained path in the remaining graph. Thus, we can insert the vertex v either at the beginning or at the end of the path.

Otherwise, let u be the vertex with a degree of (n−1). There is at least one vertex w with a degree not exceeding (n−3). Remove u and w from the graph. Notice that the number of edges in such a graph does not exceed 

 n2−3n+42−(n−1)−(n−3)+1=n2−7n+142 n2−7n+142=n2−5n+62−2n−82 n2−5n+62−2n−82=(n−2)(n−3)2−(n−4) (n−2)(n−3)2−(n−4)=(n−2)((n−2)−1)2−((n−2)−2).The invariant is preserved, so we can run the algorithm for the remaining graph. Then, we can arrange the vertices in the following order: w — u — s — ..., where s — the start of the Hamiltonian path in the remaining graph.

It remains to understand how to use queries.

Make a query d=(n−2). Let u be the second number in the response to our query. If u≠0, the degree of vertex v is (n−2). Run our recursive algorithm, and then compare the start and end of the obtained path with u.

Otherwise, if u=0, it means the degree of vertex v is (n−1). In this case, ask about any vertex with a low degree (this can be done with a query d=0). Then simply arrange the vertices in the order mentioned above.

We will make no more than n queries, and the final asymptotic will be O(n).

 **Code**
```cpp
#include <bits/stdc++.h>
using namespace std;

pair <int, int> ask(int d) {
    cout << "? " << d << endl;
    int v, u;
    cin >> v >> u;
    return {v, u};
}
 
pair <int, int> get(int n, vector <int>& nxt) {
    if (n == 1) {
        int v = ask(0).first;
        return {v, v};
    }
    if (n == 2) {
        int u = ask(0).first;
        int v = ask(0).first;
        nxt[u] = v;
        return {u, v};
    }
    pair <int, int> t = ask(n - 2);
    int v = t.first;
    int ban = t.second;
    if (ban != 0) {
        pair <int, int> res = get(n - 1, nxt);
        if (ban != res.first) {
            nxt[v] = res.first;
            return {v, res.second};
        } else {
            nxt[res.second] = v;
            return {res.first, v};
        }
    } else {
        int u = ask(0).first;
        nxt[u] = v;
        pair <int, int> res = get(n - 2, nxt);
        nxt[v] = res.first;
        return {u, res.second};
    }
}
 
void solve() {
    int n;
    cin >> n;
    
    vector <int> nxt(n + 1, -1);
    pair <int, int> ans = get(n, nxt);
    
    int v = ans.first;
    cout << "! ";
    do {
        cout << v << " ";
        v = nxt[v];
    } while (v != -1);
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
```
