<h1 style='text-align: center;'> D. Color with Occurrences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given some text $t$ and a set of $n$ strings $s_1, s_2, \dots, s_n$. 

In one step, you can choose any occurrence of any string $s_i$ in the text $t$ and color the corresponding characters of the text in red. For example, if $t=\texttt{bababa}$ and $s_1=\texttt{ba}$, $s_2=\texttt{aba}$, you can get $t=\color{red}{\texttt{ba}}\texttt{baba}$, $t=\texttt{b}\color{red}{\texttt{aba}}\texttt{ba}$ or $t=\texttt{bab}\color{red}{\texttt{aba}}$ in one step.

You want to color all the letters of the text $t$ in red. When you color a letter in red again, it stays red.

In the example above, three steps are enough:

* Let's color $t[2 \dots 4]=s_2=\texttt{aba}$ in red, we get $t=\texttt{b}\color{red}{\texttt{aba}}\texttt{ba}$;
* Let's color $t[1 \dots 2]=s_1=\texttt{ba}$ in red, we get $t=\color{red}{\texttt{baba}}\texttt{ba}$;
* Let's color $t[4 \dots 6]=s_2=\texttt{aba}$ in red, we get $t=\color{red}{\texttt{bababa}}$.

Each string $s_i$ can be applied any number of times (or not at all). Occurrences for coloring can intersect arbitrarily.

Determine the minimum number of steps needed to color all letters $t$ in red and how to do it. If it is impossible to color all letters of the text $t$ in red, output -1.

### Input

The first line of the input contains an integer $q$ ($1 \le q \le 100$) —the number of test cases in the test.

The descriptions of the test cases follow.

The first line of each test case contains the text $t$ ($1 \le |t| \le 100$), consisting only of lowercase Latin letters, where $|t|$ is the length of the text $t$.

The second line of each test case contains a single integer $n$ ($1 \le n \le 10$) — the number of strings in the set.

This is followed by $n$ lines, each containing a string $s_i$ ($1 \le |s_i| \le 10$) consisting only of lowercase Latin letters, where $|s_i|$ — the length of string $s_i$.

### Output

For each test case, print the answer on a separate line.

If it is impossible to color all the letters of the text in red, print a single line containing the number -1.

Otherwise, on the first line, print the number $m$ — the minimum number of steps it will take to turn all the letters $t$ red.

Then in the next $m$ lines print pairs of indices: $w_j$ and $p_j$ ($1 \le j \le m$), which denote that the string with index $w_j$ was used as a substring to cover the occurrences starting in the text $t$ from position $p_j$. The pairs can be output in any order.

If there are several answers, output any of them.

## Example

### Input


```text
6bababa2baabacaba2bacacababacabaca3ababacacabaca3acbcodeforces4defcodeefoforcesaaaabbbbcccceeee4eeeeccccaaaabbbb
```
### Output

```text

3
2 2
1 1
2 4
-1
4
1 1
2 6
3 3
3 7
4
3 1
1 2
2 3
1 4
2
4 5
2 1
4
3 1
4 5
2 9
1 13
```
## Note

The first test case is explained in the problem statement.

In the second test case, it is impossible to color all the letters of the text in red.



#### Tags 

#1600 #NOT OK #brute_force #data_structures #dp #greedy #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_811_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
