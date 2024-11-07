<h1 style='text-align: center;'> D. Misha and Apples</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Schoolboy Misha got tired of doing sports programming, so he decided to quit everything and go to the magical forest to sell magic apples.

His friend Danya came to the magical forest to visit Misha. What was his surprise when he found out that Misha found a lot of friends there, the same former sports programmers. And all of them, like Misha, have their own shop where they sell magic apples. To support his friends, who have changed their lives so drastically, he decided to buy up their entire assortment.

The buying process works as follows: in total there are $n$ stalls, numbered with integers from $1$ to $n$, and $m$ kinds of magic apples, numbered with integers from $1$ to $m$. Each shop sells some number of kinds of apples. Danya visits all the shops in order of increasing number, starting with the first one. Upon entering the shop he buys one magic apple of each kind sold in that shop and puts them in his backpack.

However, magical apples wouldn't be magical if they were all right. The point is that when two apples of the same type end up together in the backpack, all of the apples in it magically disappear. Importantly, the disappearance happens after Danya has put the apples in the backpack and left the shop.

Upon returning home, Danya realized that somewhere in the forest he had managed to lose his backpack. Unfortunately, for some shops Danya had forgotten what assortment of apples there was. Remembering only for some shops, what kinds of magical apples were sold in them, he wants to know what is the maximum number of apples he could have in his backpack after all his purchases at best.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 2 \cdot 10^5$) —the number of test cases. The description of test cases follows.

The first line contains two integers $n$ and $m$ ($1 \leq n, m \leq 2 \cdot 10^5$) —the number of stalls and kinds of apples.

Each of the following $n$ lines describes the assortment of the next stall in the format described below.

Each line starts with an integer $k_i$ ($0 \le k_i \le 2 \cdot 10^5$). This is followed by $k_i$ of different integers $a_{ij}$ ($1 \le a_{ij} \le m$) —the kinds of apples sold in the $i$-th stall. If $k_i = 0$, then Danya does not remember what assortment was in that shop, and the set of apple kinds can be anything (including empty).

It is guaranteed that the sum of all $k_i$ over all test cases does not exceed $2 \cdot 10^5$ and the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$

## Output

For each test case, output a single integer — the maximum number of apples that could be in Dani's backpack after visiting all the shops at best.

## Example

## Input


```

43 42 1 22 4 12 1 24 42 1 22 3 401 12 5005 303 1 2 32 3 101 3
```
## Output


```

2
1
5
3

```
## Note

In the first test case, Danya remembers all the shops, so the process will be deterministic. He will take two apples at the first shop and two more at the second, but after he puts them in his backpack, they will disappear. So at the end there will only be $2$ apples left, which he will take at the third shop.

In the second test case, if the third shop is empty, then after visiting the fourth shop all the apples will disappear. In any other case the apples will disappear after the third shop, and in the fourth shop Dan can take one apple, so the answer is $1$.

In the third test case, the first shop may sell all kinds of apples, and the second shop may sell nothing. Then all $5$ apples will be left at the end.



#### tags 

#2800 #brute_force #data_structures #dp #two_pointers 