<h1 style='text-align: center;'> D. Shop Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Alice and Bob are playing a game in the shop. There are $n$ items in the shop; each item has two parameters: $a_i$ (item price for Alice) and $b_i$ (item price for Bob).

Alice wants to choose a subset (possibly empty) of items and buy them. After that, Bob does the following: 

* if Alice bought less than $k$ items, Bob can take all of them for free;
* otherwise, he will take $k$ items for free that Alice bought (Bob chooses which $k$ items it will be), and for the rest of the chosen items, Bob will buy them from Alice and pay $b_i$ for the $i$-th item.

Alice's profit is equal to $\sum\limits_{i \in S} b_i - \sum\limits_{j \in T} a_j$, where $S$ is the set of items Bob buys from Alice, and $T$ is the set of items Alice buys from the shop. In other words, Alice's profit is the difference between the amount Bob pays her and the amount she spends buying the items.

Alice wants to maximize her profit, Bob wants to minimize Alice's profit. Your task is to calculate Alice's profit if both Alice and Bob act optimally.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains two integers $n$ and $k$ ($1 \le n \le 2 \cdot 10^5$; $0 \le k \le n$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$).

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le 10^9$).

Additional constraint on the input: the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print a single integer — Alice's profit if both Alice and Bob act optimally.

## Example

### Input


```text
42 02 11 24 11 2 1 43 3 2 34 22 1 1 14 2 3 26 21 3 4 9 1 37 6 8 10 6 8
```
### Output

```text

1
1
0
7

```
## Note

In the first test case, Alice should buy the $2$-nd item and sell it to Bob, so her profit is $2 - 1 = 1$.

In the second test case, Alice should buy the $1$-st, the $2$-nd and the $3$-rd item; then Bob takes the $1$-st item for free and pays for the $2$-nd and the $3$-rd item. Alice's profit is $(3+2) - (1+2+1) = 1$. Bob could take $2$-nd item for free instead; this does not change Alice's profit. Bob won't take the $3$-rd item for free, since this would lead to a profit of $2$.



#### Tags 

#1900 #NOT OK #data_structures #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_165_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
