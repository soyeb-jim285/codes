<h1 style='text-align: center;'> B. Letters Shop</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The letters shop showcase is a string $s$, consisting of $n$ lowercase Latin letters. As the name tells, letters are sold in the shop.

Letters are sold one by one from the leftmost to the rightmost. Any customer can only buy some prefix of letters from the string $s$.

There are $m$ friends, the $i$-th of them is named $t_i$. Each of them is planning to estimate the following value: how many letters (the length of the shortest prefix) would s/he need to buy if s/he wanted to construct her/his name of bought letters. The name can be constructed if each letter is presented in the equal or greater amount.

* For example, for $s$="arrayhead" and $t_i$="arya" $5$ letters have to be bought ("arrayhead").
* For example, for $s$="arrayhead" and $t_i$="harry" $6$ letters have to be bought ("arrayhead").
* For example, for $s$="arrayhead" and $t_i$="ray" $5$ letters have to be bought ("arrayhead").
* For example, for $s$="arrayhead" and $t_i$="r" $2$ letters have to be bought ("arrayhead").
* For example, for $s$="arrayhead" and $t_i$="areahydra" all $9$ letters have to be bought ("arrayhead").

It is guaranteed that every friend can construct her/his name using the letters from the string $s$.

Note that the values for friends are independent, friends are only estimating them but not actually buying the letters.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of showcase string $s$.

The second line contains string $s$, consisting of exactly $n$ lowercase Latin letters.

The third line contains one integer $m$ ($1 \le m \le 5 \cdot 10^4$) — the number of friends.

The $i$-th of the next $m$ lines contains $t_i$ ($1 \le |t_i| \le 2 \cdot 10^5$) — the name of the $i$-th friend.

It is guaranteed that $\sum \limits_{i=1}^m |t_i| \le 2 \cdot 10^5$.

## Output

For each friend print the length of the shortest prefix of letters from $s$ s/he would need to buy to be able to construct her/his name of them. The name can be constructed if each letter is presented in the equal or greater amount.

It is guaranteed that every friend can construct her/his name using the letters from the string $s$.

## Example

## Input


```

9
arrayhead
5
arya
harry
ray
r
areahydra

```
## Output


```

5
6
5
2
9

```


#### tags 

#1300 #binary_search #implementation #strings 