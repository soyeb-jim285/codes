<h1 style='text-align: center;'> G. Keep talking and nobody explodes – medium</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

This is an unusual problem in an unusual contest, here is the announcement: [http://codeforces.com../blogs/Announcement_(en).md](//codeforces.com../blogs/Announcement_(en).md)

You have the safe lock which consists of 5 decimal digits. If you rotate some digit, it increases by one, except 9 which becomes 0.

Initially, the lock contains number $x$. To unlock the safe you must do the following operations in order (and be careful, don't mix up if and else statements).

If sum of digits on positions 3 and 4 is greater than 10, rotate digit on position 2 by 9 times, else rotate digit on position 5 by 4 times.

If digit on position 3 is greater than digit on position 5, rotate digit on position 2 by 4 times, else rotate digit on position 4 by 6 times.

If digit on position 5 is greater than digit on position 3, rotate digit on position 2 by 1 times, else rotate digit on position 1 by 7 times.

If sum of digits on positions 4 and 1 is greater than 8, rotate digit on position 2 by 7 times, else rotate digit on position 3 by 3 times.

If digit on position 4 is greater than digit on position 1, rotate digit on position 2 by 3 times, else rotate digit on position 3 by 2 times.

If sum of digits on positions 1 and 2 is greater than 9, rotate digit on position 3 by 6 times, else rotate digit on position 5 by 3 times.

If digit on position 3 is greater than digit on position 2, rotate digit on position 1 by 2 times, else rotate digit on position 4 by 5 times.

If digit on position 5 is greater than digit on position 3, rotate digit on position 2 by 1 times, else rotate digit on position 4 by 5 times.

If sum of digits on positions 5 and 1 is greater than 10, rotate digit on position 4 by 7 times, else rotate digit on position 3 by 5 times.

If sum of digits on positions 5 and 4 is greater than 9, rotate digit on position 3 by 9 times, else rotate digit on position 2 by 4 times.

If sum of digits on positions 3 and 1 is greater than 8, rotate digit on position 2 by 8 times, else rotate digit on position 4 by 4 times.

If digit on position 5 is greater than digit on position 2, rotate digit on position 1 by 5 times, else rotate digit on position 3 by 8 times.

If sum of digits on positions 1 and 4 is greater than 10, rotate digit on position 3 by 4 times, else rotate digit on position 5 by 1 times.

If digit on position 3 is greater than digit on position 5, rotate digit on position 2 by 1 times, else rotate digit on position 1 by 6 times.

If sum of digits on positions 1 and 5 is greater than 9, rotate digit on position 3 by 3 times, else rotate digit on position 2 by 1 times.

If digit on position 5 is greater than digit on position 1, rotate digit on position 4 by 8 times, else rotate digit on position 2 by 1 times.

If digit on position 4 is greater than digit on position 1, rotate digit on position 3 by 4 times, else rotate digit on position 5 by 4 times.

If sum of digits on positions 3 and 1 is greater than 8, rotate digit on position 5 by 3 times, else rotate digit on position 2 by 6 times.

If digit on position 3 is greater than digit on position 4, rotate digit on position 2 by 3 times, else rotate digit on position 1 by 5 times.

If digit on position 5 is greater than digit on position 4, rotate digit on position 2 by 7 times, else rotate digit on position 3 by 8 times.

If digit on position 2 is greater than digit on position 4, rotate digit on position 5 by 9 times, else rotate digit on position 1 by 4 times.

If sum of digits on positions 3 and 5 is greater than 10, rotate digit on position 4 by 1 times, else rotate digit on position 2 by 5 times.

If digit on position 4 is greater than digit on position 1, rotate digit on position 3 by 9 times, else rotate digit on position 2 by 9 times.

If digit on position 5 is greater than digit on position 3, rotate digit on position 2 by 4 times, else rotate digit on position 1 by 6 times.

If sum of digits on positions 3 and 4 is greater than 9, rotate digit on position 5 by 8 times, else rotate digit on position 2 by 5 times.

If sum of digits on positions 3 and 4 is greater than 10, rotate digit on position 5 by 2 times, else rotate digit on position 1 by 5 times.

If sum of digits on positions 5 and 4 is greater than 9, rotate digit on position 3 by 3 times, else rotate digit on position 1 by 8 times.

If digit on position 5 is greater than digit on position 2, rotate digit on position 1 by 4 times, else rotate digit on position 3 by 8 times.

If digit on position 3 is greater than digit on position 1, rotate digit on position 5 by 6 times, else rotate digit on position 2 by 6 times.

If digit on position 4 is greater than digit on position 5, rotate digit on position 1 by 6 times, else rotate digit on position 3 by 1 times.

If sum of digits on positions 3 and 5 is greater than 10, rotate digit on position 2 by 5 times, else rotate digit on position 1 by 7 times.

If sum of digits on positions 5 and 2 is greater than 9, rotate digit on position 4 by 9 times, else rotate digit on position 3 by 5 times.

If sum of digits on positions 2 and 4 is greater than 10, rotate digit on position 3 by 1 times, else rotate digit on position 1 by 2 times.

If digit on position 3 is greater than digit on position 4, rotate digit on position 5 by 7 times, else rotate digit on position 2 by 1 times.

If digit on position 2 is greater than digit on position 5, rotate digit on position 1 by 6 times, else rotate digit on position 4 by 2 times.

If digit on position 2 is greater than digit on position 1, rotate digit on position 5 by 3 times, else rotate digit on position 4 by 4 times.

If digit on position 5 is greater than digit on position 4, rotate digit on position 3 by 9 times, else rotate digit on position 1 by 9 times.

If digit on position 1 is greater than digit on position 5, rotate digit on position 4 by 6 times, else rotate digit on position 2 by 5 times.

If sum of digits on positions 1 and 5 is greater than 10, rotate digit on position 3 by 7 times, else rotate digit on position 2 by 4 times.

If sum of digits on positions 2 and 1 is greater than 9, rotate digit on position 3 by 7 times, else rotate digit on position 5 by 4 times.

#### Input

#### Input

 contains single number $x$ consisting of exactly 5 digits, leading zeroes are allowed.

#### Output

#### Output

 the number after applying all operations.

## Examples

#### Input


```text
00000
```
#### Output


```text
43266
```
#### Input


```text
12345
```
#### Output


```text
87229
```


#### Tags 

#NOT OK 

## Blogs
- [All Contest Problems](../AIM_Tech_Poorly_Prepared_Contest_(unrated,_funny,_Div._1_preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
- [../blogs/Announcement_(en).md](../blogs/https:_codeforces.com_blog_entry_73543.md)
