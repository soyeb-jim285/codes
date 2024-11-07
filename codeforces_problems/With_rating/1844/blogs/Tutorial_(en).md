# Tutorial_(en)

Video editorials for [B](https://codeforces.com/https://www.youtube.com/watch?v=5nzUni8dFLQ), [C](https://codeforces.com/https://www.youtube.com/watch?v=8mz7gnAJ5QM), and [D](https://codeforces.com/https://www.youtube.com/watch?v=ahnNAwpGwHc) are available on [ak2006](https://codeforces.com/profile/ak2006 "Специалист ak2006")'s channel.

### [1844A - Игра в вычитание](../problems/A._Subtraction_Game.md)

 **Hint 1**There exists a small n where the second player can win.

 **Hint 2**If a≥2, then n=1 works.

 **Solution**
### [1844A - Игра в вычитание](../problems/A._Subtraction_Game.md "Codeforces Round 884 (Div. 1 + Div. 2)")

We present two approaches.

Approach 1

If a≥2, then n=1 works.

Else if a=1 and b≥3, n=2 works.

Otherwise, a=1 and b=2, so n=3 works.

Approach 2

Printing a+b works because no matter what move the first player makes, the second player can respond with the opposite move.

The time complexity is O(1) per test case.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&a,&b);
        printf("%dn",a+b);
    }
    return 0;
}
```
### [1844B - Перестановки и простые числа](../problems/B._Permutations_&_Primes.md)

 **Hint 1**In order for (l,r) to contribute to the primality, we must have MEX(al,…,ar)≥2, so there is some value 1 between indices l and r.

 **Hint 2**To maximize the number of pairs (l,r) that contain the value 1, we should put 1 near the middle of the array.

 **Hint 3**To minimize the number of pairs (l,r) where MEX(al,…,ar)≥2 but is not prime, we should put 2 and 3 at the ends of the array.

 **Solution**
### [1844B - Перестановки и простые числа](../problems/B._Permutations_&_Primes.md "Codeforces Round 884 (Div. 1 + Div. 2)")

The cases n≤2 can be handled separately. For n≥3, any construction with a1=2,a⌊(n+1)/2⌋=1,an=3 is optimal. 

We can prove this as follows: Note that since 2 and 3 are both prime, any (l,r) with l≤⌊n+12⌋≤r has a prime MEX(al,…,ar) except for possibly (l,r)=(1,n), where MEX(a1,…,an)=n+1. Therefore the primality of this array is ⌊n+12⌋⋅⌈n+12⌉−[n+1 is not prime], where [P]=1 if proposition P is true and 0 if P is false. On the other hand, for any permutation of 1,…,n, let k be the index with ak=1. The primality of this array cannot exceed k(n+1−k)−[n+1 is not prime], since any pair (l,r) with prime MEX(al,…,ar)≥2 must satisfy l≤k≤r, and additionally MEX(a1,…,an)=n+1 no matter what the permutation is. The function f(k)=k(n+1−k) is a quadratic which is maximized at k=⌊n+12⌋, so k(n+1−k)−[n+1 is not prime]≤⌊n+12⌋⋅⌈n+12⌉−[n+1 is not prime] as required.

The time complexity is O(n) (note that we don't even need to sieve for primes!).

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

int a[200000];
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        if (n == 1) printf("1n");
        else if (n == 2) printf("1 2n");
        else {
            int c = 4;
            fill(a,a+n,0);
            a[0] = 2,a[n/2] = 1,a[n-1] = 3;
            for (i = 0; i < n; i++) {
                if (a[i] == 0) a[i] = c++;
            }
            for (i = 0; i < n; i++) printf("%d%c",a[i],(i == n-1) ? 'n':' ');
        }
    }
    return 0;
}
```
### [1844C - Частицы](../problems/C._Particles.md)

 **Hint 1**The answer is the sum of some subset of c1,…,cn. Think about which subsets are obtainable.

 **Hint 2**Consider the set of even-indexed particles and the set of odd-indexed particles.

 **Solution**
### [1844C - Частицы](../problems/C._Particles.md "Codeforces Round 884 (Div. 1 + Div. 2)")

Consider the set of even-indexed particles and the set of odd-indexed particles. Observe that particles can only ever combine with other particles from the same set. It follows that the answer is at most max(∑odd imax(ci,0),∑even imax(ci,0)).

