<h1 style='text-align: center;'> A. Problemsolving Log</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is participating in a programming contest, which features $26$ problems, named from 'A' to 'Z'. The problems are sorted by difficulty. Moreover, it's known that Monocarp can solve problem 'A' in $1$ minute, problem 'B' in $2$ minutes, ..., problem 'Z' in $26$ minutes.

After the contest, you discovered his contest log — a string, consisting of uppercase Latin letters, such that the $i$-th letter tells which problem Monocarp was solving during the $i$-th minute of the contest. If Monocarp had spent enough time in total on a problem to solve it, he solved it. Note that Monocarp could have been thinking about a problem after solving it.

Given Monocarp's contest log, calculate the number of problems he solved during the contest.

## Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 500$) — the duration of the contest, in minutes.

The second line contains a string of length exactly $n$, consisting only of uppercase Latin letters, — Monocarp's contest log.

## Output

For each testcase, print a single integer — the number of problems Monocarp solved during the contest.

## Example

## Input


```

36ACBCBC7AAAAFPC22FEADBBDFFEDFFFDHHHADCC
```
## Output


```

3
1
4

```


#### tags 

#800 #implementation #strings 