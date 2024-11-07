# Tutorial_2_(ru)

Tutorial is loading...Jury solution: [54047380](https://codeforces.com/contest/1159/submission/54047380 "Submission 54047380 by isaf27") 

Tutorial is loading... Jury solution: [54047416](https://codeforces.com/contest/1159/submission/54047416 "Submission 54047416 by isaf27") Tutorial is loading... Jury solution: [54047456](https://codeforces.com/contest/1158/submission/54047456 "Submission 54047456 by isaf27") Tutorial is loading... Jury solution: [54047487](https://codeforces.com/contest/1158/submission/54047487 "Submission 54047487 by isaf27") 
### [1159E - Permutation recovery](https://codeforces.com/contest/1159/problem/E "Codeforces Round 559 (Div. 2)")

Note that if there are indices $i < j$ for which the values $next_i$ and $next_j$ are defined and $i < j < next_i < next_j$ are satisfied, then there is no answer. Suppose that this is not true and there exists permutation $p_1, p_2, \ldots, p_n$. Note that since $j < next_i$ we get that $p_i > p_j$ (otherwise $next_i$ would not be the minimum position in which the number is greater than $p_i$). But then $p_j < p_i < p_{next_i}$, so $next_j$ is not the minimum position for $j$. Contradiction.

Now we prove that if for any pair of indices $i < j$ such condition is not satisfied, then the permutation always exists.

First, let's get rid of $next_i = -1$. If $next_i = -1$ let's say $next_i = i + 1$. Note that for any pair $i < j$ the condition $i < j < next_i < next_j$ is still not satisfied (since $next_i = i + 1$ cannot take part in such inequality).

Consider the following rooted tree with $n + 1$ vertices: the vertex with index $n + 1$ will be the root, and the ancestor of the vertex with index $i$ will be $next_i$. Since it is always $i < next_i$ we get the rooted tree. 

Let's run the depth first search algorithm ($dfs$) from the vertex $n + 1$ in this tree. In this case, we will bypass the sons of each vertex in order from the smaller number to the larger one. Let's make some global variable $timer = n + 1$. Each time we come to the vertex $i$, we will make $p_i = timer$ and reduce $timer$ by $1$. Note that $p_1, p_2, \ldots, p_n$ will form a permutation of numbers from $1$ to $n$.

We prove that this permutation is the answer.

First of all, for all $i$ due to $next_i$ was the ancestor of $i$, we'll go there early and so $p_{next_i} > p_i$. Let $i < j < next_i$. We need to prove that we will come to the vertex $j$ later than to the vertex $i$. Note that then the vertex $next_i$ will be a descendant of $j$ in the tree, because if you start go from $j$ by $next$, you cannot jump over $next_i$, because otherwise there is an index $x$, for which the inequality $i < x < next_i < next_x$ is satisfied. But such pair of indexes $i$, $x$ cannot exist. We'll get to $j$ later because the son of $next_i$, which is the ancestor of $j$ will be $\geq j$, and thus $> i$. 

That is, we understood what is the criterion of the answer and learned how to quickly build an answer, if this criterion is satisfied. But we still need to check that this criterion is satisfied. This can be done by some simple linear algorithm. But we will do this: let's make an algorithm for constructing the answer (without checking the criterion) and find the permutation $p$. Now, using the stack and the standard algorithm, we find the $next_i$ values for it. If they match the given $next_i$, then we have found the answer, otherwise, let's say that there is no answer. If the criterion is satisfied we will find the answer and if not satisfied after checking $p$ we will say there are no answers.

Complexity: $O(n)$ time and memory.

 Jury solution: [54047513](https://codeforces.com/contest/1158/submission/54047513 "Submission 54047513 by isaf27") Tutorial is loading... Jury solution: [54047561](https://codeforces.com/contest/1158/submission/54047561 "Submission 54047561 by isaf27") Tutorial is loading... Jury solution: [54047626](https://codeforces.com/contest/1158/submission/54047626 "Submission 54047626 by isaf27") Tutorial is loading... Jury solution: [54047665](https://codeforces.com/contest/1158/submission/54047665 "Submission 54047665 by isaf27")