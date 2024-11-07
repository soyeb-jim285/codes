# Tutorial

[984A - Game](https://codeforces.com/contest/984/problem/A "Codeforces Round 483 (Div. 2) [Thanks, Botan Investments and Victor Shaburov!]")

 **tutorial**
### [984A - Game](https://codeforces.com/contest/984/problem/A "Codeforces Round 483 (Div. 2) [Thanks, Botan Investments and Victor Shaburov!]")

First let's notice that the first player makes $\lceil \frac{n - 1}{2} \rceil$ turns and the second one makes $\lfloor \frac{n - 1}{2} \rfloor$. 

So, if numbers are $1$-indexed and sorted, first player can make the answer not more than $(n - \lceil \frac{n - 1}{2} \rceil)$-th by deleting maximal number every time. The second can make it not less than $(\lfloor \frac{n - 1}{2} \rfloor + 1)$-th. 

But $n - \lceil \frac{n - 1}{2} \rceil = \lfloor \frac{n - 1}{2} \rfloor + 1$, because $n - 1 = \lceil \frac{n - 1}{2} \rceil + \lfloor \frac{n - 1}{2} \rfloor$.

So the answer has minimal and maximal values, which are the same. So the answer is $(\lfloor \frac{n - 1}{2} \rfloor + 1)$-th number ascending.

Asymptotics is $O(n \cdot log(n)$ or $O(n^2)$

[Solution](//codeforces.com/contest/984/submission/38302744)

[984B - Minesweeper](https://codeforces.com/contest/984/problem/B "Codeforces Round 483 (Div. 2) [Thanks, Botan Investments and Victor Shaburov!]")

 **tutorial**
### [984B - Minesweeper](https://codeforces.com/contest/984/problem/B "Codeforces Round 483 (Div. 2) [Thanks, Botan Investments and Victor Shaburov!]")

Let's make two-dimensional array d[n][m]. For each cell i,j if it has bomb in it we add 1 in d[g][h] where g,h is neighboring cell for i,j. Now d[i][j] is a number of bombs in neighboring cells of i,j and we can check validity of field according to the condition of the problem: 

* If there is a number k in the cell, then exacly k of neighboring cells have bombs.
* Otherwise, if cell has no bomb, then neighboring cells have no bombs.

[Solution](//codeforces.com/contest/984/submission/38302738)

[983A - Finite or not?](../problems/A._Finite_or_not_.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

 **tutorial**
### [983A - Finite or not?](../problems/A._Finite_or_not_.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

First, if p and q are not coprime, divide them on gcd(p,q). Fraction is finite if and only if there is integer k such that q∣p⋅bk. Since p and q are being coprime now, q∣bk⇒ all prime factors of q are prime factors of b. Now we can do iterations q=q÷gcd(b,q) while gcd(q,b)≠1. If q≠1 after iterations, there are prime factors of q which are not prime factors of b⇒ fraction is Infinite, else fraction is Finite. But this solution works in O(nlog21018). Let's add b=gcd(b,q) in iterations and name iterations when gcd(b,q) changes iterations of the first type and when it doesn't change — iterations of the second type. Iterations of second type works summary in O(log1018). Number of iterations of the first type is O(log1018) too but on each iteration b decreases twice. Note that number of iterations in Euclid's algorithm is equal to number of this decreases. So iterations of first type works in O(log1018) summary. Total time complexity is O(nlog1018)

[Solution](//codeforces.com/contest/983/submission/38302722)

[983B - XOR-pyramid](../problems/B._XOR-pyramid.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

 **tutorial**
### [983B - XOR-pyramid](../problems/B._XOR-pyramid.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

Let's calculate f(a) recursively and save arrays from each level of recursion. We get two-dimencional array dp[n][n] and dp[n][1]=f(a). Now let's view recursive calculation for f(al…ar). You can see what array of i-th level of recursion is dp[i][l…r−i+1]⇒dp[r−l+1][l]=f(al…ar) (numbeer of levels of recursion is length of segment). To calculate maximum of all sub-segments for each segment, replace dp[i][j] on max(dp[i][j],dp[i−1][j],dp[i−1][j+1]). Now answer of question l,r is dp[r−l+1][l]. Overall time complexity is O(n2+q).

[Solution](//codeforces.com/contest/983/submission/38302716)

[983C - Elevator](../problems/C._Elevator.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

 **tutorial**
### [983C - Elevator](../problems/C._Elevator.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

This problem is inspired by living in the house of 9 floors with the elevator, which can accommodate up to 4 people. What a surprise!

We have a strict order. So let's make *dp*[*i*][*state*] =  minimal possible time, where *i* means that first *i* employees already came in the elevator (and possibly came out). 

So, what is a *state*? Let's store something what will allow us to determine the state. For this purpose we want to know the floor, where the elevator currently is, and number of people, who want to reach each floor. So, it's 10 integers. Let's estimate the number of states: floor takes 9 values, *state* can take ![](images/d48dbc4c781dc9ff6734950fabb7e7b5d79fd5a6.png) (Wow!). Also let's notice, that we don't want to visit floor of nobody in the elevator don't want to go there and the next person isn't on that floor. So we have not more than 5 interesting floors for each *state*. Let's say the total count of states is *s* = 5·256.

Now we've got two different solutions.

The fast one is we say we go from the floor *a*[*i*] to the floor *a*[*i* + 1] and iterate over the persons who we let come in on the way.

The slow one is to run Dijkstra for each *i*: from *state* we can go to the floor and let somebody come out or go to the floor *a*[*i* + 1]. Now, when we calculated answers for *i* - 1, we can calculate *dp*[*i*][*state*] = 1 + *dp*[*i* - 1][*state*], if state has floor equals to *a**i* and there are no more than 3 people inside.

The answer will be in *dp*[*n*][*floor* = *j* & *elevator* *is* *empty*] for ![](images/39b0458fb9577f3e261186a7bb4d1017bb440216.png).

Asymptotics is *O*(*n*·*s*) or *O*(*n*·*s*·*log*(*s*))

[Solution](//codeforces.com/contest/983/submission/38302708)

[983D - Arkady and Rectangles](../problems/D._Arkady_and_Rectangles.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

 **tutorial**
### [983D - Arkady and Rectangles](../problems/D._Arkady_and_Rectangles.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

First let's compress the coordinates. Now all the coordinates are in [0,2n).

Now we do scanline on x coordinate with segment tree on y coordinate. Let's talk about segment tree structute. In each vertex we store: 

* Set of colors which cover the whole segment. If color covers a segment, we don't push it to it childs (colors[v])
* Maximal visible color in subtree which isn't in the answer (max[v])
* Minimal visible color in subtree (min[v])

For the vertex max and min can be calculated as: 

* If colors isn't empty and max value in colors is more than max in children:
	+ If it's already in the answer or it's less than min in children, max=−1.
	+ Otherwise max=max in colors
* Otherwise max=max in children
* If colors isn't empty min=max(max in colors,min in children)
* Otherwise min=min in children

Now in scanline we: 

* Add all the segments, starting at this point
* Remove all the segments, ending at this point
* While max[root] isn't −1 we put it into answer and recalculate everything by readding this segment to tree.

At the end we know all visible colors and print the number of them.

Asymptotics is O(n⋅log(n)+n⋅log2(n))

[Solution](//codeforces.com/contest/983/submission/38302697)

[983E - NN country](../problems/E._NN_country.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

 **tutorial**
### [983E - NN country](../problems/E._NN_country.md "Codeforces Round 483 (Div. 1) [Thanks, Botan Investments and Victor Shaburov!]")

Let's say we go down when we go towards the root, and we go up when we go against the root. Also we say that vertex a lower than vertex b if a is closer to the root.

Each way from v to u can be represented as two parts: at first we go down from v to lca and then we go up from lca to u. 

Let's say we have to use a buses to go from v to lca and b buses to go from lca to u. Let's learn how to calculate a and b fast. Firstly, notice that we can move down greedily. So we calculate lowest[v] as the lowest vertex, where we can go from v using only one bus. Secondly, notice that we can now build binary lifting on lowest. 

The answer is either a+b or a+b−1. Let's say the lowest vertex we can go from v using a−1 buses is lv and for u and b−1 buses it's lu. lv and lu can be also calculated using binary lifting on lowest. Then, if there is a route connecting lv and lu, the answer is a+b−1 and it's a+b otherwise.

Let's calculate lv and lu for all the queries.

Now we build an euler's tour. For each we now know the interval, corresponding to it's subtree. Let's say it is [time_in[v],time_out[v]). Then we run dfs again and do the following: when we came into lv we ask for sum on [time_in[lu],time_out[lu]). Now for each way, starting in lv we add 1 to its other end. Now we run dfs for all of its children. And now we ask for sum on [time_in[lu],time_out[lu]) for the second time. If it changed the route connecting lv and lu exists. 

Asymptotics is O(n⋅log(n)+m⋅log(n)+q⋅log(n)).

Read the solution for better understanding. It tried to make it as readable as possible.

[Solution](//codeforces.com/contest/983/submission/38302686)

