<h1 style='text-align: center;'> A. Rudolph and Cut the Rope </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ nails driven into the wall, the $i$-th nail is driven $a_i$ meters above the ground, one end of the $b_i$ meters long rope is tied to it. All nails hang at different heights one above the other. One candy is tied to all ropes at once. Candy is tied to end of a rope that is not tied to a nail.

To take the candy, you need to lower it to the ground. To do this, Rudolph can cut some ropes, one at a time. Help Rudolph find the minimum number of ropes that must be cut to get the candy.

The figure shows an example of the first test:

 ![](images/00f14114dd979e028305fc59f7fa58a0718d918f.png) ## Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains one integer $n$ ($1 \le n \le 50$) — the number of nails.

The $i$-th of the next $n$ lines contains two integers $a_i$ and $b_i$ ($1 \le a_i, b_i \le 200$) — the height of the $i$-th nail and the length of the rope tied to it, all $a_i$ are different.

It is guaranteed that the data is not contradictory, it is possible to build a configuration described in the statement.

## Output

For each test case print one integer — the minimum number of ropes that need to be cut to make the candy fall to the ground.

## Example

## Input


```

434 33 11 249 25 27 73 4511 75 1012 93 21 535 64 57 7
```
## Output


```

2
2
3
0

```


#### tags 

#800 #implementation #math 