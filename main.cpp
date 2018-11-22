#include <iostream>

struct Node
{
    int mData;
    Node *mNext;

    Node()
    {
        mData = 0;
        mNext = nullptr;
    }
};

class LinkedList
{
private:
    Node *mHead;
    Node *mTail;

public:
//    creates empty linked list
    LinkedList()
    {
        mHead = nullptr;
        mTail = nullptr;
    }

    ~LinkedList()
    {
        clear();
    }

//    insearts an element in the end of the linked list
    void append(int data)
    {
        Node *temp = new Node;
        temp->mData = data;
        if (!mHead)
        {
            mHead = temp;
            mTail = temp;
        }
        else
        {
            mTail->mNext = temp;
            mTail = temp;
        }
    }

//    prints the linked list
    void display() const
    {
        Node *current = mHead;
        while (current)
        {
            std::cout << current->mData << "\t";
            current = current->mNext;
        }
        std::cout << std::endl;
    }

//    inserts an element at the beginning of the linked list
    void prepend(int data)
    {
        Node *temp = new Node;
        temp->mData = data;

        temp->mNext = mHead;
        mHead = temp;
    }

//    returns size of the linked list
    int size() const
    {
        Node *current = mHead;
        int retSize = 0;
        while (current)
        {
            current = current->mNext;
            ++retSize;
        }
        return retSize;
    }

//    removes an element from the end of the linked list
    void popBack()
    {
        Node *popedItem = mHead;
        Node *itemBeforePoped = nullptr;

        while (popedItem)
        {
            itemBeforePoped = popedItem;
            popedItem = popedItem->mNext;
            if (!popedItem->mNext)
            {
                popedItem->mData = 0;
                delete popedItem;
                popedItem = nullptr;
                itemBeforePoped->mNext = popedItem;
            }
        }
    }

//    removes an element from the beginning of the linked list
    void popFront()
    {
        Node *popedItem = mHead;
        Node *itemAferPoped = mHead->mNext;

        popedItem->mData = 0;
        delete popedItem;
        popedItem = nullptr;
        mHead = itemAferPoped;
    }

//    insearts an element in the specified position in the linked list
    void inseart(int pos, int data)
    {
        if (!size())
        {
            prepend(data);
        }
        else if (pos > size())
        {
            append(data);
        }
        else
        {
            int counter = 0;
            Node *currentPos = mHead;
            Node *prevPos = nullptr;
            Node *temp = new Node;
            temp->mData = data;
            while (currentPos)
            {
                if (pos == counter)
                {
                    temp->mNext = currentPos;
                    if (prevPos)
                    {
                        prevPos->mNext = temp;
                    }
                    currentPos = temp;
                }
                else
                {
                    prevPos = currentPos;
                    currentPos = currentPos->mNext;
                }
                ++counter;
            }
        }
    }

//    removes an element from the specified position in the linked list
    void deleteBy(int position)
    {
        if (position == size())
        {
            popBack();
        }
        else if (position == 0)
        {
            popFront();
        }
        else
        {
            int counter = 0;
            Node *currentPos = mHead;
            Node *prevItem = nullptr;
            while (currentPos)
            {
                if (counter == position)
                {
                    if (prevItem)
                    {
                        prevItem->mNext = currentPos->mNext;
                    }
                    delete currentPos;
                    currentPos = nullptr;
                }
                else
                {
                    prevItem = currentPos;
                    currentPos = currentPos->mNext;
                    ++counter;
                }
            }
        }
    }

//    release allocated memory for each node in the linked list
    void clear()
    {
        Node *next = mHead;
        while (next)
        {
            Node *deletingNode = next;
            next = next->mNext;
            delete deletingNode;
        }
        mHead = nullptr;
        mTail = nullptr;
    }
};

int main()
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.display();
    list.prepend(4);
    list.prepend(5);
    list.display();
    list.popBack();
    list.display();
    list.popFront();
    list.display();
    list.inseart(1, 9);
    list.display();
    list.deleteBy(2);
    list.display();
    return 0;
}
