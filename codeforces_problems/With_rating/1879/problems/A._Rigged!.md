<h1 style='text-align: center;'> A. Rigged!</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp organizes a weightlifting competition. There are $n$ athletes participating in the competition, the $i$-th athlete has strength $s_i$ and endurance $e_i$. The $1$-st athlete is Monocarp's friend Polycarp, and Monocarp really wants Polycarp to win.

The competition will be conducted as follows. The jury will choose a positive (greater than zero) integer $w$, which denotes the weight of the barbell that will be used in the competition. The goal for each athlete is to lift the barbell as many times as possible. The athlete who lifts the barbell the most amount of times will be declared the winner (if there are multiple such athletes — there's no winner).

If the barbell's weight $w$ is strictly greater than the strength of the $i$-th athlete $s_i$, then the $i$-th athlete will be unable to lift the barbell even one single time. Otherwise, the $i$-th athlete will be able to lift the barbell, and the number of times he does it will be equal to his endurance $e_i$.

For example, suppose there are $4$ athletes with parameters $s_1 = 7, e_1 = 4$; $s_2 = 9, e_2 = 3$; $s_3 = 4, e_3 = 6$; $s_4 = 2, e_4 = 2$. If the weight of the barbell is $5$, then:

* the first athlete will be able to lift the barbell $4$ times;
* the second athlete will be able to lift the barbell $3$ times;
* the third athlete will be unable to lift the barbell;
* the fourth athlete will be unable to lift the barbell.

Monocarp wants to choose $w$ in such a way that Polycarp (the $1$-st athlete) wins the competition. Help him to choose the value of $w$, or report that it is impossible.

### Input

The first line contains one integer $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains one integer $n$ ($2 \le n \le 100$) — the number of athletes. Then $n$ lines follow, the $i$-th of them contains two integers $s_i$ and $e_i$ ($1 \le s_i \le 10^9$; $1 \le e_i \le 100$) — the strength and the endurance of the $i$-th athlete.

### Output

For each test case, print the answer as follows:

* if the answer exists, print one integer — the value of $w$ meeting the constraints. The integer you print should satisfy $1 \le w \le 10^9$. It can be shown that if the answer exists, at least one such value of $w$ exists as well. If there are multiple answers, you can print any of them;
* otherwise, print one integer $-1$.
## Example

### Input


```text
347 49 34 62 224 6100 10021337 31337 3
```
### Output

```text

5
-1
-1

```
## Note

The first test case of the example is described in the statement.



#### Tags 

#800 #OK #greedy 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_155_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
