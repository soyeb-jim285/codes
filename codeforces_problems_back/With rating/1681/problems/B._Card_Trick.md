<h1 style='text-align: center;'> B. Card Trick</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp has just learned a new card trick, and can't wait to present it to you. He shows you the entire deck of $n$ cards. You see that the values of cards from the topmost to the bottommost are integers $a_1, a_2, \dots, a_n$, and all values are different.

Then he asks you to shuffle the deck $m$ times. With the $j$-th shuffle, you should take $b_j$ topmost cards and move them under the remaining $(n - b_j)$ cards without changing the order.

And then, using some magic, Monocarp tells you the topmost card of the deck. However, you are not really buying that magic. You tell him that you know the topmost card yourself. Can you surprise Monocarp and tell him the topmost card before he shows it?

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the number of cards in the deck.

The second line contains $n$ pairwise distinct integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$) — the values of the cards.

The third line contains a single integer $m$ ($1 \le m \le 2 \cdot 10^5$) — the number of shuffles.

The fourth line contains $m$ integers $b_1, b_2, \dots, b_m$ ($1 \le b_j \le n - 1$) — the amount of cards that are moved on the $j$-th shuffle.

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$. The sum of $m$ over all testcases doesn't exceed $2 \cdot 10^5$.

## Output

For each testcase, print a single integer — the value of the card on the top of the deck after the deck is shuffled $m$ times.

## Example

## Input


```

321 231 1 143 1 4 223 152 1 5 4 353 2 1 2 1
```
## Output


```

2
3
3

```
## Note

In the first testcase, each shuffle effectively swaps two cards. After three swaps, the deck will be $[2, 1]$.

In the second testcase, the second shuffle cancels what the first shuffle did. First, three topmost cards went underneath the last card, then that card went back below the remaining three cards. So the deck remained unchanged from the initial one — the topmost card has value $3$.



#### tags 

#800 #implementation #math 