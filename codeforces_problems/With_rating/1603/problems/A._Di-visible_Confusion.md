<h1 style='text-align: center;'> A. Di-visible Confusion</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

YouKn0wWho has an integer sequence $a_1, a_2, \ldots, a_n$. He will perform the following operation until the sequence becomes empty: select an index $i$ such that $1 \le i \le |a|$ and $a_i$ is not divisible by $(i + 1)$, and erase this element from the sequence. Here $|a|$ is the length of sequence $a$ at the moment of operation. 
## Note

 that the sequence $a$ changes and the next operation is performed on this changed sequence.

For example, if $a=[3,5,4,5]$, then he can select $i = 2$, because $a_2 = 5$ is not divisible by $i+1 = 3$. After this operation the sequence is $[3,4,5]$.

Help YouKn0wWho determine if it is possible to erase the whole sequence using the aforementioned operation.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10\,000$)  — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \le n \le 10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

### Output

For each test case, print "YES" (without quotes) if it is possible to erase the whole sequence using the aforementioned operation, print "NO" (without quotes) otherwise. You can print each letter in any register (upper or lower).

## Example

### Input


```text
5
3
1 2 3
1
2
2
7 7
10
384836991 191890310 576823355 782177068 404011431 818008580 954291757 160449218 155374934 840594328
8
6 69 696 69696 696969 6969696 69696969 696969696
```
### Output


```text
YES
NO
YES
YES
NO
```
## Note

In the first test case, YouKn0wWho can perform the following operations (the erased elements are underlined): $[1, \underline{2}, 3] \rightarrow [\underline{1}, 3] \rightarrow [\underline{3}] \rightarrow [\,].$

In the second test case, it is impossible to erase the sequence as $i$ can only be $1$, and when $i=1$, $a_1 = 2$ is divisible by $i + 1 = 2$.



#### Tags 

#1300 #NOT OK #constructive_algorithms #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_752_(Div._1).md)
- [Codeforces Round #752 (en)](../blogs/Codeforces_Round_752_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
