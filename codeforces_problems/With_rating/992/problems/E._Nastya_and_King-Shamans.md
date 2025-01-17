<h1 style='text-align: center;'> E. Nastya and King-Shamans</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Nastya likes reading and even spends whole days in a library sometimes. Today she found a chronicle of Byteland in the library, and it stated that there lived shamans long time ago. It is known that at every moment there was exactly one shaman in Byteland, and there were *n* shamans in total enumerated with integers from 1 to *n* in the order they lived. Also, each shaman had a magic power which can now be expressed as an integer.

The chronicle includes a list of powers of the *n* shamans. Also, some shamans can be king-shamans, if they gathered all the power of their predecessors, i.e. their power is exactly the sum of powers of all previous shamans. Nastya is interested in whether there was at least one king-shaman in Byteland.

Unfortunately many of the powers are unreadable in the list, so Nastya is doing the following:

* Initially she supposes some power for each shaman.
* After that she changes the power of some shaman *q* times (the shamans can differ) and after that wants to check if there is at least one king-shaman in the list. If yes, she wants to know the index of any king-shaman.

Unfortunately the list is too large and Nastya wants you to help her.

##### Input

The first line contains two integers *n* and *q* (1 ≤ *n*, *q* ≤ 2·105).

The second line contains *n* integers *a*1, ..., *a**n* (0 ≤ *a**i* ≤ 109), where *a**i* is the magic power of the *i*-th shaman.

After that *q* lines follow, the *i*-th of them contains two integers *p**i* and *x**i* (1 ≤ *p**i* ≤ *n*, 0 ≤ *x**i* ≤ 109) that mean that the new power of the *p**i*-th shaman is *x**i*.

##### Output

Print *q* lines, the *i*-th of them should contain  - 1, if after the *i*-th change there are no shaman-kings, and otherwise a single integer *j*, where *j* is an index of some king-shaman after the *i*-th change.

If there are multiple king-shamans after each change, print the index of any of them.

## Examples

##### Input


```text
2 1  
1 3  
1 2  

```
##### Output


```text
-1  

```
##### Input


```text
3 4  
2 2 3  
1 1  
1 2  
2 4  
3 6  

```
##### Output


```text
3  
2  
-1  
3  

```
##### Input


```text
10 7  
0 3 1 4 6 2 7 8 10 1  
2 5  
1 3  
9 36  
4 10  
4 9  
1 2  
1 0  

```
##### Output


```text
1  
-1  
9  
-1  
4  
-1  
1  

```
## Note

In the first example powers of shamans after the first change are equal to (2, 3). The answer equals  - 1, because the sum of powers of shamans before the first shaman is equal to 0, and before the second is equal to 2.

In the second example after the first change the powers are equal to (1, 2, 3). The answer is equal to 3, because the power of the third shaman is equal to 3, and the sum of powers of the first and the second shaman is also 1 + 2 = 3. After the second change the powers become equal to (2, 2, 3), where the answer equals 2. After the third change the powers become equal to (2, 4, 3), where the answer equals  - 1. After the fourth change the powers become equal to (2, 4, 6), where the answer equals 3.



#### Tags 

#2500 #NOT OK #binary_search #data_structures 

## Blogs
- [All Contest Problems](../Codeforces_Round_489_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
