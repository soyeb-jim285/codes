<h1 style='text-align: center;'> H. Exam</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

This year a Chunin Selection Exam is held again in Konoha, and taking part in it are $n$ ninjas named $s_1$, $s_2$, ..., $s_n$. All names are distinct. One of the exam stages consists of fights between the participants. This year the rules determining the ninjas for each fight are the following: ninjas $i$ and $j$ fight against each other if the following conditions are held:

* $i \neq j$;
* $s_{j}$ is a substring of $s_{i}$;
* there is no $k$ except $i$ and $j$ that $s_{j}$ is a substring of $s_{k}$, and $s_{k}$ is a substring of $s_{i}$.

A string $a$ is a substring of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

Your task is to find out how many fights are going to take place this year.

#### Input

The first line consists of the only integer $n$ ($1 \leq n \leq 10^{6}$) standing for the number of examinees.

The following $n$ lines contain their names. No two names coincide, all names are non-empty and consist of lowercase English letters. The total length of all names doesn't exceed $10^6$.

#### Output

Print the only integer standing for the number of fights.

## Examples

#### Input


```text
5
hidan
dan
hanabi
bi
nabi
```
#### Output


```text
3
```
#### Input


```text
4
abacaba
abaca
acaba
aca
```
#### Output


```text
4
```
## Note

In the first example hidan fights against dan, and hanabi fights against nabi, who also fights bi. Ninjas named hanabi and bi don't fight each other since there is the ninja called nabi who breaks the third condition for them.

In the second example the fights are held between abacaba and acaba, abacaba and abaca, acaba and aca, abaca and aca.



#### Tags 

#3400 #NOT OK #data_structures #string_suffix_structures #trees 

## Blogs
- [All Contest Problems](../Технокубок_2021_-_Финал.md)
- [Tutorial](../blogs/Tutorial.md)
