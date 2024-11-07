<h1 style='text-align: center;'> C. Minimum Extraction</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Yelisey has an array $a$ of $n$ integers.

If $a$ has length strictly greater than $1$, then Yelisei can apply an operation called minimum extraction to it: 

1. First, Yelisei finds the minimal number $m$ in the array. If there are several identical minima, Yelisey can choose any of them.
2. Then the selected minimal element is removed from the array. After that, $m$ is subtracted from each remaining element.

Thus, after each operation, the length of the array is reduced by $1$.

For example, if $a = [1, 6, -4, -2, -4]$, then the minimum element in it is $a_3 = -4$, which means that after this operation the array will be equal to $a=[1 {- (-4)}, 6 {- (-4)}, -2 {- (-4)}, -4 {- (-4)}] = [5, 10, 2, 0]$.

Since Yelisey likes big numbers, he wants the numbers in the array $a$ to be as big as possible.

Formally speaking, he wants to make the minimum of the numbers in array $a$ to be maximal possible (i.e. he want to maximize a minimum). To do this, Yelisey can apply the minimum extraction operation to the array as many times as he wants (possibly, zero). ## Note

 that the operation cannot be applied to an array of length $1$.

Help him find what maximal value can the minimal element of the array have after applying several (possibly, zero) minimum extraction operations to the array.

## Input

The first line contains an integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The next $2t$ lines contain descriptions of the test cases.

In the description of each test case, the first line contains an integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the original length of the array $a$. The second line of the description lists $n$ space-separated integers $a_i$ ($-10^9 \leq a_i \leq 10^9$) — elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

Print $t$ lines, each of them containing the answer to the corresponding test case. The answer to the test case is a single integer — the maximal possible minimum in $a$, which can be obtained by several applications of the described operation to it.

## Example

## Input


```

8
1
10
2
0 0
3
-1 2 0
4
2 10 1 7
2
2 3
5
3 2 -4 -2 0
2
-1 1
1
-2

```
## Output


```

10
0
2
5
2
2
2
-2

```
## Note

In the first example test case, the original length of the array $n = 1$. Therefore minimum extraction cannot be applied to it. Thus, the array remains unchanged and the answer is $a_1 = 10$.

In the second set of input data, the array will always consist only of zeros.

In the third set, the array will be changing as follows: $[\color{blue}{-1}, 2, 0] \to [3, \color{blue}{1}] \to [\color{blue}{2}]$. The minimum elements are highlighted with $\color{blue}{\text{blue}}$. The maximal one is $2$.

In the fourth set, the array will be modified as $[2, 10, \color{blue}{1}, 7] \to [\color{blue}{1}, 9, 6] \to [8, \color{blue}{5}] \to [\color{blue}{3}]$. Similarly, the maximum of the minimum elements is $5$.



#### tags 

#1000 #brute_force #sortings 