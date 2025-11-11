#include "deque.H"

template<typename T>
class Edll : public Deque<T>
{
    public:

    Edll() = default;
    Edll(size_t sizeParm,T valParam): Deque<T>(sizeParm,valParam){}

    Edll(const Edll &object) = delete;
    Edll(const Edll &&object)= delete;
    Edll& operator= (const Edll& object) = delete;
    Edll& operator= (const Edll&& object)= delete;

    ~Edll() = default;

    bool insertAtIndex(T valParm, int indexParm);
    bool removeFromIndex(int indexParm);

};

template<typename T>
bool Edll<T>::insertAtIndex(T valParm, int indexParm)
{
    Node<T> *sTemp = Deque<T>::getHead();
    int sCounter = 1;
    while (sCounter <= indexParm)
    {
        if(sCounter == indexParm)
        {
            Node<T> *newNode = new Node<T>(valParm);
            newNode->mNextPtr = sTemp;
            newNode->mPrevPtr = sTemp->mPrevPtr;
            sTemp->mPrevPtr->mNextPtr = newNode;
            sTemp->mPrevPtr = newNode;

            Deque<T>::incSize();
            return true;

        }
        sTemp = sTemp->mNextPtr;
        sCounter++;
    }
    return false;
}

template<typename T>
bool Edll<T>::removeFromIndex(int indexParm)
{
    Node<T> *sTemp = Deque<T>::getHead();
    int sCounter = 1;
    if (indexParm == 1)
    {  
        Deque<T>::popFront();
        return true;
    }

    while (sTemp != nullptr && sCounter < indexParm)
    {
        sCounter++;
        sTemp = sTemp->mNextPtr;
    }

    if(sTemp == nullptr)
    {
        return false;
    }

    sTemp->mPrevPtr->mNextPtr = sTemp->mNextPtr;

    if (sTemp->mNextPtr != nullptr)
    {
        sTemp->mNextPtr->mPrevPtr = sTemp->mPrevPtr;
    }
    this->decSize();
    delete sTemp;
    sTemp = nullptr;
    return true;
}
