<h1 style='text-align: center;'> C. Unfair Poll</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

On the Literature lesson Sergei noticed an awful injustice, it seems that some students are asked more often than others.

Seating in the class looks like a rectangle, where *n* rows with *m* pupils in each. 

The teacher asks pupils in the following order: at first, she asks all pupils from the first row in the order of their seating, then she continues to ask pupils from the next row. If the teacher asked the last row, then the direction of the poll changes, it means that she asks the previous row. The order of asking the rows looks as follows: the 1-st row, the 2-nd row, ..., the *n* - 1-st row, the *n*-th row, the *n* - 1-st row, ..., the 2-nd row, the 1-st row, the 2-nd row, ...

The order of asking of pupils on the same row is always the same: the 1-st pupil, the 2-nd pupil, ..., the *m*-th pupil.

During the lesson the teacher managed to ask exactly *k* questions from pupils in order described above. Sergei seats on the *x*-th row, on the *y*-th place in the row. Sergei decided to prove to the teacher that pupils are asked irregularly, help him count three values:

1. the maximum number of questions a particular pupil is asked,
2. the minimum number of questions a particular pupil is asked,
3. how many times the teacher asked Sergei.

If there is only one row in the class, then the teacher always asks children from this row.

## Input

The first and the only line contains five integers *n*, *m*, *k*, *x* and *y* (1 ≤ *n*, *m* ≤ 100, 1 ≤ *k* ≤ 1018, 1 ≤ *x* ≤ *n*, 1 ≤ *y* ≤ *m*).

## Output

Print three integers:

1. the maximum number of questions a particular pupil is asked,
2. the minimum number of questions a particular pupil is asked,
3. how many times the teacher asked Sergei.
## Examples

## Input


```
1 3 8 1 1  

```
## Output


```
3 2 3
```
## Input


```
4 2 9 4 2  

```
## Output


```
2 1 1
```
## Input


```
5 5 25 4 3  

```
## Output


```
1 1 1
```
## Input


```
100 100 1000000000000000000 100 100  

```
## Output


```
101010101010101 50505050505051 50505050505051
```
## Note

The order of asking pupils in the first test: 

1. the pupil from the first row who seats at the first table, it means it is Sergei;
2. the pupil from the first row who seats at the second table;
3. the pupil from the first row who seats at the third table;
4. the pupil from the first row who seats at the first table, it means it is Sergei;
5. the pupil from the first row who seats at the second table;
6. the pupil from the first row who seats at the third table;
7. the pupil from the first row who seats at the first table, it means it is Sergei;
8. the pupil from the first row who seats at the second table;

The order of asking pupils in the second test: 

1. the pupil from the first row who seats at the first table;
2. the pupil from the first row who seats at the second table;
3. the pupil from the second row who seats at the first table;
4. the pupil from the second row who seats at the second table;
5. the pupil from the third row who seats at the first table;
6. the pupil from the third row who seats at the second table;
7. the pupil from the fourth row who seats at the first table;
8. the pupil from the fourth row who seats at the second table, it means it is Sergei;
9. the pupil from the third row who seats at the first table;


#### tags 

#1700 #binary_search #constructive_algorithms #implementation #math 