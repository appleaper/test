vector用法

原文链接：https://blog.csdn.net/msdnwolaile/article/details/52708144

1. 基本操作

   1. 头文件#include

   2. 创建vector对象，vector vec;

   3. 尾部插入数字：vec.push_back(a);

   4. 使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。

   5. 使用迭代器访问元素.

      ```
      for(it=vec.begin();it!=vec.end();it++)
          cout<<*it<<endl;</span>
      ```

   6. 插入元素： vec.insert(vec.begin()+i,a);在第i个元素后面插入a;

   7. 删除元素： vec.erase(vec.begin()+2);删除第3个元素 　　　　　　　 vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始

   8. 向量大小:vec.size();

   9. 清空:vec.clear()　　　//清空之后，vec.size()为０

   简单的程序：[vector简单使用](vector.cpp)

   

2. vector的元素不仅仅可以使int,double,string,还可以是结构体，但是要注意：结构体要定义为全局的，否则会出错。

3. 于vector的内存占用空间只增不减，比如你首先分配了10,000个字节，然后erase掉后面9,999个，留下一个有效元素，但是内存占

   用仍为10,000个。所有内存空间是在vector析构时候才能被系统回收。empty()用来检测容器是否为空的，clear()可以清空所有元素。

   但是即使clear()，vector所占用的内存空间依然如故，无法保证内存的回收。

   如果需要空间动态缩小，可以考虑使用deque。如果非vector不可，可以用swap()来帮助你释放内存。

   [用法](vector1626.cpp)



1. 析构函数

   ~vector()

   销毁容器对象并回收了所有分配的内存

2. 重载了=符号

   ```c++
   vector<int> E;
   E = B; //使用=符号
   B = vector<int>(); //将B置为空容器
   ```

3. vector::begin() 返回第一个元素的迭代器

4. vector::end() 返回的是越界后的第一个位置，也就是最后一个元素的下一个位置

5. vector::rbegin() 反序的第一个元素，也就是正序最后一个元素

6. vector::rend() 反序的最后一个元素下一个位置，也相当于正序的第一个元素前一个位置

7. vector::size() 返回容器中元素个数

8. vector::max_size()返回容器的最大可以存储的元素个数，这是个极限，当容器扩展到这个最大值时就不能再自动增大

9. vector::resize()

   void resize ( size_type sz, T c = T() );

   重新分配容器的元素个数，这个还可以改容器的容量，如果重新分配的元素个数比原来的小，将截断序列，后面的部分丢弃，如果大于原来的个数，后面的值是c的值，默认为0

10. vector::capacity() 返回vector的实际存储空间的大小

11.  vector::empty()  当元素个数为0时返回true，否则为false，根据的是元素个数而不是容器的存储空间的大小

12. vector::reserve() 

    重新分配空间的大小，不过这个n值要比原来的capacity()返回的值大，不然存储空间保持不变，n值要比原来的实际存储空间大才能重新分配空间，但是最大值不可以大于max_size的值，否则会抛出异常

13. vector::front() 返回第一个元素的值，与begin()函数有区别，begin()函数返回的是第一个元素的迭代器

14. vector::back()  返回最后一个元素的值，注意与end()函数的区别

15. vector::assign()  将丢弃原来的元素然后重新分配元素，第一个函数是使用迭代器，第二个函数是使用n个元素，每个元素的值为u。

16. vector::push_back()  在容器的最后一个位置插入元素x,如果size值大于capacity值，则将重新分配空间

17. vector::pop_back()   删除最后一个元素

18. vector::insert() 插入新的元素

    iterator insert ( iterator position, const T& x );

    void insert ( iterator position, size_type n, const T& x );

    template <class InputIterator>

    void insert ( iterator position, InputIterator first, InputIterator last );

       插入新的元素，

    第一个函数，在迭代器指定的位置前插入值为x的元素

    第二个函数，在迭代器指定的位置前插入n个值为x的元素

    第三个函数，在迭代器指定的位置前插入另外一个容器的一段序列迭代器first到last

    若插入新的元素后总得元素个数大于capacity，则重新分配空间

19. vector::erase()

    iterator erase ( iterator position );

    iterator erase ( iterator first, iterator last );

    删除元素或一段序列

20. vector::swap()

    void swap ( vector<T,Allocator>& vec );

    交换这两个容器的内容，这涉及到存储空间的重新分配

21. vector::clear()  将容器里的内容清空，size值为0，但是存储空间没有改变

[用例](vector1702.cpp)
