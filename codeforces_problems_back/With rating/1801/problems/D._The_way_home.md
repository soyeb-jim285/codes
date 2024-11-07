<h1 style='text-align: center;'> D. The way home</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

 The famous magician Borya Budini traveled through the country $X$, which consists of $n$ cities. However, an accident happened, and he was robbed in the city number $1$. Now Budini will have a hard way home to the city number $n$.He's going to get there by plane. In total, there are $m$ flights in the country, $i$-th flies from city $a_i$ to city $b_i$ and costs $s_i$ coins. ## Note

 that the $i$-th flight is one-way, so it can't be used to get from city $b_i$ to city $a_i$. To use it, Borya must be in the city $a_i$ and have at least $s_i$ coins (which he will spend on the flight). 

After the robbery, he has only $p$ coins left, but he does not despair! Being in the city $i$, he can organize performances every day, each performance will bring him $w_i$ coins. 

Help the magician find out if he will be able to get home, and what is the minimum number of performances he will have to organize. 

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 80$) – the number of test cases. The description of test cases follows.

The first line contains three integers $n$, $m$ and $p$ ($2 \le n \le 800$, $1 \le m \le 3000$, $0 \le p \le 10^9$) — the number of cities, the number of flights and the initial amount of coins.

The second line contains $n$ integers $w_1, w_2, \ldots, w_n$ $(1 \le w_i \le 10^9)$ — profit from representations.

The following $m$ lines each contain three integers $a_i$, $b_i$ and $s_i$ ($1 \le a_i, b_i \le n$, $1 \le s_i \le 10^9$) — the starting and ending city, and the cost of $i$-th flight.

It is guaranteed that the sum of $n$ over all test cases does not exceed $800$ and the sum of $m$ over all test cases does not exceed $10000$. 

## Output

For each test case print a single integer — the minimum number of performances Borya will have to organize to get home, or $-1$ if it is impossible to do this. 

## Example

 

## Input


```

44 4 27 4 3 11 2 213 2 61 3 82 4 114 4 101 2 10 11 2 202 4 301 3 253 4 894 4 75 1 6 21 2 52 3 103 4 503 4 704 1 21 1 1 11 3 2
```
## Output


```

4
24
10
-1

```
 ## Note

In the first example, it is optimal for Borya to make $4$ performances in the first city, having as a result $2 + 7 \cdot 4 = 30$ coins, and then walk along the route $1-3-2-4$, spending $6+8+11=25$ coins. In the second example, it is optimal for Borya to make $15$ performances in the first city, fly to $3$ city, make $9$ performances there, and then go to $4$ city. 



#### tags 

#2100 #binary_search #data_structures #dp #graphs #greedy #shortest_paths #sortings 