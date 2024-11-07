<h1 style='text-align: center;'> E. Game of the Year</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp and Polycarp are playing a computer game. This game features $n$ bosses for the playing to kill, numbered from $1$ to $n$.

They will fight each boss the following way: 

* Monocarp makes $k$ attempts to kill the boss;
* Polycarp makes $k$ attempts to kill the boss;
* Monocarp makes $k$ attempts to kill the boss;
* Polycarp makes $k$ attempts to kill the boss;
* ...

Monocarp kills the $i$-th boss on his $a_i$-th attempt. Polycarp kills the $i$-th boss on his $b_i$-th attempt. After one of them kills the $i$-th boss, they move on to the $(i+1)$-st boss. The attempt counters reset for both of them. Once one of them kills the $n$-th boss, the game ends.

Find all values of $k$ from $1$ to $n$ such that Monocarp kills all bosses.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of bosses.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le n$) — the index of attempt Monocarp kills each boss on.

The third line contains $n$ integers $b_1, b_2, \dots, b_n$ ($1 \le b_i \le n$) — the index of attempt Polycarp kills each boss on.

The sum of $n$ over all testcases doesn't exceed $2 \cdot 10^5$.

### Output

For each testcase, print two lines. The first line should contain a single integer $\mathit{cnt}$ — the number of values of $k$ from $1$ to $n$ such that Monocarp kills all bosses. The second line should contain $\mathit{cnt}$ distinct integers — the values of $k$ themselves.

## Example

### Input


```text
331 1 12 3 111141 4 3 23 3 4 1
```
### Output

```text

3
1 2 3 
1
1 
2
2 4 

```
## Note

Consider the last testcase of the example.

Let $k = 1$. First, Monocarp makes one attempt to kill the first boss. It's successful, since $a_1 = 1$. Then, Monocarp makes one attempt to kill the second boss. It's unsuccessful, since $a_2 > 1$. So, Polycarp makes an attempt then. It's also unsuccessful, since $b_2 > 1$. Then, Monocarp makes another attempt. It's still unsuccessful, since $a_2 > 2$. This goes on until Polycarp finally kills the boss on his third attempt. Monocarp didn't kill this boss, thus, $k = 1$ isn't the answer.

Let $k = 2$. Monocarp still kills the first boss on his first attempt. Then, he makes two unsuccessful attempts for the second boss. Then, Polycarp makes two unsuccessful attempts. Then, Monocarp makes two more attempts and kills the boss on his fourth attempt. The third boss is similar. First, two unsuccessful attempts by Monocarp. Then, two unsuccessful attempts by Polycarp. Then, Monocarp has two more attempts, but even his first one is successful, since $a_3 = 3$. The fourth boss is also killed by Monocarp. Thus, $k = 2$ is the answer.



#### Tags 

#2300 #NOT OK #brute_force #data_structures #math #number_theory 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_141_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
