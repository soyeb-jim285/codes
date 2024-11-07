# Tutorial_(en)

**Problem A**
### [1375A - Sign Flipping](../problems/A._Sign_Flipping.md "Codeforces Global Round 9")

Notice that $a_{i + 1} - a_i \ge 0$ is equivalent to $a_{i + 1} \ge a_i$. Similarly $a_{i + 1} - a_i \le 0$ is equivalent to $a_{i + 1} \le a_i$. Flip the signs in such a way that $a_i \ge 0$ for odd $i$, while $a_i \le 0$ for even $i$. Then

* $a_{i + 1} \ge 0 \ge a_i$, and thus $a_{i + 1} \ge a_i$, for $i = 2, 4, \dots, n - 1$.
* $a_{i + 1} \le 0 \le a_i$, and thus $a_{i + 1} \le a_i$, for $i = 1, 3, \dots, n - 2$.

Giving at least $\frac{n - 1}{2}$ of each, as desired.

Problem A authors — [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o"), [Ari](https://codeforces.com/profile/Ari "International Master Ari")

 **Problem B**
### [1375B - Neighbor Grid](../problems/B._Neighbor_Grid.md "Codeforces Global Round 9")

For every cell $(i, j)$ let's denote by $n_{i, j}$ the number of neighbors it has (either zero or non-zero, it doesn't matter). Then for each cell, it must hold that $a_{i, j} \le n_{i, j}$, otherwise, no solution exists because it is impossible to decrease $a_{i, j}$.

Let's now suppose that $a_{i, j} \le n_{i, j}$ for all cells $(i, j)$. Then a solution always exists: We can increase each $a_{i, j}$ to make it equal to $n_{i, j}$. This always works because every number will be non-zero, so every neighbor of every cell will be non-zero, and every cell has a value equal to its number of neighbors.

