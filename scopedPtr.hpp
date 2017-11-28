#ifndef SCOPEDPTR_HPP_INCLUDED
#define SCOPEDPTR_HPP_INCLUDED

#include "scopedPtr.h"


template <typename T>
scopedPtr<T>::scopedPtr(T* ptr) : mPtr(ptr) {}

template <typename T>
scopedPtr<T>::~scopedPtr()
{
    delete mPtr;
}

template <typename T>
T* scopedPtr<T>::get() const
{
    return mPtr;
}

template <typename T>
T* scopedPtr<T>::release ()
{
    T* ptr = mPtr;
    mPtr = nullptr;
    return ptr;
}

template <typename T>
void scopedPtr<T>::reset (T *ptr)
{
    delete mPtr;
    mPtr = ptr;
}

template <typename T>
T& scopedPtr<T>::operator*() const
{
    return *mPtr;
}

template <typename T>
T* scopedPtr<T>::operator->() const
{
    return mPtr;
}


#endif // SCOPEDPTR_HPP_INCLUDED
