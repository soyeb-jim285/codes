# Editorial_(en)

[1846A - Rudolph and Cut the Rope](../problems/A._Rudolph_and_Cut_the_Rope_.md "Codeforces Round 883 (Div. 3)") 

Author: [Sasha0738](https://codeforces.com/profile/Sasha0738 "Expert Sasha0738")

 **Hint 1**What if the nail with the rope is the only one?

 **Hint 2**How long should be rope to reach the ground?

 **Tutorial**
### [1846A - Rudolph and Cut the Rope](../problems/A._Rudolph_and_Cut_the_Rope_.md "Codeforces Round 883 (Div. 3)")

In order for the candy to be on the ground, it is necessary that all the ropes touch the ground. This means that the length of all ropes must be greater than or equal to the height of the nails to which they are attached. That is, you need to cut all the ropes, the length of which is less than the height of their nail. Then the answer is equal to the number of elements that have $a_i>b_i$.

 **Solution**
```cpp
#include <iostream>

using namespace std;


int main() {
	int test_cases;
	cin >> test_cases;

	for (int test_case = 0; test_case < test_cases; test_case++) {
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b)
				ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
```
 **Rate the problem*** Didn't solve 


[*21*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*266*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*51*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*77*](https://codeforces.com/data/like?action=like "I like this")
[1846B - Rudolph and Tic-Tac-Toe](../problems/B._Rudolph_and_Tic-Tac-Toe.md "Codeforces Round 883 (Div. 3)")

Author: [Sasha0738](https://codeforces.com/profile/Sasha0738 "Expert Sasha0738")

 **Hint 1**What is the win condition to be checked?

 **Tutorial**
### [1846B - Rudolph and Tic-Tac-Toe](../problems/B._Rudolph_and_Tic-Tac-Toe.md "Codeforces Round 883 (Div. 3)")

To solve this problem, it is enough to check the equality of elements on each row, column and diagonal of three elements. If all three elements are equal and are not ".", then the value of these elements is the answer. Note that a row of "." does not give you answer ".". Statement does not say that the players have equal amount of moves, which means that one player can have several winning rows.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main() {
	int test_cases;
	cin >> test_cases;
	for (int test_case = 0; test_case < test_cases; test_case++) {
		vector<string> v(3);
		for (int i = 0; i < 3; i++)
			cin >> v[i];
		string ans = "DRAW";
		for(int i = 0; i < 3; i++) {
			if (v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][0] != '.')
				ans=v[i][0];
		}
		for (int i = 0; i < 3; i++) {
			if (v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[0][i] != '.')
				ans=v[0][i];
		}
		if (v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '.')
			ans=v[0][0];
		if (v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] != '.')
			ans=v[0][2];
		cout << ans << endl;
	}
	return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*4*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*96*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*73*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*295*](https://codeforces.com/data/like?action=like "I like this")
[1846C - Rudolf and the Another Competition](../problems/C._Rudolf_and_the_Another_Competition.md "Codeforces Round 883 (Div. 3)")

Author: [vladmart](https://codeforces.com/profile/vladmart "Master vladmart")

 **Hint 1**What is the optimal order of task solving?

 **Hint 2**t1 ≤ t2 ≤ t3 ≤ ... ≤ tm 

 **Tutorial**
### [1846C - Rudolf and the Another Competition](../problems/C._Rudolf_and_the_Another_Competition.md "Codeforces Round 883 (Div. 3)")

First of all, it is necessary to determine the optimal order of solving problems for each participant. It is claimed that it is most optimal to solve problems in ascending order of their solution time. Let's prove this: 

* Firstly, it is obvious that this strategy will allow solving the maximum number of problems.
* Secondly, this strategy will also result in the minimum total penalty time. Let's assume that the participant solves a total of $m$ problems. The solution time of the first problem will be added to the penalty time for all $m$ problems, the solution time of the second problem will be added to the penalty time for $m-1$ problems, and so on. Therefore, it is advantageous for the longest time to be added to the fewest number of problems. In other words, the problem with the longest solution time should be solved last. Then, the same reasoning is repeated for the remaining $m-1$ problems.

Next, it is necessary to calculate the number of solved problems and the penalty time for each participant, based on the described strategy. To do this, sort the solution times of the problems for each participant and simulate the solving process. Finally, count the number of participants who outperform Rudolph in the results table. The overall time complexity is $O(n \cdot m \cdot \log m)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while(ttt--){
        int n, m, h;
        cin >> n >> m >> h;
        pair<int, long long> rud;
        int ans = 1;
        for(int i = 0; i < n; i++){
            vector<int> cur(m);
            for(int j = 0; j < m; j++){
                cin >> cur[j];
            }
            std::sort(cur.begin(), cur.end());
            int task_cnt = 0;
            long long penalty = 0, sum = 0;
            for(int j = 0; j < m; j++){
                if (sum + cur[j] > h) break;
                sum += cur[j];
                penalty += sum;
                task_cnt++;
            }
            if (i){
                if (make_pair(-task_cnt, penalty) < rud) ans++;
            } else rud = {-task_cnt, penalty};
        }
        cout << ans << 'n';
    }
    return 0;
}

```
 **Rate the problem*** Didn't solve 

 
[*31*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*249*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*93*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*128*](https://codeforces.com/data/like?action=like "I like this")
[1846D - Rudolph and Christmas Tree](../problems/D._Rudolph_and_Christmas_Tree.md "Codeforces Round 883 (Div. 3)")

Author: [vladmart](https://codeforces.com/profile/vladmart "Master vladmart")

 **Hint 1**Consider all the triangles in order from bottom to top.

 **Hint 2**What if the current triangle intersects with the next one?

 **Hint 3**Trapezoid

 **Tutorial**
### [1846D - Rudolph and Christmas Tree](../problems/D._Rudolph_and_Christmas_Tree.md "Codeforces Round 883 (Div. 3)")

Let's consider the triangles in ascending order of $y_i$. Let the current triangle have index $i$. There are two cases: 

1. The triangle does not intersect with the $(i+1)$-th triangle $(y_{i + 1} - y_i \ge h)$. In this case, we simply add the area of the triangle to the answer. The area will be $\frac{d \cdot h}{2}$.
2. The triangle intersects with the $(i+1)$-th triangle $(y_{i + 1} - y_i < h)$. We can add to the answer the area of the figure that does not belong to the intersection and move on to the next triangle. Note that this figure is a trapezoid with a lower base $d$ and height $h' = y_{i + 1} - y_i$. The upper base can be found based on the similarity of triangles. The heights of the triangles are in the ratio $k = \frac{h - h'}{h}$. Then the upper base $d_{top} = d \cdot k$. The area of the trapezoid is $h' \cdot \frac{d + d_{top}}{2}$.

Time complexity is $O(n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10); cout.setf(ios::fixed);
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, d, h;
        cin >> n >> d >> h;
        vector<int> y(n);
        for(int i = 0; i < n; i++){
            cin >> y[i];
        }
        long double ans = (long double)d * h / 2.0;
        for (int i = 0; i + 1 < n; ++i) {
            if (y[i + 1] >= y[i] + h) ans += (long double)d * h / 2.0;
            else{
                long double d2 = (long double)d * (y[i] + h - y[i + 1]) / h;
                long double nh = y[i + 1] - y[i];
                ans += (d + d2) / 2.0 * nh;
            }
        }
        cout << ans << 'n';
    }
    return 0;
}

```
 **Rate the problem*** Didn't solve 

 
[*17*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*309*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*47*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*90*](https://codeforces.com/data/like?action=like "I like this")
[1846E1 - Rudolf and Snowflakes (simple version)](../problems/E1._Rudolf_and_Snowflakes_(simple_version).md "Codeforces Round 883 (Div. 3)")

Author: [natalina](https://codeforces.com/profile/natalina "Expert natalina")

 **Hint 1**1 + k + k2 + k3 + ... + kp

 **Hint 2**What maximum value of k can be reached for the current constrains on n?

 **Hint 3**Can we precalculate for each n if there is appropriate k?

 **Tutorial**
### [1846E1 - Rudolf and Snowflakes (simple version)](../problems/E1._Rudolf_and_Snowflakes_(simple_version).md "Codeforces Round 883 (Div. 3)")

For the current given constraint you can precalculate whether it is possible to obtain each $n$ for some $k$. To do this, we can iterate through all possible $2 \le k \le 10^6$ and for each of them calculate the values $1 + k + k^2$, $1 + k + k^2 + k^3$, ..., $1 + k + k^2 + k^3 + ... + k^p$, where $p$ is such that $1 \le 1 + k + k^2 + k^3 + ... + k^p \le 10^6$. For this version of problem it is enougth to calculete valuse for $p \le 20$.

Note that the minimum number of snowflake layers is $3$. Therefore, the calculations start from the value $1 + k + k^2$.

We can store all the obtained values, for example, in a set. Alternatively, we can use an array called "used" and set the value $1$ in the array element with the corresponding index for each obtained value.

It is better to perform this precalculation before iterating through the test cases.

Then, for each test, we only need to read the value of $n$ and check if we have obtained it in the precalculation described above.

The time complexity of the solution using a set is $O(\sqrt n \cdot p \cdot \log n + tc \cdot \log n$.

The time complexity of the solution using the "used" array is $O(\sqrt n \cdot p + tc)$.

Here $tc$ — number of test cases.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

using LL = long long;

set<long long> nums;

int main() {

    for (long long k = 2; k <= 1000; ++k) {
        long long val = 1 + k;
        long long p = k*k;
        for (int cnt = 2; cnt <= 20; ++cnt) {
            val += p;
            if (val > 1e6) break;
            nums.insert(val);            
            p *= k;
        }
    }



    int _ = 0, __ = 1;
    cin >> __;

    for (int _ = 0; _ < __; ++_) {
        long long n;
        cin >> n;
        

        if (nums.count(n)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }


    return 0;
}

```
 **Rate the problem*** Didn't solve 

 
[*24*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*323*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*26*](https://codeforces.com/data/like?action=like "I like this")
[1846E2 - Rudolf and Snowflakes (hard version)](../problems/E2._Rudolf_and_Snowflakes_(hard_version).md "Codeforces Round 883 (Div. 3)")

Author: [natalina](https://codeforces.com/profile/natalina "Expert natalina")

 **Hint 1**1 + k + k2 + k3 + ... + kp

 **Hint 2**What maximum value of k can be reached for the current constrains on n?

 **Hint 3**Can we precalculate for some n and snowflakes with 4 or more levels if there is appropriate k?

 **Hint 4**How can we check snowflakes with 3 levels separately?

 **Tutorial**
### [1846E2 - Rudolf and Snowflakes (hard version)](../problems/E2._Rudolf_and_Snowflakes_(hard_version).md "Codeforces Round 883 (Div. 3)")

On these constraints, it is also possible to precalculate whether it is possible to obtain certain values of $n$ for some $k$. To do this, we can iterate through all possible $2 \le k \le 10^6$ and for each of them calculate the values $1 + k + k^2$, $1 + k + k^2 + k^3$, ..., $1 + k + k^2 + k^3 + ... + k^p$, where $p$ is such that $1 \le 1 + k + k^2 + k^3 + ... + k^p \le 10^{18}$. However, in order to obtain all possible values of $n$, we would have to iterate through $k \le 10^9$, which exceeds the time limits. Therefore, let's precalculate all possible values of $n$ that can be obtained for $3 \le p \le 63$.

We will store all the obtained values, for example, in a set. We cannot use an array called "used" here due to the constraints on $n$.

It is better to perform this precalculation before iterating through the test cases of the current test case.

Next, for each test, we only need to read the value of $n$ and check if we obtained it in the aforementioned precalculation.

If we obtained it, we output "YES" and move on to the next test.

If we did not obtain it, we need to separately check if we could obtain this value for $p = 2$. To do this, we solve the quadratic equation $k^2 + k + 1 = n$. If it has integer roots that satisfy the problem's constraints ($k > 1$), then the answer is "YES". Otherwise, it is "NO".

The time complexity of the solution is $O(\sqrt[3] n \cdot p \cdot \log n + tc \cdot \log n)$.

Here, $tc$ is the number of tests in the test case.

 **Solution**
```cpp
#include<bits/stdc++.h>

using namespace std;

using LL = long long;

set<long long> nums;

int main() {

    for (long long k = 2; k <= 1000000; ++k) {
        long long val = 1 + k;
        long long p = k*k;
        for (int cnt = 3; cnt <= 63; ++cnt) {
            val += p;
            if (val > 1e18) break;
            nums.insert(val);
            if (p > (long long)(1e18) / k) break;
            p *= k;
        }
    }



    int _ = 0, __ = 1;
    cin >> __;

    for (int _ = 0; _ < __; ++_) {
        long long n;
        cin >> n;
        if (n < 3)
        {
            cout << "NO" << endl;
            continue;
        }
        long long d = 4*n - 3;
        long long sq = sqrt(d);
        long long sqd = -1;
        for (long long i = max(0ll, sq - 5); i <= sq + 5; ++i) {
            if (i*i == d)
            {
                sqd = i;
                break;
            }
        }
        if (sqd != -1 && (sqd - 1) % 2 == 0 && (sqd - 1) / 2 > 1)
        {
            cout << "YES" << endl;
            continue;
        }

        if (nums.count(n)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }


    return 0;
}

```
 **Rate the problem*** Didn't solve 

 
[*56*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*303*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*19*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*73*](https://codeforces.com/data/like?action=like "I like this")
[1846F - Rudolph and Mimic](../problems/F._Rudolph_and_Mimic.md "Codeforces Round 883 (Div. 3)")

Author: [Sasha0738](https://codeforces.com/profile/Sasha0738 "Expert Sasha0738")

 **Hint 1**How number of objects of each type will change after the mimic transformation?

 **Hint 2**What if all the current objects have the same value?

 **Tutorial**
### [1846F - Rudolph and Mimic](../problems/F._Rudolph_and_Mimic.md "Codeforces Round 883 (Div. 3)")

The strategy is to keep track of the number of objects of each type. When the number of objects of a certain type increases, that means the mimic has turned into an object of that type. Then you can delete all other objects. After the first such removal, all objects will become equal. Then, after maximum two stages, the mimic will be forced to turn into something else and it will be possible to unambiguously identify it.

Let's consider the worst case, where the mimic does not change its appearance between the first and second stages. Then we do not remove any element with the first two requests. Between the second and third steps, the mimic will be forced to transform, and then we can remove all objects except for those that have the same type as the mimic. The mimic may not change between the third and fourth stages, but will be forced to transform between the fourth and fifth. Then we will be able to unambiguously determine the mimic, since before the transformation all objects were the same.

 **Solution**
```cpp
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int test_cases;
	cin >> test_cases;
	for (int test_case = 0; test_case < test_cases; test_case++) {
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		vector<int> elements_to_erase;
		int ans;
		for (int i = 0; i < 5; i++) {
			if (v.size() - elements_to_erase.size() == 1) {
				cout << "! " << ans << endl;
				break;
			}
			cout << "- " << elements_to_erase.size() << " ";
			for (int j = 0; j < elements_to_erase.size(); j++) {
				cout << elements_to_erase[j] << " ";
			}
			cout << endl;
			vector<int> new_v;
			map<int, int> new_m;
			for (int j = 0; j < v.size() - elements_to_erase.size(); j++) {
				int x;
				cin >> x;
				new_v.push_back(x);
				new_m[x]++;
			}
			elements_to_erase.clear();
			int tm = -1;
			for (auto& k : new_m) {
				if (k.second > m[k.first]) {
					tm = k.first;
				}
			}
			if (tm != -1) {
				for (int j = 0; j < new_v.size(); j++) {
					if (new_v[j] != tm)
						elements_to_erase.push_back(j + 1);
					else
						ans = j + 1;
				}
				m.clear();
				m[tm] = new_m[tm];
			}
			v = new_v;
		}
	}
	return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*35*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*75*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*21*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*80*](https://codeforces.com/data/like?action=like "I like this")
[1846G - Rudolf and CodeVid-23](../problems/G._Rudolf_and_CodeVid-23.md "Codeforces Round 883 (Div. 3)")

Author: [vladmart](https://codeforces.com/profile/vladmart "Master vladmart")

 **Hint 1**Bitmasks

 **Hint 2**Weighted graph

 **Hint 3**Dijkstra's algorithm

 **Tutorial**
### [1846G - Rudolf and CodeVid-23](../problems/G._Rudolf_and_CodeVid-23.md "Codeforces Round 883 (Div. 3)")

Let's denote Rudolf's state as a binary mask of length $n$ consisting of $0$ and $1$, similar to how it is given in the input data. Then each medicine transforms Rudolf from one state to another.

Let's construct a weighted directed graph, where the vertices will represent all possible states of Rudolf. There will be $2^n$ such vertices. Two vertices will be connected by an edge if there exists a medicine that transforms Rudolf from the state corresponding to the first vertex to the state corresponding to the second vertex. The weight of the edge will be equal to the number of days that this medicine needs to be taken. Note that in this case, we simply need to find the shortest path in this graph from the vertex $s$, corresponding to the initial state of Rudolf, to the vertex $f$, corresponding to the state without symptoms.

To find the shortest path in a weighted graph, we will use Dijkstra's algorithm. We will run it from the vertex $s$ and if, as a result, we visit the vertex $f$, output the distance to it, otherwise $-1$. 

The time complexity is $O(n \cdot m \cdot 2^n)$.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m;
        cin >> n >> m;
        bitset<10> tmp;
        cin >> tmp;
        int s = (int) tmp.to_ulong();
        vector<pair<pair<int, int>, int>> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].second;
            cin >> tmp;
            edges[i].first.first = ((1 << n) - 1) ^ (int) tmp.to_ulong();
            cin >> tmp;
            edges[i].first.second = (int) tmp.to_ulong();
        }
        vector<int> dist(1 << n, INT_MAX);
        dist[s] = 0;
        set<pair<int, int>> q = {{0, s}};
        while (!q.empty()) {
            auto [d, v] = *q.begin();
            q.erase(q.begin());
            for (int i = 0; i < m; i++) {
                int to = v & edges[i].first.first;
                to |= edges[i].first.second;
                if (dist[to] > d + edges[i].second) {
                    q.erase({dist[to], to});
                    dist[to] = d + edges[i].second;
                    q.insert({dist[to], to});
                }
            }
        }
        if (dist[0] == INT_MAX) dist[0] = -1;
        cout << dist[0] << 'n';
    }
    return 0;
}
```
 **Rate the problem*** Didn't solve 

 
[*32*](https://codeforces.com/data/like?action=like "I like this")
* Good task 

 
[*270*](https://codeforces.com/data/like?action=like "I like this")
* Average task 

 
[*9*](https://codeforces.com/data/like?action=like "I like this")
* Bad task 

 
[*15*](https://codeforces.com/data/like?action=like "I like this")
