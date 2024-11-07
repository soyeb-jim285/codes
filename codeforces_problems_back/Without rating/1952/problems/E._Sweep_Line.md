<h1 style='text-align: center;'> E. Sweep Line</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Be careful not to make a mistake. You might have to start all over again.— Someone, probably## Input

The first line contains one integer $n$ ($1 \leq n \leq 10^5$) — the length of the array $a$.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 2$) — the array $a$.

## Output

## Output

 a single integer — the number of solutions, modulo $20240401$.

## Examples

## Input


```

71 1 2 1 1 2 0
```
## Output


```

1
```
## Input


```

71 1 2 1 1 1 0
```
## Output


```

2
```
## Input


```

70 1 2 1 1 1 0
```
## Output


```

0
```
## Note

In the first sample, the array looks like this:



| $ \color{blue}{1} $ | $ \color{blue}{1} $ | $ \color{darkgreen}{2} $ | $ \color{blue}{1} $ | $ \color{blue}{1} $ | $ \color{darkgreen}{2} $ | $ \color{gray}{0} $ |
| --- | --- | --- | --- | --- | --- | --- |



Obviously, the answer here is $1 \pmod{20240401}$.

In the second sample, the array looks like this:



| $ \color{blue}{1} $ | $ \color{blue}{1} $ | $ \color{darkgreen}{2} $ | $ \color{blue}{1} $ | $ \color{blue}{1} $ | $ \color{blue}{1} $ | $ \color{gray}{0} $ |
| --- | --- | --- | --- | --- | --- | --- |



I do not know why the answer here is $2 \pmod{20240401}$, I had to take a guess.

In the third sample, the array looks like this:



| $ \color{gray}{0} $ | $ \color{blue}{1} $ | $ \color{darkgreen}{2} $ | $ \color{blue}{1} $ | $ \color{blue}{1} $ | $ \color{blue}{1} $ | $ \color{gray}{0} $ |
| --- | --- | --- | --- | --- | --- | --- |



If the answer here is not $0 \pmod{20240401}$, I am literally going to explode.



#### tags 

#combinatorics #games #math 