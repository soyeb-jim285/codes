<h1 style='text-align: center;'> E. Cat, Fox and Swaps </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Fox has found an array $p_1, p_2, \ldots, p_n$, that is a permutation of length $n^\dagger$ of the numbers $1, 2, \ldots, n$. She wants to sort the elements in increasing order. Cat wants to help her — he is able to swap any two numbers $x$ and $y$ in the array, but only if $l \leq x + y \leq r$ (note that the constraint is imposed on the values of the elements, not their positions). He can make such swaps any number of times.

They don't know the numbers $l$, $r$ yet, they only know that it's true that $1 \leq l \leq r \leq 2 \cdot n$. 

You are given the number $n$ and the array $p_1, p_2, \ldots, p_n$. Determine how many pairs $(l, r)$ satisfying the conditions are there such that you can sort the permutation if you can only swap two number $(x, y)$ such that $l \leq x + y \leq r$ (arbitrary number of times, possibly $0$).

$^\dagger$ A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

Description of each test case consists of two lines. The first line contains one integer $n$ ($1 \leq n \leq 10^5$).

The second line contains $n$ integers: the array $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$). It is guaranteed that this array is a permutation of length $n$. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, print the number of pairs of integers $(l, r)$ such that $1 \leq l \leq r \leq 2 \cdot n$, and you can sort the array under the constraints.

## Example

### Input


```text
722 133 1 243 2 1 455 3 1 2 451 2 3 4 563 2 1 5 4 661 3 2 4 5 6
```
### Output

```text

6
11
23
29
55
46
58

```
## Note

In the first example, we need to be able to swap $1$ and $2$, so we must be able to swap numbers with sum $3$. There are exactly $6$ pairs satisfying the condition: $(1, 3), (2, 3), (3, 3), (1, 4), (2, 4)$ and $(3, 4)$, so the answer is $6$.

In the second example, the $11$ pairs satisfying the condition are $(1, 4), (1, 5), (1, 6), (2, 4), (2, 5), (2, 6), (3, 4), (3, 5), (3, 6), (4, 5)$ and $(4, 6)$. For example, if we pick the pair $(3, 4)$ we can first swap the numbers $1$ and $2$ and then the numbers $1$ and $3$, after this, the permutation is sorted.



#### Tags 

#2500 #NOT OK #graphs #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_945_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
