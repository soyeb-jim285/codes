# Tutorial


### [1104A - Splitting into digits](../problems/A._Splitting_into_digits.md "Codeforces Round 534 (Div. 2)")

It was a joke :). Let's split number nn to nn digits, equal to 11. Their sum is nn and the number of different digits is 11. So, it can be found as the answer.

Author: [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

 
### [1104B - Game with string](../problems/B._Game_with_string.md "Codeforces Round 534 (Div. 2)")

It can be shown that the answer does not depend on the order of deletions. Let's remove letters from left to right, storing a stack of letters, remaining in the left. When we process a letter, it will be deleted together with the last letter in the stack if they are equal or will be pushed to the stack. Let's calculate parity of the number of deletions during this process and determine the answer.

Author: [300iq](https://codeforces.com/profile/300iq "Grandmaster 300iq")

Statements and editorial: [scanhex](https://codeforces.com/profile/scanhex "Grandmaster scanhex")

 
### [1104C - Grid game](https://codeforces.com/contest/1104/problem/C "Codeforces Round 534 (Div. 2)")

One possible solution is to place vertical tiles into lower-left corner and place horizontal tiles into upper-right corner.If some tile comes, but there is already a tile of the same type, than we will place the new tile into upper-left corner. So both tiles will be cleared and only them.

Author: [scanhex](https://codeforces.com/profile/scanhex "Grandmaster scanhex")

[Solution](https://codeforces.com/contest/1103/submission/48800045)

 
### [1104D - Game with modulo](https://codeforces.com/contest/1104/problem/D "Codeforces Round 534 (Div. 2)")

Let's ask this pairs of numbers: (0,1),(1,2),(2,4),(4,8),…,(229,230)(0,1),(1,2),(2,4),(4,8),…,(229,230). Let's find the first pair in this list with the answer "x". This pair exists and it will happen for the first pair (l0,r0)(l0,r0), that satisfy the inequality l0<a≤r0l0<a≤r0. We can simply find this pair using ≤30≤30 or ≤31≤31 questions.

Now we have a pair of numbers (l0,r0)(l0,r0), such that l0<a≤r0l0<a≤r0. Let's note, that r0<2⋅ar0<2⋅a, because it was the first such pair in the list. Now if we ask pair (l0,x)(l0,x) for some l0<x≤r0l0<x≤r0 we will get the answer "y", if x<ax<a and the answer "x" otherwise. So let's do the binary search in the segment [l0+1,r0][l0+1,r0], asking the question (l0,x)(l0,x) and moving the borders of binary search according to this. Here we will use ≤29≤29 questions.

So we have a solution asked ≤59≤59 questions.

Author: [isaf27](https://codeforces.com/profile/isaf27 "International Grandmaster isaf27")

 
### [1104E - Johnny Solving](https://codeforces.com/contest/1104/problem/E "Codeforces Round 534 (Div. 2)")

Let's build a dfs spanning tree from the vertex 11 and find the depth of the tree. If the depth is at least nknk then we can just print the path from the root to the deepest vertex.

Otherwise, there will be at least kk leaves in the tree. Let's prove it. Consider a tree with cc leaves, after that consider a path from a particular leaf to the root, let's denote length of ii-th path (in vertices) by xixi. We can say that x1+…+xc≥nx1+…+xc≥n, because every particular vertex in the tree will be covered by one of pathways. So, using Dirichlet's principle we can say that max(x1,…,xc)≥ncmax(x1,…,xc)≥nc. Hence, depth of the tree is at least ncnc.

Now, consider a leaf in our spanning tree, let's denote it like vv. This leaf has at least 2 back edges (edges which connected with one of ancestors), let's denote ancestors like xx and yy. Obviosly, we have three cycles here: path from xx to vv with corresponding back edge, the same cycle from yy to vv, and path between xx and yy with two back edges connected with vv. Lengths of these cycles are d(v,x)+1d(v,x)+1, d(v,y)+1d(v,y)+1 and d(x,y)+2d(x,y)+2, where d(a,b)d(a,b) - distance between vertices a and b. It's clear that one of these numbers is not divisible by three. Last problem is to choose representative - we should choose leaves. Size of output is not exceed 106106 because the depth of our tree at most nknk and each cycle has length O(nk)O(nk).

Author: [altruist](https://codeforces.com/profile/altruist "Master altruist")

 
### [1103D - Professional layer](https://codeforces.com/contest/1103/problem/D "Codeforces Round 534 (Div. 1)")

We supposed this as the author solution:

Let's find gcdgcd and factorize it. gcd=pα11⋅…⋅pαmmgcd=pα11⋅…⋅pαmm, where pipi ii-th prime number in factorization (pi<pi+1pi<pi+1) and αi>0αi>0 — number of occurrences of this prime. It's clear, that m≤11m≤11 in our constraints, because ai≤1012ai≤1012. Obviously, that in optimal answer is always best to divide set of our primes in subsets and distribute these subsets between array numbers and divide each number aiai by product of all primes (with aiai powers) in corresponding subset. 

Also clear, that we are interested in only vector of powers of primes of gcdgcd, other primes in a factorization of aiai we can ignore, but we need to be cautious about costs, so, we can left the cheapest mm numbers with the same prime-vector. After this compression we will left at most M=12000M=12000 numbers. We can get this estimation by this point: maximum numbers after compression we can reach if all primes are small as possible and αi=1αi=1 for all ii. Hence, we have at most 1111 possibilities and can easily brute all of them. Also, after compression, let's calculate vector best(mask)best(mask) - best mm numbers by cost to cover set of primes corresponding to maskmask. We can do it easily in O(M⋅2m⋅m)O(M⋅2m⋅m).

Now let's fix a partition of our set of primes into subsets. Well known, that the number of partitions is equal to BmBm, where BiBi — ii-th Bell number. Now, we want to update the current answer. We need to do it by value x⋅yx⋅y, where xx is number of subsets in the partition (we already know it) and yy is minimum cost to distribute our subsets between array numbers. Let's consider all indices ii for subset maskmask which we can match with this maskmask by constraint "divisor is at most k". We will get the bipartite graph with weighted right part (part with indices) and our purpose is to find perfect matching with minimal cost of used vertices in the right part. We can solve this problem with Kuhn algorithm greedily — we can sort right part in not ascending order and do all iterations in this order. It's correct, because we can consider transversal matroid with elements in right part and apply greed Rado-Edmonds theorem. Now we need just to figure out, that we can build this graph using precalced best(mask)best(mask), because we are interested only in at most mm best indices for the particular vertex in the left part. So, we will have graph with O(x2)O(x2) edges and O(x)O(x) size of the left part. Kuhn algorithm will be work in O(x3)O(x3) (even we do the algorithm in right part with size O(x2)O(x2)) if we clear usedused array carefully — only after increasing of the current matching. Summing up x3x3 over all partitions of 1111 elements we will get ∼108∼108 operations.

P. S. Solutions that were passed by participants during the contest used same ideas about the compression. But instead of minimal matching we will use dynamic programming approach. Let's denote dp(mask,i)dp(mask,i) - minimal cost to correctly cover set of primes corresponding to maskmask using exactly ii divisions. To calculate it let's precalc best′(i)best′(i) (inversion of best(mask)best(mask)) — mm masks for which ii-th number of the array is one of mm best. Using this helped data we can calculate our dp(mask,i)dp(mask,i). For this, we can iterate over all numbers and try to update all states where we can use our best′(i)best′(i) masks. It will be work in O(m2⋅3m)O(m2⋅3m) and all algorithm will be work in O(M⋅2m⋅m+m2⋅3m)O(M⋅2m⋅m+m2⋅3m)

Author: [altruist](https://codeforces.com/profile/altruist "Master altruist")

 
### [1103E - Radix sum](https://codeforces.com/contest/1103/problem/E "Codeforces Round 534 (Div. 1)")

After reading the problem statement, it is pretty clear that you should apply something like Hadamard transform, but inner transform should have size ten instead of two. There is no 1010-th root of one modulo 258258 (except 55-th and 22-th roots), so it is not possible to solve the problem just calculating all values modulo 258258. 

The main idea is that you should calculate all values in a polynomial ring modulo x10−1x10−1 (in this ring identity x10=1x10=1 holds, so xx is the one's 1010-th root).

Now the problem is there is no modular inverse of 105105, so we apply the trick. Let's just use unsigned long long, and in the end we will divide the answer by 5555 (it is invertible, because it is relatively prime to 2), and then we simply divide the answer by 2525 with integer division, it can be easily shown that the result will be correct. It is worth noting that after inverse transform you should eliminate monomes larger than x4x4 by applying the identity x4−x3+x2−x1+x0=0x4−x3+x2−x1+x0=0 (modulo x10−1x10−1). After that only the coefficient with x0x0 remains, and this will be the answer.

Author: [scanhex](https://codeforces.com/profile/scanhex "Grandmaster scanhex")

[Solution 1](https://codeforces.com/contest/1103/submission/48799976)

[Solution 2](https://codeforces.com/contest/1103/submission/48799935)

