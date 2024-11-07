<h1 style='text-align: center;'> B. Rebranding</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The name of one small but proud corporation consists of *n* lowercase English letters. The Corporation has decided to try rebranding — an active marketing strategy, that includes a set of measures to change either the brand (both for the company and the goods it produces) or its components: the name, the logo, the slogan. They decided to start with the name.

For this purpose the corporation has consecutively hired *m* designers. Once a company hires the *i*-th designer, he immediately contributes to the creation of a new corporation name as follows: he takes the newest version of the name and replaces all the letters *x**i* by *y**i*, and all the letters *y**i* by *x**i*. This results in the new version. It is possible that some of these letters do no occur in the string. It may also happen that *x**i* coincides with *y**i*. The version of the name received after the work of the last designer becomes the new name of the corporation.

Manager Arkady has recently got a job in this company, but is already soaked in the spirit of teamwork and is very worried about the success of the rebranding. Naturally, he can't wait to find out what is the new name the Corporation will receive.

Satisfy Arkady's curiosity and tell him the final version of the name.

## Input

The first line of the input contains two integers *n* and *m* (1 ≤ *n*, *m* ≤ 200 000) — the length of the initial name and the number of designers hired, respectively.

The second line consists of *n* lowercase English letters and represents the original name of the corporation.

Next *m* lines contain the descriptions of the designers' actions: the *i*-th of them contains two space-separated lowercase English letters *x**i* and *y**i*.

## Output

Print the new name of the corporation.

## Examples

## Input


```
6 1  
police  
p m  

```
## Output


```
molice  

```
## Input


```
11 6  
abacabadaba  
a b  
b c  
a d  
e g  
f a  
b b  

```
## Output


```
cdcbcdcfcdc  

```
## Note

In the second sample the name of the corporation consecutively changes as follows:

 ![](images/e0abf65a2fac53c073dd72d8619461dca323f904.png)![](images/c7648432f7138ca53234357d7e08d1d119166055.png)

![](images/de89ad7bc7f27c46ec34f5e66ce0dc23bd5bc90a.png)

![](images/812e653c8d7ff496e6a0f04c676423806751531e.png)

![](images/19c564fcefb8dde36256240a8b877bb6a4792bfe.png)

![](images/e1cafd93792430ad1a49e893e04715383bdae757.png)



#### tags 

#1200 #implementation #strings 