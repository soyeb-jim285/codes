<h1 style='text-align: center;'> C. Dominoes</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

During the break, we decided to relax and play dominoes. Our box with Domino was empty, so we decided to borrow the teacher's dominoes.

The teacher responded instantly at our request. He put *nm* dominoes on the table as an *n* × 2*m* rectangle so that each of the *n* rows contained *m* dominoes arranged horizontally. Each half of each domino contained number (0 or 1).

We were taken aback, and the teacher smiled and said: "Consider some arrangement of dominoes in an *n* × 2*m* matrix. Let's count for each column of the matrix the sum of numbers in this column. Then among all such sums find the maximum one. Can you rearrange the dominoes in the matrix in such a way that the maximum sum will be minimum possible? ## Note

 that it is prohibited to change the orientation of the dominoes, they all need to stay horizontal, nevertheless dominoes are allowed to rotate by 180 degrees. As a reward I will give you all my dominoes".

We got even more taken aback. And while we are wondering what was going on, help us make an optimal matrix of dominoes.

## Input

The first line contains integers *n*, *m* (1 ≤ *n*, *m* ≤ 103).

In the next lines there is a description of the teachers' matrix. Each of next *n* lines contains *m* dominoes. The description of one domino is two integers (0 or 1), written without a space — the digits on the left and right half of the domino.

## Output

Print the resulting matrix of dominoes in the format: *n* lines, each of them contains *m* space-separated dominoes.

If there are multiple optimal solutions, print any of them.

## Examples

## Input


```
2 3  
01 11 00  
00 01 11  

```
## Output


```
11 11 10  
00 00 01  

```
## Input


```
4 1  
11  
10  
01  
00  

```
## Output


```
11  
10  
01  
00  

```
## Note

Consider the answer for the first sample. There, the maximum sum among all columns equals 1 (the number of columns is 6, and not 3). Obviously, this maximum can't be less than 1, then such matrix is optimal.

## Note

 that the dominoes can be rotated by 180 degrees.



#### tags 

#constructive_algorithms #greedy 