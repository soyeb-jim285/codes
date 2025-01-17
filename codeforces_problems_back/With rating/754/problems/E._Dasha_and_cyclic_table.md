<h1 style='text-align: center;'> E. Dasha and cyclic table</h1>

<h5 style='text-align: center;'>time limit per test: 6 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Dasha is fond of challenging puzzles: Rubik's Cube 3 × 3 × 3, 4 × 4 × 4, 5 × 5 × 5 and so on. This time she has a cyclic table of size *n* × *m*, and each cell of the table contains a lowercase English letter. Each cell has coordinates (*i*, *j*) (0 ≤ *i* < *n*, 0 ≤ *j* < *m*). The table is cyclic means that to the right of cell (*i*, *j*) there is the cell ![](images/e00cecdb9def14eda362dd13b8a57d183987a244.png), and to the down there is the cell ![](images/4af907e4db06c705844ece1487c9a8b73c4446aa.png).

Dasha has a pattern as well. A pattern is a non-cyclic table of size *r* × *c*. Each cell is either a lowercase English letter or a question mark. Each cell has coordinates (*i*, *j*) (0 ≤ *i* < *r*, 0 ≤ *j* < *c*).

The goal of the puzzle is to find all the appearance positions of the pattern in the cyclic table.

We say that the cell (*i*, *j*) of cyclic table is an appearance position, if for every pair (*x*, *y*) such that 0 ≤ *x* < *r* and 0 ≤ *y* < *c* one of the following conditions holds: 

* There is a question mark in the cell (*x*, *y*) of the pattern, or
* The cell ![](images/d5c67d542f3276ced72278777147ac5f3b4c9958.png) of the cyclic table equals to the cell (*x*, *y*) of the pattern.

Dasha solved this puzzle in no time, as well as all the others she ever tried. Can you solve it?.

## Input

The first line contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 400) — the cyclic table sizes.

Each of the next *n* lines contains a string of *m* lowercase English characters — the description of the cyclic table.

The next line contains two integers *r* and *c* (1 ≤ *r*, *c* ≤ 400) — the sizes of the pattern.

Each of the next *r* lines contains a string of *c* lowercase English letter and/or characters '?' — the description of the pattern.

## Output

Print *n* lines. Each of the *n* lines should contain *m* characters. Each of the characters should equal '0' or '1'.

The *j*-th character of the *i*-th (0-indexed) line should be equal to '1', in case the cell (*i*, *j*) is an appearance position, otherwise it should be equal to '0'.

## Examples

## Input


```
5 7  
qcezchs  
hhedywq  
wikywqy  
qckrqzt  
bqexcxz  
3 2  
??  
yw  
?q  

```
## Output


```
0000100  
0001001  
0000000  
0000000  
0000000  

```
## Input


```
10 10  
fwtoayylhw  
yyaryyjawr  
ywrdzwhscy  
hnsyyxiphn  
bnjwzyyjvo  
kkjgseenwn  
gvmiflpcsy  
lxvkwrobwu  
wyybbcocyy  
yysijsvqry  
2 2  
??  
yy  

```
## Output


```
1000100000  
0000000001  
0001000000  
0000010000  
0000000000  
0000000000  
0000000000  
0100000010  
1000000001  
0000010000  

```
## Input


```
8 6  
ibrgxl  
xqdcsg  
okbcgi  
tvpetc  
xgxxig  
igghzo  
lmlaza  
gpswzv  
1 4  
gx??  

```
## Output


```
000100  
000001  
000000  
000000  
010001  
000000  
000000  
000000  

```


#### tags 

#2600 #bitmasks #brute_force #fft #strings #trees 