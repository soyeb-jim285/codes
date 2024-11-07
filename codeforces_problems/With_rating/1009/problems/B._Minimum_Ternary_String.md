<h1 style='text-align: center;'> B. Minimum Ternary String</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a ternary string (it is a string which consists only of characters '0', '1' and '2').

You can swap any two adjacent (consecutive) characters '0' and '1' (i.e. replace "01" with "10" or vice versa) or any two adjacent (consecutive) characters '1' and '2' (i.e. replace "12" with "21" or vice versa).

For example, for string "010210" we can perform the following moves: 

* "010210" $\rightarrow$ "100210";
* "010210" $\rightarrow$ "001210";
* "010210" $\rightarrow$ "010120";
* "010210" $\rightarrow$ "010201".

Note than you cannot swap "02" $\rightarrow$ "20" and vice versa. You cannot perform any other operations with the given string excluding described above.

You task is to obtain the minimum possible (lexicographically) string by using these swaps arbitrary number of times (possibly, zero).

String $a$ is lexicographically less than string $b$ (if strings $a$ and $b$ have the same length) if there exists some position $i$ ($1 \le i \le |a|$, where $|s|$ is the length of the string $s$) such that for every $j < i$ holds $a_j = b_j$, and $a_i < b_i$.

##### Input

The first line of the input contains the string $s$ consisting only of characters '0', '1' and '2', its length is between $1$ and $10^5$ (inclusive).

##### Output

Print a single string — the minimum possible (lexicographically) string you can obtain by using the swaps described above arbitrary number of times (possibly, zero).

## Examples

##### Input


```text
100210  

```
##### Output


```text
001120  

```
##### Input


```text
11222121  

```
##### Output


```text
11112222  

```
##### Input


```text
20  

```
##### Output


```text
20  

```


#### Tags 

#1400 #NOT OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_47_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
