<h1 style='text-align: center;'> E. Distinguish Bell states</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two qubits which are guaranteed to be in one of the Bell states:

* ![](images/3bd300187bec68a260f07bb41226aad198f9aef0.png)
* ![](images/2b05513e9a357b2122b3d30583a71885a247a3b8.png)
* ![](images/8c3b892f53b8bf7ed84f55a5087ada2ab50dd4d1.png)
* ![](images/d094280f4b9897c9aec5e2ba5e920d00e37656fc.png)

Your task is to perform necessary operations and measurements to figure out which state it was and to return the index of that state (0 for ![](images/aec27febc80bfeb882cb96d33386f048ce011703.png), 1 for ![](images/4c7fe2c174363ceb367b7686e92c7fb9a36da8bf.png) etc.). The state of the qubits after the operations does not matter.

## Input

You have to implement an operation which takes an array of two qubits as an input and returns an integer. 

Your code should have the following signature:


```text
namespace Solution {  
    open Microsoft.Quantum.Primitive;  
    open Microsoft.Quantum.Canon;  
  
    operation Solve (qs : Qubit[]) : Int  
    {  
        body  
        {  
            // your code here  
        }  
    }  
}
```


#### Tags 

#1600 #NOT OK #*special 

## Blogs
- [All Contest Problems](../Microsoft_Q_Coding_Contest_-_Summer_2018_-_Warmup.md)
- [Contest Anouncement (en)](../blogs/Contest_Anouncement_(en).md)
- [https://codeforces.com/blog/entry/60319](../blogs/https:_codeforces.com_blog_entry_60319.md)
