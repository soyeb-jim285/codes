<h1 style='text-align: center;'> A. Two Friends</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp wants to throw a party. He has $n$ friends, and he wants to have at least $2$ of them at his party.

The $i$-th friend's best friend is $p_i$. All $p_i$ are distinct, and for every $i \in [1, n]$, $p_i \ne i$.

Monocarp can send invitations to friends. The $i$-th friend comes to the party if both the $i$-th friend and the $p_i$-th friend receive an invitation (note that the $p_i$-th friend doesn't have to actually come to the party). Each invitation is sent to exactly one of the friends.

For example, if $p = [3, 1, 2, 5, 4]$, and Monocarp sends invitations to the friends $[1, 2, 4, 5]$, then the friends $[2, 4, 5]$ will come to the party. The friend $1$ won't come since his best friend didn't receive an invitation; the friend $3$ won't come since he didn't receive an invitation.

Calculate the minimum number of invitations Monocarp has to send so that at least $2$ friends come to the party.

## Input

The first line contains one integer $t$ ($1 \le t \le 5000$) — the number of test cases.

Each test case consists of two lines:

* the first line contains one integer $n$ ($2 \le n \le 50$) — the number of friends;
* the second line contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \le p_i \le n$; $p_i \ne i$; all $p_i$ are distinct).
## Output

Print one integer — the minimum number of invitations Monocarp has to send.

## Example

## Input


```

353 1 2 5 442 3 4 122 1
```
## Output


```

2
3
2

```
## Note

In the first testcase, Monocarp can send invitations to friends $4$ and $5$. Both of them will come to the party since they are each other's best friends, and both of them have invitations.

In the second testcase, Monocarp can send invitations to friends $1, 2$ and $3$, for example. Then friends $1$ and $2$ will attend: friend $1$ and his best friend $2$ have invitations, friend $2$ and his best friend $3$ have invitations. Friend $3$ won't attend since his friend $4$ doesn't have an invitation. It's impossible to send invitations to fewer than $3$ friends in such a way that at least $2$ come.

In the third testcase, Monocarp can send invitations to both friends $1$ and $2$, and both of them will attend.



#### tags 

#800 #constructive_algorithms #implementation #math 