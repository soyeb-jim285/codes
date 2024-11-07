# Tutorial

[1579A - Casimir's String Solitaire](../problems/A._Casimir's_String_Solitaire.md "Codeforces Round 744 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1579A - Casimir's String Solitaire](../problems/A._Casimir's_String_Solitaire.md "Codeforces Round 744 (Div. 3)")

Note that no matter which action is chosen, after this action is performed 

* exactly one letter 'B' is erased from the string
* exactly two letters in total are erased from the string

Let's denote the length of the string s by n. If n is odd, then described turns can not erase all the characters from the strings, because if he is deleting two letters on each turn, the length will always remain odd. For example, if the original length of the string is 5, then after one turn it will be equal to 3, and after two moves it will be equal to 1 in which case the next turn is impossible. Thus, if the length of the row is odd, the answer is NO.

If n is even, it will take exactly n2 steps to erase all characters from the string. Since each action removes exactly one letter 'B' from the string, the string can become empty only if there are exactly n2 letters 'B'.

Let us show that this condition is sufficient, that is, if a string has exactly half of the letters equal to 'B', then there always exists a sequence of actions leading to an empty string. Indeed, if a string of length n has exactly n2 letters 'B', exactly x letters 'A' and exactly y letters 'C', then x+y=n−n2=n2. Then Casimir can make x moves of the first type, each time removing the first occurrence of 'B' and the first occurrence of 'A', and y moves of the second type, each time removing the first occurrence of 'B' and the first occurrence of 'C'. After x+y=n2 such moves, the string will become empty.

Thus, checking that the number of letters 'B' in the string is exactly half of its length was enough to solve the problem.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << (count(s.begin(), s.end(), 'B') * 2 == s.size() ?
                 "YESn" : "NOn");
    }
}
```
[1579B - Shifting Sort](../problems/B._Shifting_Sort.md "Codeforces Round 744 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1579B - Shifting Sort](../problems/B._Shifting_Sort.md "Codeforces Round 744 (Div. 3)")

In this problem, it was enough to implement an analogue of standard selection sort or insertion sort. Here is an example of a solution based on selection sort.

Let's find the minimum element in the array by simply iterating over it. Let's denote its index in the array by p1. If we apply a shift "1 p1 (p1−1)" to it, the following happens: a→[ap1,a1,a2,…,ap1−1,ap1+1,…,an] Once again, please note that all shifts are made in the left direction, so shifting by p1−1 to the left will put the element that was previously at index p1 in the first place.

Let us perform a similar shift for the second-largest element of the array, putting it in second place, for the third-largest element of the array, putting it in third place, and so on. More formally, let's describe the i-th iteration as follows: 

1. At the beginning of the i-th iteration, the first i−1 elements of the array are its i−1 minimal elements, already in their correct places in sorted order.
2. During the i-th iteration, the i-th largest element of the array is placed in the i-th place in the array.
3. Since the first i−1 minimal elements are already in their places, the i-th largest element of the array is simply the smallest element among [ai,ai+1,…,an]. Let's find it by iterating over these elements and denote its index in the array a by pi.
4. Make a shift "i pi (pi−i)". The first i−1 elements will not change, and the element from the pi-th place in the array will move to the i-th: a→[a1,…,ai−1,api,ai,ai+1,…,api−1,api+1,…,an] It is worth noting that the output format forbids shifting segments with l=r. Regarding this case, we should check the equality i=pi separately. If these two indexes coincide, then the i-th element is already in its place, and no shift should be done on this iteration.

Let us repeat this algorithm for i=2, i=3, ..., i=n−1. At each iteration, the new element will be shifted into its place in sorted order, and each iteration performs no more than one shift operation. Thus, in strictly less than n shifts, the array will be completely sorted.

The time complexity is O(t⋅n2).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<pii> actions;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n - 1; i++) {
            int min_pos = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[min_pos])
                    min_pos = j;

            if (min_pos > i) {
                actions.push_back({i, min_pos});
                int opt = a[min_pos];
                for (int j = min_pos; j > i; j--)
                    a[j] = a[j - 1];
                a[i] = opt;
            }
        }

        cout << actions.size() << 'n';
        for (auto &lr: actions) {
            cout << lr.first + 1 << ' ' << lr.second + 1 << ' ' << lr.second - lr.first << 'n';
        }
    }

}
```
[1579C - Ticks](../problems/C._Ticks.md "Codeforces Round 744 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1579C - Ticks](../problems/C._Ticks.md "Codeforces Round 744 (Div. 3)")

For each painted cell, we will determine whether it can be part of some tick of the allowed size. If some of the cells cannot be a part of any tick, the answer is obviously NO. Otherwise, let's match each colored cell with an arbitrary valid (entirely contained in the field under consideration and of size ≥k) tick containing it. Let's draw all such ticks, then the following holds: 

* no empty (white) cell of the field will be painted, since only ticks that do not contradict the field in question have been considered;
* every colored cell of the field will be covered by at least one drawn tick (at least the one we matched it with).

 Basically, this process gives us a field in which the set of painted cells matches the data in the input, which means that the field given in the input could have been obtained, in particular, in the way described above, and the answer is YES.In order to check that all painted cells are parts of some ticks, let's go through all possible ticks of size d≥k and for each tick mark all the cells included in it. If there is at least one unmarked painted cell in the end, it can't be a part of any valid tick, and the answer is NO.

To consider all possible ticks, we can iterate through all their possible center cells, that is, all the painted cells. Since smaller ticks are subsets of larger ticks with the same center cell it is sufficient to find the maximal size tick that can be constructed from that center cell. So for each painted cell we aim to find the maximal possible size of a tick with its center in this very cell. 

Let us now consider a painted cell (i,j) as a possible center of some tick. By the definition of a tick, this cell can be a center of a tick of size d if for all h from 0 to d both cells (i−h,j−h) and (i−h,j+h) exist (are not out of bounds) and are painted. Let's iterate through h from 1 to i, and stop when the described condition is no longer satisfied. The largest h for which the condition is still satisfied gives us di,j — the maximum possible size of a tick with its center in (i,j). Now if di,j≥k, then such a tick is valid, and all the cells included in it should be marked. Otherwise, it could not have been drawn, and none of its cells should be marked.

After a complete check of all possible ticks in a given field, either there will be no unchecked painted cells and then the answer is YES, or at least one painted cell is not covered by any valid checkbox and then the answer is NO.

The time complexity is O(t⋅n2m).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> status(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                if (s[j] == '*')
                    status[i][j] = 1;
        }
        for (int i = n - 1; i > -1; i--) {
            for (int j = 0; j < m; j++) {
                if (status[i][j] == 0)
                    continue;
                int len = 0;
                while (j > len && j + len + 1 < m && i > len) {
                    if (status[i - len - 1][j - len - 1] == 0 || status[i - len - 1][j + len + 1] == 0)
                        break;
                    len++;
                }
                if (len >= k) {
                    for (int d = 0; d <= len; d++) {
                        status[i - d][j - d] = 2;
                        status[i - d][j + d] = 2;
                    }
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (status[i][j] == 1)
                    ok = false;

        cout << (ok ? "YES" : "NO") << 'n';
    }
}
```
[1579D - Productive Meeting](../problems/D._Productive_Meeting.md "Codeforces Round 744 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1579D - Productive Meeting](../problems/D._Productive_Meeting.md "Codeforces Round 744 (Div. 3)")

For the first conversation let's choose two people i and j with maximal values of sociability. Note that after this conversation takes place, we move on to a similar problem, but in which ai and aj are decreased by 1. After decreasing ai and aj by 1, we repeat the choice of the two people with the maximum values of sociability. Let us repeat such iterations while at least two people with positive sociability parameters remain.

Let us prove that this solution leads to the optimal answer. Let's denote the sum n∑i=1ai by S and consider two fundamentally different cases: 

1. The maximal element a is greater than or equal to the sum of all remaining elements. That is, there exists i such that ai≥∑i≠jaj=S−ai. In this case, note that the i-th person can not possibly have more than S−ai conversations, because by that point all other people already reached their sociability limits and left the meeting. Thus, if ai≥S−ai, the answer cannot be more than (S−ai)+∑j≠iaj=2⋅(S−ai). Note that this estimation is accurate since an example exists in which i-th person talks to all other people as many times as possible (that is, aj times with j-th person for all j). And the algorithm described above will just choose the ith person as one of the participants of a conversation every time, because for every conversation both ai and ∑j≠iaj decrease by exactly 1, so the inequality holds and it follows that ∀k≠i:ai≥∑j≠iaj≥ak.
2. Otherwise, we can prove that the maximum number of conversations is always ⌊S2⌋. Obviously, it is impossible to get more than this number, since each conversation requires exactly two units of sociability (one from two people), while a larger answer would mean that S=n∑i=1ai≥2⋅(⌊S2⌋+1)>S, which is obviously wrong. Let us prove that this answer is achieved by the described algorithm. Let's look at the last conversation held. If there are at least two more people left in the meeting after it, we can hold another conversation, which means there is a more optimal answer. If there are zero people left in the meeting, then an estimate of S2 of conversations has been achieved. And if there is one person with a remaining sociability =1, then an estimate of S−12 of conversations has been achieved.

 If there is exactly one remaining person i with a sociability residual >1, then we can guarantee that this person has participated in all previous conversations. Indeed, let's look at the last conversation — it was held between two people with the maximum parameters of the remaining sociability. But the i-th person has at least 2 sociability remaining, so it couldn't have been the other two people with residuals of 1 who left right after that. Thus, analyzing all conversations in reverse order, we can prove that at any time ai>∑j≠iaj, which means that it is in fact the case considered above.

We have proven that the described greedy algorithm works. This algorithm can be implemented by using any balanced search tree, such as std::set. By storing pairs of elements (ai,i) in it, we could for O(logn) each time choose the next two people to talk to and update the sociability values.

The time complexity is O(Slogn).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto cmp = [](pii const &x, pii const &y) {
            return x > y;
        };
        set<pii, decltype(cmp)> a(cmp);
        vector<pii> answer;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            if (ai > 0)
                a.emplace(ai, i + 1);
        }
        while (a.size() > 1) {
            auto p1 = *a.begin();
            a.erase(a.begin());
            auto p2 = *a.begin();
            a.erase(a.begin());
            answer.emplace_back(p1.second, p2.second);
            if (p1.first > 1) a.emplace(p1.first - 1, p1.second);
            if (p2.first > 1) a.emplace(p2.first - 1, p2.second);
        }
        cout << answer.size() << 'n';
        for (auto &p : answer) {
            cout << p.first << ' ' << p.second << 'n';
        }
    }
}
```
[1579E1 - Permutation Minimization by Deque](../problems/E1._Permutation_Minimization_by_Deque.md "Codeforces Round 744 (Div. 3)")

Idea: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1579E1 - Permutation Minimization by Deque](../problems/E1._Permutation_Minimization_by_Deque.md "Codeforces Round 744 (Div. 3)")

We'll process the permutation elements one by one.

For the first element, it doesn't matter which side of the deque we add it to, the result of its addition will be the same — there will be a sequence of one element (equal to the first permutation element) in the deque.

Now let's consider adding the i-th element of a permutation to the deque. First i=2 will be considered, then i=3, and so on up to i=n. Let us describe the general algorithm for choosing the side of the deque for each step. Note that if the elements [d1,…,di−1] are now in the deque, then all final permutations that can be obtained in the deque from the current state can be broken down into pairs of the form […,ai,d1,…,di−1,…] […,d1,…,di−1,ai,…], where the beginning and the end of the final permutations, hidden behind "…", are obtained by the same sequences of all the following choices and thus are equal between the first and the second.

Note that when ai<d1 the first permutation will always be lexicographically smaller than the second one, and vice versa. Therefore, regardless of the following choices, if ai<d1 then the second permutation will never be minimal, and if ai>d1 then the first permutation will never be minimal.

This means that we can make a choice about the side of the deque to add the i-th element to based only on its relation to d1: if ai<d1, then ai is added to the beginning of the deque, otherwise — to the end.

The time complexity is O(n). Alternative solutions, which also fit in the time limit, involved finding a lexicographically minimal increasing sequence in the reversed original permutation and could be implemented either with O(nlogn) time complexity or with O(n) time complexity if the permutation's definition was taken into consideration.

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n;
        deque<int> d;
        for (int i = 0; i < n; i++) {
            cin >> a;
            if (d.empty() || a < d[0])
                d.push_front(a);
            else
                d.push_back(a);
        }
        for (int x : d)
            cout << x << ' ';
        cout << 'n';
    }
}
```
[1579E2 - Array Optimization by Deque](../problems/E2._Array_Optimization_by_Deque.md "Codeforces Round 744 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1579E2 - Array Optimization by Deque](../problems/E2._Array_Optimization_by_Deque.md "Codeforces Round 744 (Div. 3)")

Let's process the array elements one by one.

For the first element, it doesn't matter which side of the deque we add it to, the result of its addition will be the same — there will be a sequence of one element (equal to the first array element) in the deque.

Now let's consider adding the ith element of an array into the deck. First i=2 will be considered, then i=3, and so on up to i=n. Let us describe the general algorithm for choosing the side of the dec for each step. Note that if the elements [d1,…,di−1] now lie in the deck, then all final sequences that can be obtained in the deck from the current state can be broken down into pairs of the form […,ai,d1,…,di−1,…] […,d1,…,di−1,ai,…], where the beginning and the end of the final sequences hidden behind "…" are obtained by the same sequences of all the following choices and, respectively, coincide.

Note that since the prefix and suffix hidden behind the dots completely coincide in the two sequences under consideration, as well as the set of numbers in the central part coincides, the numbers of inversions also coincide: 

* inside the prefix and inside the suffix;
* between elements of the prefix and elements of the suffix;
* between elements of the prefix or suffix and elements of the central part.

The difference between the number of inversions in the first and second sequence consists only of the difference between the number of inversions in their central part. So, we can determine at the stage of adding ai to the deque, which direction of its addition is guaranteed not to lead to the optimal answer and choose the opposite one.

If ai is added to the beginning of the deque, the number of inversions in the central part will increase by the number of elements in the deque strictly smaller than ai, and if we add it to the end of the deque, it will increase by the number of elements in the deque strictly larger than ai. Let us make a choice such that the number of inversions increases by the minimum of these two values.

To quickly find the number of elements smaller or larger than ai, we will store all already processed array elements in a structure that supports the element order search operation, such as __gnu_pbds::tree. Besides using this structure specifically, you can 

* write any balanced binary search tree (such as a Cartesian tree);
* sort all numbers in the input array and compress them to values [1,n], preserving the "≤" relation, then build a segment tree on them, storing in the node [l,r) the number of array numbers already processed by the deque with values between l and r.

Requests to update and get an order in such structures take O(logn) time, and the construction takes at worst O(nlogn), so the time complexity of the algorithm is O(nlogn).

 **Solution**
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> node;
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ordered_set s;
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            int less = s.order_of_key(node(a, 0)),
                    greater = i - s.order_of_key(node(a, n));
            cnt += min(less, greater);
            s.insert(node(a, i));
        }
        cout << cnt << 'n';
    }
}
```
[1579F - Array Stabilization (AND version)](../problems/F._Array_Stabilization_(AND_version).md "Codeforces Round 744 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov")

 **Tutorial**
