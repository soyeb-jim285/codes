<h1 style='text-align: center;'> D. Least Cost Bracket Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

This is yet another problem on regular bracket sequences.

A bracket sequence is called regular, if by inserting "+" and "1" into it we get a correct mathematical expression. For example, sequences "(())()", "()" and "(()(()))" are regular, while ")(", "(()" and "(()))(" are not. You have a pattern of a bracket sequence that consists of characters "(", ")" and "?". You have to replace each character "?" with a bracket so, that you get a regular bracket sequence.

For each character "?" the cost of its replacement with "(" and ")" is given. Among all the possible variants your should choose the cheapest.

## Input

The first line contains a non-empty pattern of even length, consisting of characters "(", ")" and "?". Its length doesn't exceed 5·104. Then there follow *m* lines, where *m* is the number of characters "?" in the pattern. Each line contains two integer numbers *a**i* and *b**i* (1 ≤ *a**i*,  *b**i* ≤ 106), where *a**i* is the cost of replacing the *i*-th character "?" with an opening bracket, and *b**i* — with a closing one.

## Output

Print the cost of the optimal regular bracket sequence in the first line, and the required sequence in the second.

Print -1, if there is no answer. If the answer is not unique, print any of them. 

## Examples

## Input


```
(??)  
1 2  
2 8  

```
## Output


```
4  
()()  

```


#### tags 

#2600 #greedy 