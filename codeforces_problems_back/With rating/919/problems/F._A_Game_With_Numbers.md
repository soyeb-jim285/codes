<h1 style='text-align: center;'> F. A Game With Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Imagine that Alice is playing a card game with her friend Bob. They both have exactly $8$ cards and there is an integer on each card, ranging from $0$ to $4$. In each round, Alice or Bob in turns choose two cards from different players, let them be $a$ and $b$, where $a$ is the number on the player's card, and $b$ is the number on the opponent's card. It is necessary that $a \cdot b \ne 0$. Then they calculate $c = (a + b) \bmod 5$ and replace the number $a$ with $c$. The player who ends up with numbers on all $8$ cards being $0$, wins.

Now Alice wants to know who wins in some situations. She will give you her cards' numbers, Bob's cards' numbers and the person playing the first round. Your task is to determine who wins if both of them choose the best operation in their rounds.

## Input

The first line contains one positive integer $T$ ($1 \leq T \leq 100\,000$), denoting the number of situations you need to consider.

The following lines describe those $T$ situations. For each situation:

* The first line contains a non-negative integer $f$ ($0 \leq f \leq 1$), where $f = 0$ means that Alice plays first and $f = 1$ means Bob plays first.
* The second line contains $8$ non-negative integers $a_1, a_2, \ldots, a_8$ ($0 \leq a_i \leq 4$), describing Alice's cards.
* The third line contains $8$ non-negative integers $b_1, b_2, \ldots, b_8$ ($0 \leq b_i \leq 4$), describing Bob's cards.

We guarantee that if $f=0$, we have $\sum_{i=1}^{8}a_i \ne 0$. Also when $f=1$, $\sum_{i=1}^{8}b_i \ne 0$ holds.

## Output

## Output

 $T$ lines. For each situation, determine who wins. ## Output

 

* "Alice" (without quotes) if Alice wins.
* "Bob" (without quotes) if Bob wins.
* "Deal" (without quotes) if it gets into a deal, i.e. no one wins.
## Example

## Input


```
4  
1  
0 0 0 0 0 0 0 0  
1 2 3 4 1 2 3 4  
1  
0 0 0 1 0 0 0 0  
0 0 0 0 4 0 0 0  
0  
1 0 0 0 0 0 0 0  
0 0 0 4 0 0 2 0  
1  
1 1 1 1 1 1 1 1  
1 1 1 1 1 1 1 1  

```
## Output


```
Alice  
Bob  
Alice  
Deal  

```
## Note

In the first situation, Alice has all her numbers $0$. So she wins immediately.

In the second situation, Bob picks the numbers $4$ and $1$. Because we have $(4 + 1) \bmod 5 = 0$, Bob wins after this operation.

In the third situation, Alice picks the numbers $1$ and $4$. She wins after this operation.

In the fourth situation, we can prove that it falls into a loop.



#### tags 

#2600 #games #graphs #shortest_paths 