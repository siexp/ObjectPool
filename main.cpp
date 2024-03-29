#include <iostream>
#include <string>
#include <vector>
#include <mutex>


template< class T >
class ObjectPool
{
public:
    ObjectPool( size_t size );
    virtual ~ObjectPool() = default;

    ObjectPool( const ObjectPool& ) = delete;
    ObjectPool( const ObjectPool&& ) = delete;
    ObjectPool& operator=( const ObjectPool& ) = delete;
    ObjectPool& operator=( ObjectPool&& ) = delete;
    
    T& acquire();
    void release( T& obj );

    void resize( size_t size );

private:
    std::vector< T > m_objects;

    mutable std::mutex m_objects_mutex;
};


template< class T >
ObjectPool< T >::ObjectPool( size_t size ) :
    m_objects{ size, "Hello, World!" }
{
}

template< class T >
T& ObjectPool< T >::acquire()
{
    std::lock_guard{ m_objects_mutex };
    auto& instance = m_objects.back();

    return instance;
}

template< class T >
void ObjectPool< T >::release( T& obj )
{
    std::lock_guard{ m_objects_mutex };
    m_objects.push_back( obj );
}

template< class T >
void ObjectPool< T >::resize( size_t size )
{
    std::lock_guard{ m_objects_mutex };
    m_objects.resize( size );
}


int main(int argc, char *argv[])
{ 
    ObjectPool< std::string > test{ 10 };

    std::cout << test.acquire() << std::endl;

    return 0;
}