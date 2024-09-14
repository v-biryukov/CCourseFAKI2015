#pragma once
#include <cstddef>

template <typename T>
class LinkedList
{
private:

    struct Node
    {
        T value     {};
        Node* next  {nullptr};
    };

    Node* mpHead {nullptr};
    Node* mpTail {nullptr};

public:


    struct iterator
    {
        Node* ptr;

        bool operator==(const iterator& other)
        {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator& other)
        {
            return ptr != other.ptr;
        }

        T operator*()
        {
            return ptr->value;
        }

        iterator& operator++()
        {
            if (ptr != nullptr)
                ptr = ptr->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator copy = *this;
            if (ptr != nullptr)
                ptr = ptr->next;
            return copy;
        }
    };

    iterator begin() const {return iterator{mpHead};}
    iterator end() const {return iterator{nullptr};}


    LinkedList();

    void clear();
    std::size_t size() const;
    bool isEmpty() const;

    LinkedList(const LinkedList& ll);
    LinkedList& operator=(const LinkedList& ll) = delete;

    LinkedList(LinkedList&& ll);
    LinkedList& operator=(LinkedList&& ll) = delete;

    ~LinkedList();

    void pushFront(const T& value);
    void pushBack(const T& value);
    T popFront();

    T get(std::size_t id);

};