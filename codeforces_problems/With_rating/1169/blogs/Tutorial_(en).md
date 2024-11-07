# Tutorial_(en)


### [1169A - Circle Metro](../problems/A._Circle_Metro.md "Codeforces Round 562 (Div. 2)")

Straightforward simulation. Check the intended solutions:

* [Simulation](https://codeforces.com/https://pastebin.com/UwggLUZK)
 
### [1169B - Pairs](../problems/B._Pairs.md "Codeforces Round 562 (Div. 2)")

One of $x,y$ is obviously one of $a_1, b_1$. For example, let's fix who is $x$ from the first pair. Then you need to check that there exists some $y$ such that all pairs that don't contain $x$, contain $y$. For this, you can remember in the array for each value how many pairs that don't contain $x$ contain this value, and then you need to check that in the array there exists some value that is equal to the number of pairs left.

[This solution](https://codeforces.com/https://pastebin.com/KPM3yBCa)

 
### [1169C - Increasing by Modulo](https://codeforces.com/contest/1169/problem/C "Codeforces Round 562 (Div. 2)")

Let's check that the answer to the problem is $\leq x$.

Then, for each element, you have some interval (interval on the "circle" of remainders modulo $m$) of values, that it can be equal to.

So you need to check that you can pick in each interval some point, to make all these values non-decrease.

You can do it with greedy! Each time, let's take the smallest element from the interval, that is at least the previously chosen value.

And after this, let's make the binary search on $x$.

So we have the solution in $O(n \log m)$.

[This solution](https://codeforces.com/https://pastebin.com/dDf2JKNd)

 
### [1169D - Good Triple](https://codeforces.com/contest/1169/problem/D "Codeforces Round 562 (Div. 2)")

Lemma: there are no strings without such $x,k$ of length at least 9.

In fact, you just can write brute force to find all "good" strings and then realize that they all are small.

Ok, so with this you can just write some sort of "naive" solution, for each $l$ find the largest $r$, such that $l \ldots r$ is a "good" string, and then add $n - r$ to the answer. You can do it in $9 \cdot 9 \cdot n$ or in $9 \cdot n$, as I do in my solution. [Check it out!](https://codeforces.com/https://pastebin.com/ZJA8Y8Z5)

 
### [1169E - And Reachability](https://codeforces.com/contest/1169/problem/E "Codeforces Round 562 (Div. 2)")

Let's calculate $go_{i, k}$ — the smallest $j$, such that $a_j$ contains bit $k$, which is reachable from $i$.

How to recalculate it? Let $last_{i,k}$ is the smallest $j > i$, such that $a_j$ contains bit $k$.

Then, I claim that $go_{i,k}$ is equal to the $i$ or to the $\min{(go_{last_{i,j},k})}$ for all bits $j$ that $a_i$ contains. 

Why? Because if you go from $i$ to some number, which has bit $j$ in the intersection, it is useless to go to the number which is not equal to $last_{i,j}$, because from $last_{i,j}$ you can go to all numbers that have bit $j$ and that positioned farther.

So in $O(n \log )$ you can calculate all these values, and then to answer the query you can check that there exists some bit $j$ in $a_y$ such that $go_{x, j} \leq y$.

[This solution](https://codeforces.com/https://pastebin.com/QbQa3x4V)

 
### [1168D - Anagram Paths](https://codeforces.com/contest/1168/problem/D "Codeforces Round 562 (Div. 1)")

Ok, let's make some useless (ha-ha, in fact not) observation at first, obviously, all leaves must have the same depth.

Now, I will define the criterion for the tree to be good.

Let $f(v,x)$ be the largest number of characters $x$ that contained on edges of some path from vertex $v$ to the leaf, and $len_v$ be the length of a path from $v$ to the leaf.

Lemma: tree is good iff for each vertex $\sum{f(v,x)} \leq len_v$.

Obviously, if the tree is good $\sum{f(v,x)} \leq len_v$ for each vertex because else you just don't have enough "space" in the subtree of the vertex to contain all required characters.

Why is it criterion? If for each vertex it is satisfied, from the root you can find some suitable characters on the edges from it, and then it is easy to see that you can restore the children by induction.

Ok, with this knowledge how to solve the problem? Maybe some spooky tree data structures will help us?... 

Yup, you can do it with the "Dynamic tree DP technique" with HLD, and you will get the solution in $O(n \log^2 n)$ even for not a binary tree.

But it is not very easy to realize it :)

Let's remember that all leaves must have the same depth, so I will give you another Lemma!

Lemma: if you will "compress" all vertices with one son in the tree, where all leaves have an equal depth, then the depth of this tree will be $O(\sqrt{n})$.

Why? let $a_i$ be the number of vertices on the depth $i$, then $a_i \geq a_{i-1}$ for each $i \leq h$ as each vertex at the depth $i-1$ should have at least one son, and you have $\sum{a_i}=n$, so there are $O( \sqrt{n})$ distinct values among them, so almost all (without some $O(\sqrt{n})$ values) $i$ has $a_i = a_{i-1}$ (which means that all vertices at the depth $i-1$ has exactly one son).

So with this knowledge, you can "compress" the tree as I described, and after each query just go up from the end of the changed edge and recalculate the DP. Of course, each edge now will have several characters on it, so you should maintain a counter in each edge, but it is more a realization aspect.

[Finally, here is the solution](https://codeforces.com/https://pastebin.com/5bwnF7En)

 
### [1168E - Xor Permutations](https://codeforces.com/contest/1168/problem/E "Codeforces Round 562 (Div. 1)")

If xor of all elements of the array is not zero, then the answer is "Fou".

Now let's assume that you have two permutations $p,q$ and when xored they are producing an array $a$.

I will show that it is possible to change any two elements $a_i, a_j$ to elements $a_i \oplus x, a_j \oplus x$ with some transformation of the given permutations. 

Let's change $a_i, a_j$ to $a_i \oplus x, a_j \oplus x$.

Let's find such $t$, that $a_i \oplus q_i = p_t$.

If $t$ is equal to $i$ or $i+1$, then you can make some swaps to "fix" the array, to make it satisfy $a_i = p_i \oplus q_i$ for all $i$.

Now you have:

* $p_t, q_t, a_t$ at position $t$
* $p_i, q_i, a_i$ at position $i$
* $p_j, q_j, a_j$ at position $j$

Let's make some swaps at these positions to transform it to:

* $p_i, q_j, a_t$ at position $t$
* $p_t, q_i, a_i$ at position $i$
* $p_j, q_t, a_j$ at position $j$

Now, after you make these transition, you will have $p_i \oplus q_i = a_i$, and now you need to "fix" positions $t$ and $j$, and just process recursively.

Lemma: this thing will end in $O(n)$ operations.

______________________________________________________________________________________

Proof: Let's assume that at some two moments you have $p_t$ coincided with some $p_t$ earlier, let's check the first that moment.

For simplicity of the proof, let's assume that numbers are moving like that:

* $p_t, q_i, a_i$ at position $t$
* $p_i, q_j, a_t$ at position $i$
* $p_j, q_t, a_j$ at position $j$

(So $p_i$'s are constant, and $a_i$'s are changing now. Obviously, it is equivalent to the previous transformation)

Now, assume, that you had numbers:

* $p_t, q_t, a_t$ at position $t$
* $p_i, q_x, a_y$ at position $i$ (1)
* $p_j, q_y, a_j$ at position $j$ (2)

and then, you will make one transformation, and everything will go to:

* $p_t, q_x, a_y$ at position $t$
* $p_i, q_y, a_t$ at position $i$
* $p_j, q_t, a_j$ at position $j$

After that, before you will be stuck into described earlier equality:

* $p_t, q_x, a_y$ at position $t$
* $p_i, q_v, a_u$ at position $i$
* $p_j, q_u, a_j$ at position $j$

And after swapping with $t$

* $p_i, q_u, a_y$ at position $i$ (3)
* $p_j, q_x, a_j$ at position $j$ (4)

Let's look at (1), (2) and (3), (4)

From (1), (2), we can see $q_y = p_i \oplus q_x \oplus a_y \oplus p_j \oplus a_j$

From (3), (4), we can see $q_u = p_i \oplus a_y \oplus p_j \oplus q_x \oplus a_j$

So $q_y = q_u$, but $u \neq y$, so it is a contradiction, because $q$ is a permutation.. _________________________________________________________________________________

Ok, using these operations it is pretty simple to get an arbitrary array. Just start with $0,0,\ldots,0$ (two equal permutations). And then make $a_i = b_i, a_{i+1} = a_{i+1} \oplus (a_i \oplus b_i)$, at the end you will have one element rest and it will be good because initially xor was zero.

[My solution.](https://codeforces.com/https://pastebin.com/S310JdDa)

