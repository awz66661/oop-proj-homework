作业运行方式：.\main.exe
使用
g++ .\main.cpp .\utils.cpp -o main.exe
编译运行

各文件的内容：
1)utils.h:
    包含链表中的结点Node的struct定义，创建Node结构
    Node为双向链表的结点，用模板Object定义，包含数据Object,前结点的指针previous和后一个结点的指针next
2)utils.cpp:
    无内容
3)myListIter.h:
    使用类模板定义了List的迭代器Iterator
    使用继承的方式，将const_iterator作为iterator的父类
    将 List 类作为friend class声明，使其成为List类的迭代器
    (在声明是发现要先声明List作为模板类，否则因为myListIter未包含myList头文件而报错)
4)myList.h:
    指针head,tail
    List类的定义，成员函数的定义：
    push_back
    push_front
    pop_back
    pop_front
    empty
    clear
    front
    pop_back
    size
    insert
    sort: sort使用冒泡排序实现
    begin
    end
    erase
5)myList.cpp:
    因为List为模板类所以函数实现在myList.h中进行，此为空文件
6)main.cpp
    包含了主函数和测试函数：
    test_begin_and_end
    test_push_back
    test_pop_back
    test_size
    test_insert
    test_sort
    对类中API进行检测
    检测采用与标准STL::list进行操作并比较得出结论
    若检测全部通过会输出
    "All tests passed:"
    "1.begin_and_end 2.push/pop_back 3.size 4.insert 5.sort"

    ps:因为自己比较菜，在实现的过程中借鉴了网上的一些内容，在理解吸收以后完成此Lab
    一下为借鉴的一部分网址:
    https://blog.csdn.net/juicewyh/article/details/82845320
    http://c.biancheng.net/view/6955.html
    http://c.biancheng.net/view/6892.html