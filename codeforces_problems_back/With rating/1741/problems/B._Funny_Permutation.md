<h1 style='text-align: center;'> B. Funny Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A sequence of $n$ numbers is called permutation if it contains all numbers from $1$ to $n$ exactly once. For example, the sequences $[3, 1, 4, 2]$, [$1$] and $[2,1]$ are permutations, but $[1,2,1]$, $[0,1]$ and $[1,3,4]$ are not.

For a given number $n$ you need to make a permutation $p$ such that two requirements are satisfied at the same time:

* For each element $p_i$, at least one of its neighbors has a value that differs from the value of $p_i$ by one. That is, for each element $p_i$ ($1 \le i \le n$), at least one of its neighboring elements (standing to the left or right of $p_i$) must be $p_i + 1$, or $p_i - 1$.
* the permutation must have no fixed points. That is, for every $i$ ($1 \le i \le n$), $p_i \neq i$ must be satisfied.

Let's call the permutation that satisfies these requirements funny.

For example, let $n = 4$. Then [$4, 3, 1, 2$] is a funny permutation, since: 

* to the right of $p_1=4$ is $p_2=p_1-1=4-1=3$;
* to the left of $p_2=3$ is $p_1=p_2+1=3+1=4$;
* to the right of $p_3=1$ is $p_4=p_3+1=1+1=2$;
* to the left of $p_4=2$ is $p_3=p_4-1=2-1=1$.
* for all $i$ is $p_i \ne i$.

For a given positive integer $n$, output any funny permutation of length $n$, or output -1 if funny permutation of length $n$ does not exist.

## Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The description of the test cases follows.

Each test case consists of f single line containing one integer $n$ ($2 \le n \le 2 \cdot 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print on a separate line: 

* any funny permutation $p$ of length $n$;
* or the number -1 if the permutation you are looking for does not exist.
## Example

## Input


```

543752
```
## Output


```

3 4 2 1
-1
6 7 4 5 3 2 1
5 4 1 2 3
2 1
```
## Note

The first test case is explained in the problem statement.

In the second test case, it is not possible to make the required permutation: permutations $[1, 2, 3]$, $[1, 3, 2]$, $[2, 1, 3]$, $[3, 2, 1]$ have fixed points, and in $[2, 3, 1]$ and $[3, 1, 2]$ the first condition is met not for all positions.



#### tags 

#800 #constructive_algorithms #math 