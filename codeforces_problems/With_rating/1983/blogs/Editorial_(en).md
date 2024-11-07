# Editorial_(en)

Thank you for participating in our contest! We hope you enjoyed it. 

 **On a personal note (contains spoilers)**This is the first time some of us are problemsetting. I apologise in case some of you did not have a good experience with the contest. I realise B was probably too hard for its position, we had a 2 hour 15 minutes contest and I expected the extra time to compensate for that. I believe some people did not like B being easily guessable. We were actually in a position where we could punish guessers who submit without proof. A lot of testers had submitted the sum over the entire grid modulo 3 to be equal as an initial guess (the samples were weak back then). I added a lot of samples to B (and, for that matter, to C, too) to make the problem easier instead of going the other way and punishing guessers. I really do not know if going the other way would have been appreciated, either.

I really like observation-based problems, like the format we have on CF nowadays. I did not realise all these constructives might cause a bad experience. I've never prepared for math olympiads or related stuff, and it has been CF that introduced me to all these sorts of problems, so I have no idea what would count as math-heavy and what would not.

For D I'm very surprised people managed to guess permutation parity without proving. We wanted to introduce new and uncommon problems, like the usage of permutation parity here would have been for a div2D. D and G are my personal favourites from this round. For G, too, it is possible to solve it without any heavy data structures, just plain observations. 

It had been a complaint in last year's ByteRace round that the problems in the Div1 range were not hard or interesting enough. This time, we did try to ensure that, hopefully. I really like problem G, as said before. Actually, we were planning to have a 3-hour long 8 problem round, but we had to get down to this.

We ended up overlooking some mistakes in the statement of E. I'm sorry about that, too. Many of us preparing the contest have been busy interning, and sometimes it gets hard to manage time.

I believe the observations required for B and D make them really good and unique problems. We just did not put them in ways that would, like, prevent guessing. Are we supposed to? E was one math-heavy problem, is that a lot? I'm genuinely curious, can any experienced problemsetter (and not random greys echoing each other) explain what did not go well with this contest, if anything?

