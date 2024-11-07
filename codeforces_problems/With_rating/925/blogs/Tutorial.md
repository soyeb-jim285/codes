# Tutorial


### [967A - Mind the Gap](https://codeforces.com/contest/967/problem/A "Codeforces Round 477 (rated, Div. 2, based on VK Cup 2018 Round 3)")

This problem requires you to carefully read and understand the statement. First, scan all the landing times, transforming each $h$ and $m$ pair into the number of minutes from the starting moment $60h + m$. Then, there are three possibilities:

* The first plane takes of not earlier than $s + 1$ minutes from now. In this case we may put new takeoff right now.
* Otherwise, if there is a pair of planes with at least $2 + 2s$ minutes between them. In this case we may choose the earliest such pair and put a new takeoff at $1 + s$ minutes after the first of these planes.
* Otherwise, we may always put a new plane in $1 + s$ minutes after the last plane.

Finally, print the answer in an $h~m$ format.

 
### [967B - Watering System](https://codeforces.com/contest/967/problem/B "Codeforces Round 477 (rated, Div. 2, based on VK Cup 2018 Round 3)")

It's obvious that we should block several largest holes. Let's first sort them. After that, let's iterate through the number of blocked holes, maintaining the sum of sizes of non-blocked holes $S$. With the value $S$ it is easy to compute if the flow from the first hole is large enough or not. Just output the number of blocked pipes at the first moment when the flow is large enough. The complexity is $O(n)$.

 
### [925A - Stairs and Elevators](../problems/A._Stairs_and_Elevators.md "VK Cup 2018 - Round 3")

First thing to mention is that we can use no more than one stairs or elevator per query. Indeed, optimal path is always a few sections horizontally, then a stair of elevator, then a few sections horizontally.

Then, we can note that we can always use one of the nearest stairs/elevators to start/finish. Using this fact, we can binary search in the sequence of stairs/elevators to find the optimal one, and choose the optimum between using a stairs and an elevator. Don't forget about the case where you don't have to reach any stairs/elevators.

The complexity is $O(q \log{n})$.

 
### [925B - Resource Distribution](../problems/B._Resource_Distribution.md "VK Cup 2018 - Round 3")

Suppose that the load of the first service was divided among $k_1$ servers and the load of the second service was divided among $k_2$ servers. In such case first service will be running on $k_1$ servers of resource at least $p_1 = \lceil x_1 / k_1 \rceil$ and second service will be run on $k_2$ servers of resource at least $p_2 = \lceil x_2 / k_2 \rceil$. 

Suppose that $p_1 \leq p_2$, the remaining case will be dealt in the similar way. Remove all servers that have less than $p_1$ resources, we are not going to use them. We may consider only assignments in which any server assigned to the first service has at most as many resources as any server assigned to the second service (otherwise we may swap them and the answer will still be correct). In such manner we may show that the first service may be assigned to the first $k_1$ servers having at least $p_1$ resource units and the second service may be assigned to the last $k_2$ servers in ascending order of available resources.

Finally notice that if we fix $k_1$, the optimal value of $k_2$ is minimum such that the last $k_2$ servers have at least $p_2$ resource units. Calculate the minimum possible $k_2$ in linear time, after that try each possible value of $k_1$ and check if the first $k_1$ servers having at least $p_1$ resource units do not intersect with the last $k_2$ servers (it may be checked in a single binary search).

We got a solution with running time of $O(n \log n)$.

 
### [925C - Big Secret](../problems/C._Big_Secret.md "VK Cup 2018 - Round 3")

Let's assume that we've found a suitable permutation of all numbers, except all occurences of the number $1$. When can we insert the $1$'s so that the new arrangement of numbers is again good? We can see that the XOR of all numbers before any occurence of the number $1$ must be even, so there should an even number of odd numbers before it.

Suppose that there are $x$ $1$'s in the input, and $y$ odd numbers greater than $1$. If $x > y + 1$, then in any arrangement there is going to be a pair of $1$'s such that there are no odd numbers between them, hence the condition above cannot hold for both of them simultaneously. On the other hand, if $x \leq y + 1$, then it is possible to insert the $1$'s into any permutation of greater numbers. Indeed, we can place one instance of $1$ at the start, and then place remaining $1$'s immediately after greater odd numbers.

Note that this argument works just as well if we consider numbers in the range $[2^k, 2^{k + 1})$ as "$1$'s", and numbers in $[2^{k + 1}, \infty)$ as "numbers greater than $1$". Note further that it doesn't matter how exactly we insert the "$1$'s" since number of available gaps doesn't depend on that. Hence, we can go as follows: group the numbers by their leading bits. Make an empty list for the answer, and process the numbers in groups by decreasing of their leading bits. Suppose there are $x$ numbers with leading bit $k$, and $y$ greater numbers that have $1$ in the $k$-th bit. If $x > y + 1$, then there is no answer. Otherwise, insert the numbers from the current group as described above.

The complexity of this solution is $O(n \log A)$, where $A$ is the largest value among the numbers in the input.

 Tutorial is loading... Tutorial is loading... 
### [925F - Parametric Circulation](../problems/F._Parametric_Circulation.md "VK Cup 2018 - Round 3")

