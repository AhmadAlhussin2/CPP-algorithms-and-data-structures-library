#ifndef ORDERED_CONTAINER_H
#define ORDERED_CONTAINER_H

template <typename T>
class OrderedContainer {
public:
  virtual ~OrderedContainer() = default;
  virtual int size() const = 0;
  virtual void clear() = 0;
  virtual bool contains(const T& element) const = 0;
  virtual void insert(const T& key) = 0;
  virtual void remove(int key) = 0;
  virtual T getTheKthElement(int index) const = 0;
};

#endif //ORDERED_CONTAINER_H