[1983A - Array Divisibility](../problems/A._Array_Divisibility.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

Idea: [BlazingDragon](https://codeforces.com/profile/BlazingDragon "Expert BlazingDragon")  
 Preparation: [Pew_Pew.](https://codeforces.com/profile/Pew_Pew. "Expert Pew_Pew.")  
 Editorial: [Swap-nil](https://codeforces.com/profile/Swap-nil "Expert Swap-nil")

 **Hints****Hint 1**Think simple.

 **Hint 2**If a and b both are divisible by c then, a+b will also be divisible by c. 

 **Solution**
### [1983A - Array Divisibility](../problems/A._Array_Divisibility.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

The construction $a[i] = i$ for all $1 \le i \le n$ satisfies all the required conditions.

 **Implementation (C++)**[269328935](https://codeforces.com/contest/1983/submission/269328935 "Submission 269328935 by Swap-nil")

 **Implementation (Python)**[269329008](https://codeforces.com/contest/1983/submission/269329008 "Submission 269329008 by Swap-nil")

 **Feedback*** [*246*](https://codeforces.com/data/like?action=like "I like this")





 Good problem
* [*121*](https://codeforces.com/data/like?action=like "I like this")




 Average problem
* [*51*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*2*](https://codeforces.com/data/like?action=like "I like this")




 Did not solve
[1983B - Corner Twist](../problems/B._Corner_Twist.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

Idea: [Swap-nil](https://codeforces.com/profile/Swap-nil "Expert Swap-nil")  
 Preparation: [Swap-nil](https://codeforces.com/profile/Swap-nil "Expert Swap-nil")  
 Editorial: [Swap-nil](https://codeforces.com/profile/Swap-nil "Expert Swap-nil")

 **Hint****Hint 1**1+2≡0(mod3).

 **Hint 2**Can you notice something that does not change, an invariant?

 **Solution**
### [1983B - Corner Twist](../problems/B._Corner_Twist.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

Notice how the operations affect each row and column. The problem offers a really simple solution: the sum of each row and each column modulo $3$ needs to remain constant throughout all the operations. It is easy to see that this is a necessary condition. 

Let's prove that this is sufficient as well.

Notice that using the 2x2 versions of the operations defined in the statement, i.e., addition of $\begin{matrix}1 & 2 \\\ 2 & 1\end{matrix}$ or $\begin{matrix}2 & 1 \\\ 1 & 2\end{matrix}$ along the corners of a 2x2 square can be used to generate the same result as the operation applied on any rectangle. For instance, we can combine two 2x2 operations sideways to get a 2x3 operation:

$$\begin{matrix}1 & \fbox{2+1} & 2\\\ 2 & \fbox{1+2} & 1\end{matrix} \equiv \begin{matrix}1 & 0 & 2\\\ 2 & 0 & 1\end{matrix} \pmod{3}$$ Let the grid $a$ and $b$ have $n$ rows and $m$ columns, you can iterate over $i$ thorugh $1\ldots n-1$ and for $i$'s each iteration, $j$ through $1\ldots m-1$. 

* If $a[i][j] + 1 \equiv b[i][j] \pmod{3}$, add $\begin{matrix}1 & 2 \\\ 2 & 1\end{matrix}$ to the subrectange of $a$ starting at $a[i[j]$.
* If $a[i][j] + 2 \equiv b[i][j] \pmod{3}$, add $\begin{matrix}2 & 1 \\\ 1 & 2\end{matrix}$ to the subrectange of $a$ starting at $a[i[j]$.
* Make no changes otherwise.

We see that it is always possible to make all the elements in the first $n-1$ rows and $m-1$ columns equal using this method. 

Note that the sum of each row and each column stays constant after each operation. If $b$ is derived from $a$ using these operations, then all the values for the remaining $n + m - 1$ elements of the grid can be uniquely determined using the row and column sums and need to be equal. Hence, proving sufficiency.

 **Implementation (C++)**[269329137](https://codeforces.com/contest/1983/submission/269329137 "Submission 269329137 by Swap-nil")

 **Implementation (Python)**[269329083](https://codeforces.com/contest/1983/submission/269329083 "Submission 269329083 by Swap-nil")

 **Feedback*** [*254*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*26*](https://codeforces.com/data/like?action=like "I like this")




 Average problem
* [*358*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*52*](https://codeforces.com/data/like?action=like "I like this")




 Did not solve
[1983C - Have Your Cake and Eat It Too](../problems/C._Have_Your_Cake_and_Eat_It_Too.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

Idea: [DC17](https://codeforces.com/profile/DC17 "Candidate Master DC17")  
 Preparation: [Swap-nil](https://codeforces.com/profile/Swap-nil "Expert Swap-nil")  
 Editorial: [BlazingDragon](https://codeforces.com/profile/BlazingDragon "Expert BlazingDragon")

 **Solution**
### [1983C - Have Your Cake and Eat It Too](../problems/C._Have_Your_Cake_and_Eat_It_Too.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

There can be several correct answers. It is sufficient to find any correct answer.

Although it is not necessary to finish the entire cake, we can easily find a way such that the entire cake is given away.

We can start by trying to give a prefix to Alice. To determine if it is possible to divide the cake such that Alice gets at least one-third of the total value by taking a prefix, and Bob and Charlie can split the remaining cake into two parts where each gets at least one-third of the total value, we can use the following approach:

We start by calculating the prefix sums for Alice, Bob, and Charlie. 

Using these prefix sums, we iterate left to right to search for the minimum prefix size for Alice, where she gets at least one-third of the total value. Once we find an index, we give that prefix to Alice and search again on array $b$ to check if we can give a prefix of the remaining cake to Bob such that Bob gets at least one-third of the total sum, and so does Charlie. If, after removing the prefix of the remaining cake, the value left for Charlie is not enough, we repeat the last step on array $c$ instead and check if the value of the cake left for Bob after Alice and Charlie get theirs' is enough.

If the above fails, we repeat the process starting with a prefix of $b$. If that fails too, we try again, beginning with a prefix of $c$. 

Here are the specific steps for each of the 6 permutations of Alice, Bob, and Charlie:

1. Start with a prefix for Alice, then check Bob's prefix and Charlie gets the rest of the cake.

2. Start with a prefix for Alice, then check Charlie's prefix and Bob gets the rest of the cake.

3. Start with a prefix for Bob, then check Alice's prefix and Charlie gets the rest of the cake.

4. Start with a prefix for Bob, then check Charlie's prefix and Alice gets the rest of the cake.

5. Start with a prefix for Charlie, then check Alice's prefix and Bob gets the rest of the cake.

6. Start with a prefix for Charlie, then check Bob's prefix and Alice gets the rest of the cake.

If after trying all permutations, none of them work, the answer is "-1". Otherwise, print the respective indices for the subarrays.

 **Implementation (C++)**[269329204](https://codeforces.com/contest/1983/submission/269329204 "Submission 269329204 by Swap-nil")

 **Implementation (Python)**[269329258](https://codeforces.com/contest/1983/submission/269329258 "Submission 269329258 by Swap-nil")

 **Feedback*** [*143*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*79*](https://codeforces.com/data/like?action=like "I like this")




 Average problem
* [*263*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*13*](https://codeforces.com/data/like?action=like "I like this")




 Did not solve
[1983D - Swap Dilemma](../problems/D._Swap_Dilemma.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

Idea: [MrSavageVS](https://codeforces.com/profile/MrSavageVS "Expert MrSavageVS")  
 Preparation: [MrSavageVS](https://codeforces.com/profile/MrSavageVS "Expert MrSavageVS")  
 Editorial: [MrSavageVS](https://codeforces.com/profile/MrSavageVS "Expert MrSavageVS")

 **Hint****Hint 1**Can we convert this complicated operation to something simpler?

 **Hint 2**We can convert the operation to basically swapping adjacent elements and it still works. Try to prove why?

 **Hint 3**Swapping adjacent elements in a distinct array is basically trying to equate two permutations using adjacent swaps. When is it possible?

 **Hint 4**Inversions in a permutation

 **Solution**
### [1983D - Swap Dilemma](../problems/D._Swap_Dilemma.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

If both the arrays don't have the same multiset of elements then trivially the answer is "NO".

Otherwise, we can convert any operation of the form $l$, $r$, $p$, $q$ to swapping $l$, $l+1$, $p$, $p+1$ multiple times.

For example: swapping $l=1$, $r=3$, $p=2$, $q=4$ can be converted into three steps: swapping $l=1$, $r=2$, $p=2$, $q=3$, then swapping $l=2$, $r=3$, $p=3$, $q=4$ and finally $l=1$, $r=2$, $p=2$, $q=3$.

This can be generalized for any such operation.

An interesting observation here is that swapping any two adjacent elements in a distinct array leads to a change in number of inversions of that array by $1$ — which essentially means the parity of inversions of the array gets changed.

So, if both the arrays don't have the same parity of inversions initially, they will never have the same parity of inversions. 

Now, we will prove that when both arrays have the same parity of inversions, then it is definitely possible to make them equal. Keep using operations for array $a$ of the form $l=1$ and $r=2$ while changing the operation $p, q$ to different values to make the elements at indices $3, 4, \ldots n$ the same in array $b$ as they are in array $a$. Now, since both the arrays should have the same parity of inversions at the end, $a_1 = b_1$ and $a_2 = b_2$, and so, our arrays $a$ and $b$ will become equal.

Therefore, the answer is "YES" in this case.

 **Implementation (C++)**[269303026](https://codeforces.com/contest/1983/submission/269303026 "Submission 269303026 by MrSavageVS")

 **Feedback*** [*294*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*31*](https://codeforces.com/data/like?action=like "I like this")




 Average problem
* [*87*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*32*](https://codeforces.com/data/like?action=like "I like this")




 Did not solve
[1983E - I Love Balls](../problems/E._I_Love_Balls.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

Idea: [DC17](https://codeforces.com/profile/DC17 "Candidate Master DC17")  
 Preparation: [BlazingDragon](https://codeforces.com/profile/BlazingDragon "Expert BlazingDragon")  
 Editorial: [BlazingDragon](https://codeforces.com/profile/BlazingDragon "Expert BlazingDragon")

 **Solution**
### [1983E - I Love Balls](../problems/E._I_Love_Balls.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

When there are no special balls, Alice and Bob alternately pick balls starting with Alice. This means Alice picks ${\frac{n+1}{2}}$ balls if $n$ is odd or $\frac{n}{2}$ if $n$ is even. The total value of all balls is $\sum v_i$. On average, Alice's score is $\lfloor\frac{n + 1}{2}\rfloor \cdot \frac{\sum v_i}{n}$.

With $k$ special balls, the picking order can be interrupted, allowing the same player to pick again. We need to distribute $k$ special balls into $n - k + 1$ possible positions (gaps). The expected number of special balls picked by Alice can be derived as the expected number of gaps encountered by Alice ($\lfloor\frac{n - k + 2}{2}\rfloor$) times the expected number of special balls per gap($\frac{k}{n - k + 1}$). The formula is $\frac{(\lfloor\frac{n - k + 2}{2} \rfloor) \cdot k}{n - k + 1}$.

Expected value without special balls: $\lfloor\frac{n + 1}{2}\rfloor \cdot \frac{\sum v_i}{n}$. 

Expected special balls for Alice: $\frac{(\lfloor\frac{n - k}{2}\rfloor + 1) \cdot k}{n - k + 1}$. 

Expected normal balls for Alice when there are non-zero special balls: $\lfloor\frac{n - k + 1}{2}\rfloor$

Therefore, expected score of Alice: $\frac{(\lfloor\frac{n - k}{2}\rfloor + 1) \cdot k}{n - k + 1} \cdot \frac{\sum_{i \in \{1,2, \cdot \cdot \cdot k\}}{v_i}}{k} + \lfloor\frac{n - k + 1}{2}\rfloor \cdot \frac{\sum_{i \in \{k+1,k+2, \cdot \cdot \cdot n\}}{v_i}}{n - k}$

Similarly, expected score of Bob: $(k - \frac{(\lfloor\frac{n - k}{2}\rfloor + 1) \cdot k}{n - k + 1}) \cdot \frac{\sum_{i \in \{1,2, \cdot \cdot \cdot k\}}{v_i}}{k} + (n - k - \lfloor \frac{n - k + 1}{2} \rfloor) \cdot \frac{\sum_{i \in \{k+1,k+2, \cdot \cdot \cdot n\}}{v_i}}{n - k}$

 **Implementation (C++)**[269329340](https://codeforces.com/contest/1983/submission/269329340 "Submission 269329340 by Swap-nil")

 **Feedback*** [*105*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*15*](https://codeforces.com/data/like?action=like "I like this")




 Average problem
* [*80*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*44*](https://codeforces.com/data/like?action=like "I like this")




 Did not solve
[1983F - array-value](../problems/F._array-value.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

Idea: [TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Candidate Master TimeWarp101")  
 Preparation: [MrSavageVS](https://codeforces.com/profile/MrSavageVS "Expert MrSavageVS")  
 Editorial: [MrSavageVS](https://codeforces.com/profile/MrSavageVS "Expert MrSavageVS")

 **Hint****Hint 1**Can we fix an upper bound to count the number of subarrays having xor-pair less than that?

 **Hint 2**We can use binary search to fix an upper bound and calculate all subarrays with xor-pair less than the given value.

 **Hint 3**In order to count the number of subarrays we can use a popular data-structure used for a lot of xor-operations.

 **Hint 4**We can binary search on the upper bound and use tries to count the number of subarrays with xor-pair less than given value. This way we can find the kth-smallest value.

 **Solution**
### [1983F - array-value](../problems/F._array-value.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

We can binary search on the the value of the $k$th-smallest and maintain the number of subarrays with xor-pair less than the value. This way, we can find the $k$th-smallest value easily.

In order to maintain the number of subarrays, we can use our popular xor data structure called trie. 

For a given binary searched value, we will traverse from left to right, putting in the values of the array in our trie with their highest corresponding indices.

For a fixed index $i$, we would like to find the highest index $j<i$ such that the subarray from $[j,i]$ contains xor-pair less than the fixed upper bound. Then all subarrays with their left end between $[1,j]$ and right end fixed at $i$ will have xor-pair less than the value.

Therefore, this becomes a sliding window where we want to maximize the value of the left end $j$ so that the number of subarrays for a fixed right end $i$ becomes as large as possible.

To achieve this, we would maintain in our trie the following two things: - the current bit (on/off) - the maximum index which reached this bit in our trie

Now when querying: - if both searched bit and current array index bit is $1$: take the max for left index from child "on" bit and go to child "off" bit - if both searched bit and current array index bit is $0$: just go to child "off" bit - if searched bit is $1$ and current array index bit is $0$: take the max for left index from child "off" bit and go to child "on" bit - if searched bit is $0$ and current array index bit is $1$: just go to child "on" bit

This is done so that we can find the maximum left index for the given fixed right index at $i$. We follow binary searched value as closely as possible while traversing the trie to stay under the upper bound as well as maximize the left index.

Finally, putting the values and corresponding index in the trie is trivial. Simply follow the trie and put in the corresponding bits the maximum index which can reach that bit.

This way we can solve this problem in $O(n \log^2 n)$

 **Implementation (C++)**[269305957](https://codeforces.com/contest/1983/submission/269305957 "Submission 269305957 by MrSavageVS")

 **Feedback*** [*64*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*11*](https://codeforces.com/data/like?action=like "I like this")




 Average problem
* [*21*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*35*](https://codeforces.com/data/like?action=like "I like this")




 Did not solve
[1983G - Your Loss](../problems/G._Your_Loss.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

Idea: [AwakeAnay](https://codeforces.com/profile/AwakeAnay "Grandmaster AwakeAnay"),[TimeWarp101](https://codeforces.com/profile/TimeWarp101 "Candidate Master TimeWarp101")  
 Preparation: [ShivanshJ](https://codeforces.com/profile/ShivanshJ "Master ShivanshJ"), [Swap-nil](https://codeforces.com/profile/Swap-nil "Expert Swap-nil"), [Pew_Pew.](https://codeforces.com/profile/Pew_Pew. "Expert Pew_Pew.")  
 Editorial: [Swap-nil](https://codeforces.com/profile/Swap-nil "Expert Swap-nil")

 **Hints****Hint 1**Try looking at the problem bit by bit.

 **Hint 2**What does the contribution of a particular bit over a path look like?

 **Hint 3**Can you think of some simpler queries you can easily solve the problem for?

 **Hint 4**Root the tree.

 **Hint 5**For a query from a node u to its ancestor v, the countribution from the counting term (0,1,2,3,…) changes for the first time at an ancestor at a jump of a power of two. 

 **Hint 6**Let dp[u][k] be the contribution of bit k to the query from u to the root.

 **Hint 7**Keep track of a few additional nodes for each query. Read hint 5 again.

 **Solution**
### [1983G - Your Loss](../problems/G._Your_Loss.md "Codeforces Round 956 (Div. 2) and ByteRace 2024")

We'll solve for each bit separately. Observe that the number of nodes contributing to the sum for a fixed bit $j$ is the sum of the bit xor'ed with an alternating pattern of $2^j$ continuous bits over the path, i.e., say for $j=2$, the bits are xor'ed with $0000111100001\ldots$. For the rest of the editorial, we will use the word "bit pattern" to refer to this binary string.

Let's root the tree arbitrarily and define $dp[u][j]$ as the number of nodes that contribute $2^j$ to the sum required in the query on the path from the node $u$ to the root. Notice that for $dp[u][j]$ the pattern $000\ldots0111\ldots1$ transitions from $0$ to $1$ at the $2^j$th ancestor of $u$. Hence, you can compute $dp[u][j]$ just by knowing the value of the $dp$ at the $2^j$th ancestor and its depth, and the sum of set bits on the remaining path. You can precompute all the power of two ancestors by binary jumping and calculate sums using root-to-node prefix sums.

Now, you need to keep track of a few variables to answer queries. Let there be a query from the node $u$ to the node $v$. We define $lc$ as $lca(u,v)$. 

For a fixed bit $j$, let there be nodes $ux[j],vx[j]$ such that the path from $ux[j]$ to $vx[j]$ is the largest subpath of the path from $u$ to $v$ with $lc$ lying on this path and all the bits from the pattern being the same over this path. Let's call it the central path.

One more position to keep track of is the node $vy[j]$ such that it is the lowest ancestor of $v$ where the length of the path from $u$ to $vy$ is a multiple of $2^j$ and $vy$ lies on the path from $u$ to $v$. It is possible that this node does not exist. Notice that the bit pattern for $dp[vy][j]$ upwards will coincide or will be the exact opposite of the bit pattern for the query up to the node $lc$.

With these values computed, we can split the query path into separate paths; the answer for each can be easily calculated using prefix sums and precomputed $dp$ values:

* The path from $u$ to $ux[j]$.
* The path from $ux[j]$ to $vx[j]$.
* The path from $vx[j]$ to $vy[j]$.
* The path from $vy[j]$ to $v$.

To compute these three positions quickly, we will again use binary jumping, precomputing these for all queries. To compute $vy[j]$, we notice that for $vy[0] = v$. Then, we make binary jumps whenever necessary. For $ux[j]$ and $vx[j]$, we can start iterating from a bit larger than n to the smallest, noting that if $2^j >= n$, the endpoints will be $ux[j]=u$ and $vx[j]=v$. We make binary jumps when necessary, $vy[j]$ is also required for the computation.

Another alternative to binary jumping is to maintain a list of ancestors of the current node while running dfs on the tree and calculate these positions directly during the dfs for each query.

 **Implementation (C++)**[269315826](https://codeforces.com/contest/1983/submission/269315826 "Submission 269315826 by Swap-nil")

 **Feedback*** [*27*](https://codeforces.com/data/like?action=like "I like this")




 Good problem
* [*3*](https://codeforces.com/data/like?action=like "I like this")




 Average problem
* [*20*](https://codeforces.com/data/like?action=like "I like this")




 Bad problem
* [*37*](https://codeforces.com/data/like?action=like "I like this")




 Did not solve
