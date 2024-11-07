<h1 style='text-align: center;'> D. Genius</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 32 megabytes</h5>

Please note the non-standard memory limit.

There are $n$ problems numbered with integers from $1$ to $n$. $i$-th problem has the complexity $c_i = 2^i$, tag $tag_i$ and score $s_i$.

After solving the problem $i$ it's allowed to solve problem $j$ if and only if $\text{IQ} < |c_i - c_j|$ and $tag_i \neq tag_j$. After solving it your $\text{IQ}$ changes and becomes $\text{IQ} = |c_i - c_j|$ and you gain $|s_i - s_j|$ points.

Any problem can be the first. You can solve problems in any order and as many times as you want.

Initially your $\text{IQ} = 0$. Find the maximum number of points that can be earned.

### Input

The first line contains a single integer $t$ $(1 \le t \le 100)$  — the number of test cases. 

The first line of each test case contains an integer $n$ $(1 \le n \le 5000)$  — the number of problems.

The second line of each test case contains $n$ integers $tag_1, tag_2, \ldots, tag_n$ $(1 \le tag_i \le n)$  — tags of the problems.

The third line of each test case contains $n$ integers $s_1, s_2, \ldots, s_n$ $(1 \le s_i \le 10^9)$  — scores of the problems.

It's guaranteed that sum of $n$ over all test cases does not exceed $5000$.

### Output

For each test case print a single integer  — the maximum number of points that can be earned.

## Example

### Input


```text
5
4
1 2 3 4
5 10 15 20
4
1 2 1 2
5 10 15 20
4
2 2 4 1
2 8 19 1
2
1 1
6 9
1
1
666
```
### Output


```text
35
30
42
0
0
```
## Note

In the first test case optimal sequence of solving problems is as follows: 

1. $1 \rightarrow 2$, after that total score is $5$ and $\text{IQ} = 2$
2. $2 \rightarrow 3$, after that total score is $10$ and $\text{IQ} = 4$
3. $3 \rightarrow 1$, after that total score is $20$ and $\text{IQ} = 6$
4. $1 \rightarrow 4$, after that total score is $35$ and $\text{IQ} = 14$

In the second test case optimal sequence of solving problems is as follows: 

1. $1 \rightarrow 2$, after that total score is $5$ and $\text{IQ} = 2$
2. $2 \rightarrow 3$, after that total score is $10$ and $\text{IQ} = 4$
3. $3 \rightarrow 4$, after that total score is $15$ and $\text{IQ} = 8$
4. $4 \rightarrow 1$, after that total score is $35$ and $\text{IQ} = 14$

In the third test case optimal sequence of solving problems is as follows: 

1. $1 \rightarrow 3$, after that total score is $17$ and $\text{IQ} = 6$
2. $3 \rightarrow 4$, after that total score is $35$ and $\text{IQ} = 8$
3. $4 \rightarrow 2$, after that total score is $42$ and $\text{IQ} = 12$


#### Tags 

#2500 #NOT OK #bitmasks #dp #graphs #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_708_(Div._2).md)
- [Codeforces Round #708](../blogs/Codeforces_Round_708.md)
- [Tutorial](../blogs/Tutorial.md)
