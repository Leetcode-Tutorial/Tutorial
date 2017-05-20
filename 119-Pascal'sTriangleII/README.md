## 题目分析：

求Pascal三角形的第k行。

### 解题思路
Pascal第k行第i个数为C(k, i), 0 <= i <= k
C(k, i) = C(k, i-1)*(k-i+1)/i, 0 < i <= k
顺序求得即可.