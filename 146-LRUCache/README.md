## 题目分析：

设计一个`Least Recently Used (LRU) cache`(最近最少使用缓存)的数据结构, 支持  
1.`new LRUCache(capacity)`, 初始化内存大小;  
2.`get(key)`, 访问关键字为`key`的`value`值;  
3.`put(key, value)`, 设置关键字为`key`的`value`值 

### 解题思路（1）
维护一个以访问时间为键值, 大小为`capacity`的平衡树。那么每次替换的时候，将键值最小的替换出去即可。单次操作时间复杂度为`O(log(capacity))`.
### 解题思路（2）
想象一下双端队列。每次从队首`pop`, 从队尾`push`, 询问成功, 则将询问的元素从中间抽出调至队尾。这样, 在最坏的情况下, 我们每次需要移动大量元素。那么我们可以将双端队列改成链表的数据结构, 每次可以`O(1)`增删调整。要做到这一点, 我们需要一个额外的`hashtable`来快速访问元素在链表中的位置。单次操作时间复杂度为`O(1)`.
#### 算法的正确性：
举例如下：
```
LRUCache cache = new LRUCache( 2 /* capacity */ );
cache.put(1, 1);	 //list: 1
cache.put(2, 2);	 //list: 2, 1
cache.get(1);       //list: 1, 2; returns 1
cache.put(3, 3);    //list: 3, 1; evicts key 2
cache.get(2);       //list: 3, 1; returns -1 (not found)
cache.put(4, 4);    //list: 4, 3; evicts key 1
cache.get(1);       //list: 4, 3; returns -1 (not found)
cache.get(3);       //list: 3, 4; returns 3
cache.get(4);       //list: 4, 3; returns 4
```
