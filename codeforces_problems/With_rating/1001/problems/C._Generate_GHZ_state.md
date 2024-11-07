<h1 style='text-align: center;'> C. Generate GHZ state</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given *N* qubits (1 ≤ *N* ≤ 8) in zero state ![](images/8bb67080da7081bfb802ca6ecc5abc4f4c5ca190.png). Your task is to create Greenberger–Horne–Zeilinger (GHZ) state on them:

![](images/acb08ce15c611d90dc85f731accccd9bbfac8fd3.png)Note that for *N* = 1 and *N* = 2 GHZ state becomes states ![](images/891b1e75c93e44f237b7fde497062f8e85c1d952.png) and ![](images/aec27febc80bfeb882cb96d33386f048ce011703.png) from the previous tasks, respectively.

## Input

You have to implement an operation which takes an array of *N* qubits as an input and has no output. The "output" of your solution is the state in which it left the input qubits.

Your code should have the following signature:


```text
namespace Solution {  
    open Microsoft.Quantum.Primitive;  
    open Microsoft.Quantum.Canon;  
  
    operation Solve (qs : Qubit[]) : ()  
    {  
        body  
        {  
            // your code here  
        }  
    }  
}
```


#### Tags 

#1400 #NOT OK #*special 

## Blogs
- [All Contest Problems](../Microsoft_Q_Coding_Contest_-_Summer_2018_-_Warmup.md)
- [Contest Anouncement (en)](../blogs/Contest_Anouncement_(en).md)
- [https://codeforces.com/blog/entry/60319](../blogs/https:_codeforces.com_blog_entry_60319.md)
