<h1 style='text-align: center;'> E. Pills</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Doctor prescribed medicine to his patient. The medicine is represented by pills. Each pill consists of a shell and healing powder. The shell consists of two halves; each half has one of four colors — blue, red, white or yellow.

The doctor wants to put 28 pills in a rectangular box 7 × 8 in size. Besides, each pill occupies exactly two neighboring cells and any cell contains exactly one half of a pill. Thus, the result is a four colored picture 7 × 8 in size.

The doctor thinks that a patient will recover sooner if the picture made by the pills will be special. Unfortunately, putting the pills in the box so as to get the required picture is not a very easy task. That's why doctor asks you to help. 

Doctor has some amount of pills of each of 10 painting types. They all contain the same medicine, that's why it doesn't matter which 28 of them will be stored inside the box.

Place the pills in the box so that the required picture was formed. If it is impossible to place the pills in the required manner, then place them so that the number of matching colors in all 56 cells in the final arrangement and the doctor's picture were maximum.

## Input

First 7 lines contain the doctor's picture. Each line contains 8 characters, each character can be "B", "R", "W" and "Y" that stands for blue, red, white and yellow colors correspondingly.

Next four lines contain 10 numbers that stand for, correspondingly, the number of pills painted:

"BY" "BW" "BR" "BB"

"RY" "RW" "RR"

"WY" "WW"

"YY"

Those numbers lie within range from 0 to 28 inclusively. It is guaranteed that the total number of pills in no less than 28.

## Output

Print on the first line the maximal number cells for which the colors match.

Then print 13 lines each containing 15 characters — the pills' position in the optimal arrangement. The intersections of odd lines and odd columns should contain characters "B", "R", "W" and "Y". All other positions should contain characters ".", "-" and "|". Use "-" and "|" to show which halves belong to one pill. See the samples for more clarification.

If there are several possible solutions, print any of them.

## Examples

## Input


```
WWWBBWWW  
WWWBBWWW  
YYWBBWWW  
YYWBBWRR  
YYWBBWRR  
YYWBBWRR  
YYWBBWRR  
0 0 0 8  
0 1 5  
1 10  
5  

```
## Output


```
53  
W.W.W.B.B.W.W.W  
|.|.|.|.|.|.|.|  
W.W.W.B.B.W.W.W  
...............  
Y.Y.W.B.B.W.W-W  
|.|.|.|.|.|....  
Y.Y.W.B.B.W.R.R  
............|.|  
Y.Y.W.B.B.R.R.R  
|.|.|.|.|.|....  
Y.Y.W.B.B.W.R.R  
............|.|  
Y-Y.B-B.B-B.R.R  

```
## Input


```
WWWWWWWW  
WBYWRBBY  
BRYRBWYY  
WWBRYWBB  
BWWRWBYW  
RBWRBWYY  
WWWWWWWW  
0 0 0 1  
0 0 1  
0 1  
25  

```
## Output


```
15  
W.Y.Y-Y.Y-Y.Y-Y  
|.|............  
W.Y.Y.Y.Y.B-B.Y  
....|.|.|.....|  
Y-Y.Y.Y.Y.Y-Y.Y  
...............  
Y.Y.Y.R.Y.Y.Y-Y  
|.|.|.|.|.|....  
Y.Y.Y.R.Y.Y.Y.Y  
............|.|  
Y-Y.Y.Y-Y.Y.Y.Y  
....|.....|....  
Y-Y.Y.Y-Y.Y.Y-Y  

```


#### tags 

#2900 #brute_force #flows 