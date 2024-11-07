<h1 style='text-align: center;'> F. Passports</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Gleb is a famous competitive programming teacher from Innopolis. He is planning a trip to *N* programming camps in the nearest future. Each camp will be held in a different country. For each of them, Gleb needs to apply for a visa. 

For each of these trips Gleb knows three integers: the number of the first day of the trip *s**i*, the length of the trip in days *len**i*, and the number of days *t**i* this country's consulate will take to process a visa application and stick a visa in a passport. Gleb has *P* (1 ≤ *P* ≤ 2) valid passports and is able to decide which visa he wants to put in which passport.

For each trip, Gleb will have a flight to that country early in the morning of the day *s**i* and will return back late in the evening of the day *s**i* + *len**i* - 1.

To apply for a visa on the day *d*, Gleb needs to be in Innopolis in the middle of this day. So he can't apply for a visa while he is on a trip, including the first and the last days. If a trip starts the next day after the end of the other one, Gleb can't apply for a visa between them as well. The earliest Gleb can apply for a visa is day 1.

After applying for a visa of country *i* on day *d*, Gleb will get his passport back in the middle of the day *d* + *t**i*. Consulates use delivery services, so Gleb can get his passport back even if he is not in Innopolis on this day. Gleb can apply for another visa on the same day he received his passport back, if he is in Innopolis this day. 

Gleb will not be able to start his trip on day *s**i* if he doesn't has a passport with a visa for the corresponding country in the morning of day *s**i*. In particular, the passport should not be in another country's consulate for visa processing.

Help Gleb to decide which visas he needs to receive in which passport, and when he should apply for each visa. 

## Input

In the first line of the input there are two integers *N* (1 ≤ *N* ≤ 22) and *P* (1 ≤ *P* ≤ 2)—the number of trips and the number of passports Gleb has, respectively.

The next *N* lines describe Gleb's trips. Each line contains three positive integers *s**i*, *len**i*, *t**i* (1 ≤ *s**i*, *len**i*, *t**i* ≤ 109)—the first day of the trip, the length of the trip and number of days the consulate of this country needs to process a visa application. It is guaranteed that no two trips intersect.

## Output

If it is impossible to get all visas on time, just print "NO" (quotes for clarity). Otherwise, print "YES" and *N* lines describing trips. For each trip, first print number of the passport Gleb should put this country's visa in, and then print number of the day he should apply for it. Print trips in the same order as they appear in the input. Days are numbered from 1, starting with tomorrow—the first day you can apply for a visa. Passports are numbered from 1 to *P*.

If there are several possible answers, print any of them.

## Examples

## Input


```
2 1  
3 1 1  
6 1 1  

```
## Output


```
YES  
1 1  
1 4  

```
## Input


```
3 1  
13 2 2  
7 3 1  
19 3 4  

```
## Output


```
YES  
1 10  
1 1  
1 2  

```
## Input


```
7 2  
15 1 1  
14 1 1  
18 1 1  
21 1 1  
9 4 6  
22 2 5  
5 4 3  

```
## Output


```
YES  
2 13  
1 1  
1 16  
1 19  
1 2  
2 16  
2 1  

```
## Input


```
3 1  
7 3 1  
13 2 3  
19 3 4  

```
## Output


```
NO  

```
## Note

## Examples

 with answer "YES" are depicted below.

Each cell of the stripe represents a single day. Rectangles represent trips, each trip starts in the morning and ends in the evening. Rectangles with angled corners represent visa applications. Each application starts in the middle of a day and ends *t**i* days after. The trip and the visa application for the same country have the same color.

In examples with two passports, visa applications and trips depicted above the time stripe are made using the first passport, visa applications and trips depicted below the time stripe are made using the second passport.

Example 1: 

 ![](images/271eb32425258afcdcf4142cd1fc0797bf10c666.png) Example 2: 

 ![](images/4d9eecfe23e2cdfe6decd127ca2dd68cf3e7e739.png) Example 3: 

 ![](images/77b7940f26740d9319136e78b5ef2a1c807cb340.png) 

#### tags 

#3400 #dp #implementation 