<h1 style='text-align: center;'> E. Range Minimum Sum</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

For an array $[a_1,a_2,\ldots,a_n]$ of length $n$, define $f(a)$ as the sum of the minimum element over all subsegments. That is, $$f(a)=\sum_{l=1}^n\sum_{r=l}^n \min_{l\le i\le r}a_i.$$

A permutation is a sequence of integers from $1$ to $n$ of length $n$ containing each number exactly once. You are given a permutation $[a_1,a_2,\ldots,a_n]$. For each $i$, solve the following problem independently:

* Erase $a_i$ from $a$, concatenating the remaining parts, resulting in $b = [a_1,a_2,\ldots,a_{i-1},\;a_{i+1},\ldots,a_{n}]$.
* Calculate $f(b)$.
### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^5$). Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1\le n\le 5\cdot 10^5$).

The second line of each test case contains $n$ distinct integers $a_1,\ldots,a_n$ ($1\le a_i\le n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^6$.

### Output

For each test case, print one line containing $n$ integers. The $i$-th integer should be the answer when erasing $a_i$.

## Example

### Input


```text
41133 1 254 2 1 5 388 1 4 6 7 3 5 2
```
### Output

```text

0 
4 7 5 
19 21 27 17 19 
79 100 72 68 67 80 73 80 

```
## Note

In the second test case, $a=[3,1,2]$.

* When removing $a_1$, $b=[1,2]$. $f(b)=1+2+\min\{1,2\}=4$.
* When removing $a_2$, $b=[3,2]$. $f(b)=3+2+\min\{3,2\}=7$.
* When removing $a_3$, $b=[3,1]$. $f(b)=3+1+\min\{3,1\}=5$.


#### Tags 

#2300 #NOT OK #binary_search #brute_force #data_structures #divide_and_conquer #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_958_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Video Tutorial (en)](../blogs/Video_Tutorial_(en).md)
- [Tutorial #2 (en)](../blogs/Tutorial_2_(en).md)
