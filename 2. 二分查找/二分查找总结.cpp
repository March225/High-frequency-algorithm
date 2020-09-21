最近一直在LeetCode上刷二分查找相关的题，发现有几点细节问题需要注意，特地总结如下：

（1）之所以将 mid = (left + right) / 2 写成 mid = left + (right - left) / 2，是怕 left + right 会整型溢出。

（2）如果 mid 的写法是 mid = left + (right - left) / 2，看到 left = mid，需要考虑 [left(mid)，right] 会无限循环的问题，
     这里通常做法是改变 mid 的写法，将 mid = left + (right - left) / 2 改成 mid = left + (right - left + 1) / 2，就会解决这个问题。

（3）除以2没必要写成 >> 1，写成 /2 就行，因为编译器会自动把 /2 优化成 >> 1，写成左移的形式反而会降低代码的可读性。

（4）如果在二分搜索问题中遇到要返回数组下标，并且这个下标可能会越界（比如插入数据到数组尾部，返回的下标就是越界的），
     这时候可以考虑将左边界 r 改成数组的长度 len ，而不是 len - 1。

（5）二分搜索代码的写法不唯一，选择一种自己喜欢的就好，下面附上我自己常用的写法：

    // 二分搜索
    int BinarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int m = (r + l) / 2;
            if (nums[m] == target) 
                return m;
            else if(nums[m] < target) 
                l = m + 1;
            else 
                r = m - 1;
        }
        return -1;
    }

二分查找有很多变形，比如查找第一个（最后一个）大于（小于或等于）指定元素的位置，都是根据上面的代码改动而来，因此最基本的要牢记，需要变形的时候简单修改一下就可以了。