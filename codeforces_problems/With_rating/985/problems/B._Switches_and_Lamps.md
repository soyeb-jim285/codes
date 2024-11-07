<h1 style='text-align: center;'> B. Switches and Lamps</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *n* switches and *m* lamps. The *i*-th switch turns on some subset of the lamps. This information is given as the matrix *a* consisting of *n* rows and *m* columns where *a**i*, *j* = 1 if the *i*-th switch turns on the *j*-th lamp and *a**i*, *j* = 0 if the *i*-th switch is not connected to the *j*-th lamp.

Initially all *m* lamps are turned off.

Switches change state only from "off" to "on". It means that if you press two or more switches connected to the same lamp then the lamp will be turned on after any of this switches is pressed and will remain its state even if any switch connected to this lamp is pressed afterwards.

It is guaranteed that if you push all *n* switches then all *m* lamps will be turned on.

Your think that you have too many switches and you would like to ignore one of them. 

Your task is to say if there exists such a switch that if you will ignore (not use) it but press all the other *n* - 1 switches then all the *m* lamps will be turned on.

#### Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 2000) — the number of the switches and the number of the lamps.

The following *n* lines contain *m* characters each. The character *a**i*, *j* is equal to '1' if the *i*-th switch turns on the *j*-th lamp and '0' otherwise.

It is guaranteed that if you press all *n* switches all *m* lamps will be turned on.

#### Output

Print "YES" if there is a switch that if you will ignore it and press all the other *n* - 1 switches then all *m* lamps will be turned on. Print "NO" if there is no such switch.

## Examples

#### Input


```text
4 5  
10101  
01000  
00111  
10000  

```
#### Output


```text
YES  

```
#### Input


```text
4 5  
10100  
01000  
00110  
00101  

```
#### Output


```text
NO  

```


#### Tags 

#1200 #NOT OK #implementation 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_44_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
