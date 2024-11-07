<h1 style='text-align: center;'> D. Mike and distribution</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mike has always been thinking about the harshness of social inequality. He's so obsessed with it that sometimes it even affects him while solving problems. At the moment, Mike has two sequences of positive integers *A* = [*a*1, *a*2, ..., *a**n*] and *B* = [*b*1, *b*2, ..., *b**n*] of length *n* each which he uses to ask people some quite peculiar questions.

To test you on how good are you at spotting inequality in life, he wants you to find an "unfair" subset of the original sequence. To be more precise, he wants you to select *k* numbers *P* = [*p*1, *p*2, ..., *p**k*] such that 1 ≤ *p**i* ≤ *n* for 1 ≤ *i* ≤ *k* and elements in *P* are distinct. Sequence *P* will represent indices of elements that you'll select from both sequences. He calls such a subset *P* "unfair" if and only if the following conditions are satisfied: 2·(*a**p*1 + ... + *a**p**k*) is greater than the sum of all elements from sequence *A*, and 2·(*b**p*1 + ... + *b**p**k*) is greater than the sum of all elements from the sequence *B*. Also, *k* should be smaller or equal to ![](images/e70d0af1413d58226605b883a776c3d3115f99a2.png) because it will be to easy to find sequence *P* if he allowed you to select too many elements!

Mike guarantees you that a solution will always exist given the conditions described above, so please help him satisfy his curiosity!

## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) — the number of elements in the sequences. 

On the second line there are *n* space-separated integers *a*1, ..., *a**n* (1 ≤ *a**i* ≤ 109) — elements of sequence *A*.

On the third line there are also *n* space-separated integers *b*1, ..., *b**n* (1 ≤ *b**i* ≤ 109) — elements of sequence *B*.

## Output

On the first line output an integer *k* which represents the size of the found subset. *k* should be less or equal to ![](images/a469312c13fe74770be91238847356d82f74c170.png).

On the next line print *k* integers *p*1, *p*2, ..., *p**k* (1 ≤ *p**i* ≤ *n*) — the elements of sequence *P*. You can print the numbers in any order you want. Elements in sequence *P* should be distinct.

## Example

## Input


```
5  
8 7 4 8 3  
4 2 5 3 7  

```
## Output


```
3  
1 4 5  

```


#### tags 

#2400 #constructive_algorithms #sortings 