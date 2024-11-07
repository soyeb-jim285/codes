<h1 style='text-align: center;'> G. Game Relics</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Esports is a form of competitive sports using video games. Dota 2 is one of the most popular competitive video games in Esports. Recently, a new video game Dota 3 was released. In Dota 3 a player can buy some relics for their hero. Relics are counters that track hero's actions and statistics in a game.

Gloria likes to play Dota 3, so she wants to buy all $n$ available relics for her favorite hero.

Relics can be bought using an in-game currency called shards. Each relic has its own price — $c_i$ shards for the $i$-th relic. A player can buy a relic using one of the following options: 

* Pay $c_i$ shards to buy the $i$-th relic;
* Pay $x$ shards and randomly get one of all $n$ relics. The probability of getting a relic is the same for all $n$ relics. If a duplicate relic is received, then the relic is recycled and $\frac{x}{2}$ shards are given back to the player.

Gloria wants to buy all $n$ relics. Help her minimize the expected number of shards she spends to buy all the relics.

#### Input

The first line contains two integers $n$ and $x$ ($1 \le n \le 100$; $1 \le x \le 10\,000$) — the number of relics and the cost to receive a random relic.

The second line consists of $n$ integers $c_1, c_2, \ldots, c_n$ ($x \le c_i \le 10\,000$; $\sum{c_i} \le 10\,000$) — the prices of $n$ relics.

#### Output

Print a single real number — the minimum expected number of shards that Gloria must spend to buy all the relics.

The absolute or relative error should not exceed $10^{-9}$.

## Examples

#### Input


```text
2 20
25 100
```
#### Output


```text
47.50000000000000000
```
#### Input


```text
4 30
60 50 60 80
```
#### Output


```text
171.25000000000000000
```
## Note

In the first example, the optimal strategy is to randomly get one of the two relics paying $20$ shards. Then there are two scenarios. 

The first one happens if Gloria receives the first relic. Then she keeps getting random relics until she obtains the second relic. The expected number of shards to spend in this scenario is $20 + 30 = 50$.

In the second scenario, Gloria initially gets the second relic. Then it is better to buy the first relic for $25$ shards, so the expected number of shards to spend in this scenario is $20 + 25 = 45$.

Thus, the expected number of shards to spend is $\frac{50 + 45}{2} = 47.5$.



#### Tags 

#3000 #NOT OK #math #probabilities 

## Blogs
- [All Contest Problems](../2019-2020_ICPC,_NERC,_Northern_Eurasia_Finals_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
