#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data myData;
    myData.value = 42;
    myData.text = "Data test";

    std::cout << "Original address:  " << &myData << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized value:  " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized addr: " << ptr << std::endl;

    if (ptr == &myData)
    {
        std::cout << "Verification: Success! The pointer is identical." << std::endl;
        std::cout << "Content: [" << ptr->value << ", " << ptr->text << "]" << std::endl;
    }
    else
    {
        std::cout << "Verification: Failed." << std::endl;
    }

    return 0;
}
