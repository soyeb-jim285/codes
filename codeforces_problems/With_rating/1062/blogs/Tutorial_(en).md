# Tutorial_(en)


### [1062A - A Prank](../problems/A._A_Prank.md "Codeforces Round 520 (Div. 2)")

Since $1 \le a_i \le 10^3$ for all $i$, let set $a_0=0$ and $a_{n+1}=1001$. For every $i,j$ such that $0 \le i<j \le n+1$, if $a_j-j=a_i-i$ then we can erase all the elements between $i$ and $j$ (not inclusive). So just check for all the valid pairs and maximize the answer. Time complexity: $O(n^2)$.

 
### [1062B - Math](../problems/B._Math.md "Codeforces Round 520 (Div. 2)")

By factorizing $n$ we get $n={p_1}^{a_1}{p_2}^{a_2}\dots{p_k}^{a_k}$ ($k$ is the number of prime factors). Because we can't get rid of those prime factors then the smallest $n$ is ${p_1}{p_2}\dots{p_k}$. For each $a_i$, let $u_i$ be the positive integer so that $2^{u_i} \ge a_i>2^{u_i-1}$. Let $U$ be $max(u_i)$. It's clear that we have to apply the "$sqrt$" operation at least $U$ times, since each time we apply it, $a_i$ is divided by $2$ for all $i$. If for all $i$, $a_i=2^U$ then the answer is $U$, obviously. Otherwise, we need to use the operation "$mul$" $1$ time to make all the $a_i$ equal $2^U$ and by now the answer is $U+1$.

Complexity: $O(sqrt(N))$

 
### [1062C - Banh-mi](../problems/C._Banh-mi.md "Codeforces Round 520 (Div. 2)")

For each part that we choose, we need to calculate how many times that element is added to our score. You can see that, the first element that we choose is added $2^{k-1}$ times in our score ($k=r-l+1$), the second element is added $2^{k-2}$ times and so on. Therefore, we just need to choose all the $1s$ first and then all the remaining parts. The final score is $(2^x-1) \cdot 2^y$, where $x$ is the number of $1s$ and $y$ is the number of $0s$. Complexity: $O(n + Q)$.

 
### [1062D - Fun with Integers](../problems/D._Fun_with_Integers.md "Codeforces Round 520 (Div. 2)")

For every integer $x$ $(1 \le x \le n)$, let's call $D$ the set of integers that are able to be transformed into $x$. As you can see, if $a$ could be transformed into $b$ then $-a$ could also be transformed into $b$. Therefore $|D|$ is always even. Let's build a graph consists of $2n-2$ nodes, numbered $-n$ through $n$ (except for $-1$, $0$, and $1$). There is an weighted undirected edge between node $u$ and $v$ if and only if $u$ can be transformed into $v$. The weight of the edge is the score of the transformation. Every node in the graph has an even degree so you can split the graph into some connected components so that each components is an Euler circuit (a circuit that contains all the edges). Therefore you just need to find all those Euler circuits and maximize your score. Moreover, you can see that, if an integer $a$ can be transformed into $b$ then $x$ and $2$ are in the same component. Proof: Suppose $a<b$, there exists an integer $x=b/a$. If $x=2$ then it is proved, otherwise there exists an integer $c=2x<b \le n$. $c$ and $2$ are in the same component so $x$ and $2$ are also in the same component. Therefore, if we ignore all the nodes that have no edges attached to it, the graph will be connected. So you need to simply get the sum of all the weights of the edges.

The complexity is $O(n + nlog(n))$ since the number of edges can go up to $nlog(n)$.

 
### [1062E - Company](../problems/E._Company.md "Codeforces Round 520 (Div. 2)")

Let's call $in_u$ the time that we reach the node $u$ in depth first search and $out_u=max(in_{v1}, in_{v2}, \cdots, in_{vk})$ where $v_i$ is a child of $u$. If node $u$ is in charge of node $v$ ($u$ is an ancestor of $v$) then $in_u \le in_v \le out_u$. Suppose we don't have to ignore any node then the answer to each query is the LCA of two nodes $u$ and $v$ ($l \le u,v \le r$), where $u$ and $v$ are chosen so that $in_u=max(in_l, in_{l+1}, \dots, in_r)$ and $in_v=min(in_l,in_{l+1}, \dots, in_r)$. Proof: Let $r$ be the LCA of $u$ and $v$, then $in_r \le in_v \le in_u \le out_r$. For every node $w \in [l,r]$, $in_v \le in_w \le in_u \Rightarrow in_r \le in_w \le out_r \Rightarrow r$ is an ancestor of $w$. Therefore, the node that needs to be ignored is either $u$ or $v$. Suppose we ignore $u$, the query splits into two halves $[l,u-1] \cup [u+1,r]$. We find the LCA to each half and get the LCA of them. We do similarly for $v$ and optimize the answer.

