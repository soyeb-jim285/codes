<h1 style='text-align: center;'> A. Ilya and Diplomas</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Soon a school Olympiad in Informatics will be held in Berland, *n* schoolchildren will participate there.

At a meeting of the jury of the Olympiad it was decided that each of the *n* participants, depending on the results, will get a diploma of the first, second or third degree. Thus, each student will receive exactly one diploma.

They also decided that there must be given at least *min*1 and at most *max*1 diplomas of the first degree, at least *min*2 and at most *max*2 diplomas of the second degree, and at least *min*3 and at most *max*3 diplomas of the third degree.

After some discussion it was decided to choose from all the options of distributing diplomas satisfying these limitations the one that maximizes the number of participants who receive diplomas of the first degree. Of all these options they select the one which maximizes the number of the participants who receive diplomas of the second degree. If there are multiple of these options, they select the option that maximizes the number of diplomas of the third degree.

Choosing the best option of distributing certificates was entrusted to Ilya, one of the best programmers of Berland. However, he found more important things to do, so it is your task now to choose the best option of distributing of diplomas, based on the described limitations.

It is guaranteed that the described limitations are such that there is a way to choose such an option of distributing diplomas that all *n* participants of the Olympiad will receive a diploma of some degree.

## Input

The first line of the input contains a single integer *n* (3 ≤ *n* ≤ 3·106) — the number of schoolchildren who will participate in the Olympiad.

The next line of the input contains two integers *min*1 and *max*1 (1 ≤ *min*1 ≤ *max*1 ≤ 106) — the minimum and maximum limits on the number of diplomas of the first degree that can be distributed.

The third line of the input contains two integers *min*2 and *max*2 (1 ≤ *min*2 ≤ *max*2 ≤ 106) — the minimum and maximum limits on the number of diplomas of the second degree that can be distributed. 

The next line of the input contains two integers *min*3 and *max*3 (1 ≤ *min*3 ≤ *max*3 ≤ 106) — the minimum and maximum limits on the number of diplomas of the third degree that can be distributed. 

It is guaranteed that *min*1 + *min*2 + *min*3 ≤ *n* ≤ *max*1 + *max*2 + *max*3.

## Output

In the first line of the output print three numbers, showing how many diplomas of the first, second and third degree will be given to students in the optimal variant of distributing diplomas.

The optimal variant of distributing diplomas is the one that maximizes the number of students who receive diplomas of the first degree. Of all the suitable options, the best one is the one which maximizes the number of participants who receive diplomas of the second degree. If there are several of these options, the best one is the one that maximizes the number of diplomas of the third degree.

## Examples

## Input


```
6  
1 5  
2 6  
3 7  

```
## Output


```
1 2 3   

```
## Input


```
10  
1 2  
1 3  
1 5  

```
## Output


```
2 3 5   

```
## Input


```
6  
1 3  
2 2  
2 2  

```
## Output


```
2 2 2   

```


#### tags 

#1100 #greedy #implementation #math 