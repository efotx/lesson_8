#ifndef SHAREDPTR_HPP_INCLUDED
#define SHAREDPTR_HPP_INCLUDED

#include "sharedPtr.h"

template <typename T>
sharedPtr<T>::sharedPtr(T *ptr) : mPtr(ptr), mRefCount(nullptr)
{
    if (ptr)
    {
        mRefCount = new size_t(1);
    }
}

template <typename T>
sharedPtr<T>::sharedPtr(const sharedPtr& other) : mPtr(other.mPtr), mRefCount(other.mRefCount)
{
    if (other.mPtr)
    {
        ++*mRefCount;
    }
}

template <typename T>
sharedPtr<T>& sharedPtr<T>::operator= (const sharedPtr &other)
{
    if (mPtr != other.mPtr)
    {
        if (mRefCount && (--*mRefCount == 0))
        {
            delete mPtr;
            delete mRefCount;
        }
        mPtr = other.mPtr;
        mRefCount = other.mRefCount;
        if (mPtr)
        {
            ++*mRefCount;
        }
    }
    return *this;
}

template <typename T>
sharedPtr<T>::~sharedPtr()
{
    if (mRefCount && (--*mRefCount == 0))
    {
        delete mPtr;
        delete mRefCount;
    }
}

template <typename T>
T* sharedPtr<T>::get() const
{
    return mPtr;
}

template <typename T>
void sharedPtr<T>::reset(T* ptr)
{
    if (mRefCount && (--*mRefCount == 0))
        {
            delete mPtr;
            delete mRefCount;
        }
        mPtr = ptr;
        mRefCount = nullptr;
        if (mPtr)
        {
            mRefCount = new size_t(1);
        }
}

template <typename T>
T& sharedPtr<T>::operator*() const
{
    return *mPtr;
}

template <typename T>
T* sharedPtr<T>::operator->() const
{
    return mPtr;
}

#endif // SHAREDPTR_HPP_INCLUDED
