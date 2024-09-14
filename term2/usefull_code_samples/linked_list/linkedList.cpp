#include "LinkedList.hpp"
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList()
{
    mpHead = nullptr;
    mpTail = nullptr;
}


template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return (mpHead == nullptr && mpTail == nullptr);
}

template <typename T>
void LinkedList<T>::clear()
{
    Node* ptr = mpHead;

    while (ptr != nullptr)
    {
        Node* ptemp = ptr->next;
        delete ptr;
        ptr = ptemp;
    }
}

template <typename T>
std::size_t LinkedList<T>::size() const
{
    Node* ptr = mpHead;
    std::size_t result = 0;
    while (ptr != nullptr)
    {
        ptr = ptr->next;
        result += 1;
    }
    return result;
}


template <typename T>
LinkedList<T>::LinkedList(const LinkedList& source)
{
    if (source.isEmpty())
    {
        mpHead = nullptr;
        mpTail = nullptr;
        return;
    }

    mpHead = new Node{source.mpHead->value, nullptr};

    Node* ptr = mpHead;
    Node* ptrSource = source.mpHead->next;

    while (ptrSource != nullptr)
    {
        Node* nn = new Node;
        nn->value = ptrSource->value;

        ptr->next = nn;

        ptr = ptr->next;
        ptrSource = ptrSource->next;
    }

    mpTail = ptr;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList&& source)
{
    mpHead = source.mpHead;
    mpTail = source.mpTail;

    source.mpHead = nullptr;
    source.mpTail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}


template <typename T>
void LinkedList<T>::pushFront(const T& value)
{
    Node* nn = new Node{value, mpHead};

    if (isEmpty())
        mpTail = nn;

    mpHead = nn;
}


template <typename T>
void LinkedList<T>::pushBack(const T& value)
{
    Node* nn = new Node{value, nullptr};

    if (isEmpty())
        mpHead = nn;
    else
        mpTail->next = nn;

    mpTail = nn;
}


template <typename T>
T LinkedList<T>::popFront()
{
    if (isEmpty())
    {
        throw std::runtime_error("Linked list: pop while list is empty.");
    }
    
    T result = mpHead->value;

    Node* ptemp = mpHead;
    mpHead = mpHead->next;
    if (mpHead == nullptr)
        mpTail = nullptr;

    delete ptemp;
    return result;
}



template <typename T>
T LinkedList<T>::get(std::size_t id)
{
    Node* ptr = mpHead;
    std::size_t i = 0;
    while (ptr != nullptr)
    {
        if (i == id)
            return ptr->value;

        i += 1;
        ptr = ptr->next;
    }

    throw std::runtime_error("Linked list: out of range.");
}



template class LinkedList<int>;