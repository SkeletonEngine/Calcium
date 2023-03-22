#pragma once

#include <unordered_set>

namespace Calcium {

template <typename T, typename TCreateInfo> class ResourceContainer {
public:
  ~ResourceContainer() {
    for (auto& e : set) {
      delete e;
    }
  }

  inline T* Create(const TCreateInfo& create_info) {
    T* t = new T(create_info);
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
