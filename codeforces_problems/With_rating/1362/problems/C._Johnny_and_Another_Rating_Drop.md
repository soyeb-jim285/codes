<h1 style='text-align: center;'> C. Johnny and Another Rating Drop</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The last contest held on Johnny's favorite competitive programming platform has been received rather positively. However, Johnny's rating has dropped again! He thinks that the presented tasks are lovely, but don't show the truth about competitors' skills.

The boy is now looking at the ratings of consecutive participants written in a binary system. He thinks that the more such ratings differ, the more unfair is that such people are next to each other. He defines the difference between two numbers as the number of bit positions, where one number has zero, and another has one (we suppose that numbers are padded with leading zeros to the same length). For example, the difference of $5 = 101_2$ and $14 = 1110_2$ equals to $3$, since $0101$ and $1110$ differ in $3$ positions. Johnny defines the unfairness of the contest as the sum of such differences counted for neighboring participants.

Johnny has just sent you the rating sequence and wants you to find the unfairness of the competition. You have noticed that you've got a sequence of consecutive integers from $0$ to $n$. That's strange, but the boy stubbornly says that everything is right. So help him and find the desired unfairness for received numbers.

### Input

The input consists of multiple test cases. The first line contains one integer $t$ ($1 \leq t \leq 10\,000$) — the number of test cases. The following $t$ lines contain a description of test cases.

The first and only line in each test case contains a single integer $n$ ($1 \leq n \leq 10^{18})$.

### Output

### Output

 $t$ lines. For each test case, you should output a single line with one integer — the unfairness of the contest if the rating sequence equals to $0$, $1$, ..., $n - 1$, $n$.

## Example

### Input


```text
5
5
7
11
1
2000000000000
```
### Output


```text
8
11
19
1
3999999999987
```
## Note

For $n = 5$ we calculate unfairness of the following sequence (numbers from $0$ to $5$ written in binary with extra leading zeroes, so they all have the same length): 

* $000$
* $001$
* $010$
* $011$
* $100$
* $101$

The differences are equal to $1$, $2$, $1$, $3$, $1$ respectively, so unfairness is equal to $1 + 2 + 1 + 3 + 1 = 8$.



#### Tags 

#1400 #NOT OK #bitmasks #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_647_(Div._2)_-_Thanks,_Algo_Muse!.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
