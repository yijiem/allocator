//
// Created by Yijie Ma on 10/27/16.
//
#ifndef ALLOCATOR_COUNT_ALLOCATOR_H
#define ALLOCATOR_COUNT_ALLOCATOR_H

#include <cstddef>
#include <new>

namespace allocator {
template <class T>
class CountAllocator {
public:
    typedef T value_type;

    CountAllocator(std::size_t* count) noexcept : count_(count) {};

    template <typename U>
    CountAllocator(const CountAllocator<U>& ca) noexcept {
        count_ = ca.count_;
    }

    T* allocate(std::size_t num) {
        // std::cout << "[allocate " << num * sizeof(T) << " bytes]" << std::endl;
        *count_ += num * sizeof(T);
        return static_cast<T*>(::operator new(num * sizeof(T)));
    }

    void deallocate(T* p, std::size_t num) {
        // std::cout << "[deallocate " << num * sizeof(T) << " bytes]" << std::endl;
        *count_ -= num * sizeof(T);
        ::operator delete(p);
    }

    std::size_t* count_;
};

template <typename T1, typename T2>
bool operator==(const CountAllocator<T1>&, const CountAllocator<T2>&) noexcept {
    return true;
};

template <typename T1, typename T2>
bool operator!=(const CountAllocator<T1>&, const CountAllocator<T2>&) noexcept {
    return false;
};
} // namespace allocator

#endif //ALLOCATOR_COUNT_ALLOCATOR_H
