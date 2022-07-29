#include <iostream>


template <typename Object> struct Node {
    Object object;
    Node<Object> *previous;//指向前一节点
    Node<Object> *next;//指向后一节点
    Node(const Object&obj) :object(obj), next(NULL),previous(NULL) {}
    Node():next(NULL),previous(NULL){}
};