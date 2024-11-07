<h1 style='text-align: center;'> H. Kuroni the Private Tutor</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As a professional private tutor, Kuroni has to gather statistics of an exam. Kuroni has appointed you to complete this important task. You must not disappoint him.

The exam consists of $n$ questions, and $m$ students have taken the exam. Each question was worth $1$ point. Question $i$ was solved by at least $l_i$ and at most $r_i$ students. Additionally, you know that the total score of all students is $t$.

Furthermore, you took a glance at the final ranklist of the quiz. The students were ranked from $1$ to $m$, where rank $1$ has the highest score and rank $m$ has the lowest score. Ties were broken arbitrarily.

You know that the student at rank $p_i$ had a score of $s_i$ for $1 \le i \le q$.

You wonder if there could have been a huge tie for first place. Help Kuroni determine the maximum number of students who could have gotten as many points as the student with rank $1$, and the maximum possible score for rank $1$ achieving this maximum number of students.

#### Input

The first line of input contains two integers ($1 \le n, m \le 10^{5}$), denoting the number of questions of the exam and the number of students respectively.

The next $n$ lines contain two integers each, with the $i$-th line containing $l_{i}$ and $r_{i}$ ($0 \le l_{i} \le r_{i} \le m$).

The next line contains a single integer $q$ ($0 \le q \le m$). 

The next $q$ lines contain two integers each, denoting $p_{i}$ and $s_{i}$ ($1 \le p_{i} \le m$, $0 \le s_{i} \le n$). It is guaranteed that all $p_{i}$ are distinct and if $p_{i} \le p_{j}$, then $s_{i} \ge s_{j}$.

The last line contains a single integer $t$ ($0 \le t \le nm$), denoting the total score of all students.

#### Output

#### Output

 two integers: the maximum number of students who could have gotten as many points as the student with rank $1$, and the maximum possible score for rank $1$ achieving this maximum number of students. If there is no valid arrangement that fits the given data, output $-1$ $-1$.

## Examples

#### Input


```text
5 4
2 4
2 3
1 1
0 1
0 0
1
4 1
7
```
#### Output


```text
3 2
```
#### Input


```text
5 6
0 6
0 6
2 5
6 6
4 6
1
3 3
30
```
#### Output


```text
-1 -1
```
## Note

For the first sample, here is one possible arrangement that fits the data:

Students $1$ and $2$ both solved problems $1$ and $2$.

Student $3$ solved problems $2$ and $3$.

Student $4$ solved problem $4$.

The total score of all students is $T = 7$. 
## Note

 that the scores of the students are $2$, $2$, $2$ and $1$ respectively, which satisfies the condition that the student at rank $4$ gets exactly $1$ point. Finally, $3$ students tied for first with a maximum score of $2$, and it can be proven that we cannot do better with any other arrangement.



#### Tags 

#3500 #NOT OK #binary_search #greedy 

## Blogs
- [All Contest Problems](../Ozon_Tech_Challenge_2020_(Div.1_+_Div.2,_Rated,_T-shirts_+_prizes!).md)
- [Ozon Tech Challenge 2020](../blogs/Ozon_Tech_Challenge_2020.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
