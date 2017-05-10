## 题目分析：
编写一个程序，将所给的URL编码为较短的一个TinyURL，而后再将其解码为原本的URL。  
验证方式为`Decode( Encode(x) ) = x`。
## 解题思路(1)
比较捉急的做法，由验证方式思考，若`Encode(x) = x`, `Decode(x) = x`，则可以满足上述需求。即解码与编码直接返回原串即可。时间复杂度为O(1)，但算是一种欺诈。  
## 解题思路(2)
对于每个URL构造一个对应的TinyURL，建立一一对应的映射关系。  
如构造TinyURL的格式为 `http://tinyurl.com/` + `序号`。  
通过unordered_map建立正反两连接即可。
