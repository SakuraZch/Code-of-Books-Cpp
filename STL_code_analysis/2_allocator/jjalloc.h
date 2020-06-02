
// 2020/5/29 //

#ifndef _JJALLOC_
#define _JJALLOC_

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace JJ
{
    template <typename T>
    inline T* _allocate(ptrdiff_t size, T*)
    {
        std::set_new_handler(nullptr);
        T* tmp = static_cast<T*>(::operator new(static_cast<size_t>(size*sizeof(T))));
        if(tmp == nullptr)
        {
            std::cerr << "Out of Memory" << std::endl;
            exit(1);
        }
        return tmp;
    }

    template <typename T>
    inline void _deallocate(T* buffer)
    {
        ::operator delete(buffer);
    }

    template <typename T1, typename T2>
    inline void _construct(T1* p, const T2& value)
    {
        new(p) T1(value);
    }

    template <typename T>
    inline void _destory(T* ptr)
    {
        ptr->~T();
    }

    template <typename T>
    class allocator
    {
        public:
            typedef T         value_type;
            typedef T*        pointer;
            typedef const T*  const_pointer;
            typedef T&        reference;
            typedef const T&  const_reference;
            typedef size_t    size_type;
            typedef ptrdiff_t difference_type;

        template <typename U>
        struct rebind
        {
            typedef allocator<U> other;
        };

        pointer allocate(size_type n, const void* hint = nullptr)
        {
            return _allocate(static_cast<difference_type>(n), static_cast<pointer>(nullptr));
        }

        void deallocate(pointer p, size_type n)
        {
            _deallocate(p);
        }

        void construct(pointer p, const T& value)
        {
            _construct(p, value);
        }

        void destroy(pointer p)
        {
            _destory(p);
        }

        pointer address(reference x)
        {
            return static_cast<pointer>(&x);
        }

        const_pointer const_address(const_reference x)
        {
            return static_cast<const_pointer>(&x);
        }

        size_type max_size() const
        {
            return static_cast<size_type>(UINT_MAX/sizeof(T));
        }
    };
} // end of namespace JJ

#endif