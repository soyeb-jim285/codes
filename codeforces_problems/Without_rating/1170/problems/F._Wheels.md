<h1 style='text-align: center;'> F. Wheels</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp has $n$ wheels and a car with $m$ slots for wheels. The initial pressure in the $i$-th wheel is $a_i$.

Polycarp's goal is to take exactly $m$ wheels among the given $n$ wheels and equalize the pressure in them (then he can put these wheels in a car and use it for driving). In one minute he can decrease or increase the pressure in any (single) wheel by $1$. He can increase the pressure no more than $k$ times in total because it is hard to pump up wheels.

Help Polycarp and say what is the minimum number of minutes he needs to spend to equalize the pressure of at least $m$ wheels among the given $n$ wheels.

##### Input

The first line of the input contains three integers $n, m$ and $k$ ($1 \le m \le n \le 2 \cdot 10^5, 0 \le k \le 10^9$) — the number of wheels, the number of slots for wheels in a car and the number of times Polycarp can increase by $1$ the pressure in a wheel.

The second line of the input contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$), where $a_i$ is the pressure in the $i$-th wheel.

##### Output

Print one integer — the minimum number of minutes Polycarp needs to spend to equalize the pressure in at least $m$ wheels among the given $n$ wheels.

## Examples

##### Input


```text
6 6 7
6 15 16 20 1 5
```
##### Output


```text
39
```
##### Input


```text
6 3 1
4 8 15 16 23 42
```
##### Output


```text
8
```
##### Input


```text
5 4 0
5 5 5 4 5
```
##### Output


```text
0
```


#### Tags 

#NOT OK #*special #binary_search #greedy 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_1.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Kotlin Heroes Editorial (en)](../blogs/Kotlin_Heroes_Editorial_(en).md)
