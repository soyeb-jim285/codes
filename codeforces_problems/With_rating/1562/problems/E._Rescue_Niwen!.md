<h1 style='text-align: center;'> E. Rescue Niwen!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

 Morning desert sun horizonRise above the sands of time...

Fates Warning, "Exodus"After crossing the Windswept Wastes, Ori has finally reached the Windtorn Ruins to find the Heart of the Forest! However, the ancient repository containing this priceless Willow light did not want to open!

Ori was taken aback, but the Voice of the Forest explained to him that the cunning Gorleks had decided to add protection to the repository.

The Gorleks were very fond of the "string expansion" operation. They were also very fond of increasing subsequences.

Suppose a string $s_1s_2s_3 \ldots s_n$ is given. Then its "expansion" is defined as the sequence of strings $s_1$, $s_1 s_2$, ..., $s_1 s_2 \ldots s_n$, $s_2$, $s_2 s_3$, ..., $s_2 s_3 \ldots s_n$, $s_3$, $s_3 s_4$, ..., $s_{n-1} s_n$, $s_n$. For example, the "expansion" the string 'abcd' will be the following sequence of strings: 'a', 'ab', 'abc', 'abcd', 'b', 'bc', 'bcd', 'c', 'cd', 'd'. 

To open the ancient repository, Ori must find the size of the largest increasing subsequence of the "expansion" of the string $s$. Here, strings are compared lexicographically.

Help Ori with this task!

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds:

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
### Input

Each test contains multiple test cases.

The first line contains one positive integer $t$ ($1 \le t \le 10^3$), denoting the number of test cases. Description of the test cases follows.

The first line of each test case contains one positive integer $n$ ($1 \le n \le 5000$) — length of the string.

The second line of each test case contains a non-empty string of length $n$, which consists of lowercase latin letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^4$.

### Output

For every test case print one non-negative integer — the answer to the problem.

## Example

### Input


```text
7
5
acbac
8
acabacba
12
aaaaaaaaaaaa
10
abacabadac
8
dcbaabcd
3
cba
6
sparky
```
### Output


```text
9
17
12
29
14
3
9
```
## Note

In first test case the "expansion" of the string is: 'a', 'ac', 'acb', 'acba', 'acbac', 'c', 'cb', 'cba', 'cbac', 'b', 'ba', 'bac', 'a', 'ac', 'c'. The answer can be, for example, 'a', 'ac', 'acb', 'acba', 'acbac', 'b', 'ba', 'bac', 'c'.



#### Tags 

#2500 #NOT OK #dp #greedy #string_suffix_structures #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_741_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
