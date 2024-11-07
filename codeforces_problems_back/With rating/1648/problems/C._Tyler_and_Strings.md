<h1 style='text-align: center;'> C. Tyler and Strings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

While looking at the kitchen fridge, the little boy Tyler noticed magnets with symbols, that can be aligned into a string $s$.

Tyler likes strings, and especially those that are lexicographically smaller than another string, $t$. After playing with magnets on the fridge, he is wondering, how many distinct strings can be composed out of letters of string $s$ by rearranging them, so that the resulting string is lexicographically smaller than the string $t$? Tyler is too young, so he can't answer this question. The alphabet Tyler uses is very large, so for your convenience he has already replaced the same letters in $s$ and $t$ to the same integers, keeping that different letters have been replaced to different integers.

We call a string $x$ lexicographically smaller than a string $y$ if one of the followings conditions is fulfilled: 

* There exists such position of symbol $m$ that is presented in both strings, so that before $m$-th symbol the strings are equal, and the $m$-th symbol of string $x$ is smaller than $m$-th symbol of string $y$.
* String $x$ is the prefix of string $y$ and $x \neq y$.

Because the answer can be too large, print it modulo $998\,244\,353$.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 200\,000$) — the lengths of strings $s$ and $t$ respectively.

The second line contains $n$ integers $s_1, s_2, s_3, \ldots, s_n$ ($1 \le s_i \le 200\,000$) — letters of the string $s$.

The third line contains $m$ integers $t_1, t_2, t_3, \ldots, t_m$ ($1 \le t_i \le 200\,000$) — letters of the string $t$.

## Output

Print a single number — the number of strings lexicographically smaller than $t$ that can be obtained by rearranging the letters in $s$, modulo $998\,244\,353$.

## Examples

## Input


```

3 4
1 2 2
2 1 2 1

```
## Output


```

2

```
## Input


```

4 4
1 2 3 4
4 3 2 1

```
## Output


```

23

```
## Input


```

4 3
1 1 1 2
1 1 2

```
## Output


```

1

```
## Note

In the first example, the strings we are interested in are $[1\, 2\, 2]$ and $[2\, 1\, 2]$. The string $[2\, 2\, 1]$ is lexicographically larger than the string $[2\, 1\, 2\, 1]$, so we don't count it.

In the second example, all strings count except $[4\, 3\, 2\, 1]$, so the answer is $4! - 1 = 23$.

In the third example, only the string $[1\, 1\, 1\, 2]$ counts.



#### tags 

#1900 #combinatorics #data_structures #implementation 