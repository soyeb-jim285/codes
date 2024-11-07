<h1 style='text-align: center;'> E. Helping Hiasat </h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Hiasat registered a new account in NeckoForces and when his friends found out about that, each one of them asked to use his name as Hiasat's handle.

Luckily for Hiasat, he can change his handle in some points in time. Also he knows the exact moments friends will visit his profile page. Formally, you are given a sequence of events of two types:

* $1$ — Hiasat can change his handle.
* $2$ $s$ — friend $s$ visits Hiasat's profile.

The friend $s$ will be happy, if each time he visits Hiasat's profile his handle would be $s$.

Hiasat asks you to help him, find the maximum possible number of happy friends he can get.

#### Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5, 1 \le m \le 40$) — the number of events and the number of friends.

Then $n$ lines follow, each denoting an event of one of two types: 

* $1$ — Hiasat can change his handle.
* $2$ $s$ — friend $s$ ($1 \le |s| \le 40$) visits Hiasat's profile.

It's guaranteed, that each friend's name consists only of lowercase Latin letters.

It's guaranteed, that the first event is always of the first type and each friend will visit Hiasat's profile at least once.

#### Output

Print a single integer — the maximum number of happy friends.

## Examples

#### Input


```text
5 3
1
2 motarack
2 mike
1
2 light
```
#### Output


```text
2
```
#### Input


```text
4 3
1
2 alice
2 bob
2 tanyaromanova
```
#### Output


```text
1
```
## Note

In the first example, the best way is to change the handle to the "motarack" in the first event and to the "light" in the fourth event. This way, "motarack" and "light" will be happy, but "mike" will not.

In the second example, you can choose either "alice", "bob" or "tanyaromanova" and only that friend will be happy.



#### Tags 

#2200 #NOT OK #bitmasks #brute_force #dp #meet-in-the-middle 

## Blogs
- [All Contest Problems](../Codeforces_Round_533_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
