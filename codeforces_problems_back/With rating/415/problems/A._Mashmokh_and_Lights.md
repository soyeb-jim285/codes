<h1 style='text-align: center;'> A. Mashmokh and Lights</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mashmokh works in a factory. At the end of each day he must turn off all of the lights. 

The lights on the factory are indexed from 1 to *n*. There are *n* buttons in Mashmokh's room indexed from 1 to *n* as well. If Mashmokh pushes button with index *i*, then each light with index not less than *i* that is still turned on turns off.

Mashmokh is not very clever. So instead of pushing the first button he pushes some of the buttons randomly each night. He pushed *m* distinct buttons *b*1, *b*2, ..., *b**m* (the buttons were pushed consecutively in the given order) this night. Now he wants to know for each light the index of the button that turned this light off. Please note that the index of button *b**i* is actually *b**i*, not *i*.

Please, help Mashmokh, print these indices.

## Input

The first line of the input contains two space-separated integers *n* and *m* (1 ≤ *n*, *m* ≤ 100), the number of the factory lights and the pushed buttons respectively. The next line contains *m* distinct space-separated integers *b*1, *b*2, ..., *b**m* (1 ≤ *b**i* ≤ *n*).

It is guaranteed that all lights will be turned off after pushing all buttons.

## Output

## Output

 *n* space-separated integers where the *i*-th number is index of the button that turns the *i*-th light off.

## Examples

## Input


```
5 4  
4 3 1 2  

```
## Output


```
1 1 3 4 4   

```
## Input


```
5 5  
5 4 3 2 1  

```
## Output


```
1 2 3 4 5   

```
## Note

In the first sample, after pressing button number 4, lights 4 and 5 are turned off and lights 1, 2 and 3 are still on. Then after pressing button number 3, light number 3 is turned off as well. Pressing button number 1 turns off lights number 1 and 2 as well so pressing button number 2 in the end has no effect. Thus button number 4 turned lights 4 and 5 off, button number 3 turned light 3 off and button number 1 turned light 1 and 2 off.



#### tags 

#900 #implementation 