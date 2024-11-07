<h1 style='text-align: center;'> C. Serval and Toxel's Arrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Toxel likes arrays. Before traveling to the Paldea region, Serval gave him an array $a$ as a gift. This array has $n$ pairwise distinct elements.

In order to get more arrays, Toxel performed $m$ operations with the initial array. In the $i$-th operation, he modified the $p_{i}$-th element of the $(i-1)$-th array to $v_{i}$, resulting in the $i$-th array (the initial array $a$ is numbered as $0$). During modifications, Toxel guaranteed that the elements of each array are still pairwise distinct after each operation.

Finally, Toxel got $m+1$ arrays and denoted them as $A_{0}=a, A_{1},\ldots,A_{m}$. For each pair $(i,j)$ ($0\le i<j\le m$), Toxel defines its value as the number of distinct elements of the concatenation of $A_{i}$ and $A_{j}$. Now Toxel wonders, what is the sum of the values of all pairs? Please help him to calculate the answer.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\le t\le10^{4}$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1\le n,m\le2\cdot10^{5}$) — the length of the array and the number of operations.

The second line of each test case contains $n$ integers $a_{1},a_{2},\dots,a_{n}$ ($1\le a_{i}\le n+m$). It is guaranteed that all $a_i$ are pairwise distinct.

Each of the next $m$ lines of each test case contains two integers $p_{i}$ and $v_{i}$ ($1\le p_{i}\le n$, $1\le v_{i}\le n+m$) — the position of the modified element and its new value. It is guaranteed that the elements of each array are still pairwise distinct after each modification.

It is guaranteed that the sum of $n$ and the sum of $m$ over all test cases do not exceed $2\cdot10^{5}$.

## Output

For each test case, print a single integer — the sum of the values of all pairs of arrays.

## Example

## Input


```

33 21 2 31 42 51 111 110 104 6 9 12 16 20 2 10 19 71 35 42 172 186 117 18 175 55 52 2
```
## Output


```

13
1
705

```
## Note

In the first test case, the arrays change as follows: $[1,2,3]\to[\underline{4},2,3]\to[4,\underline{5},3]$.

The concatenation of the $0$-th array and the $1$-st array is $\require{cancel}[1,2,3,4,\cancel{2},\cancel{3}]$. There are $4$ distinct elements.

The concatenation of the $0$-th array and the $2$-nd array is $\require{cancel}[1,2,3,4,5,\cancel{3}]$. There are $5$ distinct elements.

The concatenation of the $1$-st array and the $2$-nd array is $\require{cancel}[4,2,3,\cancel{4},5,\cancel{3}]$. There are $4$ distinct elements.

Strikethrough elements are duplicates in the array.

Therefore, the answer is $4+5+4=13$.

In the second test case, note that the array may remain unchanged after operations.



#### tags 

#1500 #combinatorics #dp #implementation #math 