On the other hand, this bound is almost always obtainable. We can first perform the operation on all negatively charged particles in the same set as the desired final particle, then perform the operation on all the particles from the opposite set. There is a corner case where all particles are negative, where the answer is just max(c1,…,cn).

The time complexity is O(n).

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;

int c[200000];
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&c[i]);

        int allneg = 1;
        for (i = 0; i < n; i++) allneg &= (c[i] < 0);
        if (allneg) printf("%dn",*max_element(c,c+n));
        else {
            LLI ans1 = 0,ans2 = 0;
            for (i = 0; i < n; i++) {
                if (i & 1) ans1 += max(c[i],0);
                else ans2 += max(c[i],0);
            }
            printf("%lldn",max(ans1,ans2));
        }
    }
    return 0;
}
```
### [1844D - Построчная склейка](../problems/D._Row_Major.md)

 **Hint 1**Describe, using a graph, all the pairs of characters in s that need to be different.

 **Hint 2**Consider the smallest positive integer that does not divide n.

 **Solution**
### [1844D - Row Major](../problems/D._Row_Major.md "Codeforces Round 884 (Div. 1 + Div. 2)")

The condition is equivalent to a graph of pairs of characters in s that need to be different. In graph-theoretic language, we need to find the chromatic number of this graph.

By considering the 1×n and n×1 grids, there is an edge between character u and u+1 for all 1≤u≤n−1. By considering a nd×d grid (where d divides n), there is an edge between character u and u+d for all 1≤u≤n−d whenever d divides n. 

Let c be the smallest positive integer that does not divide n. There is an edge between every pair of the characters 1,…,c (in graph-theoretic language, this is a clique), so the answer is at least c. On the other hand, consider the string obtained by letting s1,…,sc be all distinct characters and repeating this pattern periodically (si=si+c for all 1≤i≤n−c). Any pair of equal characters have an index difference that is a multiple of c, say kc. But since c does not divide n, kc also does not divide n, so these characters are not connected by an edge. Therefore this construction gives a suitable string with c distinct characters.

The time complexity is O(n).

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;

char s[1000001];
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        int c = 1;
        while ((n % c) == 0) c++;
        for (i = 0; i < n; i++) s[i] = 'a'+(i % c);
        s[n] = '0';
        printf("%sn",s);
    }
    return 0;
}
```
### [1844E - Прекрасные таблицы](../problems/E._Great_Grids.md)

 **Hint 1**Try to find a characterization of all great grids.

 **Hint 2**There are two approaches that lead to the same conclusion. Approach 1 is more clever and leads more easily to the conclusion, while approach 2 is perhaps more natural to consider. Feel free to read the hint towards the approach that sounds better.

 **Hint Towards Approach 1**Think of the letters as numbers modulo 3 and look at differences of adjacent cells.

 **Hint Towards Approach 2**Draw a `/` or `` for each 2×2 subgrid connecting the equal letters, and look for patterns.

 **Hint 3**In either approach, we can associate a type to each row and column, which has one of two possibilities. The constraints correspond to a row and a column needing to have the same or different types.

 **Hint 4**The problem reduces to checking the 2-colourability of a graph.

 **Solution**
### [1844E - Прекрасные таблицы](../problems/E._Great_Grids.md "Codeforces Round 884 (Div. 1 + Div. 2)")

We present two approaches.

Approach 1

Let the letters 'A', 'B', and 'C' correspond to the numbers 0, 1, and 2 modulo 3 respectively. Consider drawing an arrow between any two adjacent cells in a great grid pointing to the right or down, and label this arrow with the difference of the two cells modulo 3.

The conditions imply that all labels are 1 or 2, and in each contiguous 2×2 subgrid, the top arrow has the same label as the bottom arrow, and the left arrow has the same label as the right arrow. Hence we can associate a type to each of n−1 rows and m−1 columns which is its label. A constraint for cells (x,y) and (x+1,y+1) means that row x and column y must have different labels, and a constraint for cells (x,y+1) and (x+1,y) means that row x and y must have the same label.

These relations form a graph, and the problem reduces to a variant of 2-colourability, which can be checked using DFS or a DSU.

Approach 2

In a great grid, draw a '/' or '\' for each 2×2 subgrid connecting the equal letters.

We can observe that these grids have a simple pattern: every two rows are either the same or opposite. Furthermore, any such pattern corresponds to a great grid (this can be proven with the idea in approach 1). We can associate a type to each row and column, a boolean variable 0 or 1, such that an entry is '/' or '\' depending on whether the labels are the same or different.

