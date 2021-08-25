#pragma once
#include <list>
#include <unordered_map>

class LRUCache {
  private:
    int capacity;
    int size;
    std::list<std::pair<int, int>> nodes;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hmap; 
  public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
};