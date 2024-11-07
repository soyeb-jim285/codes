<h1 style='text-align: center;'> E. Messages</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp is a tutor of a group of $n$ students. He communicates with them using a conference in a popular messenger.

Today was a busy day for Monocarp — he was asked to forward a lot of posts and announcements to his group, that's why he had to write a very large number of messages in the conference. Monocarp knows the students in the group he is tutoring quite well, so he understands which message should each student read: Monocarp wants the student $i$ to read the message $m_i$.

Of course, no one's going to read all the messages in the conference. That's why Monocarp decided to pin some of them. Monocarp can pin any number of messages, and if he wants anyone to read some message, he should pin it — otherwise it will definitely be skipped by everyone.

Unfortunately, even if a message is pinned, some students may skip it anyway. For each student $i$, Monocarp knows that they will read at most $k_i$ messages. Suppose Monocarp pins $t$ messages; if $t \le k_i$, then the $i$-th student will read all the pinned messages; but if $t > k_i$, the $i$-th student will choose exactly $k_i$ random pinned messages (all possible subsets of pinned messages of size $k_i$ are equiprobable) and read only the chosen messages.

Monocarp wants to maximize the expected number of students that read their respective messages (i.e. the number of such indices $i$ that student $i$ reads the message $m_i$). Help him to choose how many (and which) messages should he pin!

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$) — the number of students in the conference.

Then $n$ lines follow. The $i$-th line contains two integers $m_i$ and $k_i$ ($1 \le m_i \le 2 \cdot 10^5$; $1 \le k_i \le 20$) — the index of the message which Monocarp wants the $i$-th student to read and the maximum number of messages the $i$-th student will read, respectively.

## Output

In the first line, print one integer $t$ ($1 \le t \le 2 \cdot 10^5$) — the number of messages Monocarp should pin. In the second line, print $t$ distinct integers $c_1$, $c_2$, ..., $c_t$ ($1 \le c_i \le 2 \cdot 10^5$) — the indices of the messages Monocarp should pin. The messages can be listed in any order.

If there are multiple answers, print any of them.

## Examples

## Input


```

3
10 1
10 2
5 2

```
## Output


```

2
5 10 

```
## Input


```

3
10 1
5 2
10 1

```
## Output


```

1
10 

```
## Input


```

4
1 1
2 2
3 3
4 4

```
## Output


```

3
2 3 4 

```
## Input


```

3
13 2
42 2
37 2

```
## Output


```

3
42 13 37

```
## Note

Let's consider the examples from the statement.

1. In the first example, Monocarp pins the messages $5$ and $10$.
	* if the first student reads the message $5$, the second student reads the messages $5$ and $10$, and the third student reads the messages $5$ and $10$, the number of students which have read their respective messages will be $2$;
	* if the first student reads the message $10$, the second student reads the messages $5$ and $10$, and the third student reads the messages $5$ and $10$, the number of students which have read their respective messages will be $3$.So, the expected number of students which will read their respective messages is $\frac{5}{2}$.
2. In the second example, Monocarp pins the message $10$.
	* if the first student reads the message $10$, the second student reads the message $10$, and the third student reads the message $10$, the number of students which have read their respective messages will be $2$.So, the expected number of students which will read their respective messages is $2$. If Monocarp had pinned both messages $5$ and $10$, the expected number of students which read their respective messages would have been $2$ as well.
3. In the third example, the expected number of students which will read their respective messages is $\frac{8}{3}$.
4. In the fourth example, the expected number of students which will read their respective messages is $2$.


#### tags 

#2000 #brute_force #dp #greedy #probabilities #sortings 