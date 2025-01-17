<h1 style='text-align: center;'> C. Creative Snap</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Thanos wants to destroy the avengers base, but he needs to destroy the avengers along with their base.

Let we represent their base with an array, where each position can be occupied by many avengers, but one avenger can occupy only one position. Length of their base is a perfect power of $2$. Thanos wants to destroy the base using minimum power. He starts with the whole base and in one step he can do either of following: 

* if the current length is at least $2$, divide the base into $2$ equal halves and destroy them separately, or
* burn the current base. If it contains no avenger in it, it takes $A$ amount of power, otherwise it takes his $B \cdot n_a \cdot l$ amount of power, where $n_a$ is the number of avengers and $l$ is the length of the current base.

 
#### Output

 the minimum power needed by Thanos to destroy the avengers' base.
#### Input

The first line contains four integers $n$, $k$, $A$ and $B$ ($1 \leq n \leq 30$, $1 \leq k \leq 10^5$, $1 \leq A,B \leq 10^4$), where $2^n$ is the length of the base, $k$ is the number of avengers and $A$ and $B$ are the constants explained in the question.

The second line contains $k$ integers $a_{1}, a_{2}, a_{3}, \ldots, a_{k}$ ($1 \leq a_{i} \leq 2^n$), where $a_{i}$ represents the position of avenger in the base.

#### Output

#### Output

 one integer — the minimum power needed to destroy the avengers base.

## Examples

#### Input


```text
2 2 1 2
1 3
```
#### Output


```text
6
```
#### Input


```text
3 2 1 2
1 7
```
#### Output


```text
8
```
## Note

Consider the first example.

One option for Thanos is to burn the whole base $1-4$ with power $2 \cdot 2 \cdot 4 = 16$.

Otherwise he can divide the base into two parts $1-2$ and $3-4$.

For base $1-2$, he can either burn it with power $2 \cdot 1 \cdot 2 = 4$ or divide it into $2$ parts $1-1$ and $2-2$.

For base $1-1$, he can burn it with power $2 \cdot 1 \cdot 1 = 2$. For $2-2$, he can destroy it with power $1$, as there are no avengers. So, the total power for destroying $1-2$ is $2 + 1 = 3$, which is less than $4$. 

Similarly, he needs $3$ power to destroy $3-4$. The total minimum power needed is $6$.



#### Tags 

#1700 #NOT OK #binary_search #brute_force #divide_and_conquer #math 

## Blogs
- [All Contest Problems](../CodeCraft-19_and_Codeforces_Round_537_(Div._2).md)
- [CodeCraft-19 (en)](../blogs/CodeCraft-19_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