First, let's use the classical reduction of $lr$-circulation problem to the maximum flow problem. Consider a network $G' = (V \cup \{s, t\}, E')$ where for each $e = uv \in E$ there are three edges:

* $e_0 = uv$ with capacity $c_{e_0} = r_e - l_e$
* $e_1 = sv$ with capacity $c_{e_1} = l_e$
* $e_2 = ut$ with capacity $c_{e_2} = l_e$

Statement: it is possible to provide a bisection between $s-t$ flows of value $\sum \limits_{e \in E} l_e$ in $G'$ and $lr$-circulations in $G$. Indeed, consider a flow $f'$ in $G'$, that saturates all edges going from $s$ (and all the edges leading into $t$ at the same time). Let $f_e = f'_{e_0} + l_e$. Notice that it is a correct circulation: for any vertex $v$ 

$$\sum\limits_{e \in \delta^{+}(v)} f_{e} = \sum\limits_{e \in \delta^{+}(v)} f'_{e_0} + \sum\limits_{e \in \delta^{+}} l_e = \sum\limits_{e \in \delta^{+}(v)} f'_{e_0} + \sum\limits_{e \in \delta^{+}} f_{e_1} = \sum\limits_{e \in \delta^{-}(v)} f'_{e_0} + \sum\limits_{e \in \delta^{-}} f_{e_2} = \sum\limits_{e \in \delta^{-}(v)} f'_{e_0} + \sum\limits_{e \in \delta^{-}} l_e = \sum\limits_{e \in \delta^{-}(v)} f_{e}$$

where the middle equation is immediately following from the conservation condition for any vertex from $V$ for a flow $f'$.

On the other hand, the obtained circulation is indeed an $lr$-circulation because of how we got values of $f'_e$. By performing all the steps in the reverse direction, we may recover a maximum flow in $G'$ by any $lr$-circulation that finishes our proof.

Now we are going to answer the following question: we have a parametric network $G'(t)$ in which all capacities linearly depend on $t$, we have to find the probability that $G'$ allows a flow that saturates all edges from the source under condition that $t$ is sampled from $U[0, 1]$.

Let us show that the set of $t$ that allow existence of a sought flow is a segment. It follows from the fact that the value $maxflow(t)$ of a maximum flow in $G'(t)$ is concave: suppose $f'(t_1)$ is a an admissible flow in $G'(t_1)$ and $f'(t_2)$ is an admissible flow in $G'_{t_2}$. Then it is easy to see that $\lambda f'(t_1) + (1 - \lambda) f'(t_2)$ is an admissible flow in $G'\left(\lambda t_1 + (1 - \lambda) t_2\right)$ for any $\lambda \in [0, 1]$ (as all the constraints on variables $f'_{e}$ are linear inequalities), from which immediately follows that $maxflow(\lambda t_1 + (1 - \lambda) t_2) \geq \lambda maxflow(t_1) + (1 - \lambda) maxflow(t_2)$.

Denote $suml(t) = \sum\limits_{e \in E}l(t)$. Let us notices that $gap(t) = suml(t) - maxflow(t) \geq 0$ for any $t$ and we are interested in precisely those values of $t$, such that $gap(t) = 0$. Thus, the sought values of $t$ form a segment as the function $gap(t)$ is convex.

The remaining part of the solution is very simple: find a minimum of a convexvalue $gap(t)$ over a segment $[0, 1]$. If it is non-zero, then the answer is 0. Otherwise, we can locate the boundaries of an answer segment using two binary searches and print the difference between them.

While implementing such a solution, one may face several difficulties arising from the precision issues, so we will provide two observations that may help you deal with them.

One may notice that $maxflow(t)$ is actually a piecewise linear function, all pieces of which have the integer slope. Actually, $maxflow(t) = mincut(t) = \min\limits_{\text{cut }C} cost(C, t)$, and the cost of any fixed cut in $G'(t)$ is a linear function of $t$ with an integer slope. Thus, $maxflow(t)$ is a lower envelope of a family of linear functions with integer slopes. The similar fact holds for a function $gap(t)$ also. And we are interested in a horizontal segment in $gap(t)$ which may be found using the binary search over a sign of a derivative $gap'(t)$. Finally notice that calculating a derivative $gap'(t)$ may be done by finding a maximum flow and adding up all slopes of capacities of the edges defining a minimum cut restricting given maximum flow (since exactly this cut provides a linear constraint defining a segment of a function $gap(t)$, which a point $t$ belongs to).

An alternative observation — consider only the points $t$ such that $t = \frac{k}{10^7}$ where $k$ is integer. If we keep only such points on the sought segment, its length will decrease by no more than $2 \cdot 10^{-7}$ which is allowed by a required answer precision. Finally, we can multiply all $b_e$ and $d_e$ by $10^7$ and consider $t$ to be an integer between $0$ and $10^7$ which allows you to implement a solution that only uses integer data types.

We get a solution with a running time of $O(maxflow \cdot \log prec^{-1})$ where $prec$ is a required precision equal to $10^{-6}$ under conditions of a given problem and $maxflow$ is a running time of your favourite maximum flow algorithm. Practically you could use Dinic algorithm or Edmonds-Karp algorithm with capacity scaling.

