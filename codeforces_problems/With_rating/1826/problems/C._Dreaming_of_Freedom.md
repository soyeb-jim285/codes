<h1 style='text-align: center;'> C. Dreaming of Freedom</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Because to take away a man's freedom of choice, even his freedom to make the wrong choice, is to manipulate him as though he were a puppet and not a person.— Madeleine L'EngleThere are $n$ programmers choosing their favorite algorithm amongst $m$ different choice options. Before the first round, all $m$ options are available. In each round, every programmer makes a vote for one of the remaining algorithms. After the round, only the algorithms with the maximum number of votes remain. The voting process ends when there is only one option left. Determine whether the voting process can continue indefinitely or no matter how people vote, they will eventually choose a single option after some finite amount of rounds?

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^5$) — the number of test cases.

Each test case consists of a single line containing two integers $n$ and $m$ ($1 \leq n, m \leq 10^6$) — the number of people and choice options respectively.

### Output

For each test case output "YES" if the programmers will eventually choose a single option, and "NO" otherwise.

You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as a positive answer).

## Example

### Input


```text
53 24 25 31000000 10000001 1000000
```
### Output

```text

YES
NO
YES
NO
YES

```
## Note

In the first example, there are $8$ ways people could vote: $\{1|1|1, 1|1|2, 1|2|1, 1|2|2, 2|1|1, 2|1|2, 2|2|1, 2|2|2\}$.

In cases $1$, $2$, $3$, and $5$, the programmers are left with the first algorithm, and in the remaining cases people are left with the second one, so the voting ends in one round in any case.

In the second example, the programmers could always vote $1|1|2|2$. Both algorithms have the maximum number of votes and remain for the next round, so the voting never ends.



#### Tags 

#1300 #OK #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_870_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
