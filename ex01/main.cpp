/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:04:24 by chnaranj          #+#    #+#             */
/*   Updated: 2026/03/12 19:04:25 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
