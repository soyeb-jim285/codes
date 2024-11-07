<h1 style='text-align: center;'> C. Sequence Pair Weight</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The weight of a sequence is defined as the number of unordered pairs of indexes $(i,j)$ (here $i \lt j$) with same value ($a_{i} = a_{j}$). For example, the weight of sequence $a = [1, 1, 2, 2, 1]$ is $4$. The set of unordered pairs of indexes with same value are $(1, 2)$, $(1, 5)$, $(2, 5)$, and $(3, 4)$.

You are given a sequence $a$ of $n$ integers. Print the sum of the weight of all subsegments of $a$. 

A sequence $b$ is a subsegment of a sequence $a$ if $b$ can be obtained from $a$ by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, print a single integer — the sum of the weight of all subsegments of $a$.

## Example

### Input


```text
2
4
1 2 1 1
4
1 2 3 4
```
### Output


```text
6
0
```
## Note

* In test case $1$, all possible subsegments of sequence $[1, 2, 1, 1]$ having size more than $1$ are:
	1. $[1, 2]$ having $0$ valid unordered pairs;
	2. $[2, 1]$ having $0$ valid unordered pairs;
	3. $[1, 1]$ having $1$ valid unordered pair;
	4. $[1, 2, 1]$ having $1$ valid unordered pairs;
	5. $[2, 1, 1]$ having $1$ valid unordered pair;
	6. $[1, 2, 1, 1]$ having $3$ valid unordered pairs. Answer is $6$.
* In test case $2$, all elements of the sequence are distinct. So, there is no valid unordered pair with the same value for any subarray. Answer is $0$.


#### Tags 

#1600 #NOT OK #hashing #implementation #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_721_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
