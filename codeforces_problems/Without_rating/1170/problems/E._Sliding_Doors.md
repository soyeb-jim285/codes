<h1 style='text-align: center;'> E. Sliding Doors</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Imagine that you are the CEO of a big old-fashioned company. Unlike any modern and progressive company (such as JetBrains), your company has a dress code. That's why you have already allocated a spacious room for your employees where they can change their clothes. Moreover, you've already purchased an $m$-compartment wardrobe, so the $i$-th employee can keep his/her belongings in the $i$-th cell (of course, all compartments have equal widths).

The issue has occurred: the wardrobe has sliding doors! More specifically, the wardrobe has $n$ doors (numbered from left to right) and the $j$-th door has width equal to $a_j$ wardrobe's cells. The wardrobe has single rails so that no two doors can slide past each other.

 ![](images/d386d5dda686a64db2d590ef631aaf51b72c215c.png) Extremely schematic example of a wardrobe: $m=9$, $n=2$, $a_1=2$, $a_2=3$. The problem is as follows: sometimes to open some cells you must close some other cells (since all doors are placed on the single track). For example, if you have a $4$-compartment wardrobe (i.e. $m=4$) with $n=2$ one-cell doors (i.e. $a_1=a_2=1$) and you need to open the $1$-st and the $3$-rd cells, you have to close the $2$-nd and the $4$-th cells.

As CEO, you have a complete schedule for the next $q$ days. Now you are wondering: is it possible that all employees who will come on the $k$-th day can access their cells simultaneously?

### Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 2 \cdot 10^5$, $1 \le m \le 4 \cdot 10^5$) — the number of doors and compartments respectively.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le m$, $\sum{a_i} \le m$) — the corresponding widths of the doors.

The third line contains a single integer $q$ ($1 \le q \le 2 \cdot 10^5$) — the number of days you have to process.

The next $q$ lines describe schedule of each day. Each schedule is represented as an integer $c_k$ followed by $c_k$ integers $w_1, w_2, \dots, w_{c_k}$ ($1 \le c_k \le 2 \cdot 10^5$, $1 \le w_1 < w_2 < \dots < w_{c_k} \le m$) — the number of employees who will come on the $k$-th day, and their indices in ascending order.

It's guaranteed that $\sum{c_k}$ doesn't exceed $2 \cdot 10^5$.

### Output

Print $q$ answers. Each answer is "YES" or "NO" (case insensitive). Print "YES" if it is possible, that all employees on the corresponding day can access their compartments simultaneously.

## Example

### Input


```text
3 10
2 3 2
6
1 5
2 1 10
2 2 9
2 5 6
3 1 7 8
4 1 2 3 4
```
### Output


```text
YES
YES
NO
NO
YES
NO
```


#### Tags 

#NOT OK #*special #binary_search 

## Blogs
- [All Contest Problems](../Kotlin_Heroes:_Episode_1.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Kotlin Heroes Editorial (en)](../blogs/Kotlin_Heroes_Editorial_(en).md)
