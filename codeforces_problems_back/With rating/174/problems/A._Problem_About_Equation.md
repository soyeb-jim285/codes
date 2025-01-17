<h1 style='text-align: center;'> A. Problem About Equation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A group of *n* merry programmers celebrate Robert Floyd's birthday. Polucarpus has got an honourable task of pouring Ber-Cola to everybody. Pouring the same amount of Ber-Cola to everybody is really important. In other words, the drink's volume in each of the *n* mugs must be the same.

Polycarpus has already began the process and he partially emptied the Ber-Cola bottle. Now the first mug has *a*1 milliliters of the drink, the second one has *a*2 milliliters and so on. The bottle has *b* milliliters left and Polycarpus plans to pour them into the mugs so that the main equation was fulfilled.

Write a program that would determine what volume of the drink Polycarpus needs to add into each mug to ensure that the following two conditions were fulfilled simultaneously: 

* there were *b* milliliters poured in total. That is, the bottle need to be emptied;
* after the process is over, the volumes of the drink in the mugs should be equal.
## Input

The first line contains a pair of integers *n*, *b* (2 ≤ *n* ≤ 100, 1 ≤ *b* ≤ 100), where *n* is the total number of friends in the group and *b* is the current volume of drink in the bottle. The second line contains a sequence of integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 100), where *a**i* is the current volume of drink in the *i*-th mug.

## Output

Print a single number "-1" (without the quotes), if there is no solution. Otherwise, print *n* float numbers *c*1, *c*2, ..., *c**n*, where *c**i* is the volume of the drink to add in the *i*-th mug. Print the numbers with no less than 6 digits after the decimal point, print each *c**i* on a single line. Polycarpus proved that if a solution exists then it is unique.

Russian locale is installed by default on the testing computer. Make sure that your solution use the point to separate the integer part of a real number from the decimal, not a comma.

## Examples

## Input


```
5 50  
1 2 3 4 5  

```
## Output


```
12.000000  
11.000000  
10.000000  
9.000000  
8.000000  

```
## Input


```
2 2  
1 100  

```
## Output


```
-1  

```


#### tags 

#1100 #math 