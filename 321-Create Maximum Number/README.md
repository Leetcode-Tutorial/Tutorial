## 题目分析：
给你两个长度分别为m和n的元素为0到9的数组，从这两个数组中选出k<=m+n个元素组成最大的数，来自同一个数组的元素的相对位置应该保持不变。

### 解题思路：
可以将这个问题拆分成两个子问题，一个是从一个数组里选择固定个数的数字组成最大的数，另一个是把两个数组中选出的数字合并成最大数。第二个问题很好解决，只需每次把最前面的数字取出比较选择较大的即可，当遇到两个数字相同时，就需要比较后面的数，直到出现不一样的数字或者某个数组没有数了为止。对于第一个问题，我们可以用栈来解决，遇到一个数字的时候将栈顶元素和当前数字比较，如果栈顶元素小则把该元素弹出栈然后继续比较，直到栈空或者栈顶元素不小于当前数字为止，然后看栈中元素个数，如果已经达到需要的个数就丢弃当前数字，否则将其压栈。需要注意的是如果某一时刻剩余的数字个数等于还需要的数字个数，则需要将剩余所有数字都选上。最后回到初始问题，我们可以枚举在第一个数组需要取的个数，然后把每次枚举的结果进行比较即可。极端情况下时间复杂度为O((n+m+k)\*k^2)。

#### 算法正确性：
算法的关键点在于第一个问题中栈的处理，在取固定数量的数字的情况下，要让数尽量大，首先就要让高位的数字尽量大，弹栈的过程就相当于增大高位数字的过程，虽然不断弹栈可能会使得剩余的数字个数等于还需要的数字个数的时刻早到来，但如果不弹栈就相当于高位数小了，哪怕后面有更多的选择也只是优化低位数，不会产生更优的解，因此上述算法是正确的。

下面举一个简单例子走一遍算法帮助理解：数组为[3,9]、[8,9]，k=3。</br>
确定边界：初始时数组1选两个元素，数组2选一个元素，之后还要枚举一次；</br>
处理数组1：</br>
处理数字3，由于剩下元素必须都选，因此3入栈；</br>
处理数字9，由于剩下元素必须都选，因此9入栈；</br>
数组1的选择结果为[3,9]；</br>
处理数组2：</br>
处理数字8，由于栈空，因此8入栈；</br>
处理数字9，栈顶元素为8，8出栈，由于剩下元素必须都选，因此9入栈；</br>
数组2的选择结果为[9]；</br>
两个数组合并，依次选择数组2中的9、数组1中的3、数组1中的9，得结果[9,3,9]；</br>
下一次枚举：数组1选一个元素，数组2选两个元素；</br>
处理数组1：</br>
处理数字3，由于栈空，因此3入栈；</br>
处理数字9，栈顶元素为3，3出栈，由于剩下元素必须都选，因此9入栈；</br>
数组1的选择结果为[9]；</br>
处理数组2：</br>
处理数字8，由于剩下元素必须都选，因此8入栈；</br>
处理数字9，由于剩下元素必须都选，因此9入栈；</br>
数组2的选择结果为[8,9]；</br>
两个数组合并，依次选择数组1中的9、数组2中的8、数组2中的9，得结果[9,8,9]，该结果更优，更新答案；</br>
最终结果为[9,8,9]。