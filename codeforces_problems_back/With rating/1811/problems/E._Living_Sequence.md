<h1 style='text-align: center;'> E. Living Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Japan, the number $4$ reads like death, so Bob decided to build a live sequence. Living sequence $a$ contains all natural numbers that do not contain the digit $4$. $a = [1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, \ldots]$.

For example, the number $1235$ is part of the sequence $a$, but the numbers $4321$, $443$ are not part of the sequence $a$.

Bob realized that he does not know how to quickly search for a particular number by the position $k$ in the sequence, so he asks for your help.

For example, if Bob wants to find the number at position $k = 4$ (indexing from $1$), you need to answer $a_k = 5$.

## Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

In the only line of each test case, there is a single integer $k$ ($1 \le k \le 10^{12}$) — the position Bob is interested in.

## Output

For each test case, print on a separate line the number $a_k$ in indexing with $1$.

## Example

## Input


```

735221010012345827264634912
```
## Output


```

3
6
25
11
121
18937
2932285320890

```


#### tags 

#1500 #binary_search #dp #math #number_theory 