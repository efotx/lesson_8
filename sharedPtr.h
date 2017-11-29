#ifndef SHAREDPTR_H_INCLUDED
#define SHAREDPTR_H_INCLUDED

template <typename T>
class sharedPtr
{
private:
    T *mPtr;
    size_t *mRefCount;
public:
    explicit sharedPtr (T *ptr = nullptr);
    sharedPtr(const sharedPtr &other);
    sharedPtr& operator= (const sharedPtr &other);
    ~sharedPtr();

    T* get () const;
    void reset (T *ptr = nullptr);

    T& operator* () const;
    T* operator-> () const;

};

#include "sharedPtr.hpp"

#endif // SHAREDPTR_H_INCLUDED
