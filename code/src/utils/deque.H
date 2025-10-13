#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include "common.H"

template <typename T>
class Node
{
    public:
    T mData;
    Node *mNextPtr;
    Node *mPrevPtr;
    Node(T data):mData(data),mNextPtr(nullptr),mPrevPtr(nullptr){};
};

template <typename T>
class Deque
{
public:
    Deque():mHead(nullptr),mTail(nullptr),mSize(static_cast<size_t>(Generic::Common::DEFAULT_ZERO_VALUE)){};
    Deque(size_t size,T value);
    
    Deque(const Deque &object) = delete;
    Deque(const Deque &&object)= delete;
    Deque& operator= (const Deque& object) = delete;
    Deque& operator= (const Deque&& object)= delete;

    ~Deque() = default;

    bool pushBack(T dataParm);
    bool pushFront(T dataParm);
    bool popBack();
    bool popFront();
    T front();
    T back();
    bool empty();
    size_t size();
    void clear();
    bool resize(size_t sParm,T dParm,int directionParm = static_cast<int>(Generic::Direction::FRONTDIRECTION));
    Node<T>* getHead(){return mHead;}
    inline void incSize(){mSize++;}
    inline void decSize(){mSize--;}
    T operator[] (size_t indexParm);
    void print();

private:
    Node<T> *mHead;
    Node<T> *mTail;
    size_t mSize;

};

template <typename T>
void Deque<T>::print()
{
    Node<T> *sTemp;
    sTemp = Deque<T>::getHead();

    std::cout << "Deque: ";
    while (sTemp != nullptr)
    {
        std::cout << sTemp->mData << std::endl;
        sTemp = sTemp->mNextPtr;
    }
}

/// @brief parameterize constructor
/// @tparam T 
/// @param size size of deque
/// @param value default value
template <typename T>
Deque<T>::Deque(size_t size,T value):mHead(nullptr),mTail{nullptr}
{
    while(size--)
    {
        pushBack(value);
    }

}

/// @brief To get value at a perticular index
/// @tparam T 
/// @param indexParm 
/// @return return the indxed value
template <typename T>
T Deque<T>::operator[](size_t indexParm)
{
    T sRet = T();
    Node<T> *sTemp = getHead();
    size_t sCounter = 1;
    while (sCounter <= indexParm)
    {
        if(sCounter == indexParm)
        {
            sRet = sTemp->mData;
            break;
        }
        sTemp = sTemp->mNextPtr;
        sCounter++;
    }
    
    return sRet;

}

/// @brief Add Element At End
/// @tparam T 
/// @param dataParm 
/// @return true is success otherwise false
template <typename T>
bool Deque<T>::pushBack(T dataParm)
{
    try
    {
        Node<T> *sNewNode = new Node<T>(dataParm);

        if (nullptr == mHead)
        {
            mHead = sNewNode;
            mTail = sNewNode;
        }
        else
        {
            sNewNode->mPrevPtr = mTail;
            mTail->mNextPtr = sNewNode;
            mTail = sNewNode;
        }
        incSize();
        return true;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

/// @brief Add data to the front of queue
/// @tparam T 
/// @param dataParm 
/// @return 
template <typename T>
bool Deque<T>::pushFront(T dataParm)
{
    try
    {
        Node<T> *sNewNode = new Node<T>(dataParm);
        if (nullptr == mHead)
        {
            mHead = sNewNode;
            mTail = sNewNode;
        }
        else
        {
            sNewNode->mNextPtr = mHead;
            mHead->mPrevPtr = sNewNode;
            mHead = sNewNode;
        }
        incSize();
        return true;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

/// @brief Delete from the end of queue
/// @tparam T 
/// @return true is success otherwise false
template <typename T>
bool Deque<T>::popBack()
{
    bool sStatus = false;
    if(mTail != nullptr)
    {
        Node<T> *sTemp = mTail->mPrevPtr;
        delete(mTail);
        mTail = sTemp;
        mTail->mNextPtr = nullptr;
        sStatus = true;
        decSize();
    }
    return sStatus;
}

/// @brief Delete from the front of queue
/// @tparam T 
/// @return true is success otherwise false
template <typename T>
bool Deque<T>::popFront()
{
    bool sStatus = false;
    if(mHead != nullptr)
    {
        Node<T> *sTemp = mHead->mNextPtr;
        delete(mHead);
        mHead = sTemp;
        mHead->mPrevPtr = nullptr;
        sStatus =  true;
        decSize();
    }
    return sStatus;
}

/// @brief Get first element
/// @tparam T 
/// @return return the element
template <typename T>
T Deque <T> ::front()
{
    T sRet = T();
    if(mHead != nullptr)
    {
        sRet = mHead->mData;
    }
    return sRet;
}

/// @brief Get the last element
/// @tparam T 
/// @return return the element
template <typename T>
T Deque <T> ::back()
{
    T sRet = T();
    if(mTail != nullptr)
    {
        sRet = mTail->mData;
    }
    return sRet;
}

/// @brief check if queue empty
/// @tparam T 
/// @return true is success otherwise false
template <typename T>
bool Deque <T> ::empty()
{
    return (nullptr == mHead && nullptr == mTail);
}

/// @brief get the size of the queue
/// @tparam T 
/// @return return the size
template <typename T>
size_t Deque <T> ::size()
{
    return mSize;
}

/// @brief delete all elements of the queue
/// @tparam T 
template <typename T>
void Deque <T> ::clear()
{
    while(mHead!=mTail)
    {
        mHead = mHead->mNextPtr;
        delete(mHead->mPrevPtr);
        mHead->mPrevPtr = nullptr;
    }
    delete(mTail);
    mSize = static_cast<size_t>(Generic::Common::DEFAULT_ZERO_VALUE);
    mTail = nullptr;
    mHead = nullptr;

}

/// @brief to resize the dequeue 
/// @tparam T 
/// @param s new size of deque
/// @param d default value
/// @param direction direction either d=1, or d =-1
/// @return 
template <typename T>
bool Deque<T>::resize(size_t sParm,T dParm,int directionParm)
{
    size_t sCurrentSize = size();
    Generic::Direction sDir = static_cast<Generic::Direction>(directionParm);
    if(Generic::Direction::BACKDIRECTION == sDir || Generic::Direction::FRONTDIRECTION == sDir)
    {
        if (sParm > sCurrentSize) // newsize > current size
        {
            while (sParm--)
            {
                Generic::Direction::FRONTDIRECTION == sDir ? pushBack(dParm):pushFront(dParm);
            }
        }
        else
        {
            while (sParm--)
            {
                Generic::Direction::FRONTDIRECTION == sDir ? popFront():popBack();        
            }
        }
        return true;

    }
    return false;    
}

#endif