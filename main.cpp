#include <iostream>
#include <vector>


template <class T>
class ObjectPool
{
public:
    ObjectPool();
    virtual ~ObjectPool();

    ObjectPool( const ObjectPool& ) = delete;
    ObjectPool( const ObjectPool&& ) = delete;
    ObjectPool& operator=( const ObjectPool& ) = delete;
    ObjectPool& operator=( ObjectPool&& ) = delete;
    
private:

private:
    std::vector< T > m_objects;
};


int main(int argc, char *argv[])
{ 
    return 0;
}