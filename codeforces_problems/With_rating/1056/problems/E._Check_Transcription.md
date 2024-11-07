<h1 style='text-align: center;'> E. Check Transcription</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One of Arkady's friends works at a huge radio telescope. A few decades ago the telescope has sent a signal $s$ towards a faraway galaxy. Recently they've received a response $t$ which they believe to be a response from aliens! The scientists now want to check if the signal $t$ is similar to $s$.

The original signal $s$ was a sequence of zeros and ones (everyone knows that binary code is the universe-wide language). The returned signal $t$, however, does not look as easy as $s$, but the scientists don't give up! They represented $t$ as a sequence of English letters and say that $t$ is similar to $s$ if you can replace all zeros in $s$ with some string $r_0$ and all ones in $s$ with some other string $r_1$ and obtain $t$. The strings $r_0$ and $r_1$ must be different and non-empty.

Please help Arkady's friend and find the number of possible replacements for zeros and ones (the number of pairs of strings $r_0$ and $r_1$) that transform $s$ to $t$.

#### Input

The first line contains a string $s$ ($2 \le |s| \le 10^5$) consisting of zeros and ones — the original signal.

The second line contains a string $t$ ($1 \le |t| \le 10^6$) consisting of lowercase English letters only — the received signal.

It is guaranteed, that the string $s$ contains at least one '0' and at least one '1'.

#### Output

Print a single integer — the number of pairs of strings $r_0$ and $r_1$ that transform $s$ to $t$.

In case there are no such pairs, print $0$.

## Examples

#### Input


```text
01
aaaaaa
```
#### Output


```text
4
```
#### Input


```text
001
kokokokotlin
```
#### Output


```text
2
```
## Note

In the first example, the possible pairs $(r_0, r_1)$ are as follows:

* "a", "aaaaa"
* "aa", "aaaa"
* "aaaa", "aa"
* "aaaaa", "a"

 The pair "aaa", "aaa" is not allowed, since $r_0$ and $r_1$ must be different.

In the second example, the following pairs are possible: 

* "ko", "kokotlin"
* "koko", "tlin"


#### Tags 

#2100 #NOT OK #brute_force #data_structures #hashing #strings 

## Blogs
- [All Contest Problems](../Mail.Ru_Cup_2018_Round_3.md)
- [Mail.Ru Cup 2018 Round 3](../blogs/Mail.Ru_Cup_2018_Round_3.md)
- [Tutorial](../blogs/Tutorial.md)
