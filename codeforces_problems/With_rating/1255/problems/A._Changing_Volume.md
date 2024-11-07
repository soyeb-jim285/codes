<h1 style='text-align: center;'> A. Changing Volume</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bob watches TV every day. He always sets the volume of his TV to $b$. However, today he is angry to find out someone has changed the volume to $a$. Of course, Bob has a remote control that can change the volume.

There are six buttons ($-5, -2, -1, +1, +2, +5$) on the control, which in one press can either increase or decrease the current volume by $1$, $2$, or $5$. The volume can be arbitrarily large, but can never be negative. In other words, Bob cannot press the button if it causes the volume to be lower than $0$.

As Bob is so angry, he wants to change the volume to $b$ using as few button presses as possible. However, he forgets how to do such simple calculations, so he asks you for help. Write a program that given $a$ and $b$, finds the minimum number of presses to change the TV volume from $a$ to $b$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $T$ ($1 \le T \le 1\,000$). Then the descriptions of the test cases follow.

Each test case consists of one line containing two integers $a$ and $b$ ($0 \le a, b \le 10^{9}$) — the current volume and Bob's desired volume, respectively.

### Output

For each test case, output a single integer — the minimum number of presses to change the TV volume from $a$ to $b$. If Bob does not need to change the volume (i.e. $a=b$), then print $0$.

## Example

### Input


```text
3
4 0
5 14
3 9
```
### Output


```text
2
3
2
```
## Note

In the first example, Bob can press the $-2$ button twice to reach $0$. 
## Note

 that Bob can not press $-5$ when the volume is $4$ since it will make the volume negative. 

In the second example, one of the optimal ways for Bob is to press the $+5$ twice, then press $-1$ once.

In the last example, Bob can press the $+5$ once, then press $+1$. 



#### Tags 

#800 #NOT OK #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_601_(Div._2).md)
- [Codeforces Round #601 (en)](../blogs/Codeforces_Round_601_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
