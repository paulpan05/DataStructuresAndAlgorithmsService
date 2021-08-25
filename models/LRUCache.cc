#include "LRUCache.h"

LRUCache::LRUCache(int capacity): capacity(capacity), size(0) {}

int LRUCache::get(int key) {
  if (hmap.find(key) == hmap.end()) {
      return -1;
  }
  int value = hmap[key]->second;
  nodes.erase(hmap[key]);
  nodes.emplace_front(key, value);
  hmap[key] = nodes.begin();
  return value;
}

void LRUCache::put(int key, int value) {
  if (hmap.find(key) != hmap.end()) {
    nodes.erase(hmap[key]);
    nodes.emplace_front(key, value);
    hmap[key] = nodes.begin();
    return;
  }
  nodes.emplace_front(key, value);
  hmap[key] = nodes.begin();
  size += 1;
  if (size > capacity) {
    hmap.erase(nodes.back().first);
    nodes.pop_back();
    size -= 1;
  }
}