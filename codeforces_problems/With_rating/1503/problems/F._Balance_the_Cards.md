<h1 style='text-align: center;'> F. Balance the Cards</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A balanced bracket sequence is defined as an integer sequence that can be built with the following rules:

* The empty sequence is balanced.
* If $[a_1,\ldots,a_n]$ and $[b_1,\ldots, b_m]$ are balanced, then their concatenation $[a_1,\ldots,a_n,b_1,\ldots,b_m]$ is balanced.
* If $x$ is a positive integer and $[a_1,\ldots,a_n]$ is balanced, then $[x,a_1,\ldots,a_n,-x]$ is balanced.

The positive numbers can be imagined as opening brackets and the negative numbers as closing brackets, where matching brackets must have the same type (absolute value). For example, $[1, 2, -2, -1]$ and $[1, 3, -3, 2, -2, -1]$ are balanced, but $[1, 2, -1, -2]$ and $[-1, 1]$ are not balanced.

There are $2n$ cards. Each card has a number on the front and a number on the back. Each integer $1,-1,2,-2,\ldots,n,-n$ appears exactly once on the front of some card and exactly once on the back of some (not necessarily the same) card.

You can reorder the cards however you like. You are not allowed to flip cards, so numbers cannot move between the front and back. Your task is to order the cards so that the sequences given by the front numbers and the back numbers are both balanced, or report that it is impossible.

#### Input

The first line contains a single integer $n$ ($1\le n\le 2\cdot 10^5$) — the number of bracket types, and half the number of cards.

The next $2n$ lines describe the cards. The $i$-th of these lines contains two integers $a_i$, $b_i$ ($-n\le a_i,b_i\le n$, $a_i\ne 0$, $b_i\ne 0$) — the numbers on the front and back of the $i$-th card, respectively. Every integer $1,-1,2,-2,\ldots,n,-n$ appears exactly once as $a_i$ and exactly once as $b_i$.

#### Output

On the first line, output "YES" if it's possible to reorder these cards to satisfy the condition. Otherwise, output "NO". You can print each letter in any case (upper or lower).

If it is possible, on the next $2n$ lines output the cards in an order so that the front and back are both balanced. If there are multiple solutions, you may output any.

## Examples

#### Input


```text
5
1 3
-3 -5
4 -3
2 2
-1 -4
-2 5
3 -1
5 1
-4 4
-5 -2
```
#### Output


```text
YES
1 3
4 -3
-4 4
-1 -4
5 1
3 -1
2 2
-2 5
-3 -5
-5 -2
```
#### Input


```text
2
1 1
-1 2
2 -1
-2 -2
```
#### Output


```text
NO
```
## Note

In the first test case, the front numbers create the balanced sequence $[1,4,-4,-1,5,3,2,-2,-3,-5]$ and the back numbers create the balanced sequence $[3,-3,4,-4,1,-1,2,5,-5,-2]$.

In the second test case, the cards are given in an order so that the front numbers are balanced, but the back numbers create the unbalanced sequence $[1,2,-1,-2]$. If we swapped the second and third cards, we would balance the back numbers and unbalance the front numbers. But there is no order that balances both.



#### Tags 

#3500 #NOT OK #constructive_algorithms #data_structures #divide_and_conquer #geometry #graphs #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_712_(Div._1).md)
- [Codeforces Round #712 (en)](../blogs/Codeforces_Round_712_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
