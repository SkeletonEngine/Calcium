#pragma once

#include <unordered_set>

namespace Calcium {

template <class T> class ResourceContainer {
public:
  ~ResourceContainer() {
    for (auto& e : set) {
      delete e;
    }
  }

  inline T* Create() {
    T* t = new T();
    set.emplace(t);
    return t;
  }

  inline void Remove(T* t) {
    delete t;
    set.erase(t);
  }

private:
  std::unordered_set<T*> set;
};

}
