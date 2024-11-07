<h1 style='text-align: center;'> I. Mind Bloom</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

This is the way it always was. This is the way it always will be. All will be forgotten again soon...Jellyfish is playing a one-player card game called "Slay the Spire". There are $n$ cards in total numbered from $1$ to $n$. The $i$-th card has power $c_i$.

There is a binary string $s$ of length $n$. If $s_i = \texttt{0}$, the $i$-th card is initially in the draw pile. If $s_i = \texttt{1}$, the $i$-th card is initially in Jellyfish's hand.

Jellyfish will repeat the following process until either her hand or the draw pile is empty. 

1. Let $x$ be the power of the card with the largest power in her hand.
2. Place a single card with power $x$ back into the draw pile.
3. Randomly draw $x$ cards from the draw pile. All subsets of $x$ cards from the draw pile have an equal chance of being drawn. If there are fewer than $x$ cards in the draw pile, Jellyfish will draw all cards.

At the end of this process, find the probability that Jellyfish can empty the draw pile, modulo $1\,000\,000\,007$.

Formally, let $M=1\,000\,000\,007$. It can be shown that the answer can be expressed as an irreducible fraction $\frac{p}{q}$, where $p$ and $q$ are integers and $q \not \equiv 0 \pmod{M}$. 
### Output

 the integer equal to $p \cdot q^{-1} \bmod M$. In other words, output such an integer $x$ that $0 \le x < M$ and $x \cdot q \equiv p \pmod{M}$.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1\leq t\leq 100$). The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 120$) — the number of cards.

The second line of each test case contains $n$ integers $c_1,c_2,\ldots,c_n$ ($0 \leq c_i \leq n$) — the powers of the cards. It is guaranteed that $c_1 \leq c_2 \leq \ldots \leq c_n$.

The third line of each test case contains a binary string $s$ of length $n$. If $s_i = \texttt{0}$, the $i$-th card is initially in the draw pile. If $s_i = \texttt{1}$, the $i$-th card is initially in Jellyfish's hand.

It is guaranteed that the sum of $n^2$ over all test cases does not exceed $120^2$.

### Output

For each test case, output the probability that Jellyfish can empty the draw pile modulo $1\,000\,000\,007$.

## Example

### Input


```text
450 1 1 1 20010032 3 3000100 0 0 0 0 0 0 1 1 11111011111200 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 2 3 3 400000000001000101010
```
### Output

```text

500000004
0
0
675898154

```
## Note

In the first test case, Jellyfish will keep playing cards with power $1$ until Jellyfish draws a card with power $0$ or power $2$. If Jellyfish draws a card with power $0$, she will eventually empty her hand. If Jellyfish draws a card with power $2$, she will eventually empty the draw pile. Since there is an equal chance of drawing $0$ or $2$, the answer is $\frac{1}{2}$, and $2 \cdot 500\,000\,004 \equiv 1 \pmod {10^9+7}$



#### Tags 

#3500 #NOT OK #dp 

## Blogs
- [All Contest Problems](../Codeforces_Round_947_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