The constraints correspond to entries needing to be '/' or '\', forming a graph of pairs of labels that must be the same or different. Thus the problem reduces to a variant of 2-colourability, which can be checked using DFS or a DSU.

The intended time complexity is O(n+m+k), although slower implementations with complexities like O(nm+k) or O(k(n+m)) can also pass.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int> > vpii;
#define mp make_pair
#define pb push_back

vpii adjList[4000];
int colour[4000],bad = 0;
int doDFS(int u,int c) {
    if (colour[u] != -1) {
        if (colour[u] != c) bad = 1;
        return 0;
    }
    colour[u] = c;
    for (auto [v,e]: adjList[u]) doDFS(v,c^e);
    return 0;
}
int main() {
    int i;
    int t,n,m,k;
    int x1,y1,x2,y2;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&m,&k);
        for (i = 0; i < k; i++) {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1--,y1--,x2--,y2--;
            adjList[min(x1,x2)].pb(mp(n+min(y1,y2),(x1+y1 != x2+y2)));
            adjList[n+min(y1,y2)].pb(mp(min(x1,x2),(x1+y1 != x2+y2)));
        }

        fill(colour,colour+n+m,-1),bad = 0;
        for (i = 0; i < n+m; i++) {
            if (colour[i] == -1) doDFS(i,0);
        }
        printf(bad ? "NOn":"YESn");

        for (i = 0; i < n+m; i++) adjList[i].clear();
    }
    return 0;
}
```
### [1844F1 - Перестановка минимальной стоимости (простая версия)](../problems/F1._Min_Cost_Permutation_(Easy_Version).md)

 **Hint 1**Solve the case c≥0 first. There is a very simple description of the answer.

 **Another Hint**What is the answer when c=0?

 **Hint 2**When c≥0, the answer is the array sorted in nondecreasing order.

 **Hint 3**When c<0, the minimum cost is achieved by sorting the array in nonincreasing order, but this is not the lexicographically smallest. Try to greedily form the lexicographically smallest array one element at a time.

 **Solution (easy version)**
### [1844F1 - Перестановка минимальной стоимости (простая версия)](../problems/F1._Min_Cost_Permutation_(Easy_Version).md "Codeforces Round 884 (Div. 1 + Div. 2)")

Let the cost of a permutation b of a be the value ∑n−1i=1|bi+1−bi−c|.

When c≥0, it can be proven that the minimum cost can be obtained by sorting a in nondecreasing order. As sorting a in nondecreasing order is also the lexicographically smallest array, this is the answer.

Similarly, when c<0, it can be proven that the minimum cost can be obtained by sorting a in nonincreasing order. Furthermore, if we have fixed the values of b1,…,bk for some 1≤k<n, then intuitively, one optimal permutation bk+1,…,bn of the remaining elements is to sort them in nonincreasing order†.

To find the lexicographically smallest permutation, we can greedily loop through k=1,…,n, each time taking the smallest bk that does not increase the cost. If ak≥⋯≥an are the unused elements sorted in nonincreasing order, then the condition we need to check to determine if setting bk:=ai is good is whether |ai−1−ai−c|+|ai−ai+1−c|+|bk−1−ak−c|≥|ai−1−ai+1−c|+|bk−1−ai−c|+|ai−ak−c|(∗) (with some adjustments in the corner cases when k=1 or i=k,n). This condition (∗) can be checked in constant time, and we try O(n) values of i for each of the O(n) values of k, so the time complexity is O(n2).

The proofs of the claims used in this solution can be found at the end of the solution for the hard version.

†This is actually not true as stated (e.g. when c=−1 and we fix b1=2, [2,1,9,8] is better than [2,9,8,1]), but it turns out it is true for all states that the greedy algorithm can reach (i.e. in this example, the greedy algorithm could not have chosen b1=2).

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;

int a[200000];
int main() {
    int i,j;
    int t,n,c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&c);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);
        if (c >= 0) {
            sort(a,a+n);
            for (i = 0; i < n; i++) printf("%d%c",a[i],(i == n-1) ? 'n':' ');
            continue;
        }

        sort(a,a+n,greater<int>());
        for (i = 0; i < n; i++) {
            for (j = n-1; j > i; j--) {
                LLI diff = -abs(a[j]-a[j-1]-c);
                if (j < n-1) {
                    diff -= abs(a[j+1]-a[j]-c);
                    diff += abs(a[j+1]-a[j-1]-c);
                }
                if (i == 0) diff += abs(a[i]-a[j]-c);
                else {
                    diff -= abs(a[i]-a[i-1]-c);
                    diff += abs(a[i]-a[j]-c);
                    diff += abs(a[j]-a[i-1]-c);
                }
                if (diff == 0) {
                    for (; j > i; j--) swap(a[j],a[j-1]);
                }
            }
        }
        for (i = 0; i < n; i++) printf("%d%c",a[i],(i == n-1) ? 'n':' ');
    }
    return 0;
}
```
### [1844F2 - Перестановка минимальной стоимости (сложная версия)](../problems/F2._Min_Cost_Permutation_(Hard_Version).md)

