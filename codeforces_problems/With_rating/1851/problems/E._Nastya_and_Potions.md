<h1 style='text-align: center;'> E. Nastya and Potions</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alchemist Nastya loves mixing potions. There are a total of $n$ types of potions, and one potion of type $i$ can be bought for $c_i$ coins.

Any kind of potions can be obtained in no more than one way, by mixing from several others. The potions used in the mixing process will be consumed. Moreover, no potion can be obtained from itself through one or more mixing processes.

As an experienced alchemist, Nastya has an unlimited supply of $k$ types of potions $p_1, p_2, \dots, p_k$, but she doesn't know which one she wants to obtain next. To decide, she asks you to find, for each $1 \le i \le n$, the minimum number of coins she needs to spend to obtain a potion of type $i$ next.

#### Input

The first line of each test contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case is described as follows:

The first line contains two integers $n$ and $k$ ($1 \le k < n \le 2 \cdot 10^5$) — the total number of potion types and the number of potion types Nastya already has.

The second line contains $n$ integers $c_1, c_2, \dots, c_n$ ($1 \le c_i \le 10^9$) — the costs of buying the potions.

The third line contains $k$ distinct integers $p_1, p_2, \dots, p_k$ ($1 \le p_i \le n$) — the indices of potions Nastya already has an unlimited supply of.

This is followed by $n$ lines describing ways to obtain potions by mixing.

Each line starts with the integer $m_i$ ($0 \le m_i < n$) — the number of potions required to mix a potion of the type $i$ ($1 \le i \le n$).

Then line contains $m_i$ distinct integers $e_1, e_2, \dots, e_{m_i}$ ($1 \le e_j \le n$, $e_j \ne i$) — the indices of potions needed to mix a potion of the type $i$. If this list is empty, then a potion of the type $i$ can only be bought.

It is guaranteed that no potion can be obtained from itself through one or more mixing processes.

It is guaranteed that the sum of all $n$ values across all test cases does not exceed $2 \cdot 10^5$. Similarly, it is guaranteed that the sum of all $m_i$ values across all test cases does not exceed $2 \cdot 10^5$.

#### Output

For each test case, output $n$ integers — the minimum number of coins Nastya needs to spend to obtain a potion of each type.

## Examples

#### Input


```text
45 130 8 3 5 1033 2 4 50 0 2 3 50 3 25 143 31 31 20 2 1 25 15 4 1 3 422 4 53 3 5 42 1 41 50 4 21 1 5 42 43 2 4 30 2 2 41 2
```
#### Output

```text

23 8 0 5 10 
0 143 0 
5 0 1 3 4 
0 0 0 0 

```
#### Input


```text
36 35 5 4 5 2 23 4 52 2 51 53 4 1 64 2 6 1 50 0 6 21 4 4 1 5 23 64 6 3 4 54 6 5 3 40 1 51 60 2 14 310 1 1
```
#### Output

```text

0 0 0 0 0 2 
0 0 0 0 0 0 
0 0 

```
## Note

In the first test case of the first sample, it is optimal:

* Get a potion of the first type by buying and mixing $2$, $4$ and $5$;
* a potion of the second type can only be obtained by purchasing it;
* Nastya already has an unlimited number of potions of the third type;
* a potion of the fourth type is more profitable to buy than to buy and mix other potions;
* a potion of the fifth type can only be obtained by purchasing it.


#### Tags 

#1500 #OK #dfs_and_similar #dp #graphs #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_888_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
