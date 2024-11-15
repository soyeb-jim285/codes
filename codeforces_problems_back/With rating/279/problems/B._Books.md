<h1 style='text-align: center;'> B. Books</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

When Valera has got some free time, he goes to the library to read some books. Today he's got *t* free minutes to read. That's why Valera took *n* books in the library and for each book he estimated the time he is going to need to read it. Let's number the books by integers from 1 to *n*. Valera needs *a**i* minutes to read the *i*-th book.

Valera decided to choose an arbitrary book with number *i* and read the books one by one, starting from this book. In other words, he will first read book number *i*, then book number *i* + 1, then book number *i* + 2 and so on. He continues the process until he either runs out of the free time or finishes reading the *n*-th book. Valera reads each book up to the end, that is, he doesn't start reading the book if he doesn't have enough free time to finish reading it. 

Print the maximum number of books Valera can read.

## Input

The first line contains two integers *n* and *t* (1 ≤ *n* ≤ 105; 1 ≤ *t* ≤ 109) — the number of books and the number of free minutes Valera's got. The second line contains a sequence of *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 104), where number *a**i* shows the number of minutes that the boy needs to read the *i*-th book.

## Output

Print a single integer — the maximum number of books Valera can read.

## Examples

## Input


```
4 5  
3 1 2 1  

```
## Output


```
3  

```
## Input


```
3 3  
2 2 3  

```
## Output


```
1  

```


#### tags 

#1400 #binary_search #brute_force #implementation #two_pointers 