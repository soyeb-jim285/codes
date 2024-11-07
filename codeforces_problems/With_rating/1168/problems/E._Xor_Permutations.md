<h1 style='text-align: center;'> E. Xor Permutations</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Toad Mikhail has an array of $2^k$ integers $a_1, a_2, \ldots, a_{2^k}$.

Find two permutations $p$ and $q$ of integers $0, 1, \ldots, 2^k-1$, such that $a_i$ is equal to $p_i \oplus q_i$ for all possible $i$, or determine there are no such permutations. Here $\oplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

##### Input

The first line contains one integer $k$ ($2 \leq k \leq 12$), denoting that the size of the array is $2^k$.

The next line contains $2^k$ space-separated integers $a_1, a_2, \ldots, a_{2^k}$ ($0 \leq a_i < 2^k$) — the elements of the given array.

##### Output

If the given array can't be represented as element-wise XOR of two permutations of integers $0, 1, \ldots, 2^k-1$, print "Fou".

Otherwise, print "Shi" in the first line.

The next two lines should contain the description of two suitable permutations. The first of these lines should contain $2^k$ space-separated distinct integers $p_{1}, p_{2}, \ldots, p_{2^k}$, and the second line should contain $2^k$ space-separated distinct integers $q_{1}, q_{2}, \ldots, q_{2^k}$.

All elements of $p$ and $q$ should be between $0$ and $2^k - 1$, inclusive; $p_i \oplus q_i$ should be equal to $a_i$ for all $i$ such that $1 \leq i \leq 2^k$. If there are several possible solutions, you can print any.

## Examples

##### Input


```text
2
0 1 2 3
```
##### Output


```text
Shi
2 0 1 3 
2 1 3 0 
```
##### Input


```text
2
0 0 0 0
```
##### Output


```text
Shi
0 1 2 3 
0 1 2 3 
```
##### Input


```text
2
0 1 2 2
```
##### Output


```text
Fou
```


#### Tags 

#3100 #NOT OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_562_(Div._1).md)
- [Codeforces Round #562](../blogs/Codeforces_Round_562.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
