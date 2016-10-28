//
// Created by Yijie Ma on 10/27/16.
//

#include <iostream>
#include <set>
#include <unordered_set>

#include "count_allocator.h"

static const int NUM = 100;

int main() {
    std::size_t count1 = 0;
    auto alloc1 = allocator::CountAllocator<int>(&count1);
    std::set<int, std::less<int>,
             allocator::CountAllocator<int>> set(alloc1);
    for (int i = 0; i < NUM; ++i) {
        set.insert(i);
    }

    std::cout << "std::set allocates " << count1 << " bytes for " << NUM << " elements" << std::endl;

    return 0;
}