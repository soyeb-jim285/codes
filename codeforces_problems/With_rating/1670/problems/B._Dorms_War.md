<h1 style='text-align: center;'> B. Dorms War</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Hosssam decided to sneak into Hemose's room while he is sleeping and change his laptop's password. He already knows the password, which is a string $s$ of length $n$. He also knows that there are $k$ special letters of the alphabet: $c_1,c_2,\ldots, c_k$.

Hosssam made a program that can do the following.

1. The program considers the current password $s$ of some length $m$.
2. Then it finds all positions $i$ ($1\le i<m$) such that $s_{i+1}$ is one of the $k$ special letters.
3. Then it deletes all of those positions from the password $s$ even if $s_{i}$ is a special character. If there are no positions to delete, then the program displays an error message which has a very loud sound.

For example, suppose the string $s$ is "abcdef" and the special characters are 'b' and 'd'. If he runs the program once, the positions $1$ and $3$ will be deleted as they come before special characters, so the password becomes "bdef". If he runs the program again, it deletes position $1$, and the password becomes "def". If he is wise, he won't run it a third time.

Hosssam wants to know how many times he can run the program on Hemose's laptop without waking him up from the sound of the error message. Can you help him?

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^5$) — the number of test cases. Then $t$ test cases follow.

The first line of each test case contains a single integer $n$ ($2 \le n \le 10^5$) — the initial length of the password.

The next line contains a string $s$ consisting of $n$ lowercase English letters — the initial password.

The next line contains an integer $k$ ($1 \le k \le 26$), followed by $k$ distinct lowercase letters $c_1,c_2,\ldots,c_k$ — the special letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

### Output

For each test case, print the maximum number of times Hosssam can run the program without displaying the error message, on a new line.

## Example

### Input


```text
109iloveslim1 s7joobeel2 o e7basiozi2 s i6khater1 r7abobeih6 a b e h i o5zondl5 a b c e f6shoman2 a h7shetwey2 h y5samez1 m6mouraz1 m
```
### Output

```text

5
2
3
5
1
0
3
5
2
0

```
## Note

In the first test case, the program can run $5$ times as follows: $\text{iloveslim} \to \text{ilovslim} \to \text{iloslim} \to \text{ilslim} \to \text{islim} \to \text{slim}$

In the second test case, the program can run $2$ times as follows: $\text{joobeel} \to \text{oel} \to \text{el}$

In the third test case, the program can run $3$ times as follows: $\text{basiozi} \to \text{bioi} \to \text{ii} \to \text{i}$.

In the fourth test case, the program can run $5$ times as follows: $\text{khater} \to \text{khatr} \to \text{khar} \to \text{khr} \to \text{kr} \to \text{r}$

In the fifth test case, the program can run only once as follows: $\text{abobeih} \to \text{h}$

In the sixth test case, the program cannot run as none of the characters in the password is a special character.



#### Tags 

#1100 #NOT OK #brute_force #implementation #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_788_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
