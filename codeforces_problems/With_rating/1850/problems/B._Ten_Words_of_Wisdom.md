<h1 style='text-align: center;'> B. Ten Words of Wisdom</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In the game show "Ten Words of Wisdom", there are $n$ participants numbered from $1$ to $n$, each of whom submits one response. The $i$-th response is $a_i$ words long and has quality $b_i$. No two responses have the same quality, and at least one response has length at most $10$.

The winner of the show is the response which has the highest quality out of all responses that are not longer than $10$ words. Which response is the winner?

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 50$) — the number of responses.

Then $n$ lines follow, the $i$-th of which contains two integers $a_i$ and $b_i$ ($1 \leq a_i, b_i \leq 50$) — the number of words and the quality of the $i$-th response, respectively. 

Additional constraints on the input: in each test case, at least one value of $i$ satisfies $a_i \leq 10$, and all values of $b_i$ are distinct.

### Output

For each test case, output a single line containing one integer $x$ ($1 \leq x \leq n$) — the winner of the show, according to the rules given in the statement.

It can be shown that, according to the constraints in the statement, exactly one winner exists for each test case.

## Example

### Input


```text
357 212 59 39 410 131 23 45 611 43
```
### Output

```text

4
3
1

```
## Note

In the first test case, the responses provided are as follows:

* Response 1: $7$ words, quality $2$
* Response 2: $12$ words, quality $5$
* Response 3: $9$ words, quality $3$
* Response 4: $9$ words, quality $4$
* Response 5: $10$ words, quality $1$

We can see that the responses with indices $1$, $3$, $4$, and $5$ have lengths not exceeding $10$ words. Out of these responses, the winner is the one with the highest quality.

Comparing the qualities, we find that: 

* Response 1 has quality $2$.
* Response 3 has quality $3$.
* Response 4 has quality $4$.
* Response 5 has quality $1$.

Among these responses, Response 4 has the highest quality.



#### Tags 

#800 #OK #implementation #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_886_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
