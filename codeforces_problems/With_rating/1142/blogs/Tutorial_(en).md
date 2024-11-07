# Tutorial_(en)


### [1143A - The Doors](https://codeforces.com/contest/1143/problem/A "Codeforces Round 549 (Div. 2)")

Let's walk through the array and find for each exit the door, that was opened last. Then the answer is minimum of the numbers of these doors.

Authors: [grphil](https://codeforces.com/profile/grphil "Master grphil") and [vekarpov](https://codeforces.com/profile/vekarpov "Expert vekarpov")

 
### [1143B - Nirvana](https://codeforces.com/contest/1143/problem/B "Codeforces Round 549 (Div. 2)")

Let number $x$ be an answer, and $\overline{y_0 y_1 \ldots y_l}$ - number from input, so $x$ = $\overline{y_0 y_1 \ldots y_k (y_{k + 1} - 1) 9 9 \ldots 9}$ for some $k$ (otherwise, you can increase one of the digits by $1$, so that $x$ will still be no more than $y$). So, let's go through $k$ from $0$ to the length of $y$ and return the maximum of them by the product of digits.

Author: [MikeMirzayanov](https://codeforces.com/profile/MikeMirzayanov "Headquarters, MikeMirzayanov")

 
### [1143C - Queen](https://codeforces.com/contest/1143/problem/C "Codeforces Round 549 (Div. 2)")

From the condition about the fact that each vertex equally respects all its ancestors, we can understand that each vertex is either always a candidate for deletion or it can never be deleted. That is because when we delete some vertex all new vertices which become sons of it's parent are also disrespecting it.

Now we can iterate over all vertices and if it respects it's parent, we will remember that it's parent can not be deleted. And so we will get the answer.

Authors: [grphil](https://codeforces.com/profile/grphil "Master grphil") and [vekarpov](https://codeforces.com/profile/vekarpov "Expert vekarpov")

 
### [1142A - The Beatles](../problems/A._The_Beatles.md "Codeforces Round 549 (Div. 1)")

Let's assume that we know the length of the jump, and it is equal to $l$. Then, in order to be back at the starting point, Sergey will need to make exactly $n \cdot k / gcd(n \cdot k, l)$ moves, where $gcd$ is the greatest common divider. 

Let $l = kx + c$, where $c$ and $x$ are non-negative integers. So, if we know $a$ and $b$, than $c$ can only take $4$ values: $((a + b) \% c, (a - b) \% c, (b - a) \% c, (-a - b) \% c)$, where $\% c$ means modulo $c$. It is clear that only $x <n$ can be considered. Then we iterate over all the $ 4n $ variants of the pair $(x, c)$, and for each we find the number of moves to the starting point. The minimum and maximum of the resulting numbers will be the answer.

Authors: [grphil](https://codeforces.com/profile/grphil "Master grphil") and [vekarpov](https://codeforces.com/profile/vekarpov "Expert vekarpov")

 
### [1142B - Lynyrd Skynyrd](../problems/B._Lynyrd_Skynyrd.md "Codeforces Round 549 (Div. 1)")

For each $a_i$ if the number $a_i$ has position $j$ in $p$, let's find the greatest $l$, such that $l$ is less then $i$ and $a_l = p_{j - 1}$ (let's define $p_0 = p_n$) We will call this position $b_i$. This can be done in $O(n)$ time, just for each $p_j$ we will keep the last it's position in $a$ while iterating over $a$.

Now let's notice that using this info for each $i$ we can find the beginning of right most subsequence of $a$ which is a ciclic shift of $p$ and ends exactly at $a_i$. This can easily be done because if there is a subsequence of $a$ $a_{i_1}, a_{i_2} \ldots, a_{i_{n - 1}}, a_i$, which is the right most such subsequence, then ${i_{n - 1}}$ is $b_i$, $i_{n- 2}$ is $b_{i_{n - 1}}$, and so on. So to find such subsequence and the position of it's beginning, we need to calculate $b[b[b \ldots b[i] \ldots ]]$ $n - 1$ times. To do it we can use binary lifting. Then we will have $O(m \log n)$ precalc and we will get the beginning of such subsequence in $O(\log n)$ time. 

Now for each prefix of $a$ let's calculate the the beginning of right most subsequence of it, which is a cyclic shift of $p$. This can be calculated in linear time, first we look at the answer for this prefix without the last number, and then update it with the right most subsequence, which ends at the end of prefix. 

Now we can answer each query in $O(1)$ time, because we just need to find the beginning of the right most subsequence, which ends at prefix of length $r$ and compare it with $l$.

Author: [qoo2p5](https://codeforces.com/profile/qoo2p5 "Grandmaster qoo2p5")

 
### [1142C - U2](../problems/C._U2.md "Codeforces Round 549 (Div. 1)")

Let's rewrite parabola equation $y = x^2 + bx + c$ as $y - x^2 = bx + c$. This means, that if you change each point $(x_i, y_i)$ to $(x_i, y_i - x_i^2)$, then the parabolas will turn into straight lines, and the task will be reduced to constructing a top part of convex hull on the obtained points and calculate the number of segments on it.

Authors: [grphil](https://codeforces.com/profile/grphil "Master grphil") and [vekarpov](https://codeforces.com/profile/vekarpov "Expert vekarpov")

 
### [1142D - Foreigner](../problems/D._Foreigner.md "Codeforces Round 549 (Div. 1)")

Let's take any inadequate number $x$ of length $n$. Let's keep 3 parameters for it: $a_x$ which is the number of all inadequate numbers less of equal then $x$, $b_x$ which is the number of inadequate numbers less then $x$ which have length $n$ and $c_x$ which is the number of inadequate numbers grater then $x$ which have length $n$. We know that there are exactly $a_x$ modulo 11 inadequate numbers that come from $x$ by adding a new digit to the end. Also, because we know $b_x$ and $c_x$, we can find $a$, $b$ and $c$ parameters for each of those numbers. Let's now notice, that if instead of keeping $a$, $b$ and $c$ parameters we can keep all of them modulo 11. The parameters of all numbers that come from $x$ will still be defined because if we increase $a$ by 11, these parameters will be the same modulo 11, if we increase $b$ by 11, $a$ and $b$ parameters of all numbers that come from $x$ are increase by $0 + 1 + 2 + \ldots + 10 = (11 \cdot 10) / 2 = 55$ which is 0 modulo 11. The same is with $c$ parameter. So these 3 parameters modulo 11 exactly define what new numbers will come from $x$ and the values of these 3 parameters for them. Now we can create some kind of automaton of size $11^3$, where we will have 9 starting nodes and all paths from these nodes will be the inadequate numbers and for any inadequate number there will be path which will define it. Now let's create dynamic $dp[i][j]$, which is how long we can go into the automaton by the characters of suffix of length $i$ of our given string $s$ starting from node $j$ in automaton. We can calculate this $dp$ in $n \cdot 11^3$ time and using it we can check for each suffix of $s$ what is its longest prefix that is an inadequate number and so we can solve the problem.

Actually, during the contest it turned out that this problem has shorter solution, but this is more general one which doesn't depend on the starting numbers (in our case they were $1, 2, 3, \ldots 9$).

Authors: [grphil](https://codeforces.com/profile/grphil "Master grphil"), [qoo2p5](https://codeforces.com/profile/qoo2p5 "Grandmaster qoo2p5"), [super_azbuka](https://codeforces.com/profile/super_azbuka "Candidate Master super_azbuka")

 
### [1142E - Pink Floyd](../problems/E._Pink_Floyd.md "Codeforces Round 549 (Div. 1)")

First let's assume that graph has only the green edges and we still don't know their directions. Then we can do the following. We will keep some node which we will call the "top node" and the list of the nodes, that can be reached from the top node. Let's take some node $A$ which is not reachable and ask about the direction of edge between the top node and $A$. If the edge goes from top node to $A$, then we can add $A$ to the list of reachable nodes and the size of the list will increase by one. If the edge goes from $A$ to the top node, then we can call $A$ the new top node, and as the old top node was reachable from $A$, the list of reachable nodes will remain the same, but the node $A$ is reachable from itself, so it also will be added to the list. This way after each query we will increase the number of reachable nodes and in $n - 1$ query we will get the answer.

In our graph we have edges that are coloured in pink, so if we will repeat the described above algorithm, we may get that the edge between top node and $A$ is coloured in pink. To avoid it, let's create the condensation of pink graph (condensation means the graph of the strongly connected components (later SCC)). As it is a condensation, there always should be some SCCs, that have no incoming edges. Let's call them free SCCs. We will pick some free SCC and pick some node from it and make it top node. Now we will repeat the following: if there are no other free SCC except the one, that contains the top node, all others are reachable from the only free SCC, which means that we have solved the problem. If there is any other top SCC, let's pick some node $A$ from it. Because this SCC has no incoming edges, the edge between $A$ and top node is green. So we can repeat the algorithm described above. After that as the node $A$ is reachable by green color, we can assume that this node is deleted. If it was the last node in it's SCC, we delete this SCC as well and delete all outcoming edges from it. Now some more SCCs may become free. And then we repeat our algorithm. After at most $n-1$ steps all nodes will be reachable from top one by single coloured path, which means that we have solved the problem.

In out algorithm we need first to create condensation of the graph, which can be done in $O(n + m)$ time, then we need to remember how many nodes are in each SCC and keep a set of all free SCCs. That can also be done in $O(n + m)$ time.

Author: [grphil](https://codeforces.com/profile/grphil "Master grphil")

