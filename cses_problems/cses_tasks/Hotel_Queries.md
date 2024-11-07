![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Hotel Queries

  * Task
  * Statistics

CSES - Hotel Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ hotels on a street. For each hotel you know the number of free
rooms. Your task is to assign hotel rooms for groups of tourists. All members
of a group want to stay in the same hotel.

The groups will come to you one after another, and you know for each group the
number of rooms it requires. You always assign a group to the first hotel
having enough rooms. After this, the number of free rooms in the hotel
decreases.

# Input

The first input line contains two integers $n$ and $m$: the number of hotels
and the number of groups. The hotels are numbered $1,2,\ldots,n$.

The next line contains $n$ integers $h_1,h_2,\ldots,h_n$: the number of free
rooms in each hotel.

The last line contains $m$ integers $r_1,r_2,\ldots,r_m$: the number of rooms
each group requires.

# Output

Print the assigned hotel for each group. If a group cannot be assigned a
hotel, print 0 instead.

# Constraints

  * $1 \le n,m \le 2 \cdot 10^5$
  * $1 \le h_i \le 10^9$
  * $1 \le r_i \le 10^9$

# Example

Input:

``` 8 5 3 2 4 1 5 5 2 6 4 4 7 1 1 ```

Output:

``` 3 5 0 1 1 ```

#### Range Queries

... Range Xor QueriesRange Update QueriesForest QueriesHotel QueriesList
RemovalsSalary QueriesPrefix Sum QueriesPizzeria Queries...

* * *