Complexity: $O(Nlog(N) + Qlog(N))$.

 
### [1062F - Upgrading Cities](../problems/F._Upgrading_Cities.md "Codeforces Round 520 (Div. 2)")

The main idea of this problem is to calculate $in_u$ and $out_u$ for every node $u$, where $in_u$ denotes the number of nodes that can reach $u$ and $out_u$ denotes the number of nodes that can be reached by $u$. If $in_u+out_u=N+1$ then $u$ is important or $N$ if $u$ is semi-important.

However, it may not possible to calculate $in_u$ and $out_u$ for every node $u$ in given time (please tell me if it's possible) so we have to do some tricks.

First of all, we need to find an arbitrary longest path ($P$)$=s_1 \rightarrow s_2 \rightarrow... \rightarrow s_k$ on the graph ($k$ is the number of nodes on this path). If a node is important then it must lie on this path ($1$). Proof: Assume there is a node $u$ that is important and doesn't lie on ($P$). Let $s_i$ be the rightmost node on ($P$) and can reach $u$. It's true that $i < k$, because if $i=k$ then we have a longer path than the one we found so it's not possible. By definition of $i$, $s_{i+1}$ cannot reach $u$. Therefore $u$ must be able to reach $s_{i+1}$ (because $u$ is important). This leads to a conflict: We have a path that is longer than the one we found: $s_1 \rightarrow s_2 \rightarrow \dots \rightarrow s_i \rightarrow u \rightarrow s_{i+1} \rightarrow \dots \rightarrow s_k$. Therefore statement ($1$) is proved. 

It takes $O(N+M)$ to find ($P$).

Let's deal with important nodes first. Because all important nodes lie on the path ($P$) so it makes no sense to calculate $in$ and $out$ for those nodes that don't belong to ($P$). We can calculate $out$ by iterate through $P$ from $s_k$ to $s_1$. At each node $s_i$, we just need to use bfs or dfs to search for the nodes that can be reached by $s_i$. Because we visit each node $1$ time then it takes $O(N+M)$ to do this. To calculate $in$ we just need to reverse the direction of the edges and do similarly.

Now we need to find the semi nodes. There are two types of semi nodes: those belong to ($P$) and those don't. For the ones belong to ($P$), we just need to check if $in_u+out_u=N$. For the ones don't belong to ($P$), suppose we are dealing with node $u$. Let $s_i$ be the rightmost node on ($P$) that can reach $u$ and $s_j$ be the leftmost node on ($P$) that can be reached by $u$. It's obvious that $i<j-1$. Let $L_u=i$ and $R_u=j$, let $leng$ equal $j-i-1$. If $leng>1$ then u is not a semi node (because we have to delete all nodes between i and j not inclusive), or else we must erase $s_{i+1}$ to make $u$ a semi important node. We can see that the path from $s_i$ to $u$ contains only $s_i$ and $u$, and the path from $u$ to $s_j$ contains only $u$ and $s_j$, because otherwise there exists a longer path than ($P$), which is false. So we consider $u$ as a candidate. Moreover, if exists a node $v$ that is a candidate and $L_u=L_v$ (also leads to $R_u=R_v$) then both $u$ and $v$ are not semi important nodes. Proof: After we delete $s_{i+1}$, for $u$, exists a path that is as long as ($P$) and does not go through $u$ (it goes through $v$) so $u$ is not a important node, based on statement ($1$). Same for $v$. Briefly, at this point we have the path ($P$) and a list of nodes $u_1, u_2, ..., u_t$. For every $i$, $u_i$ is a candidate and $L_{ui}+1=R_{ui}-1$. For every $i$, $j$, $L_{ui}!=L_{uj}$.

So now we are going to calculate $in$ and $out$ for those candidate nodes. We can do this similarly as when we find the important nodes. To calculate $out$, iterate through $s_k$ to $s_1$. At each node $s_i$, bfs or dfs to search for nodes that can be reached by $s_i$. Additionally, if there is a candidate node $v$ that $R_v=i-1$, we start a search from $v$ to find those nodes that can be reached by $v$, we have $out_v=out_{si}+$ the number of nodes we just found. After that we pop those nodes from the stack (or whatever), mark them as not visited and continue to iterate to $s_{i-1}$. To calculate $in$ we reverse the directs of the edges and do the same. Because each node is visited $1$ time by nodes on ($P$) and at most $2$ times by candidate nodes so it takes $O(3(N+M))$.

The total complexity is $O(N+M)$.

Sorry if the tutorial for F is too long.

