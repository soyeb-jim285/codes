<h1 style='text-align: center;'> H. Equal LCM Subsets</h1>

<h5 style='text-align: center;'>time limit per test: 10 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given two sets of positive integers $A$ and $B$. You have to find two non-empty subsets $S_A \subseteq A$, $S_B \subseteq B$ so that the least common multiple (LCM) of the elements of $S_A$ is equal to the least common multiple (LCM) of the elements of $S_B$.

### Input

The input consists of multiple test cases. The first line of the input contains one integer $t$ ($1 \leq t \leq 200$), the number of test cases.

For each test case, there is one line containing two integers $n, m$ ($1 \leq n, m \leq 1000$), the sizes of the sets $A$ and $B$, respectively.

The next line contains $n$ distinct integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq 4 \cdot 10^{36}$), the elements of $A$.

The next line contains $m$ distinct integers $b_1, b_2, \ldots, b_m$ ($1 \leq b_i \leq 4 \cdot 10^{36}$), the elements of $B$.

The sum of $n$ for all test cases and the sum of $m$ for all test cases is at most $1000$.

### Output

For each test case, if there do not exist two subsets with equal least common multiple, output one line with NO.

Otherwise, output one line with YES, followed by a line with two integers $|S_A|, |S_B|$ ($1 \leq |S_A| \leq n$, $1 \leq |S_B| \leq m$), the sizes of the subsets $S_A$ and $S_B$

The next line should contain $|S_A|$ integers $x_1, x_2, \ldots, x_{|S_A|}$, the elements of $S_A$, followed by a line with $|S_B|$ integers $y_1, y_2, \ldots, y_{|S_B|}$, the elements of $S_B$. If there are multiple possible pairs of subsets, you can print any.

## Example

### Input


```text
4
3 4
5 6 7
2 8 9 10
4 4
5 6 7 8
2 3 4 9
1 3
1
1 2 3
5 6
3 4 9 7 8
2 15 11 14 20 12
```
### Output


```text
NO
YES
1 2
6
2 3
YES
1 1
1
1
YES
3 2
3 7 4
12 14
```


#### Tags 

#3200 #NOT OK #data_structures #math #number_theory 

## Blogs
- [All Contest Problems](../CodeTON_Round_1_(Div._1_+_Div._2,_Rated,_Prizes!).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
