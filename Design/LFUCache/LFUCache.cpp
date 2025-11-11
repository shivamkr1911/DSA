#include <bits/stdc++.h>
using namespace std;

// Node structure storing key, value, and frequency count
struct Node
{
    int key, value, cnt;
    Node *next, *prev;

    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1; // frequency starts at 1
        next = prev = nullptr;
    }
};

// Doubly linked list for each frequency group
struct List
{
    int size;
    Node *head, *tail;

    List()
    {
        // dummy head and tail
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    ~List()
    {
        delete head;
        delete tail;
    }

    // Add node to front (most recent within same frequency)
    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    // Remove a node from current list
    void removeNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

class LFUCache
{
private:
    unordered_map<int, Node *> keyNode;     // key → node pointer
    unordered_map<int, List *> freqListMap; // frequency → list of nodes

    int maxSizeCache;
    int minFreq; // currently minimum frequency in cache
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    // Move node from old freq list → new freq list (freq + 1)
    void updateFreqListMap(Node *node)
    {
        int oldFreq = node->cnt;
        List *list = freqListMap[oldFreq];
        list->removeNode(node);

        // If this was the last node in minFreq list → increase minFreq
        if (oldFreq == minFreq && list->size == 0)
        {
            freqListMap.erase(oldFreq);
            delete list;
            minFreq++;
        }

        int newFreq = oldFreq + 1;

        // Create list for new frequency if missing
        if (!freqListMap.count(newFreq))
        {
            freqListMap[newFreq] = new List();
        }

        node->cnt = newFreq;
        freqListMap[newFreq]->addFront(node);
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        // Not present
        if (!keyNode.count(key))
            return -1;

        Node *node = keyNode[key];
        int val = node->value;

        // Increase frequency
        updateFreqListMap(node);

        return val;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
            return;

        // Key already exists → update value + freq
        if (keyNode.count(key))
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            // Cache full → remove LFU node (least freq & least recent)
            if (curSize == maxSizeCache)
            {
                List *list = freqListMap[minFreq];
                Node *toDelete = list->tail->prev; // LRU in minFreq list

                keyNode.erase(toDelete->key);
                list->removeNode(toDelete);
                delete toDelete;
                curSize--;
            }

            // Insert new node with frequency = 1
            curSize++;
            minFreq = 1;

            if (!freqListMap.count(minFreq))
            {
                freqListMap[minFreq] = new List();
            }

            Node *node = new Node(key, value);
            freqListMap[minFreq]->addFront(node);
            keyNode[key] = node;
        }
    }

    ~LFUCache()
    {
        // Delete all nodes
        for (auto &pair : keyNode)
        {
            delete pair.second;
        }

        // Delete each frequency list
        for (auto &pair : freqListMap)
        {
            delete pair.second;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
