<h1 style='text-align: center;'> B. Blueprint for Seating</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

An aircraft manufacturing company wants to optimize their products for passenger airlines. The company's latest research shows that most of the delays happen because of slow boarding.

Most of the medium-sized aircraft are designed with 3-3 seat layout, meaning each row has 6 seats: 3 seats on the left side, a single aisle, and 3 seats on the right side. At each of the left and right sides there is a window seat, a middle seat, and an aisle seat. A passenger that boards an aircraft assigned to an aisle seat takes significantly less time than a passenger assigned to a window seat even when there is no one else in the aircraft.

The company decided to compute an inconvenience of a layout as the total sum of distances from each of the seats of a single row to the closest aisle. The distance from a seat to an aisle is the number of seats between them. For a 3-3 layout, a window seat has a distance of 2, a middle seat — 1, and an aisle seat — 0. The inconvenience of a 3-3 layout is $(2+1+0)+(0+1+2)=6$. The inconvenience of a 3-5-3 layout is $(2+1+0)+(0+1+2+1+0)+(0+1+2)=10$.

Formally, a layout is a sequence of positive integers $a_1, a_2, \ldots, a_{k+1}$ — group $i$ having $a_i$ seats, with $k$ aisles between groups, the $i$-th aisle being between groups $i$ and $i+1$. This means that in a layout each aisle must always be between two seats, so no aisle can be next to a window, and no two aisles can be next to each other.

The company decided to design a layout with a row of $n$ seats, $k$ aisles and having the minimum inconvenience possible. Help them find the minimum inconvenience among all layouts of $n$ seats and $k$ aisles, and count the number of such layouts modulo $998\,244\,353$.

### Input

The first line contains an integer $t$ — the number of test cases you need to solve ($1 \le t \le 10^5$).

For each of the test cases, there is a single line containing $n$ and $k$ — the number of seats, and the number of aisles in a row ($2 \le n \le 10^9$; $1 \le k \le 10^5$; $k < n$).

The total sum of $k$ in all $t$ given test cases does not exceed $10^6$.

### Output

For each test case print two integers — the minimum inconvenience among all possible layouts, and the number of layouts with the minimum inconvenience modulo $998\,244\,353$.

## Example

### Input


```text
84 13 24 25 26 16 21000000000 19 2
```
### Output

```text

2 1
0 1
0 1
1 3
6 1
2 4
249999999500000000 1
6 3

```
## Note

In the last test case of 9 2 the possible layouts with the minimum inconvenience of 6 are 3-4-2, 2-4-3, and 2-5-2.



#### Tags 

#2100 #NOT OK #combinatorics #divide_and_conquer #math 

## Blogs
- [All Contest Problems](../2023-2024_ICPC,_NERC,_Northern_Eurasia_Onsite_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Discussion (en)](../blogs/Discussion_(en).md)
