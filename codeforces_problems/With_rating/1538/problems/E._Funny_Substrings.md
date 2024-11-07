<h1 style='text-align: center;'> E. Funny Substrings</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp came up with a new programming language. There are only two types of statements in it: 

* "x := s": assign the variable named x the value s (where s is a string). For example, the statement var := hello assigns the variable named var the value hello. 
## Note

 that s is the value of a string, not the name of a variable. Between the variable name, the := operator and the string contains exactly one space each.
* "x = a + b": assign the variable named x the concatenation of values of two variables a and b. For example, if the program consists of three statements a := hello, b := world, c = a + b, then the variable c will contain the string helloworld. It is guaranteed that the program is correct and the variables a and b were previously defined. There is exactly one space between the variable names and the = and + operators.

All variable names and strings only consist of lowercase letters of the English alphabet and do not exceed $5$ characters.

The result of the program is the number of occurrences of string haha in the string that was written to the variable in the last statement.

Polycarp was very tired while inventing that language. He asks you to implement it. Your task is — for given program statements calculate the number of occurrences of string haha in the last assigned variable.

### Input

The first line contains an integer $t$ ($1 \le t \le 10^3$). Then $t$ test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 50$) — the number of statements in the program. All variable names and strings are guaranteed to consist only of lowercase letters of the English alphabet and do not exceed $5$ characters.

This is followed by $n$ lines describing the statements in the format described above. It is guaranteed that the program is correct.

### Output

For each set of input data, output the number of occurrences of the haha substring in the string that was written to the variable in the last statement.

## Example

### Input


```text
4
6
a := h
b := aha
c = a + b
c = c + c
e = c + c
d = a + c
15
x := haha
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
x = x + x
1
haha := hah
5
haahh := aaaha
ahhhh = haahh + haahh
haahh = haahh + haahh
ahhhh = ahhhh + haahh
ahhaa = haahh + ahhhh
```
### Output


```text
3
32767
0
0
```
## Note

In the first test case the resulting value of d is hhahahaha.



#### Tags 

#2100 #NOT OK #data_structures #hashing #implementation #matrices #strings 

## Blogs
- [All Contest Problems](../Codeforces_Round_725_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
