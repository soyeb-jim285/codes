# Tutorial

**Update: editorial for G is out**

 
### [1220A - Cards](../problems/A._Cards.md "Codeforces Round 586 (Div. 1 + Div. 2)")

It's easy to see that letter zz contains only in zerozero and nn contains only in oneone, so we should print 11 count(n)count(n) times and then 00 count(z)count(z) times.

 Tutorial is loading... 
### [1220C - Substring Game in the Lesson](../problems/C._Substring_Game_in_the_Lesson.md "Codeforces Round 586 (Div. 1 + Div. 2)")

The main idea of this task is that Mike never moves. Lets fix $k$, there two cases:

1) $s[k] \ge s[i]$ for all $i < k$, in this case $s[k, k] \le s[l, r]$ for all $l \le k$ и $r \ge k$, so Ann can't make her first move (Mike wins).

2) There is $i < k$ such that $s[i] < s[k]$. In this case Ann can move with substring $s[i, r]$. If we choose the least possible $i < k$ such that $s[i]$ is minimal, we will deprive Misha of the opportunity to make a move (Ann wins)

Final solution: for all $k$ we should check whether $s[k]$ is the least on substring $s[0, k]$. It can be done with one for in wich we should maintain a minimum on prefix. Complexity $O(|s|)$.

 
### [1220D - Alex and Julian](../problems/D._Alex_and_Julian.md "Codeforces Round 586 (Div. 1 + Div. 2)")

Let all numbers in B be odd. If two vertices i and j are connected, then they have different parity, hence our graph is already bipartite (first part is even vertices, second – odd vertices).

Now let's see that if we choose an integer k>0, multiply all elements of the set by 2k and build a new graph on this set, our new graph will also be bipartite. Proof: consider k-th bit. An edge connects only vertices with different k-th bit, so partition is clear.

So, we found out that if all elements in B have equal power of 2 in their factorization, then this set builds a bipartite graph. What about other cases? Let a,b∈B. They form a cycle with len=lcm(a,b)a+lcm(a,b)b=agcd(a,b)+bgcd(a,b). It's easy to see that len is odd iff a and b contain different powers of 2 in their factorization, so we just proved that there is no other cases.

Finally, the solution is to find maximum power of 2 that divides Bi for all 1≤i≤n, find the largest subset B′ with equal power of 2 and drop B∖B′. Complexity O(nlogmaxB).

 
### [1220E - Tourism](../problems/E._Tourism.md "Codeforces Round 586 (Div. 1 + Div. 2)")

Let's note that if you visit a vertex $u$ located on a loop, you can always add the numbers on vertices in this loop to answer and you can also add the numbers on vertices between $u$ and $s$. It is true because you can just visit $u$, go through the vertices of the cycle, return to $u$ and then go back to $s$. But if from the given vertex we can't get to the cycle, then we can't return back. So the problem is to choose the best branch leading only to the leaves. And from this point there are several solutions for this problem. Let's discuss one of them:

Let $e_u$ be the maximum extra value we could get, if we are in $u$ and we want to go only to leaves. First of all just put all the leaves except $s$ in stack or queue. Then we choose the next vertex $u$ from our queue and look at its parent $v$. Let's decrease $v$'s degree and update $e_v = \max(e_v, e_u + w_u)$. If $v$'s deegre became $1$, it means that $v$ is the leave now, so let's push it in our queue, if it isn't $s$. It looks like at each step, we just erase one leave from our graph and recompute $e$ value for its parent.

At the end, we considered all vertexes which are not belong to the cycles and not belong to the pathes from $s$ to one of the cycles. So we need to sum up the biggest $e_u$ with the sum of all $w_v$, where $v$ wasn't considered during our leaves removing.

There are also solutions that build edge-connectivity components and compute the value using DP on tree.

 Tutorial is loading... Tutorial is loading...