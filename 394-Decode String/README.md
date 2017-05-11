## 题目分析：
题目给出一个编码过的字符串，要求对其进行解码。  
编码规则为:`k[encoding_string]`，其中*k*为*encoding_string*的重复次数，保证为正数。  
如 `3[a2[bc]]`解码后变为 `abcbcabcbcabcbc`。
### 解题思路
简单的模拟类型题。  
使用一个指针从头开始扫描  
+ 若遇到的字符为字母则加入当前的临时字符串`tmp_string`当中。
+ 若遇到的字符为数字则说明当前遇到了压缩字符串的重复次数*k*，将其解析出来。
+ 若遇到的字符为`‘[’`则表示着*encoding_string*的开端，将当前的`tmp_string`使用栈存起来，重复次数k压入另一次存储次数的栈中，而后将`tmp_string`清为空字符串。
+ 若遇到的字符为`']'`则意味着*encoding_string*的结束，当前`tmp_string`便为*encoding_string*，取出栈顶的*k*，将`tmp_string`重复*k*次。再取出存储原字符串的栈顶元素，与当前`tmp_string`拼接。  

最后的`tmp_string`便为我们所期望的答案，输出即可。
