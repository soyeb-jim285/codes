<h1 style='text-align: center;'> H. Longest Saw</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given the sequence $a_1, a_2, \dots, a_n$. You can choose any subset of elements and then reorder them to create a "saw".

The sequence $b_1, b_2, \dots, b_m$ is called a "saw" if the elements satisfy one of the following series of inequalities: $b_1>b_2<b_3>b_4<\dots$ or $b_1<b_2>b_3<b_4>\dots$.

Find the longest saw which can be obtained from a given array.

Note that both the given sequence $a$ and the required saw $b$ can contain duplicated (non-unique) values.

## Input

The first line contains an integer $t$ ($1 \le t \le 10^5$) — the number of test cases in the input. Then the descriptions of the $t$ test cases follow. Each test case begins with a line containing integer $n$ ($1 \le n \le 2\cdot10^5$). Then a line containing $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) follows.

It's guaranteed that $\sum{n}$ doesn't exceed $2 \cdot 10^5$.

## Output

For each test case, print two lines: print the length of the longest saw in the first line, and the saw itself in the second line. If there are several solutions, print any of them.

## Example

## Input


```

3
10
10 9 8 7 6 5 4 3 2 1
7
1 2 2 2 3 2 2
3
100 100 100

```
## Output


```

10
1 6 2 7 3 8 4 9 5 10 
4
2 1 3 2 
1
100 

```


#### tags 

#*special #constructive_algorithms 