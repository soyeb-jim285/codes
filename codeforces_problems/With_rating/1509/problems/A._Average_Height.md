<h1 style='text-align: center;'> A. Average Height</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sayaka Saeki is a member of the student council, which has $n$ other members (excluding Sayaka). The $i$-th member has a height of $a_i$ millimeters.

It's the end of the school year and Sayaka wants to take a picture of all other members of the student council. Being the hard-working and perfectionist girl as she is, she wants to arrange all the members in a line such that the amount of photogenic consecutive pairs of members is as large as possible.

A pair of two consecutive members $u$ and $v$ on a line is considered photogenic if their average height is an integer, i.e. $\frac{a_u + a_v}{2}$ is an integer.

Help Sayaka arrange the other members to maximize the number of photogenic consecutive pairs.

### Input

The first line contains a single integer $t$ ($1\le t\le 500$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2000$)  — the number of other council members.

The second line of each test case contains $n$ integers $a_1$, $a_2$, ..., $a_n$ ($1 \le a_i \le 2 \cdot 10^5$)  — the heights of each of the other members in millimeters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2000$.

### Output

For each test case, output on one line $n$ integers representing the heights of the other members in the order, which gives the largest number of photogenic consecutive pairs. If there are multiple such orders, output any of them.

## Example

### Input


```text
4
3
1 1 2
3
1 1 1
8
10 9 13 15 3 16 9 13
2
18 9
```
### Output


```text
1 1 2 
1 1 1 
13 9 13 15 3 9 16 10 
9 18 
```
## Note

In the first test case, there is one photogenic pair: $(1, 1)$ is photogenic, as $\frac{1+1}{2}=1$ is integer, while $(1, 2)$ isn't, as $\frac{1+2}{2}=1.5$ isn't integer.

In the second test case, both pairs are photogenic.



#### Tags 

#800 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_715_(Div._2).md)
- [Codeforces Round #715 (en)](../blogs/Codeforces_Round_715_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
