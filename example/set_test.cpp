//
// Created by Yijie Ma on 10/27/16.
//

#include <iostream>
#include <set>
#include <unordered_set>

#include "count_allocator.h"

static const int NUM = 23;

int main() {
    std::size_t count1 = 0;
    auto alloc1 = allocator::CountAllocator<int>(&count1);
    std::set<int, std::less<int>, allocator::CountAllocator<int>> set(alloc1);
    for (int i = 0; i < NUM; ++i) {
        set.insert(i);
    }

    std::cout << "std::set allocates " << count1 << " bytes for " << NUM << " elements" << std::endl;

    std::size_t count2 = 0;
    auto alloc2 = allocator::CountAllocator<int>(&count2);
    std::unordered_set<int, std::hash<int>, std::equal_to<int>, allocator::CountAllocator<int>> unset(alloc2);
    for (int i = 0; i < NUM; ++i) {
        unset.insert(i);
    }

    std::cout << "std::unordered_set allocates " << count2 << " bytes for " << NUM << " elements" << std::endl;

    return 0;
}