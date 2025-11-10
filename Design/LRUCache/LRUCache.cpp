#include <bits/stdc++.h>
using namespace std;

// =============== Solution1 - Doubly Linked List + HashMap ===============

class LRUCache1
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1); // dummy head
    node *tail = new node(-1, -1); // dummy tail

    int cap;
    unordered_map<int, node *> m; // key → node address

    LRUCache1(int capacity)
    {
        cap = capacity;
        head->next = tail; // initialize empty doubly linked list
        tail->prev = head;
    }

    // Insert node next to head (most recently used position)
    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Remove node from list
    void deleteNode(node *delNode)
    {
        node *delPrev = delNode->prev;
        node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *resNode = m[key];
            int res = resNode->val;

            // Move node to most recent position
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;

            return res;
        }
        return -1;
    }

    void put(int key, int val)
    {
        // If key already exists → delete old node
        if (m.find(key) != m.end())
        {
            node *existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
            delete existingNode;
        }

        // If capacity full → remove least recently used (before tail)
        if (m.size() == cap)
        {
            node *lruNode = tail->prev;
            m.erase(lruNode->key);
            deleteNode(lruNode);
            delete lruNode;
        }

        // Insert new node at head
        addNode(new node(key, val));
        m[key] = head->next;
    }
};

// =============== Solution2 - std::list + HashMap ===============
class LRUCache2
{
    int cap;                                               // maximum capacity
    list<pair<int, int>> lst;                              // stores {key, value} in LRU order (front = most recent)
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key → iterator in list

public:
    LRUCache2(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        // If key not present → return -1
        if (!mp.count(key))
            return -1;

        auto it = mp[key];
        int val = it->second;

        // Move accessed key to the front (most recently used)
        lst.erase(it);
        lst.push_front({key, val});
        mp[key] = lst.begin();

        return val;
    }

    void put(int key, int value)
    {
        // If key exists → remove old position
        if (mp.count(key))
        {
            lst.erase(mp[key]);
        }
        // If full capacity → remove least recently used (back)
        else if (lst.size() == cap)
        {
            mp.erase(lst.back().first); // remove key from map
            lst.pop_back();             // remove from list
        }

        // Insert new/updated key at front
        lst.push_front({key, value});
        mp[key] = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
