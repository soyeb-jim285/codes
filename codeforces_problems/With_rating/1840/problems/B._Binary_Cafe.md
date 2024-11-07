<h1 style='text-align: center;'> B. Binary Cafe</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Once upon a time, Toma found himself in a binary cafe. It is a very popular and unusual place.

The cafe offers visitors $k$ different delicious desserts. The desserts are numbered from $0$ to $k-1$. The cost of the $i$-th dessert is $2^i$ coins, because it is a binary cafe! Toma is willing to spend no more than $n$ coins on tasting desserts. At the same time, he is not interested in buying any dessert more than once, because one is enough to evaluate the taste.

In how many different ways can he buy several desserts (possibly zero) for tasting?

### Input

The first line of the input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Then follows $t$ lines, each of which describes one test case.

Each test case is given on a single line and consists of two integers $n$ and $k$ ($1 \le n, k \le 10^9$) — the number of coins Toma is willing to spend and the number of desserts in the binary cafe.

### Output

### Output

 $t$ integers, the $i$-th of which should be equal to the answer for the $i$-th test case — the number of ways to buy desserts for tasting.

## Example

### Input


```text
51 22 12 210 2179 100
```
### Output

```text

2
2
3
4
180

```
## Note

Variants for 1st sample: {}, {1}

Variants for 2nd sample: {}, {1}

Variants for 3rd sample: {}, {1}, {2}

Variants for 4th sample: {}, {1}, {2}, {1, 2}



#### Tags 

#1100 #NOT OK #bitmasks #combinatorics #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_878_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
