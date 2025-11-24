#include <cstdlib>  // malloc, free
#include <new>      // std::align_val_t si besoin

// -----------------------------
// Allocation classique (array)
// -----------------------------
void* operator new[](size_t size, const char* /*name*/, int /*flags*/,
                     unsigned /*debugFlags*/, const char* /*file*/, int /*line*/)
{
    return malloc(size);
}

void* operator new[](size_t size, size_t /*alignment*/, size_t /*alignmentOffset*/,
                     const char* /*name*/, int /*flags*/, unsigned /*debugFlags*/,
                     const char* /*file*/, int /*line*/)
{
    return malloc(size);
}

// -----------------------------
// Delete correspondants (array)
// -----------------------------
void operator delete[](void* ptr, const char* /*name*/, int /*flags*/,
                       unsigned /*debugFlags*/, const char* /*file*/, int /*line*/)
{
    free(ptr);
}

void operator delete[](void* ptr, size_t /*alignment*/, size_t /*alignmentOffset*/,
                       const char* /*name*/, int /*flags*/, unsigned /*debugFlags*/,
                       const char* /*file*/, int /*line*/)
{
    free(ptr);
}

// -----------------------------
// Allocation simple (non-array)
// -----------------------------
void* operator new(size_t size, const char* /*name*/, int /*flags*/,
                   unsigned /*debugFlags*/, const char* /*file*/, int /*line*/)
{
    return malloc(size);
}

void* operator new(size_t size, size_t /*alignment*/, size_t /*alignmentOffset*/,
                   const char* /*name*/, int /*flags*/, unsigned /*debugFlags*/,
                   const char* /*file*/, int /*line*/)
{
    return malloc(size);
}

// -----------------------------
// Delete correspondants (non-array)
// -----------------------------
void operator delete(void* ptr, const char* /*name*/, int /*flags*/,
                     unsigned /*debugFlags*/, const char* /*file*/, int /*line*/)
{
    free(ptr);
}

void operator delete(void* ptr, size_t /*alignment*/, size_t /*alignmentOffset*/,
                     const char* /*name*/, int /*flags*/, unsigned /*debugFlags*/,
                     const char* /*file*/, int /*line*/)
{
    free(ptr);
}
