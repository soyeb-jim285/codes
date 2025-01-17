<h1 style='text-align: center;'> F. Speed Dial</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp's phone book contains $n$ phone numbers, each of them is described by $s_i$ — the number itself and $m_i$ — the number of times Polycarp dials it in daily.

Polycarp has just bought a brand new phone with an amazing speed dial feature! More precisely, $k$ buttons on it can have a number assigned to it (not necessary from the phone book). To enter some number Polycarp can press one of these $k$ buttons and then finish the number using usual digit buttons (entering a number with only digit buttons is also possible).

Speed dial button can only be used when no digits are entered. No button can have its number reassigned.

What is the minimal total number of digit number presses Polycarp can achieve after he assigns numbers to speed dial buttons and enters each of the numbers from his phone book the given number of times in an optimal way?

#### Input

The first line contains two integers $n$ and $k$ ($1 \le n \le 500$, $1 \le k \le 10$) — the amount of numbers in Polycarp's phone book and the number of speed dial buttons his new phone has.

The $i$-th of the next $n$ lines contain a string $s_i$ and an integer $m_i$ $(1 \le m_i \le 500)$, where $s_i$ is a non-empty string of digits from $0$ to $9$ inclusive (the $i$-th number), and $m_i$ is the amount of times it will be dialed, respectively.

It is guaranteed that the total length of all phone numbers will not exceed $500$.

#### Output

Print a single integer — the minimal total number of digit number presses Polycarp can achieve after he assigns numbers to speed dial buttons and enters each of the numbers from his phone book the given number of times in an optimal way.

## Examples

#### Input


```text
3 1
0001 5
001 4
01 1
```
#### Output


```text
14
```
#### Input


```text
3 1
0001 5
001 6
01 1
```
#### Output


```text
18
```
## Note

The only speed dial button in the first example should have "0001" on it. The total number of digit button presses will be $0 \cdot 5$ for the first number + $3 \cdot 4$ for the second + $2 \cdot 1$ for the third. $14$ in total.

The only speed dial button in the second example should have "00" on it. The total number of digit button presses will be $2 \cdot 5$ for the first number + $1 \cdot 6$ for the second + $2 \cdot 1$ for the third. $18$ in total.



#### Tags 

#2800 #NOT OK #dp #strings #trees 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_55_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
