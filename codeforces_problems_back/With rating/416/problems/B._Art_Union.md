<h1 style='text-align: center;'> B. Art Union</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A well-known art union called "Kalevich is Alive!" manufactures objects d'art (pictures). The union consists of *n* painters who decided to organize their work as follows.

Each painter uses only the color that was assigned to him. The colors are distinct for all painters. Let's assume that the first painter uses color 1, the second one uses color 2, and so on. Each picture will contain all these *n* colors. Adding the *j*-th color to the *i*-th picture takes the *j*-th painter *t**ij* units of time.

Order is important everywhere, so the painters' work is ordered by the following rules:

* Each picture is first painted by the first painter, then by the second one, and so on. That is, after the *j*-th painter finishes working on the picture, it must go to the (*j* + 1)-th painter (if *j* < *n*);
* each painter works on the pictures in some order: first, he paints the first picture, then he paints the second picture and so on;
* each painter can simultaneously work on at most one picture. However, the painters don't need any time to have a rest;
* as soon as the *j*-th painter finishes his part of working on the picture, the picture immediately becomes available to the next painter.

Given that the painters start working at time 0, find for each picture the time when it is ready for sale.

## Input

The first line of the input contains integers *m*, *n* (1 ≤ *m* ≤ 50000, 1 ≤ *n* ≤ 5), where *m* is the number of pictures and *n* is the number of painters. Then follow the descriptions of the pictures, one per line. Each line contains *n* integers *t**i*1, *t**i*2, ..., *t**in* (1 ≤ *t**ij* ≤ 1000), where *t**ij* is the time the *j*-th painter needs to work on the *i*-th picture.

## Output

Print the sequence of *m* integers *r*1, *r*2, ..., *r**m*, where *r**i* is the moment when the *n*-th painter stopped working on the *i*-th picture.

## Examples

## Input


```
5 1  
1  
2  
3  
4  
5  

```
## Output


```
1 3 6 10 15 
```
## Input


```
4 2  
2 5  
3 1  
5 3  
10 1  

```
## Output


```
7 8 13 21 
```


#### tags 

#1300 #brute_force #dp #implementation 