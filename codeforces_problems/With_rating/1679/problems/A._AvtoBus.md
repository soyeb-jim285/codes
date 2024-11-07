<h1 style='text-align: center;'> A. AvtoBus</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Spring has come, and the management of the AvtoBus bus fleet has given the order to replace winter tires with summer tires on all buses.

You own a small bus service business and you have just received an order to replace $n$ tires. You know that the bus fleet owns two types of buses: with two axles (these buses have $4$ wheels) and with three axles (these buses have $6$ wheels).

You don't know how many buses of which type the AvtoBus bus fleet owns, so you wonder how many buses the fleet might have. You have to determine the minimum and the maximum number of buses that can be in the fleet if you know that the total number of wheels for all buses is $n$.

### Input

The first line contains an integer $t$ ($1 \le t \le 1\,000$) — the number of test cases. The following lines contain description of test cases.

The only line of each test case contains one integer $n$ ($1 \le n \le 10^{18}$) — the total number of wheels for all buses.

### Output

For each test case print the answer in a single line using the following format.

Print two integers $x$ and $y$ ($1 \le x \le y$) — the minimum and the maximum possible number of buses that can be in the bus fleet.

If there is no suitable number of buses for the given $n$, print the number $-1$ as the answer.

## Example

### Input


```text
44724998244353998244352
```
### Output

```text

1 1
-1
4 6
166374058999707392 249561088499561088

```
## Note

In the first test case the total number of wheels is $4$. It means that there is the only one bus with two axles in the bus fleet.

In the second test case it's easy to show that there is no suitable number of buses with $7$ wheels in total.

In the third test case the total number of wheels is $24$. The following options are possible:

* Four buses with three axles.
* Three buses with two axles and two buses with three axles.
* Six buses with two axles.

So the minimum number of buses is $4$ and the maximum number of buses is $6$.



#### Tags 

#900 #OK #brute_force #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_791_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
