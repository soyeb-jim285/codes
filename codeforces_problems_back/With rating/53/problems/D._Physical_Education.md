<h1 style='text-align: center;'> D. Physical Education</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya is a school PE teacher. Unlike other PE teachers, Vasya doesn't like it when the students stand in line according to their height. Instead, he demands that the children stand in the following order: *a*1, *a*2, ..., *a**n*, where *a**i* is the height of the *i*-th student in the line and *n* is the number of students in the line. The children find it hard to keep in mind this strange arrangement, and today they formed the line in the following order: *b*1, *b*2, ..., *b**n*, which upset Vasya immensely. Now Vasya wants to rearrange the children so that the resulting order is like this: *a*1, *a*2, ..., *a**n*. During each move Vasya can swap two people who stand next to each other in the line. Help Vasya, find the sequence of swaps leading to the arrangement Vasya needs. It is not required to minimize the number of moves.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 300) which is the number of students. The second line contains *n* space-separated integers *a**i* (1 ≤ *a**i* ≤ 109) which represent the height of the student occupying the *i*-th place must possess. The third line contains *n* space-separated integers *b**i* (1 ≤ *b**i* ≤ 109) which represent the height of the student occupying the *i*-th place in the initial arrangement. It is possible that some students possess similar heights. It is guaranteed that it is possible to arrange the children in the required order, i.e. *a* and *b* coincide as multisets.

## Output

In the first line print an integer *k* (0 ≤ *k* ≤ 106) which is the number of moves. It is not required to minimize *k* but it must not exceed 106. Then print *k* lines each containing two space-separated integers. Line *p**i*, *p**i* + 1 (1 ≤ *p**i* ≤ *n* - 1) means that Vasya should swap students occupying places *p**i* and *p**i* + 1.

## Examples

## Input


```
4  
1 2 3 2  
3 2 1 2  

```
## Output


```
4  
2 3  
1 2  
3 4  
2 3  

```
## Input


```
2  
1 100500  
1 100500  

```
## Output


```
0  

```


#### tags 

#1500 #sortings 