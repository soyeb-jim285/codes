<h1 style='text-align: center;'> B. End of Exams</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Students love to celebrate their holidays. Especially if the holiday is the day of the end of exams!

Despite the fact that Igor K., unlike his groupmates, failed to pass a programming test, he decided to invite them to go to a cafe so that each of them could drink a bottle of... fresh cow milk. Having entered the cafe, the *m* friends found *n* different kinds of milk on the menu, that's why they ordered *n* bottles — one bottle of each kind. We know that the volume of milk in each bottle equals *w*.

When the bottles were brought in, they decided to pour all the milk evenly among the *m* cups, so that each got a cup. As a punishment for not passing the test Igor was appointed the person to pour the milk. He protested that he was afraid to mix something up and suggested to distribute the drink so that the milk from each bottle was in no more than two different cups. His friends agreed but they suddenly faced the following problem — and what is actually the way to do it?

Help them and write the program that will help to distribute the milk among the cups and drink it as quickly as possible!

Note that due to Igor K.'s perfectly accurate eye and unswerving hands, he can pour any fractional amount of milk from any bottle to any cup.

## Input

The only input data file contains three integers *n*, *w* and *m* (1 ≤ *n* ≤ 50, 100 ≤ *w* ≤ 1000, 2 ≤ *m* ≤ 50), where *n* stands for the number of ordered bottles, *w* stands for the volume of each of them and *m* stands for the number of friends in the company.

## Output

Print on the first line "YES" if it is possible to pour the milk so that the milk from each bottle was in no more than two different cups. If there's no solution, print "NO".

If there is a solution, then print *m* more lines, where the *i*-th of them describes the content of the *i*-th student's cup. The line should consist of one or more pairs that would look like "*b* *v*". Each such pair means that *v* (*v* > 0) units of milk were poured into the *i*-th cup from bottle *b* (1 ≤ *b* ≤ *n*). All numbers *b* on each line should be different.

If there are several variants to solve the problem, print any of them. Print the real numbers with no less than 6 digits after the decimal point.

## Examples

## Input


```
2 500 3  

```
## Output


```
YES  
1 333.333333  
2 333.333333  
2 166.666667 1 166.666667  

```
## Input


```
4 100 5  

```
## Output


```
YES  
3 20.000000 4 60.000000  
1 80.000000  
4 40.000000 2 40.000000  
3 80.000000  
2 60.000000 1 20.000000  

```
## Input


```
4 100 7  

```
## Output


```
NO  

```
## Input


```
5 500 2  

```
## Output


```
YES  
4 250.000000 5 500.000000 2 500.000000  
3 500.000000 1 500.000000 4 250.000000  

```


#### tags 

#1900 #greedy 