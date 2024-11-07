<h1 style='text-align: center;'> F. Intersection and Union</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given $n$ segments on the coordinate axis. The $i$-th segment is $[l_i, r_i]$. Let's denote the set of all integer points belonging to the $i$-th segment as $S_i$.

Let $A \cup B$ be the union of two sets $A$ and $B$, $A \cap B$ be the intersection of two sets $A$ and $B$, and $A \oplus B$ be the symmetric difference of $A$ and $B$ (a set which contains all elements of $A$ and all elements of $B$, except for the ones that belong to both sets).

Let $[\mathbin{op}_1, \mathbin{op}_2, \dots, \mathbin{op}_{n-1}]$ be an array where each element is either $\cup$, $\oplus$, or $\cap$. Over all $3^{n-1}$ ways to choose this array, calculate the sum of the following values:

$$|(((S_1\ \mathbin{op}_1\ S_2)\ \mathbin{op}_2\ S_3)\ \mathbin{op}_3\ S_4)\ \dots\ \mathbin{op}_{n-1}\ S_n|$$

In this expression, $|S|$ denotes the size of the set $S$.

## Input

The first line contains one integer $n$ ($2 \le n \le 3 \cdot 10^5$).

Then, $n$ lines follow. The $i$-th of them contains two integers $l_i$ and $r_i$ ($0 \le l_i \le r_i \le 3 \cdot 10^5$).

## Output

Print one integer — the sum of $|(((S_1\ \mathbin{op}_1\ S_2)\ \mathbin{op}_2\ S_3)\ \mathbin{op}_3\ S_4)\ \dots\ \mathbin{op}_{n-1}\ S_n|$ over all possible ways to choose $[\mathbin{op}_1, \mathbin{op}_2, \dots, \mathbin{op}_{n-1}]$. Since the answer can be huge, print it modulo $998244353$.

## Examples

## Input


```

4
3 5
4 8
2 2
1 9

```
## Output


```

162

```
## Input


```

4
1 9
3 5
4 8
2 2

```
## Output


```

102

```


#### tags 

#2300 #data_structures #dp #matrices #probabilities 