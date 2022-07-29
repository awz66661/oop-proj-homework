#pragma once
#include <iostream>
#include "utils.h"


///////////////////////////////////////////////////////////////////////////////
template <typename Object> class List;

template <typename Object> class const_iterator {
protected:
    Node<Object>* current;
    Object& retrieve()const { return current->data; }
public:
    const_iterator() :current(NULL) {}
    const Object&operator*()const;
    const_iterator &operator++(int);
    const_iterator&operator++();
    bool operator==(const const_iterator&);
    bool operator!=(const const_iterator&);
    friend class List<Object>;
};
template <typename Object> const Object& const_iterator<Object>::operator*() const {
    return current->object;
}
template <typename Object> const_iterator<Object>& const_iterator<Object>::operator++(int) {
    const_iterator old = *this;
    ++(*this);
    return old;
}
template <typename Object> const_iterator<Object>& const_iterator<Object>::operator++() {
    current = current->next;
    return *this;
}
template <typename Object>bool const_iterator<Object>::operator==(const const_iterator &rhs) {
    return current == rhs.current ? true : false;
}
template <typename Object>bool const_iterator<Object>::operator!=(const const_iterator &rhs) {
    return !(this->current == rhs.current);
}

template <typename Object> class iterator :public const_iterator<Object> {
public:
    iterator() {}
    Object&operator*() { return const_iterator<Object>::current->object; }
    const Object&operator*()const { return const_iterator<Object>::operator*(); }
    iterator&operator++() {
        const_iterator<Object>::current = const_iterator<Object>::current->next;
        return *this;
    }
    iterator&operator--() {
        const_iterator<Object>::current = const_iterator<Object>::current->previous;
        return *this;
    }
    iterator&operator++(int) {
        iterator old = *this;
        ++(*this);
        return old;
    }
    iterator&operator--(int) {
        iterator old = *this;
        --(*this);
        return old;
    }
    friend class List<Object>;
};

///////////////////////////////////////////////
// template <typename Object> class List {
// private:
//     Node<Object> *head;
//     Node<Object> *tail;
//     int theSize;
// public:
//     typedef iterator<Object> iterator;
//     typedef const_iterator<Object> const_iterator;
//     List();
//     ~List();
//     List(const List<Object>&);
//     List(unsigned initSize);
//     void push_back(const Object&);
//     void push_front(const Object&);
//     void pop_front();
//     void pop_back();
//     bool empty();
//     void clear();
//     void resize(unsigned);
//     const Object& front();
//     const Object& back();
//     int size()const;
//     void insert(iterator, const Object&);
//     void remove(const Object&);
//     const List<Object>&operator=(const List<Object>&);
//     iterator begin() {
//         iterator it;
//         it.current = head->next;
//         return it;
//     }
//     iterator end() {
//         iterator it;
//         it.current = tail;
//         return it;
//     }
//     const_iterator begin()const{
//         const_iterator it;
//         it.current=head->next;
//         return it;
//     }
//     const_iterator end()const{
//         const_iterator it;
//         it.current=tail;
//         return it;
//     }
//     iterator erase(iterator it){
//         if(it!=end()&&!empty()){
//         Node<Object>*tmp=it.current;
//         Node<Object>*p=tmp;
//         tmp->previous->next=tmp->next;
//         tmp=tmp->next;
//         delete p;
//         iterator to;
//         to.current=tmp;
//         --theSize;
//         return to;
//         }
//     }
// };