These hints and solution continue from the solution for the easy version, so please read the solution for the easy version first.

 **Hint 4**We need to optimize the O(n2) greedy with some data structures. There exist solutions with varying levels of data structure implementation depending on how much effort is put into characterizing the answer array. For a short solution, start by simplifying the formula (∗) (in the solution for the easy version) to get a cleaner description.

 **Hint 5**The condition is actually equivalent to (ai−1−ai+1≤|c| or ai−1=ai or ai=ai+1) and (bk−1−ai≤|c|).

 **Hint 6**Maintain a linked list of the unused entries of a and a set of unused entries that satisfy (ai−1−ai+1≤|c| or ai−1=ai or ai=ai+1).

 **Solution (hard version)**
### [1844F2 - Перестановка минимальной стоимости (сложная версия)](../problems/F2._Min_Cost_Permutation_(Hard_Version).md)

Let c<0.

We now simplify condition (∗), which involves considering a few cases depending on the sign of the terms. It turns out that the condition is equivalent to (ai−1−ai+1≤|c| or ai−1=ai or ai=ai+1) and (bk−1−ai≤|c|) (for full details, see the overall proof below).

Sort a in nonincreasing order so that a1≥a2≥⋯≥an. We can simulate the greedy algorithm from the easy version with the help of a linked list of the unused elements of a and a set of ai which satisfy the first part of the condition, (ai−1−ai+1≤|c| or ai−1=ai or ai=ai+1). Here, ai−1 and ai+1 actually refer to the closest unused elements of a, which are ai's left and right pointers in the linked list, respectively. 

Each time, we query the set for its smallest element ai that satisfies ai≥bk−1−|c|. If this element does not exist, then we take ai to be the largest element in the linked list. Then, we set bk:=ai, delete ai from the linked list, and update the set with the left and right elements of ai if they now satisfy the condition.

One small observation is that in the answer b, b1=a1 and bn=an. This may simplify the implementation since it means that some edge cases of (∗) actually don't need to be checked. It is also actually not necessary to check the ai−1=ai or ai=ai+1 condition.

The time complexity is O(nlogn).

 **Proofs**The case n≤2 is trivial. In the following, we only consider the case c<0 and n≥3. The case c≥0 follows by symmetry (reverse the array).

Let c′:=−c to reduce confusion with negative signs, and WLOG let a1≥a2≥⋯≥an.

Instead of considering ∑n−1i=1|bi+1−bi−c|, consider a permutation b that minimizes the *augmented cost* |b1−bn−c|+∑n−1i=1|bi+1−bi−c|. By circular symmetry, WLOG rotate b so that bn=an.

We will perform a sequence of steps to sort b in nonincreasing order without ever increasing the augmented cost. Consider looking at bn−1,bn−2,…,b1 in order, such that when we look at bk, we have the invariant that bk+1≥bk+2≥⋯≥bn=an. If bk≥bk+1, do not do anything. Otherwise, since bk≥an=bn, there exists an index k+1≤i<n such that bi≥bk≥bi+1. Consider deleting bk from the array and reinserting it between index i and i+1. We have the following results:

**Claim 1**: Deleting bk decreases the augmented cost by at least c′.

**Proof**: Let x:=bk−1−bk (or bn−b1 if k=1) and y:=bk+1−bk≥0. We need to check that |x−y−c′|+c′≤|x−c′|+|−y−c′|, which follows from |x−c′|+|−y−c′|=|x−c′|+y+c′≥|x−y−c′|+c′ (we use the triangle inequality in the last step).

