<h1 style='text-align: center;'> A. Repeating Cipher</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp loves ciphers. He has invented his own cipher called repeating.

Repeating cipher is used for strings. To encrypt the string $s=s_{1}s_{2} \dots s_{m}$ ($1 \le m \le 10$), Polycarp uses the following algorithm:

* he writes down $s_1$ ones,
* he writes down $s_2$ twice,
* he writes down $s_3$ three times,
* ...
* he writes down $s_m$ $m$ times.

For example, if $s$="bab" the process is: "b" $\to$ "baa" $\to$ "baabbb". So the encrypted $s$="bab" is "baabbb".

Given string $t$ — the result of encryption of some string $s$. Your task is to decrypt it, i. e. find the string $s$.

##### Input

The first line contains integer $n$ ($1 \le n \le 55$) — the length of the encrypted string. The second line of the input contains $t$ — the result of encryption of some string $s$. It contains only lowercase Latin letters. The length of $t$ is exactly $n$.

It is guaranteed that the answer to the test exists.

##### Output

Print such string $s$ that after encryption it equals $t$.

## Examples

##### Input


```text
6
baabbb
```
##### Output


```text
bab
```
##### Input

```text

10
ooopppssss

```
##### Output


```text
oops
```
##### Input

```text

1
z

```
##### Output


```text

z
```


#### Tags 

#800 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_529_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
