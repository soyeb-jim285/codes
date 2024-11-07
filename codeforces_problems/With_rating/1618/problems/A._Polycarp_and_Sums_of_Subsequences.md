<h1 style='text-align: center;'> A. Polycarp and Sums of Subsequences</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp had an array $a$ of $3$ positive integers. He wrote out the sums of all non-empty subsequences of this array, sorted them in non-decreasing order, and got an array $b$ of $7$ integers.

For example, if $a = \{1, 4, 3\}$, then Polycarp wrote out $1$, $4$, $3$, $1 + 4 = 5$, $1 + 3 = 4$, $4 + 3 = 7$, $1 + 4 + 3 = 8$. After sorting, he got an array $b = \{1, 3, 4, 4, 5, 7, 8\}.$

Unfortunately, Polycarp lost the array $a$. He only has the array $b$ left. Help him to restore the array $a$.

### Input

The first line contains one integer $t$ ($1 \le t \le 5000$) — the number of test cases.

Each test case consists of one line which contains $7$ integers $b_1, b_2, \dots, b_7$ ($1 \le b_i \le 10^9$; $b_i \le b_{i+1}$). 

Additional constraint on the input: there exists at least one array $a$ which yields this array $b$ as described in the statement.

### Output

For each test case, print $3$ integers — $a_1$, $a_2$ and $a_3$. If there can be several answers, print any of them.

## Example

### Input


```text
5
1 3 4 4 5 7 8
1 2 3 4 5 6 7
300000000 300000000 300000000 600000000 600000000 600000000 900000000
1 1 2 999999998 999999999 999999999 1000000000
1 2 2 3 3 4 5
```
### Output


```text
1 4 3
4 1 2
300000000 300000000 300000000
999999998 1 1
1 2 2
```
## Note

The subsequence of the array $a$ is a sequence that can be obtained from $a$ by removing zero or more of its elements.

Two subsequences are considered different if index sets of elements included in them are different. That is, the values of the elements don't matter in the comparison of subsequences. In particular, any array of length $3$ has exactly $7$ different non-empty subsequences.



#### Tags 

#800 #NOT OK #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_760_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