Note that equality holds if and only if x−c′≤0, i.e. bk−1−bk≤c′.

**Claim 2**: Reinserting bk increases the augmented cost by at most c′.

**Proof**: Let x:=bi−bk≥0 and y:=bk−bi+1≥0. We need to check that |x−c′|+|y−c′|≤|x+y−c′|+c′. Consider four cases:

 * If x,y≥c′, then |x−c′|+|y−c′|=x+y−2c′<(x+y−c′)+c′=|x+y−c′|+c′.
* If x≥c′,y≤c′, then |x−c′|+|y−c′|=x−y≤(x+y−c′)+c′=|x+y−c′|+c′.
* If x≤c′,y≥c′, then |x−c′|+|y−c′|=y−x≤(x+y−c′)+c′=|x+y−c′|+c′.
* If x,y≤c′, then |x−c′|+|y−c′|=2c′−x−y=(c′−x−y)+c′≤|x+y−c′|+c′.

Note that equality holds if and only if x=0 or y=0 or c′−x−y≥0, i.e. bi−bi+1≤c′ or bi=bk or bk=bi+1.

Therefore, each step does not increase the augmented cost. After all the steps, b will be sorted in nonincreasing order. Therefore, the smallest possible augmented cost is |a1−an−c|+∑n−1i=1|ai+1−ai−c|.

Now note that |a1−an−c|=(a1−an)+c′ is the *maximum* possible value of |b1−bn−c|! This means that the minimum cost cannot be less than the minimum augmented cost minus (a1−an)+c′. It follows that the minimum cost is obtained by sorting a in nonincreasing order, and furthermore, *any* optimal permutation b satisfies b1=a1 and bn=an.

Furthermore, suppose we have fixed b1,…,bk and also bn=an. By a similar argument (looking at bn−1,…,bk+1 and reinserting them to the right), one optimal permutation bk+1,…,bn of the remaining elements is to sort them in nonincreasing order. Our greedy algorithm can only reach states where the optimal remaining permutation satisfies bn=an, so it is correct.

Note that condition (∗) is similar to equality being achieved in both claim 1 and claim 2. It follows that (∗) is equivalent to (ai−1−ai+1≤|c| or ai−1=ai or ai=ai+1) and (bk−1−ai≤|c|) as claimed.

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair

int a[200000],b[200000],l[200000],r[200000];
set<pii> S;
int main() {
    int i;
    int t,n,c;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&c);
        for (i = 0; i < n; i++) scanf("%d",&a[i]);
        if (c >= 0) {
            sort(a,a+n);
            for (i = 0; i < n; i++) printf("%d%c",a[i],(i == n-1) ? 'n':' ');
            continue;
        }

        sort(a,a+n,greater<int>());
        b[0] = a[0];
        for (i = 0; i < n; i++) l[i] = (i+n-1) % n,r[i] = (i+1) % n;
        for (i = 2; i < n-1; i++) {
            if (a[l[i]]-a[r[i]] <= -c) S.insert(mp(a[i],i));
        }
        for (i = 1; i < n; i++) {
            int u;
            auto it = S.lower_bound(mp(b[i-1]+c,0));
            if (it == S.end()) u = r[0];
            else u = it->second,S.erase(it);
            b[i] = a[u];
            int x = l[u],y = r[u];
            r[x] = y,l[y] = x;
            S.erase(mp(a[x],x)),S.erase(mp(a[y],y));
            if ((x != 0) && (l[x] != 0) && (r[x] != 0) && (a[l[x]]-a[r[x]] <= -c)) S.insert(mp(a[x],x));
            if ((y != 0) && (l[y] != 0) && (r[y] != 0) && (a[l[y]]-a[r[y]] <= -c)) S.insert(mp(a[y],y));
        }
        for (i = 0; i < n; i++) printf("%d%c",b[i],(i == n-1) ? 'n':' ');
    }
    return 0;
}
```
### [1844G - Дерево с весами](../problems/G._Tree_Weights.md)

 **Hint 1**Model the problem as a system of linear equations. 

 **Hint 2**Let xu be the sum of the weights of the edges on the path from node 1 to node u. The equations are of the form xi+xi+1−2xlca(i,i+1)=di.

 **Hint 3**The intended solution does not do anything like attempt to maintain paths/virtual trees of known weight. One easily overlooked detail that is essential to the solution is that xi are integers.

 **Hint 4**Solve the equations modulo 2 first, so that the 2xlca(i,i+1) term disappears.

 **Hint 5**After solving the equations modulo 2, we can similarly solve modulo 4, 8, etc.

 **Solution**
### [1844G - Дерево с весами](../problems/G._Tree_Weights.md "Codeforces Round 884 (Div. 1 + Div. 2)")

Let xu be the sum of the weights of the edges on the path from node 1 to node u. We know that x1=0 and xi+xi+1−2xlca(i,i+1)=di for all 1≤i≤n−1. This is a system of n linear equations in n variables.

As xu should be integers, let's first solve this system modulo 2. The 2xlca(i,i+1) term disappears, so we just have xi+1≡di−xi(mod2). Starting from x1≡0(mod2), this uniquely determines x2(mod2), then x3(mod2), and so on.

Now that we know x1,…,xn(mod2), write xu=2x′u+bu where bu is the first bit of xu. We can rewrite our system of equations as

(2x′i+bi)+(2x′i+1+bi+1)−2(2x′lca(i,i+1)+blca(i,i+1))=di ⟺x′i+x′i+1−2x′lca(i,i+1)=12(di−bi−bi+1+2blca(i,i+1))

which has the same form as the original system. Thus we can repeat this process to find x′u(mod2) (giving xu(mod4)), then xu(mod8), and so on. Note that each bit of xu is uniquely determined.

If a solution exists, it satisfies 0≤xu≤n⋅maxdi≤1017 for all u, so it suffices to repeat this process until we have found the first 57 bits of xu. Finally, we check that these 57 bits correspond to a valid solution where all the original weights are positive.

The time complexity is O(n(logn+logmaxdi)), if the lca(i,i+1) are precomputed.

Remark: This idea is related to the method of [Hensel Lifting](https://codeforces.com/https://brilliant.org/wiki/hensels-lemma/).

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;
typedef vector<pair<int,int> > vpii;
#define mp make_pair
#define pb push_back

vpii adjList[100000];
LLI d[100000];
int parent[100000][17],parenti[100000],depth[100000];
int doDFS(int u,int p,int d) {
    parent[u][0] = p,depth[u] = d;
    for (auto [v,i]: adjList[u]) {
        if (v != p) parenti[v] = i,doDFS(v,u,d+1);
    }
    return 0;
}
int logn;
int lca(int u,int v) {
    int i;
    if (depth[u] < depth[v]) swap(u,v);
    for (i = logn-1; i >= 0; i--) {
        if ((parent[u][i] != -1) && (depth[parent[u][i]] >= depth[v])) u = parent[u][i];
    }
    if (u == v) return u;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
    }
    return parent[u][0];
}
int lcas[100000],bit[100000];
LLI ans[100000],w[100000];
int main() {
    int i;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(mp(v,i));
        adjList[v].pb(mp(u,i));
    }
    for (i = 0; i < n-1; i++) scanf("%lld",&d[i]);

    int j;
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    logn = i;
    for (i = 0; i < n-1; i++) lcas[i] = lca(i,i+1);

    for (i = 0; i < 57; i++) {
        bit[0] = 0;
        for (j = 0; j < n-1; j++) bit[j+1] = bit[j]^(d[j] & 1);
        for (j = 0; j < n-1; j++) d[j] = (d[j]-bit[j]-bit[j+1]+2*bit[lcas[j]])/2;
        for (j = 0; j < n; j++) ans[j] |= ((LLI) bit[j] << i);
    }
    for (i = 0; i < n-1; i++) {
        if (d[i] != 0) {
            printf("-1n");
            return 0;
        }
    }
    for (i = 1; i < n; i++) {
        w[parenti[i]] = ans[i]-ans[parent[i][0]];
        if (w[parenti[i]] <= 0) {
            printf("-1n");
            return 0;
        }
    }
    for (i = 0; i < n-1; i++) printf("%lldn",w[i]);

    return 0;
}
```
### [1844H - Циклы, кратные трём](../problems/H._Multiple_of_Three_Cycles.md)

 **Hint 1**The partially formed permutation is composed of several paths and cycles. Only the length of each path/cycle modulo 3 matters.

 **Hint 2**The problem reduces to the following: Given a 1s, b 2s, and c 0s, how many ways are there to build a permutation on these objects so that each cycle sums to a multiple of 3? Let f(a,b,c) be the answer. Write some dynamic programming recurrences for f(a,b,c).

 **Hint 3**Note that f(a,b,c)=(a+b+c)f(a,b,c−1) (choose the next object of any 0 and merge them). 

 **Why is this useful?**This allows us to eliminate the c parameter, multiplying the answer by a factorial and inverse factorial.

 **Hint 4**Let f(a,b)=f(a,b,0). Write down not one, but two recurrence relations f(a,b) satisfies.

 **What are the recurrences?**We have f(a,b)=b(a+b−1)f(a−1,b−1)+(a−1)f(a−2,b+1) when a>0 (choose the next object of any 1 and merge them) and also f(a,b)=a(a+b−1)f(a−1,b−1)+(b−1)f(a+1,b−2) when b>0 (choose the next object of any 2 and merge them).

 **Hint 5**These recurrences mean that given any two of f(a,b),f(a−1,b−1),f(a+2,b−1),f(a−1,b+2), we can solve for the other two.

 **Hint 6**Consider the pairs (a,b) that arise from the n queries. These pairs can be visualized as a walk in the plane, where each each pair does not differ from the previous pair by much. If we carefully use the recurrences to solve for values of f(a,b) from values we already know, we can answer all queries on this walk while calculating only O(n) values of f(a,b).

 **Solution**
