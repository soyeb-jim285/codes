<h1 style='text-align: center;'> F. Dish Shopping</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $m$ people living in a city. There are $n$ dishes sold in the city. Each dish $i$ has a price $p_i$, a standard $s_i$ and a beauty $b_i$. Each person $j$ has an income of $inc_j$ and a preferred beauty $pref_j$. 

A person would never buy a dish whose standard is less than the person's income. Also, a person can't afford a dish with a price greater than the income of the person. In other words, a person $j$ can buy a dish $i$ only if $p_i \leq inc_j \leq s_i$.

Also, a person $j$ can buy a dish $i$, only if $|b_i-pref_j| \leq (inc_j-p_i)$. In other words, if the price of the dish is less than the person's income by $k$, the person will only allow the absolute difference of at most $k$ between the beauty of the dish and his/her preferred beauty. 

Print the number of dishes that can be bought by each person in the city.

## Input

The first line contains two integers $n$ and $m$ ($1 \leq n \leq 10^5$, $1 \leq m \leq 10^5$), the number of dishes available in the city and the number of people living in the city.

The second line contains $n$ integers $p_i$ ($1 \leq p_i \leq 10^9$), the price of each dish.

The third line contains $n$ integers $s_i$ ($1 \leq s_i \leq 10^9$), the standard of each dish.

The fourth line contains $n$ integers $b_i$ ($1 \leq b_i \leq 10^9$), the beauty of each dish.

The fifth line contains $m$ integers $inc_j$ ($1 \leq inc_j \leq 10^9$), the income of every person.

The sixth line contains $m$ integers $pref_j$ ($1 \leq pref_j \leq 10^9$), the preferred beauty of every person.

It is guaranteed that for all integers $i$ from $1$ to $n$, the following condition holds: $p_i \leq s_i$.

## Output

Print $m$ integers, the number of dishes that can be bought by every person living in the city.

## Examples

## Input


```

3 3
2 1 3
2 4 4
2 1 1
2 2 3
1 2 4

```
## Output


```

1 2 0 
```
## Input


```

4 3
1 2 1 1
3 3 1 3
2 1 3 2
1 1 3
1 2 1

```
## Output


```

0 2 3 
```
## Note

In the first example, the first person can buy dish $2$, the second person can buy dishes $1$ and $2$ and the third person can buy no dishes.

In the second example, the first person can buy no dishes, the second person can buy dishes $1$ and $4$, and the third person can buy dishes $1$, $2$ and $4$.



#### tags 

#2500 #data_structures #divide_and_conquer 