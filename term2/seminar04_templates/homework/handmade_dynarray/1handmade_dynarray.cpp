#include <cstdio>
#include <cstdlib>

typedef int Data;

struct Dynarray
{
    size_t size;
    size_t capacity;
    Data* values;

    void init(size_t initialCapacity)
    {
        if (initialCapacity < 0)
        {
            std::printf("Dynarray's capacity has to be non-negative integer\n");
            std::exit(1);
        }
        size = 0;
        capacity = initialCapacity;
        values = (Data*)std::malloc(capacity * sizeof(Data));
        if (values == NULL)
        {
            std::printf("Error! Can't allocate %lu bytes of memmory using malloc()\n", capacity * sizeof(Data));
            std::exit(1);
        }
    }

    void pushBack(Data x)
    {
        if (size >= capacity)
        {
            if (capacity == 0)
                capacity = 1;
            else
                capacity *= 2;
            Data* temp = (Data*)realloc(values, capacity * sizeof(int));
            if (temp == NULL)
            {
                std::printf("Error! Can't reallocate %lu bytes of memmory using realloc()\n", capacity * sizeof(Data));
                std::free(values);
                std::exit(1);
            }
            else
            {
                values = temp;
            }
        }
        values[size] = x;
        size += 1;
    }

    void erase(size_t id)
    {
        if (id < 0 || id >= size)
        {
            std::printf("Error while erasing element from Dynarray! Index is out of range\n");
            std::exit(1);
        }
        if (size == 0)
        {
            std::printf("Error while erasing element from Dynarray! Dynarray is empty\n");
            std::exit(1);
        }
        for (size_t i = id; i < size - 1; i++)
            values[i] = values[i + 1];
        size--;
    }

    int isEmpty()
    {
        return (size == 0);
    }

    void destroy()
    {
        std::free(values);
    }
};

int main()
{
    Dynarray a;
    a.init(0);

    for (int i = 0; i < 20; ++i)
    {
        std::printf("Pushing element %d. Size = %d. Capacity = %d.\n", i*i, a.size, a.capacity);
        a.pushBack(i * i);
    }

    std::printf("Erasing 10th element\n");
    a.erase(10);
    std::printf("10th element of Dynarray is: %d\n", a.values[10]);

    a.destroy();
}