### [1844H - Циклы, кратные трём](../problems/H._Multiple_of_Three_Cycles.md "Codeforces Round 884 (Div. 1 + Div. 2)")

The partially formed permutation is composed of several paths and cycles, and only the length of each path/cycle modulo 3 matters. We can use a DSU to track the number of paths/cycles of each length (mod3). If at any point a cycle whose length is not ≡0(mod3) is formed, the answer is 0.

Thus, the problem reduces to the following: 

* Given a 1s, b 2s, and c 0s, how many ways are there to build a permutation on these objects so that each cycle sums to a multiple of 3?

Let f(a,b,c) be the answer to this problem. Note that f(a,b,c)=(a+b+c)f(a,b,c−1) for c>0, as there are a+b+c ways to choose the next object of any 0, and after merging this 0 with its next object, there are f(a,b,c−1) ways to build a permutation on the remaining objects. Repeatedly applying this recurrence gives f(a,b,c)=(a+b+c)!(a+b)!f(a,b,0), so we can eliminate the c parameter and multiply the answer by a factorial and inverse factorial in the end.

Now let f(a,b)=f(a,b,0). We have not one, but two recurrence relations f(a,b) satisfies: 

1. f(a,b)=bf(a−1,b−1,1)+(a−1)f(a−2,b+1)=b(a+b−1)f(a−1,b−1)+(a−1)f(a−2,b+1) when a>0 (consider the next object of any 1)
2. f(a,b)=af(a−1,b−1,1)+(b−1)f(a+1,b−2)=a(a+b−1)f(a−1,b−1)+(b−1)f(a+1,b−2) when b>0 (consider the next object of any 2)

The key idea now is that because we have two equations relating the four values f(a,b),f(a−1,b−1),f(a+2,b−1),f(a−1,b+2), given any two of these values, we can solve for the other two. For example, if we know f(a,b) and f(a−1,b−1), we can calculate f(a−2,b+1)=f(a,b)−b(a+b−1)f(a−1,b−1)a−1. Also note that the queried pairs (a,b) can be visualized as a walk in the plane, where each pair does not differ from the previous pair by much. By using these recurrences carefully, it is possible to calculate f(a,b) for all queries (a,b) while calculating only O(n) values of f.

The details can be tricky. The author's solution does the following: First, reverse the order of the updates, possibly adding dummy updates if a cycle whose length is not ≡0(mod3) is created early. Then we need to find f(ai,bi) for a sequence of pairs (a1,b1),(a2,b2),… where (a1,b1)=(0,0) and (ai+1,bi+1) is one of (ai,bi), (ai−1,bi+2), (ai+2,bi−1), or (ai+1,bi+1) for all i. We loop through i in order, maintaining two values u:=f(ai,bi) and v:=f(ai+1,bi+1) at all times. Whenever we need a transition of the form (ai,bi)→(ai−1,bi+2), we use the recurrence f(ai+1,bi+1)=(bi+1)(ai+bi+1)f(ai,bi)+aif(ai−1,bi+2) to solve for f(ai−1,bi+2) (the new value of u), then use the recurrence f(ai,bi+3)=ai(ai+bi+2)f(ai−1,bi+2)+(bi+2)f(ai+1,bi+1) to find f(ai,bi+3) (the new value of v). The (ai,bi)→(ai+2,bi−1) transition is similar. For (ai,bi)→(ai+1,bi+1) transitions, do both of the previous types of transitions once.