### [1579F - Array Stabilization (AND version)](../problems/F._Array_Stabilization_(AND_version).md "Codeforces Round 744 (Div. 3)")

We'll consider an arbitrary index of the array i and see what changes happen to ai during several steps of the described algorithm. Let's denote by ak the value of the array after k steps of the algorithm and prove by induction that aki is the logical "AND" of k+1 elements of the array a, starting from i with step d to the left, that is aki=ai&a(i−d)mod

Base of induction: for k = 0 the element of the original array a^0_i is a_i. For clarity we can also show that the statement is true for k = 1: during the first step a_i is replaced by a_i \,\\&\, a_{(i - d) \bmod n} by the definition of cyclic shift by d to the right.

For simplicity, we will omit the "\bmod n" operation in the following formulas but will keep it in mind implicitly. That is, a_{i - kd} will imply a_{(i - kd) \bmod n}.

Induction step: let the above statement be true for k - 1, let us prove it for k. By the definition of cyclic shift a^k_i = a^{k-1}_i \,\\&\, a^{k-1}_{i - d}. And by the induction assumption, these two numbers are equal to a^{k-1}_i = a_i \,\\&\, \ldots \,\\&\, a_{i - (k-1)d} a^{k-1}_{i - d} = a_{i - d} \,\\&\, \ldots \,\\&\, a_{i - kd} Since the logical "AND" is an idempotent operation, that is, it does not change its result when repeatedly applied to any argument, then a^k_i that is equal to their logical "AND" is also equal to a^k_i = a_i \,\\&\, a_{i - d} \,\\&\, \ldots \,\\&\, a_{i - kd}\text{,} which is what we wanted to prove.

