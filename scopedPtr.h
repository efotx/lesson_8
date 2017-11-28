#ifndef SCOPEDPTR_H_INCLUDED
#define SCOPEDPTR_H_INCLUDED

template <typename T>
class scopedPtr
{
private:
    T* mPtr;

public:
    explicit scopedPtr(T* ptr = nullptr);

    ~scopedPtr();

    scopedPtr(const scopedPtr&) = delete;
    scopedPtr& operator= (const scopedPtr&) = delete;

    T* get() const;
    T* release ();
    void reset (T *ptr = nullptr);

    T& operator*() const;
    T* operator->() const;

};

#include "scopedPtr.hpp"

#endif // SCOPEDPTR_H_INCLUDED
