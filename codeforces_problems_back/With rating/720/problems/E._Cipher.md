<h1 style='text-align: center;'> E. Cipher</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Borya has recently found a big electronic display. The computer that manages the display stores some integer number. The number has *n* decimal digits, the display shows the encoded version of the number, where each digit is shown using some lowercase letter of the English alphabet.

There is a legend near the display, that describes how the number is encoded. For each digit position *i* and each digit *j* the character *c* is known, that encodes this digit at this position. Different digits can have the same code characters.

Each second the number is increased by 1. And one second after a moment when the number reaches the value that is represented as *n* 9-s in decimal notation, the loud beep sounds. 

Andrew knows the number that is stored in the computer. Now he wants to know how many seconds must pass until Borya can definitely tell what was the original number encoded by the display. Assume that Borya can precisely measure time, and that the encoded number will first be increased exactly one second after Borya started watching at the display.

## Input

## Input

 data contains multiple test cases. The first line of input contains *t* (1 ≤ *t* ≤ 100) — the number of test cases. 

Each test case is described as follows. The first line of the description contains *n* (1 ≤ *n* ≤ 18) — the number of digits in the number. The second line contains *n* decimal digits without spaces (but possibly with leading zeroes) — the number initially stored in the display computer. The following *n* lines contain 10 characters each. The *j*-th character of the *i*-th of these lines is the code character for a digit *j* - 1 in position *i*, most significant digit positions are described first.

## Output

For each test case print an integer: the number of seconds until Borya definitely knows what was the initial number stored on the display of the computer. Do not print leading zeroes.

## Example

## Input


```
3  
2  
42  
abcdefghij  
jihgfedcba  
2  
42  
aaaaaaaaaa  
aaaaaaaaaa  
1  
2  
abcdabcdff  

```
## Output


```
0  
58  
2  

```


#### tags 

#3100 #implementation 