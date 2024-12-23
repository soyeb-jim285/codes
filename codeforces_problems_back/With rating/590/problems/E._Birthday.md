<h1 style='text-align: center;'> E. Birthday</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Today is birthday of a Little Dasha — she is now 8 years old! On this occasion, each of her *n* friends and relatives gave her a ribbon with a greeting written on it, and, as it turned out, all the greetings are different. Dasha gathered all the ribbons and decided to throw away some of them in order to make the remaining set stylish. The birthday girl considers a set of ribbons stylish if no greeting written on some ribbon is a substring of another greeting written on some other ribbon. Let us recall that the substring of the string *s* is a continuous segment of *s*.

Help Dasha to keep as many ribbons as possible, so that she could brag about them to all of her friends. Dasha cannot rotate or flip ribbons, that is, each greeting can be read in a single way given in the input.

## Input

The first line of the input contains integer *n* (1 ≤ *n* ≤ 750) — the number of Dasha's relatives and friends.

Each of the next *n* lines contains exactly one greeting. Each greeting consists of characters 'a' and 'b' only.

The total length of all greetings won't exceed 10 000 000 characters.

## Output

In the first line print the maximum size of the stylish set. In the second line print the numbers of ribbons involved in it, assuming that they are numbered from 1 to *n* in the order they appear in the input. If there are several stylish sets of the maximum size, print any of them.

## Examples

## Input


```
5  
abab  
aba  
aabab  
ababb  
bab  

```
## Output


```
2  
2 5  

```
## Note

In the sample, the answer that keeps ribbons 3 and 4 is also considered correct.



#### tags 

#3200 #graph_matchings #strings 