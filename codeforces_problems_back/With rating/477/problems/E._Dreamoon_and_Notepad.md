<h1 style='text-align: center;'> E. Dreamoon and Notepad</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dreamoon has just created a document of hard problems using notepad.exe. The document consists of *n* lines of text, *a**i* denotes the length of the *i*-th line. He now wants to know what is the fastest way to move the cursor around because the document is really long.

Let (*r*, *c*) be a current cursor position, where *r* is row number and *c* is position of cursor in the row. We have 1 ≤ *r* ≤ *n* and 0 ≤ *c* ≤ *a**r*.

We can use following six operations in notepad.exe to move our cursor assuming the current cursor position is at (*r*, *c*):

1. up key: the new cursor position (*nr*, *nc*) = (*max*(*r* - 1, 1), *min*(*a**nr*, *c*))
2. down key: the new cursor position (*nr*, *nc*) = (*min*(*r* + 1, *n*), *min*(*a**nr*, *c*))
3. left key: the new cursor position (*nr*, *nc*) = (*r*, *max*(0, *c* - 1))
4. right key: the new cursor position (*nr*, *nc*) = (*r*, *min*(*a**nr*, *c* + 1))
5. HOME key: the new cursor position (*nr*, *nc*) = (*r*, 0)
6. END key: the new cursor position (*nr*, *nc*) = (*r*, *a**r*)

You're given the document description (*n* and sequence *a**i*) and *q* queries from Dreamoon. Each query asks what minimal number of key presses is needed to move the cursor from (*r*1, *c*1) to (*r*2, *c*2).

## Input

The first line contains an integer *n*(1 ≤ *n* ≤ 400, 000) — the number of lines of text. 

The second line contains *n* integers *a*1, *a*2, ..., *a**n*(1 ≤ *a**i* ≤ 108).

The third line contains an integer *q*(1 ≤ *q* ≤ 400, 000). 

Each of the next *q* lines contains four integers *r*1, *c*1, *r*2, *c*2 representing a query (1 ≤ *r*1, *r*2 ≤ *n*, 0 ≤ *c*1 ≤ *a**r*1, 0 ≤ *c*2 ≤ *a**r*2).

## Output

For each query print the result of the query.

## Examples

## Input


```
9  
1 3 5 3 1 3 5 3 1  
4  
3 5 3 1  
3 3 7 3  
1 0 3 3  
6 0 7 3  

```
## Output


```
2  
5  
3  
2  

```
## Input


```
2  
10 5  
1  
1 0 1 5  

```
## Output


```
3  

```
## Note

In the first sample, the first query can be solved with keys: HOME, right.

The second query can be solved with keys: down, down, down, END, down.

The third query can be solved with keys: down, END, down.

The fourth query can be solved with keys: END, down.



#### tags 

#3100 #data_structures 