The time complexity of the main part of the problem is O(N). The overall time complexity is O(Nα(N)), dominated by the DSU operations.

Remark 1: Since 1s and 2s behave symmetrically, f(a,b,c)=f(b,a,c).

Remark 2: The exponential generating function for f(a,b) is ∑a≥0∑b≥0f(a,b)a!b!xayb=(1−(x3+3xy+y3))−1/3. 

 **Implementation**
```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;
#define MOD 998244353

int parent[300000],siz[300000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int queries[600000][3],ans[600000];
int fact[300000],invfact[300000],invn[300000];
int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int main() {
    int i;
    int n,x,y,bad = 1e9;
    int num[3];
    scanf("%d",&n);
    for (i = 0; i < n; i++) parent[i] = i,siz[i] = 1;
    num[0] = 0,num[1] = n,num[2] = 0;
    for (i = 0; i < n; i++) {
        scanf("%d %d",&x,&y);
        x--,y--;
        if (find(x) != find(y)) {
            num[siz[find(x)] % 3]--;
            num[siz[find(y)] % 3]--;
            siz[find(y)] += siz[find(x)];
            parent[find(x)] = find(y);
            num[siz[find(y)] % 3]++;
        }
        else if ((siz[find(x)] % 3) == 0) num[0]--;
        else if (bad == 1e9) bad = i;
        copy(num,num+3,queries[i]);
    }

    fact[0] = 1;
    for (i = 1; i < n; i++) fact[i] = ((LLI) i*fact[i-1]) % MOD;
    invfact[n-1] = inv(fact[n-1]);
    for (i = n-2; i >= 0; i--) invfact[i] = ((LLI) (i+1)*invfact[i+1]) % MOD;
    for (i = 1; i < n; i++) invn[i] = ((LLI) invfact[i]*fact[i-1]) % MOD;

    int m = n;
    while (num[1]+num[2] > 0) {
        int a = (num[1] > 0) ? 1:2;
        num[a]--;
        int b = (num[1] > 0) ? 1:2;
        num[b]--;
        num[(a+b) % 3]++;
        copy(num,num+3,queries[m++]);
    }
    x = 1,y = 1;
    int u = 1,v = 8;
    auto f = [&]() {
        assert(x > 0);
        int nu = (((v-(((LLI) (y+1)*(x+y+1)) % MOD)*u) % MOD)*invn[x]) % MOD;
        int nv = ((((LLI) x*(x+y+2)) % MOD)*nu+(LLI) (y+2)*v) % MOD;
        x--,y += 2,u = nu,v = nv;
        if (u < 0) u += MOD;
        if (v < 0) v += MOD;
    };
    auto g = [&]() {
        assert(y > 0);
        int nu = (((v-(((LLI) (x+1)*(x+y+1)) % MOD)*u) % MOD)*invn[y]) % MOD;
        int nv = ((((LLI) y*(x+y+2)) % MOD)*nu+(LLI) (x+2)*v) % MOD;
        x += 2,y--,u = nu,v = nv;
        if (u < 0) u += MOD;
        if (v < 0) v += MOD;
    };
    for (i = m-1; i >= 0; i--) {
        int a = queries[i][1],b = queries[i][2],c = queries[i][0];
        if ((a == 0) && (b == 0)) ans[i] = 1;
        else if ((a == x) && (b == y)) ans[i] = u;
        else if ((a == x-1) && (b == y+2)) f(),ans[i] = u;
        else if ((a == x+2) && (b == y-1)) g(),ans[i] = u;
        else if ((a == x+1) && (b == y+1)) {
            if (x > 0) f(),g(),ans[i] = u;
            else g(),f(),ans[i] = u;
        }
        else assert(0);
        ans[i] = ((LLI) ans[i]*fact[a+b+c]) % MOD;
        ans[i] = ((LLI) ans[i]*invfact[a+b]) % MOD;
    }
    for (i = 0; i < n; i++) printf("%dn",(i >= bad) ? 0:ans[i]);

    return 0;
}
```
