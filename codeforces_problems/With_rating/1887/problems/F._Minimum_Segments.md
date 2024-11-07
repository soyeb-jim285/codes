<h1 style='text-align: center;'> F. Minimum Segments</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You had a sequence $a_1, a_2, \ldots, a_n$ consisting of integers from $1$ to $n$, not necessarily distinct. For some unknown reason, you decided to calculate the following characteristic of the sequence: 

* Let $r_i$ ($1 \le i \le n$) be the smallest $j \ge i$ such that on the subsegment $a_i, a_{i+1}, \ldots, a_j$ all distinct numbers from the sequence $a$ appear. More formally, for any $k \in [1, n]$, there exists $l \in [i, j]$ such that $a_k = a_l$. If such $j$ does not exist, $r_i$ is considered to be equal to $n+1$.
* The characteristic of the sequence $a$ is defined as the sequence $r_1, r_2, \ldots, r_n$.

 Unfortunately, the sequence $a$ got lost, but you still have its characteristic $r$. You want to reconstruct any sequence $a$ that matches the characteristic, or determine that there is an error in the characteristic and such a sequence does not exist.
### Input

Each test consist of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the length of the lost sequence $a$.

The second line of each test case contains $n$ integers $r_1, r_2, \ldots, r_n$ ($i \le r_i \le n+1$) — the characteristic of the lost sequence $a$. 

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the following: 

* If there is no sequence $a$ with the characteristic $r$, print "No".
* Otherwise, print "Yes" on the first line, and on the second line, print any sequence of integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) that matches the characteristic $r$.

 You can output "YES" and "NO" in any case (for example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as a positive answer).
## Example

### Input


```text
532 3 452 3 5 4 61131 3 483 6 6 6 8 9 9 9
```
### Output

```text

Yes
1 2 1
No
Yes
1 
No
Yes
1 3 5 3 5 1 1 3

```
## Note

In the first test case, the sequence $a = [1, 2, 1]$ is suitable. The integers $1$ and $2$ appear on the subsegments $[1, 2]$ and $[2, 3]$.

In the second test case, it can be proved that there is no suitable sequence $a$.



#### Tags 

#3400 #NOT OK #constructive_algorithms 

## Blogs
- [All Contest Problems](../Codeforces_Round_905_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