Problem B author — [Ari](https://codeforces.com/profile/Ari "International Master Ari")

 **Problem C**
### [1375C - Element Extermination](../problems/C._Element_Extermination.md "Codeforces Global Round 9")

The answer is YES iff $a_1 < a_n$. Let's find out why.

When $a_1 < a_n$, we can repeatedly use this algorithm while the permutation contains more than one element: 

1. Find the smallest index $r$ such that $a_1 < a_r$.
2. Choose $a_r$ and the element comes right before $a_r$ and delete the element before $a_r$.
3. Repeat step 2 until $a_r$ is adjacent to $a_1$.
4. Choose $a_1$ and $a_r$, and delete $a_r$.

 This algorithm is valid because since $r$ is the smallest index such that $a_1 < a_r$, every element between $a_1$ and $a_r$ is less than $a_1$ and therefore less than $a_r$, so all of them can be deleted when pairing up with $a_r$.When $a_1 > a_n$, we have some observations: 

1. The leftmost element is non-decreasing. That is because if we want to remove the old leftmost element $a_1$, we need to pair it with $a_2 > a_1$, and that will result in the leftmost element increasing.
2. Likewise, we can use the same argument to show that the rightmost element is non-increasing.

 Therefore, the leftmost and rightmost elements can never pair up, hence our permutation cannot be reduced to one element.Problem C author — [Kuroni](https://codeforces.com/profile/Kuroni "International Grandmaster Kuroni")

 **Problem D**
### [1375D - Replace by MEX](../problems/D._Replace_by_MEX.md "Codeforces Global Round 9")

(We consider the array $0$-indexed)

Instead of trying to reach any non-decreasing array, we will try to reach precisely $[0, 1, \ldots, n-1]$.

Let's call any index $i$ such that $a_i \neq i$ an unfixed point. We will repeat the following procedure in order to remove all unfixed points:

1. If $\text{mex} = n$, we apply an operation on any unfixed point.
2. Now that $\text{mex} < n$, we apply an operation on index $\text{mex}$ (which was an unfixed point, since $\text{mex}$ was not present in the array).

Each turn uses at most $2$ operations, and decrease the number of unfixed points by exactly $1$. Since there are at most $n$ unfixed points initially, we use at most $2n$ operations.

It was not necessary under the given constraints, but one can notice that if $\text{mex} = n$, the current array is a permutation, and that solving a cycle will take $\text{size} + 1$ operations. Hence, the described algorithm use in fact at most $1.5n$ operations, the worst case being $[1, 0, 3, 2, 5, 4, \ldots]$ when there are a lot of $2$-cycles.

Since the constraint on $n$ is low, we can recompute naively the $\text{mex}$ each time in $\mathcal{O}(n)$, leading to an $\mathcal{O}(n^2)$ final time complexity.

Problem D author — [hugopm](https://codeforces.com/profile/hugopm "International Grandmaster hugopm")

 **Problem E**
### [1375E - Inversion SwapSort](../problems/E._Inversion_SwapSort.md "Codeforces Global Round 9")

We can prove that the answer always exists. Let's first solve the problem for a permutation of length $n$.

Let's define $pos_i (1 \le i \le n)$ as the index of $i$ in the permutation.

First we are going to use all the pairs whose second element is $n$. Let's define the resulting permutation that we get, after using all these pairs in some order, as $b$. We want $b$ to satisfy all of these conditions. 

* $b_n=n$
* If $a_i>a_j$ then $b_i>b_j$ ($1 \le i<j \le n-1$)
* If $a_i<a_j$ then $b_i<b_j$ ($1 \le i<j \le n-1$)

 We can achieve this if we use the pairs in the order $(pos_{a_{n}+1},n),(pos_{a_{n}+2},n),...,(pos_{n},n)$. It can be easily seen that after doing this $a_n+k$ $(0 \le k \le n-a_n-1)$ in the resulting permutation will have the same position that $a_n+k+1$ had in the starting permutation. So basically after doing operations in this order we are decreasing all the values in the starting permutation that are greater than $a_n$ by 1 and we make the last element equal to $n$. It can be easily proven that this permutation satisfies the conditions listed above. After this we can remove the last element and solve the problem for the remaining part of the permutation (which is a permutation itself because the last element was $n$). This way all the pairs of inversions that are in the new permutation coincide with the unused pairs written on the paper.So we solved the problem for a permutation, how can we approach the general problem? For every $i>j, a_i=a_j$ we can assume that $a_i>a_j$, and this won't change anything because the order of equal elements doesn't matter and we are not adding any inversions by assuming this. So after doing this we can easily squeeze the numbers into a permutation and solve the problem for a permutation.

Total complexity $O(n^2logn)$ or $O(n^2)$.

Problem E author — [enoone](https://codeforces.com/profile/enoone "Master enoone")

 **Problem F**
### [1375F - Integer Game](../problems/F._Integer_Game.md "Codeforces Global Round 9")

Let's prove that the first player can always win in at most three turns. Assume that the initial numbers of stones are $p < q < r$. On the first turn, choose $y = 2r - p - q$. We then have three cases:

Case 1.  $y$ is added to $p$.

The piles now have $2r - q$, $q$ and $r$ stones. Now choose $y = r - q$. Since the pile with $2r - q$ stones cannot be chosen on this turn, this results in a win.

Case 2.  $y$ is added to $q$.

The piles now have $p$, $2r - p$ and $r$ stones. Choose $y = r - p$. Similarly to the previous case this results in a win since the pile with $2r - p$ stones cannot be chosen on this turn.

Case 3.  $y$ is added to $r$.

The piles have $p < q < 3r - p - q$ stones. We now have a situation similar to the initial one, with the difference that the pile with the largest number of stones cannot be chosen on the next turn. Thus we may repeat the strategy and obtain a guaranteed win this time.

Problem F author — [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")

 **Problem G**
### [1375G - Tree Modification](../problems/G._Tree_Modification.md "Codeforces Global Round 9")

The solution is based on the following observation: Every tree is a bipartite graph, i. e. its vertices can be colored black or white in such a way that every white vertex is adjacent only to black vertices and vice versa. Notice that a tree is a star if and only if one of the colors appears exactly once.

Let's fix a bipartite coloring of the tree and look at what happens when we apply the operation to vertices $a$, $b$, and $c$. For concreteness, let's suppose that $b$ is black, so $a$ and $c$ must be white. When we perform the operation:

* Every neighbor of $a$ other than $b$ is black. After connecting it to $c$ it remains black since $c$ is white.
* After connecting $a$ to $c$ it must switch from being white to being black since $c$ is white.
* Every other vertex is unaffected by the operation.

Thus every operation changes the color of exactly one vertex! Suppose that initially there are $b$ black vertices and $w$ white vertices. Then we need at least $\min(w, b) - 1$ operations to turn the tree into a star since one of the colors must end up having a single vertex. This is always achievable: as long as there are at least two vertices with a certain color we can choose two which are adjacent to a common neighbor and use the operation to recolor one of them.

The values of $w$ and $b$ can be found through a simple DFS, leading to an $O(n)$ solution.

Problem G author — [antontrygubO_o](https://codeforces.com/profile/antontrygubO_o "Grandmaster antontrygubO_o")

 **Problem H**
### [1375H - Set Merging](../problems/H._Set_Merging.md "Codeforces Global Round 9")

First, two sets $a$ and $b$ can be merged if and only if the range of elements in $a$ do not intersect with the range of elements in $b$. It is obvious because if they intersect, neither $g(a)<f(b)$ nor $g(b)<f(a)$ are satisfied. If they do not intersect, there must be one of them satisfied.

Notice that $2\times n\sqrt{q}$ is near to $2.2\times 10^6$, this hints us to use sqrt-decomposition.

We separate the numbers $1,2,\cdots,n$ into $\dfrac{n}{S}$ consecutive blocks, each of size $S$.

Consider a block $B_i=[l,r]$, we take all elements in the original permutation that satisfy $l\leq a_i \leq r$, and form a new sequence that preserves the original order.

For example, if the permutation $9,8,2,1,5,6,3,7,4$ is divided into $3$ blocks $B_1=[1,3],B_2=[4,6],B_3=[7,9]$, their sequences will be $2,1,3$ and $5,6,4$ and $9,8,7$.

Consider any consecutive subsequence in the permutation. We want to construct a set that just contains all elements in it. We can first divide this subsequence into $\dfrac{n}S$ subsequences in each block that contains only elements in this block and merge them up.

For example, if we want the subsequence $8,2,1,5,6,3,7$ in the permutation above, then we can divide it into $2,1,3$ and $5,6$ and $8,7$. 

Notice that those subsequences in each block are also consecutive subsequences. Also, notice that since the range of elements in each block do not intersect, the range of elements in these subsequences also do not intersect. This means that if we can somehow construct the set that equals the set of each of those subsequences, we can just merge those subsequences of each block to form the original subsequence that we want to obtain in $\dfrac{n}S-1$ merges.

Thus the process of constructing sets in total costs less that $\dfrac{qn}S$ merges.

Now we have to construct the subsequences of each block, notice that the subsequences are consecutive, thus we can just construct sets of all of those $\dfrac12S(S+1)$ consecutive subsequences.

Consider divide and conquer. We can divide a sequence in to two parts of equal size, construct subsequences of them, and try to merge them to obtain the new sets. So how do we split and merge?

Consider two sequences, that elements in the first sequence is less than elements in the second, and we have already constructed the sets of all the consecutive subsequences in each of those sequences. Now we consider a sequence that contains the union of the elements in the two subsequences. All elements in sequences here are ordered according to the order in the original permutation. Now we want to construct all the consecutive subsequences in the new sequence. Consider for each consecutive subsequence in the new sequence, it must be composed by two parts, the ones present in the first sequence, and the one present in the second. It is obvious that each part is also a consecutive subsequence in the respective sequence, thus the sets representing them is already constructed. Because the two sequence do not intersect in range of elements, we can just merge those two sets to form the new one.

For example, we want to obtain all subsequences of the sequence $1,4,3,2,6,5$, and we have already obtained the ones of $1,3,2$ and $4,6,5$.

So if we want to get the consecutive subsequence $1,4,3,2,6$, we first divide it into $1,3,2$ and $4,6$. Because the sets of them are already constructed(they are consecutive subsequences of $1,3,2$ and $4,6,5$), and their range of elements do not intersect, we can merge it in one operation.

Other consecutive subsequences can also be obtained similarly.

Thus there are $\dfrac12S(S+1)$ subsequences, and less than $\dfrac12S(S-1)$ need a merge operation (because those with only one element in it need no operation).

We use $f(S)$ to denote the number of operation needed to construct all consecutive subsequences of a block of length $S$

There is $f(1)=0$ and $f(x)\leq \dfrac12x^2+f(\lfloor x/2\rfloor)+f(\lceil x/2\rceil)$,(if we divide a subsequence evenly),it can be proved that $f(x)\leq x^2$

So, we need $\dfrac{n}S\times S^2$ operations to construct all consecutive subsequences.

So in total, $nS+\dfrac{nq}S$ operations are needed. According to the mean inequality, there is $nS+\dfrac{nq}S\geq 2\sqrt{n^2q}=2n\sqrt{q}$, and if $S=\sqrt{q}$, $nS+\dfrac{nq}S=2\sqrt{n^2q}=2n\sqrt{q}$

And, $2n\sqrt{q}\leq 2^{21}< 2.2\times 10^6$, thus the restriction is satisfied.

Also, there exists a solution based on segment-tree.

The main idea is to maintain a segment-tree of $1$ to $n$, in each node, we save a hash-map of sets with elements in the range of that node already constructed.

Anytime we want a new set, we do a query on the segment tree, if the set on that node is constructed, we return it. Otherwise, we split the wanted set into two parts, and query on its sons, and merge them.

The details is omitted due to laziness issue.

And we find that this solution can pass, why?

Suppose $n=2^N$ and $q=2^Q$

We can calculate that we need no more than

$$\sum_{i=0}^n 2^{N-i}\min(2^{2i-1},2^Q) $$

sets. This is because in the $i$th layer(bottom to top) of the segment-tree, there are $2^{N-i}$ nodes, each one can contain no more than $2^i(2^i-1)/2$ sets (the consecutive subsegment limitation). but it is also bounded by $2^Q$ queries, because a query can only visit a node at most once.

Calculating this sum yield a bound lower that the resiriction.

Also we can find that this solution is similar to the previous sol.

We find that

For $i \leq Q/2$,the sum is 

$$\sum_{i=0}^{Q/2} 2^{N-i}2^{2i-1}= \sum_{i=0}^{Q/2} 2^{N+i-1}\leq 2^{N+Q/2} $$

And for $i> Q/2$ the sum is

$$2^Q \sum_{i=Q/2+1}^N 2^{N-i}\leq 2^Q 2^{N-Q/2}=2^{N+Q/2}$$

Summing these two parts yield $2^{N+Q/2+1}$ which is also $2n\sqrt{q}$

So these solutions have the same complexity.

Other than that, we observe that the lower-$Q/2$ layers is just like those blocks constructed in the first solution, only the merging in the upper one is different, the first solution used brute-force, while the second just extended the segment-tree up.

Thus, we say that the first solution is just the second one, but bounded manually. So these two solutions are intrinsically similar.

Problem H authors — [Ynoi](https://codeforces.com/profile/Ynoi "Candidate Master Ynoi"), [dengyaotriangle](https://codeforces.com/profile/dengyaotriangle "Master dengyaotriangle")

 **Problem I**
### [1375I - Cubic Lattice](../problems/I._Cubic_Lattice.md "Codeforces Global Round 9")

$2$-dimensional version of this problem appeared as problem K in [Makoto Soejima Contest 4](https://codeforces.com/gym/100959) from Petrozavodsk Winter Training Camp 2016 (Also known as GP of Asia in OpenCup XVI). Solution for this case is based on the fact that the whole lattice equation may be represented as the product of two Gaussian integers $a_k = \alpha_k \cdot g$, where $g$ is the complex number representing $(\vec r_1, \vec r_2)$ basis. Thus, the solution was to find largest $g$ which divides every point $a_k$. This can be done with Euclidean algorithm.

Similar idea applies to this problem except for rotations in $3$-dimensional case are represented with quaternions rather than complex numbers. You may get some basic notion of quaternions from [this](https://codeforces.com/blog/entry/46744) article. Note that in $3$-dimensional space if integer vectors $\vec r_1$, $\vec r_2$ and $\vec r_3$ are pairwise orthogonal and have the same length, then their length is an integer number as well. This is due to the fact that $\vec r_3$ may be represented explicitly in the following form:

$$\vec r_3 = \pm\frac{\vec r_1 \times \vec r_2}{|r_1|}$$

We should note here that both $\vec r_3$ and $\vec r_1 \times \vec r_2$ have integer coordinates, thus $|r_1|$ is rational. But since $|r_1|^2$ is integer, we may conclude that $|r_1|$ is integer as well. This brings us to the conclusion that vectors $\frac{\vec r_1}{|\vec r_1|}$, $\frac{\vec r_2}{|\vec r_2|}$ and $\frac{\vec r_3}{|\vec r_3|}$ have rational coordinates, thus the transformation which maps basis vectors $\vec e_x$, $\vec e_y$ and $\vec e_z$ into $\vec r_1$, $\vec r_2$ and $\vec r_3$ may be represented as the combination of rational rotation and scaling, that is:

$$\vec v \mapsto k \cdot \frac{q \cdot \vec v \cdot \bar q}{q \cdot \bar q}$$

Here $q = s + ix + jy + kz$ is an integer quaternion representing the rotation, $\bar q = s - ix - jy - kz$ is its conjugate quaternion, and $k=r$ is some integer scaling factor.

If we write this transform explicitly in matrix form, its matrix will be as follows:

$$ \frac{k}{s^2+x^2+y^2+z^2} \cdot \begin{pmatrix} s^2+x^2-y^2-z^2 & 2xy-2sz & 2xz+2sy \\\ 2xy+2sz & s^2-x^2+y^2-z^2 & 2yz-2sx \\\ 2xz-2sy & 2yz+2sx & s^2-x^2-y^2+z^2 \end{pmatrix} $$

Since this transform maps $\vec e_x$, $\vec e_y$ and $\vec e_z$ to integer vectors $\vec r_1$, $\vec r_2$ and $\vec r_3$, all matrix elements should be integer. That is, if we reduce the fraction $\frac{k}{s^2+x^2+y^2+z^2}$, its denominator should divide every matrix element. Without loss of generality we may assume that $\gcd(s,x,y,z)=1$, because otherwise we may simply reduce all quaternion coordinates by this common divisor and matrix elements will stay same. Now if $\frac{k}{s^2+x^2+y^2+z^2}=\frac{P}{Q}$ then $Q$ should divide every element of the matrix and it also should divide $s^2+x^2+y^2+z^2$. Thus, it divides:

$$\gcd\begin{pmatrix} s^2+x^2+y^2+z^2\\\ s^2+x^2-y^2-z^2\\\ s^2-x^2+y^2-z^2\\\ s^2-x^2-y^2+z^2 \end{pmatrix}=\gcd\begin{pmatrix} s^2+x^2+y^2+z^2\\\ 2(y^2+z^2)\\\ 2(x^2+z^2)\\\ 2(x^2+y^2) \end{pmatrix}=\gcd\begin{pmatrix} s^2+x^2+y^2+z^2\\\ 2(y^2+z^2)\\\ 2(x^2+z^2)\\\ 4z^2 \end{pmatrix}$$

Here we utilized the fact that $\gcd(a\pm b, b)=\gcd(a, b)=\gcd(-a,b)$. Next thing to note is that $\gcd(a, b)$ always divides $\gcd(k\cdot a, b)$, thus $Q$ should divide:

$$\gcd\begin{pmatrix} 4(s^2+x^2+y^2+z^2)\\\ 4(y^2+z^2)\\\ 4(x^2+z^2)\\\ 4z^2 \end{pmatrix}=4\gcd(s^2,x^2,y^2,z^2)=4 $$

Which means that every transform we're looking for may be represented in the following form:

$$ \vec v \mapsto \frac{k}{4} \cdot q \cdot \vec v \cdot \bar q $$

Where $q$ is some integer quaternion with $\gcd(s,x,y,z)=1$ and $k$ is some integer scaling factor. Quaternions having all integer components are called Lipschitz quaternions. But in this problem we will need to find greatest common divisor of some quaternions and using Lipschitz quaternions won't be enough for us because they don't form an Euclidean domain. Instead, we'll stick to Hurwitz quaternions in which it's also allowed for quaternion to have all of its coordinates semi-integer. With such quaternions we may further divide quaternion by $2$ if all its components are odd, which will reduce the set of possible denominators to $\{1,2\}$ only, thus in Hurwitz quaternions any transform may be represented as:

$$ \vec v \mapsto \frac{k}{2} \cdot q \cdot \vec v \cdot \bar q $$

Now, given this knowledge, we have to find a Hurwitz quaternion $q$ and scaling factor $k$ such that every point from the set $A$ is the image of some integer vector under this transform. Basically, we assume here that $\vec r_1$, $\vec r_2$ and $\vec r_3$ are images of unit basis vectors $\vec e_x$, $\vec e_y$ and $\vec e_z$. If this is true, then $a_k = u_k \cdot \vec r_1 + v_k \cdot \vec r_2 + w_k \cdot \vec r_3$ is the image of the vector $b_k$ defined as $b_k = u_k \cdot \vec e_x + v_k \cdot \vec e_y + w_k \cdot \vec e_z$.

For simplicity we will further work with vectors $a_i$ multiplied by $2$, as in this way we may safely assume that they were obtained with $v \mapsto k \cdot q \cdot \vec v \cdot \bar q$ mapping. Now we should further work with the quaternion $g=\gcd(a_1,\dots,a_n)$ which is obtained as GCD of input vectors as if they were Hurwitz quaternions and with the number $G=\gcd(\\|a_1\\|,\dots,\\|a_n\\|)$, where $\\|q\\|=q\cdot\bar q = s^2+x^2+y^2+z^2$ is the norm of $q$. Among major properties of quaternionic norm we should note that it's multiplicative, that is $\\|a\cdot b\\| =\\|a\\| \cdot \\|b\\|$. Due to this we may conclude that $\\|k\\|\cdot \\|q\\|^2=k^2 \\|q\\|^2$ should always divide $G$. Thus with the number $G$ fixed there may only be at most $O(G^{1/6})$ possible values of $\\|q\\|$ which may be found in $O(G^{1/3})$ because if $a^2$ divides $b$ then either $a$ or $b/a$ is at most $b^{1/3}$.

In our problem $G$ may only be up to $10^{16}$, which makes it up to nearly $500$ candidate numbers for being equal to $\\|q\\|$ which may be found in $\approx 2.5\cdot 10^5$ arithmetic operations. Now to check if it's possible to obtain $q$ with $\\|q\\|$ being fixed we should look on the quaternion $g$. Under given constraints $g$ is primitive (not divisible by any integer constant larger than $1$). It may be proven thus that if $g$ is primitive and $\\|g\\|=ab$ then $g$ may be uniquely (up to units) represented as $g=qp$ where $\\|q\\|=a$ and $\\|p\\|=b$. Due to this if we fix $\\|q\\|$ we may find actual $q$ as $\gcd(g,\\|q\\|)$ because $q\bar q =\\|q\\|$. After this we only have to check if this $q$ actually produces all points from the input set, which may be done in $O(n)$. Therefore, the total complexity of described solution is $O(G^{1/3}+G^{1/6}n)$.

Problem I author — [adamant](https://codeforces.com/profile/adamant "International Master adamant")

