<h1 style='text-align: center;'> C. Lucky Tickets</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya thinks that lucky tickets are the tickets whose numbers are divisible by 3. He gathered quite a large collection of such tickets but one day his younger brother Leonid was having a sulk and decided to destroy the collection. First he tore every ticket exactly in two, but he didn’t think it was enough and Leonid also threw part of the pieces away. Having seen this, Vasya got terrified but still tried to restore the collection. He chose several piece pairs and glued each pair together so that each pair formed a lucky ticket. The rest of the pieces Vasya threw away reluctantly. Thus, after the gluing of the 2*t* pieces he ended up with *t* tickets, each of which was lucky.

When Leonid tore the tickets in two pieces, one piece contained the first several letters of his number and the second piece contained the rest.

Vasya can glue every pair of pieces in any way he likes, but it is important that he gets a lucky ticket in the end. For example, pieces 123 and 99 can be glued in two ways: 12399 and 99123.

What maximum number of tickets could Vasya get after that?

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 104) — the number of pieces. The second line contains *n* space-separated numbers *a**i* (1 ≤ *a**i* ≤ 108) — the numbers on the pieces. Vasya can only glue the pieces in pairs. Even if the number of a piece is already lucky, Vasya should glue the piece with some other one for it to count as lucky. Vasya does not have to use all the pieces. The numbers on the pieces an on the resulting tickets may coincide.

## Output

Print the single number — the maximum number of lucky tickets that will be able to be restored. Don't forget that every lucky ticket is made of exactly two pieces glued together.

## Examples

## Input


```
3  
123 123 99  

```
## Output


```
1  

```
## Input


```
6  
1 1 1 23 10 3  

```
## Output


```
1  

```


#### tags 

#1300 #greedy 