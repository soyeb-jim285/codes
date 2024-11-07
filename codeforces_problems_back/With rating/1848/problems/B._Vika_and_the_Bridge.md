<h1 style='text-align: center;'> B. Vika and the Bridge</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the summer, Vika likes to visit her country house. There is everything for relaxation: comfortable swings, bicycles, and a river.

There is a wooden bridge over the river, consisting of $n$ planks. It is quite old and unattractive, so Vika decided to paint it. And in the shed, they just found cans of paint of $k$ colors.

After painting each plank in one of $k$ colors, Vika was about to go swinging to take a break from work. However, she realized that the house was on the other side of the river, and the paint had not yet completely dried, so she could not walk on the bridge yet.

In order not to spoil the appearance of the bridge, Vika decided that she would still walk on it, but only stepping on planks of the same color. Otherwise, a small layer of paint on her sole will spoil the plank of another color. Vika also has a little paint left, but it will only be enough to repaint one plank of the bridge.

Now Vika is standing on the ground in front of the first plank. To walk across the bridge, she will choose some planks of the same color (after repainting), which have numbers $1 \le i_1 < i_2 < \ldots < i_m \le n$ (planks are numbered from $1$ from left to right). Then Vika will have to cross $i_1 - 1, i_2 - i_1 - 1, i_3 - i_2 - 1, \ldots, i_m - i_{m-1} - 1, n - i_m$ planks as a result of each of $m + 1$ steps.

Since Vika is afraid of falling, she does not want to take too long steps. Help her and tell her the minimum possible maximum number of planks she will have to cross in one step, if she can repaint one (or zero) plank a different color while crossing the bridge.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 2 \cdot 10^5$) — the number of planks in the bridge and the number of different colors of paint.

The second line of each test case contains $n$ integers $c_1, c_2, c_3, \dots, c_n$ ($1 \le c_i \le k$) — the colors in which Vika painted the planks of the bridge.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the minimum possible maximum number of planks that Vika will have to step over in one step.

## Example

## Input


```

55 21 1 2 1 17 31 2 3 3 3 2 16 61 2 3 4 5 68 41 2 3 4 2 3 1 43 11 1 1
```
## Output


```

0
1
2
2
0

```
## Note

In the first test case, Vika can repaint the plank in the middle in color $1$ and walk across the bridge without stepping over any planks.

In the second test case, Vika can repaint the plank in the middle in color $2$ and walk across the bridge, stepping over only one plank each time.

In the third test case, Vika can repaint the penultimate plank in color $2$ and walk across the bridge, stepping only on planks with numbers $2$ and $5$. Then Vika will have to step over $1$, $2$ and $1$ plank each time she steps, so the answer is $2$.

In the fourth test case, Vika can simply walk across the bridge without repainting it, stepping over two planks each time, walking on planks of color $3$.

In the fifth test case, Vika can simply walk across the bridge without repainting it, without stepping over any planks.



#### tags 

#1200 #binary_search #data_structures #greedy #implementation #math #sortings 