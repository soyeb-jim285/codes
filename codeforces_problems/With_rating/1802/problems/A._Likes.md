<h1 style='text-align: center;'> A. Likes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Nikita recently held a very controversial round, after which his contribution changed very quickly.

The announcement hung on the main page for $n$ seconds. In the $i$th second $|a_i|$th person either liked or removed the like (Nikita was lucky in this task and there are no dislikes). If $a_i > 0$, then the $a_i$th person put a like. If $a_i < 0$, then the person $-a_i$ removed the like. Each person put and removed the like no more than once. A person could not remove a like if he had not put it before.

Since Nikita's contribution became very bad after the round, he wanted to analyze how his contribution changed while the announcement was on the main page. He turned to the creator of the platform with a request to give him the sequence $a_1, a_2, \ldots, a_n$. But due to the imperfection of the platform, the sequence $a$ was shuffled.

You are given a shuffled sequence of $a$ that describes user activity. You need to tell for each moment from $1$ to $n$ what the maximum and minimum number of likes could be on the post at that moment.

### Input

The first line of input data contains one number $t$ ($1 \leqslant t \leqslant 1000$) — the number of test cases.

In the first line of test case, one number is given $n$ ($1 \leqslant n \leqslant 100$) — the number of seconds during which Nikita's announcement hung on the main page.

The next line contains $n$ numbers $b_1, b_2, b_3, \ldots, b_n$ ($1 \leqslant |b_i| \leqslant n$) — mixed array $a$. It is guaranteed that there exists such a permutation of $b$ that it is a correct sequence of events described in the condition.

It is guaranteed that the sum of $n$ for all input test cases does not exceed $10^4$.

### Output

For each test case, output two lines, each of which contains $n$ numbers.

In the first line, for each test case, output the maximum number of likes that Nikita could have at the announcement at the $i$th second.

In the second line, for each test case, output the minimum number of likes that Nikita could have at the announcement at the $i$th second.

## Example

### Input


```text
531 2 -221 -164 3 -1 2 1 -254 2 -2 1 37-1 6 -4 3 2 4 1
```
### Output

```text

1 2 1 
1 0 1 
1 0 
1 0 
1 2 3 4 3 2 
1 0 1 0 1 2 
1 2 3 4 3 
1 0 1 2 3 
1 2 3 4 5 4 3 
1 0 1 0 1 2 3 

```
## Note

In the first test case, the maximum values are reached with the following permutation: $1, 2, -2$. And the minimum values for such: $2, -2, 1$.

In the third test case, all maximal values are reached with the following permutation: $4, 2, 3, 1, -1, -2$. And the minimum values for the next permutation: $2, -2, 1, -1, 3, 4$.



#### Tags 

#800 #OK #greedy #implementation 

## Blogs
- [All Contest Problems](../Codeforces_Round_857_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (ru)](../blogs/Tutorial_(ru).md)
