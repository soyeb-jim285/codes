<h1 style='text-align: center;'> A. Amusement Park</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You have been hired to supervise the project of a new amusement park. The park will have a special gimmick: directed slides that can get customers from one attraction to another quickly and in an entertaining way.

The park owner has given you the current project: a list of planned attractions and a list of slides that should be built between them. However, him being a businessman, he casually envisioned the impossible: among other things, he projected a slide coming from the Haunted Castle to the Roller Coaster, another from the Roller Coaster to the Drop Tower, and a third from the Drop Tower to the Haunted Castle. As the slides can only go downhill, it is evident why this is a problem. You don't have the luxury of ignoring the laws of physics when building the park, so you have to request changes in the project. Maybe he would accept reversing the slide between the Drop Tower and the Haunted Castle?

Formally: 

* The project is a list of attractions and a list of directed slides. Each slide starts at one attraction and ends at another attraction.
* A proposal is obtained from the project by reversing the directions of some slides (possibly none or all of them).
* A proposal is legal if there is a way to assign an elevation to each attraction in such a way that every slide goes downhill.
* The cost of a proposal is the number of slides whose directions were reversed.

For a given project, find and report the sum of costs all legal proposals. Since this number may be large, output it modulo $998,244,353$.

#### Input

The first line contains two space-separated integers $n$, $m$ ($1 \leq n \leq 18$, $0 \leq m \leq n(n-1)/2$) – the number of attractions and the number of slides, respectively. The attractions are numbered $1$ through $n$.

Then, $m$ lines follow. The $i$-th of these lines contains two space-separated integers $a_i$, $b_i$ ($1 \leq a_i, b_i \leq n$) denoting a slide from $a_i$ to $b_i$. 

You may assume that: 

* There are no self-loops. (For each $i$: $a_i \neq b_i$.)
* No slide appears twice. (For all $i \neq j$: $a_i \neq a_j$ or $b_i \neq b_j$.)
* No pair of attractions is connected in both directions. (The unordered pairs $\{a_i, b_i\}$ are distinct.)
#### Output

#### Output

 one line with a single integer, the sum of costs of all legal proposals modulo $998,244,353$.

## Scoring

Subtask 1 (7 points): $n \leq 3$

Subtask 2 (12 points): $n \leq 6$

Subtask 3 (23 points): $n \leq 10$

Subtask 4 (21 points): $n \leq 15$

Subtask 5 (37 points): no additional constraints

## Examples

#### Input


```text
2 1
1 2
```
#### Output


```text
1
```
#### Input


```text
3 3
1 2
2 3
1 3
```
#### Output


```text
9
```
## Note

In the first example, there are two proposals: 

* The slide direction is not flipped. This proposal has cost $0$.
* The slide direction is flipped. This proposal has cost $1$.

 As both proposals are valid, the answer is $0 + 1 = 1$.In the second example, there are eight proposals with the slide directions as follows: 

* $1 \rightarrow 2$, $2 \rightarrow 3$, $1 \rightarrow 3$ (cost $0$)
* $1 \rightarrow 2$, $2 \rightarrow 3$, $3 \rightarrow 1$ (cost $1$)
* $1 \rightarrow 2$, $3 \rightarrow 2$, $1 \rightarrow 3$ (cost $1$)
* $1 \rightarrow 2$, $3 \rightarrow 2$, $3 \rightarrow 1$ (cost $2$)
* $2 \rightarrow 1$, $2 \rightarrow 3$, $1 \rightarrow 3$ (cost $1$)
* $2 \rightarrow 1$, $2 \rightarrow 3$, $3 \rightarrow 1$ (cost $2$)
* $2 \rightarrow 1$, $3 \rightarrow 2$, $1 \rightarrow 3$ (cost $2$)
* $2 \rightarrow 1$, $3 \rightarrow 2$, $3 \rightarrow 1$ (cost $3$)

The second proposal is not legal, as there is a slide sequence $1 \rightarrow 2 \rightarrow 3 \rightarrow 1$. This means that the attraction $1$ has to be strictly higher than ifself, which is clearly impossible. Similarly, the seventh proposal is not legal. The answer is thus $0 + 1 + 2 + 1 + 2 + 3 = 9$.



#### Tags 

#NOT OK #*special #dp #math 

## Blogs
- [All Contest Problems](../CEOI_2019_day_2_online_mirror_(unrated,_IOI_format).md)
- [CEOI 2019 Mirror (en)](../blogs/CEOI_2019_Mirror_(en).md)
- [T (en)](../blogs/T_(en).md)
