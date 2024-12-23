<h1 style='text-align: center;'> H. Palindrome Addicts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

Your task is to maintain a [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) consisting of lowercase English letters as follows: 

* "push $c$": insert a letter $c$ at the back of the queue;
* "pop": delete a letter from the front of the queue.

Initially, the queue is empty. 

After each operation, you are asked to count the number of distinct palindromic substrings in the string that are obtained by concatenating the letters from the front to the back of the queue.

Especially, the number of distinct palindromic substrings of the empty string is $0$. 

A string $s[1..n]$ of length $n$ is palindromic if $s[i] = s[n-i+1]$ for every $1 \leq i \leq n$. 

The string $s[l..r]$ is a substring of string $s[1..n]$ for every $1 \leq l \leq r \leq n$. 

Two strings $s[1..n]$ and $t[1..m]$ are distinct, if at least one of the following holds. 

* $n \neq m$;
* $s[i] \neq t[i]$ for some $1 \leq i \leq \min\{n,m\}$.
### Input

The first line is an integer $q$ ($1 \leq q \leq 10^6$), indicating the number of operations.

Then $q$ lines follow. Each of the following lines contains one of the operations as follows. 

* "push $c$": insert a letter $c$ at the back of the queue, where $c$ is a lowercase English letter;
* "pop": delete a letter from the front of the queue.

It is guaranteed that no "pop" operation will be performed when the queue is empty.

### Output

After each operation, print the number of distinct palindromic substrings in the string presented in the queue. 

## Example

### Input


```text
12
push a
pop
push a
push a
push b
push b
push a
push a
pop
pop
pop
push b
```
### Output


```text
1
0
1
2
3
4
5
6
5
4
3
4
```
## Note

Let $s_k$ be the string presented in the queue after the $k$-th operation, and let $c_k$ be the number of distinct palindromic substrings of $s_k$. The following table shows the details of the example.

 

| $k$ | $s_k$ | $c_k$ |
| --- | --- | --- |
| $1$ | $a$ | $1$ |
| $2$ | $\textsf{empty}$ | $0$ |
| $3$ | $a$ | $1$ |
| $4$ | $aa$ | $2$ |
| $5$ | $aab$ | $3$ |
| $6$ | $aabb$ | $4$ |
| $7$ | $aabba$ | $5$ |
| $8$ | $aabbaa$ | $6$ |
| $9$ | $abbaa$ | $5$ |
| $10$ | $bbaa$ | $4$ |
| $11$ | $baa$ | $3$ |
| $12$ | $baab$ | $4$ |

 It is worth pointing out that 

* After the $2$-nd operation, the string is empty and thus has no substrings. So the answer is $0$;
* After the $8$-th operation, the string is "$aabbaa$". The $6$ distinct palindromic substrings are "$a$", "$aa$", "$aabbaa$", "$abba$", "$b$", and "$bb$".


#### Tags 

#3300 #NOT OK #data_structures #strings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_22.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
