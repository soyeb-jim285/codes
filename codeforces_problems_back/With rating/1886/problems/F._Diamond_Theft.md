<h1 style='text-align: center;'> F. Diamond Theft</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is the most famous thief in Berland. This time, he decided to steal two diamonds. Unfortunately for Monocarp, there are $n$ cameras monitoring the diamonds. Each camera has two parameters, $t_i$ and $s_i$. The first parameter determines whether the camera is monitoring the first diamond only ($t_i=1$), the second diamond only ($t_i=2$), or both diamonds ($t_i=3$). The second parameter determines the number of seconds the camera will be disabled after it is hacked.

Every second, Monocarp can perform one of the following three actions: 

* do nothing;
* choose a camera and hack it; if Monocarp hacks the $i$-th camera, it will be disabled for the next $s_i$ seconds (if the current second is the $T$-th one, the camera will be disabled from the $(T+1)$-th to the $(T+s_i)$-th second, inclusive);
* steal a diamond if all cameras monitoring it are currently disabled. Monocarp cannot steal the second diamond if he hasn't stolen the first diamond yet.

Note that Monocarp can hack a camera multiple times, even if it is currently disabled.

Your task is to determine the minimum time it will take Monocarp to steal both diamonds, beginning with the first diamond, or report that it is impossible.

## Input

The first line contains a single integer $n$ ($0 \le n \le 1500$) — the number of cameras.

Then $n$ lines follow, the $i$-th of them contains two integers $t_i$ and $s_i$ ($1 \le t_i \le 3$; $1 \le s_i \le 2n$) — the parameters of the $i$-th camera.

## Output

Print a single integer — the minimum time it will take for Monocarp to steal the first diamond first and then the second diamond. If it is impossible, print -1.

## Examples

## Input


```

4
2 6
1 2
1 2
2 1

```
## Output


```

6

```
## Input


```

4
2 8
3 2
3 2
3 5

```
## Output


```

9

```
## Input


```

2
3 2
2 3

```
## Output


```

4

```
## Input


```

1
3 1

```
## Output


```

4

```
## Input


```

8
2 1
2 2
3 5
3 6
1 2
1 3
1 4
1 5

```
## Output


```

11

```


#### tags 

#3300 #data_structures #greedy 