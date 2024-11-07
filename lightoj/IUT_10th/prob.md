In programming, a range is referred to as a continuous segment that has a lower bound and an upper bound. For example, $[2, 4]$ and $[1, 100]$ are valid and $[4, 1]$ is invalid.

Two ranges ($[u, v]$, $[x, y]$) are called non-overlapping ranges of if one of the following conditions is satisfied:

    ($x \le u$ and $y \ge v$) or ($u \le x$ and $v \ge y$)
    ($v \le x$) or ($y \le u$)

You are given an array A of N integers. So, A has a total of $(N*(N-1))/2$ different ranges. Among them, a range $(u, v)$ is valid if ($1 \le u < v \le N$) and ($A[u] == A[v]$). Let’s say there are a total of $K$ valid ranges in $A$. You have to find the largest subset of ranges from those $K$ ranges, where every possible pair of ranges should be non-overlapping.