It follows from this formula that a_i turns to zero after the k-th step if and only if a_i = 1, a_{i - d} = 1, ..., a_{i - (k-1)d} = 1, and a_{i - kd} = 0. Up to the k-th step all elements will be equal to 1, and so their logical "AND" will also be equal to 1. As soon as 0 appears in the sequence in question, the logical "AND" will also become zero. 

Thus, we reduced the problem to finding the maximal block of elements equal to 1 of the pattern a_i = a_{i - d} = a_{i - 2d} = \ldots = a_{i - (k-1)d} = 1. Note that by shifts of d the array splits into \mathtt{gcd}(n, d) cyclic sequences of this kind, each of length \frac{n}{\mathtt{gcd}(n, d)}. Let's look at these cyclic sequences independently from each other and iterate over each of them in linear time complexity to find the maximal block of consecutive elements equal to 1 — this will be the answer to the problem.

Remember to check that if at least one of these sequences consists entirely of elements equal to 1, its elements will never zero out, and the answer in such case is -1.

The time complexity is \mathcal{O}(n).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<bool> used(n, false);
        bool fail = false;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (used[i])
                continue;
            int cur = i, pref = 0, last = 0, iter = 0, ans = 0;
            do {
                used[cur] = true;
                if (a[cur] == 0) {
                    ans = max(ans, last);
                    last = 0;
                } else {
                    last++;
                    if (iter == pref) {
                        pref++;
                    }
                }
                cur = (cur + d) % n;
                iter++;
            } while (cur != i);
            if (iter != pref)
                ans = max(ans, pref + last);
            else {
                fail = true;
                break;
            }
            res = max(res, ans);
        }
        if (fail)
            cout << "-1n";
        else
            cout << res << 'n';
    }
}
```
[1579G - Minimal Coverage](../problems/G._Minimal_Coverage.md "Codeforces Round 744 (Div. 3)")

Idea: [doreshnikov](https://codeforces.com/profile/doreshnikov "Candidate Master doreshnikov"), [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 **Tutorial**
### [1579G - Minimal Coverage](../problems/G._Minimal_Coverage.md "Codeforces Round 744 (Div. 3)")

One possible solution involves the method of dynamic programming. As a state of DP we will use the number of already placed segments i, and the distance l from the "end" of the last segment to the current left boundary of the coverage, and in the DP we will store the minimal possible distance from the "end" of the last segment to the current right boundary of the coverage.

We can prove that the answer never exceeds 2 \cdot l_{\mathtt{max}}, where l_\mathtt{max} = \max(a) is the maximal length of the segments. To do this, let us define a region of length 2 \cdot l_{\mathtt{max}}, specifically the segment [-l_{\mathtt{max}}, l_{\mathtt{max}}]. If the "end" of the last segment has a coordinate x > 0, we put the next segment to the left, otherwise, we put it to the right. With this algorithm, none of the "end" endpoints of the segments will go beyond the marked boundaries, because to do so, the segment must be placed from the coordinate of one sign beyond the boundary of the opposite sign, and thus must have a length greater than l_{\mathtt{max}} which contradicts how we defined l_{\mathtt{max}}.

Using this fact, we will consider the DP \mathtt{dp}_{i, l} for 0 \le i \le n and 0 \le j \le 2 \cdot l_{\mathtt{max}} as the minimum distance between the "end" of the i-th segment and the right boundary of the axis coverage of the first i segments when the distance to the left boundary of the coverage equals to l. The "end of the 0-th segment" here is the "beginning" of the first one, that is, the point 0.

The base of DP is \mathtt{dp}_{0, 0} = 0, since when no segments are placed, the coverage boundaries and the current point 0 are all coincident. Next, we consider the forward dynamic programming relaxation: for every (i, l) there are two cases to consider, the case of the next segment being placed to the left and the case of it being placed to the right (value r below refers to the distance to the right boundary of the coverage and is an alias for \mathtt{dp}_{i, l}): 

* If a segment of length a_{i + 1} is placed to the left side, then the new distance to the left boundary will be equal to \max(0, l - a_{i + 1}), and distance to the right boundary will always be r + a_{i + 1}, which gives us the relaxation formula \mathtt{dp}_{i + 1, \max(0, l - a_{i + 1})} \leftarrow \mathtt{dp}_{i, l} + a_{i + 1}
* If a segment of length a_{i + 1} is placed to the right side, then the new distance to the right boundary will be equal to \max(0, r - a_{i + 1}), and distance to the left boundary will always be l + a_{i + 1}, which gives us the relaxation formula \mathtt{dp}_{i + 1, l + a_{i + 1}} \leftarrow \max(0, \mathtt{dp}_{i, l} - a_{i + 1})

The values in array \mathtt{dp} can be calculated in ascending order by i. Then the answer for the problem can be found as the minimum sum of l and r in the last row of \mathtt{dp}, that is \min\limits_{l} l + \mathtt{dp}_{i, l}.

The time complexity is \mathcal{O}(n \cdot l_{\mathtt{max}}).

 **Solution**
```cpp
#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int maxl = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxl = max(maxl, a[i]);
        }
        vector<vector<int>> dp(n + 1, vector<int>(2 * maxl + 1, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int left = 0; left <= 2 * maxl; left++) {
                if (dp[i][left] == INF)
                    continue;
                dp[i + 1][max(left - a[i], 0)] = min(dp[i + 1][max(left - a[i], 0)], dp[i][left] + a[i]);
                if (left + a[i] < dp[i + 1].size()) {
                    dp[i + 1][left + a[i]] = min(dp[i + 1][left + a[i]], max(dp[i][left] - a[i], 0));
                }
            }
        }

        int ans = 2 * maxl + 1;
        for (int left = 0; left <= 2 * maxl; left++)
            ans = min(ans, left + dp[n][left]);
        cout << ans << 'n';
    }
}
```
