# T_(en)

(Idea of the problem A — [----------](https://codeforces.com/profile/---------- "Master ----------"))

 
### [1136A - Nastya Is Reading a Book](../problems/A._Nastya_Is_Reading_a_Book.md "Codeforces Round 546 (Div. 2)")

It is easy to understand that the first unread chapter is the last chapter, whom $l_i \leq k$. In order to find it we can iterate through list of chapters in increasing order.

[Code](https://codeforces.com/https://pastebin.com/caetUqwX)

(Idea of the problem B — [IbragiMMamilov](https://codeforces.com/profile/IbragiMMamilov "Expert IbragiMMamilov"))

 
### [1136B - Nastya Is Playing Computer Games](../problems/B._Nastya_Is_Playing_Computer_Games.md "Codeforces Round 546 (Div. 2)")

Note that in any case we will open $n$ hatches. Also, initial position of stones is : $1,1,1,1,1,1 ... 1$ ($1$ - the number of stones on the i-th hatch ).After any permutation of stones we will have permutation of numbers : $2,0,1,1,1,1,1...$ So, to open hatch with $2$ stones, we need at least $2$ movements. So, at all, we need at least $n+1$ movements(1). To get into all the hatches we need at least $min(n-k,k-1) + n-1$ movements.(since we can only go to the neighboring). So, at all, answer is : $(n+1) + n + (n-1) + min(n-k,k-1) = 3n + min(n-k,k-1)$.

[Code](https://codeforces.com/https://pastebin.com/19BUreFe)

(Idea of the problem C — [usertab34](https://codeforces.com/profile/usertab34 "Expert usertab34"))

 
### [1136C - Nastya Is Transposing Matrices](../problems/C._Nastya_Is_Transposing_Matrices.md "Codeforces Round 546 (Div. 2)")

Let's note that after applying the operation multiset of numbers on each diagonal (which goes up and right) stays the same. Also we can get any permutation of numbers on any diagonal because we can swap neighboring elements on diagonal. So, we just need to check if the multisets of numbers on corresponding diagonals are the same.

[Code](https://codeforces.com/https://pastebin.com/mzMFdXrk)

(Idea of the problem D — [Denisson](https://codeforces.com/profile/Denisson "International Grandmaster Denisson"))

 
### [1136D - Nastya Is Buying Lunch](../problems/D._Nastya_Is_Buying_Lunch.md "Codeforces Round 546 (Div. 2)")

Solution 1: Let's solve the proiblem, iterating from the end, adding pupils one by one. I. e for every suffix we are solving original problem without pupils, which don't belong to this suffix. What happens when we add pupil $i$ to the suffix?

By the time when we add pupil $i$ we have answer for the previous suffix. In this answer there are, probably, pupils, which Nastya can't overtake. Let this subset of pupils be $P$. Then, if $i$-th pupil can give place for Nastya and all pupils from $P$, we will swap them. Otherwise, we can add this pupil to $P$. In order to check this condition we can iterate through pupils, who can swap with $i$-th pupil, and calculate how many are contained in $P$. This solution works in $O(n+m)$. Obviously, when we consider all suffixes, answer will be $n-1-|P|$.

Solution 2: Let's build directed graph, where $i$-th vertex corresponds $i$-th pupil and edge from $u$ to $v$ exists if and only if pupil $v$ can't give place to pupil $u$ and $v$ is closer to the beginning of queue than $u$. We can note that answer is number of vertexes in this graph, which are unreachable from Nastya's vertex. Proof:

(1) Obviously, if edge from $u$ to $v$ exists, pupil $v$ will always be in front of $u$.

(2) If vertex $v$ is reachable from vertex $u$, the same condition is true.

Let's prove that Nastya can overtake pupils, who are unreachable in graph by giving an algorithm how to do it. Let there are unreachable vertexes in front of Nastya, $u$ - the closest from them. If $u$ is directly in front of Nastya, they can swap and number of such vertexes will decrease.

Otherwise, let $v$ be the next pupil after $u$ (further from the beginning). Because $u$ is the closest unreachable vertex, $v$ is reachable. So, there is no edge from $u$ to $v$ and they can change their places. We can similarly move $v$ further and then swap him with Nastya.

Using this algorithm, Nastya can overtake all pupils, which correspond unreachable vertexes.

Fine, now we just have to calculate number of such vertexes. It can be done with standard algorithm "DFS by complement graph".

[Code](https://codeforces.com/https://pastebin.com/JGRSfHid)

(Idea of the problem E — [Ralsei](https://codeforces.com/profile/Ralsei "Master Ralsei"))

 
### [1136E - Nastya Hasn't Written a Legend](../problems/E._Nastya_Hasn't_Written_a_Legend.md "Codeforces Round 546 (Div. 2)")

Let $t_{i} = k_{1} + k_{2} + ... + k_{i - 1}$, $b_{i} = a_{i} - t_{i}$.

We can rewrite the condition $a_{i+1} >= a_{i} + k_{i}$, using array $b$:

$a_{i+1} >= a_{i} + k_{i}$ 

$a_{i+1} - k_{i} >= a_{i}$

$a_{i+1} - k_{i} - k_{i-1} - ... - k_{1} >= a_{i} - k_{i-1} - ... - k_{1}$

$a_{i+1} - t_{i+1} >= a_{i} - t_{i}$

$b_{i+1} >= b_{i}$

Let's calculate arrays $t$ and $b$.

So as $a_{i} = b_{i} + t_{i}$, in order to get sum in subarray of $a$, we can sum corresponding sums in $b$ and $t$.

Now let's find out what happens with $b$ after addition $x$ to position $i$. $b_{i}$ increases exactly on $x$. Then, if $b_{i+1} < b_{i}$, $b_{i+1}$ becomes equal to $b_{i}$, and so on for $i+2$, $i+3$, ..., $n$. Note that array $b$ is always sorted and each addition sets value $b_{i} + x$ in half-interval $[i, pos)$, where $pos$ - the lowest index such as $b_{pos} >= b_{i} + x$

To handle these modifications, let's build segment tree on array $b$ with operation "set value on a segment", which stores sum and maximum in every vertex. The only problem is how to find $pos$. This can be done with descending along the segment tree. If the maximum in the left son of current vertex is bigger or equal that $b_{i} + x$, we go to the left son, otherwise we go the right son.

BONUS: solve it with modifications of elements of $k$.

[Code](https://codeforces.com/https://pastebin.com/nGFM2KyW)

