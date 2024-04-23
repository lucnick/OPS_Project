#pragma once


unsigned int getRandomSeed() {
    unsigned int seed;
    // Use the memory address of a local variable
    unsigned int local_variable_address = (unsigned int)&seed;
    // Use a pointer to a local variable to get the stack pointer
    void *stack_pointer;
    // Assign the address of a local variable to the pointer to capture the stack position
    stack_pointer = &seed;

    // Cast the pointer to an unsigned integer
    unsigned int stack_pointer_address = (unsigned int)stack_pointer;
    
    // Combine both values to create a seed
    seed = local_variable_address ^ stack_pointer_address;
    return seed;
}

unsigned int getRandom(unsigned int n, unsigned int seed) {
    // Implementation of a pseudo-random number generator
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return (seed) % n;
}

unsigned int seed = getRandomSeed();
