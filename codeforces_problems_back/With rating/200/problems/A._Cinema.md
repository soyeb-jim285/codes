<h1 style='text-align: center;'> A. Cinema</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The capital of Berland has the only movie theater in the country. Besides, it consists of only one room. The room is divided into *n* rows, each row consists of *m* seats.

There are *k* people lined up to the box office, each person wants to buy exactly one ticket for his own entertainment. Before the box office started selling tickets, each person found the seat that seemed best for him and remembered it as a pair of coordinates (*x**i*, *y**i*), where *x**i* is the row number, and *y**i* is the seat number in this row.

It is possible that some people have chosen the same place, then when some people see their favorite seat taken in the plan of empty seats in the theater, they choose and buy a ticket to another place. Each of them has the following logic: let's assume that he originally wanted to buy a ticket to seat (*x*1, *y*1), then when he comes to the box office, he chooses such empty seat (*x*2, *y*2), which satisfies the following conditions: 

* the value of |*x*1 - *x*2| + |*y*1 - *y*2| is minimum
* if the choice is not unique, then among the seats that satisfy the first condition, this person selects the one for which the value of *x*2 is minimum
* if the choice is still not unique, among the seats that satisfy the first and second conditions, this person selects the one for which the value of *y*2 is minimum

Your task is to find the coordinates of a seat for each person.

## Input

The first input line contains three integers *n*, *m*, *k* (1 ≤ *n*, *m* ≤ 2000, 1 ≤ *k* ≤ *min*(*n*·*m*, 105) — the number of rows in the room, the number of seats in each row and the number of people in the line, correspondingly. Each of the next *k* lines contains two integers *x**i*, *y**i* (1 ≤ *x**i* ≤ *n*, 1 ≤ *y**i* ≤ *m*) — the coordinates of the seat each person has chosen. Numbers on the same line are separated by a space. The pairs of coordinates are located in the order, in which people stand in the line, starting from the head (the first person in the line who stands in front of the box office) to the tail (the last person in the line).

## Output

Print *k* lines, each containing a pair of integers. Print on the *i*-th line *x**i*, *y**i* — the coordinates of the seat, for which the person who stands *i*-th in the line will buy the ticket. 

## Examples

## Input


```
3 4 6  
1 1  
1 1  
1 1  
1 2  
1 3  
1 3  

```
## Output


```
1 1  
1 2  
2 1  
1 3  
1 4  
2 3  

```
## Input


```
4 3 12  
2 2  
2 2  
2 2  
2 2  
2 2  
2 2  
2 2  
2 2  
2 2  
2 2  
2 2  
2 2  

```
## Output


```
2 2  
1 2  
2 1  
2 3  
3 2  
1 1  
1 3  
3 1  
3 3  
4 2  
4 1  
4 3  

```


#### tags 

#2400 #brute_force #data_structures 