/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:44:54 by absalah           #+#    #+#             */
/*   Updated: 2024/10/14 23:45:52 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Create a Data object
    Data* originalData = new Data;
    originalData->id = 42;
    originalData->name = "Example";

    // Print original data
    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << originalData << std::endl;
    std::cout << "ID: " << originalData->id << std::endl;
    std::cout << "Name: " << originalData->name << std::endl;

    // Serialize
    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "\nSerialized value: " << serialized << std::endl;

    // Deserialize
    Data* deserializedData = Serializer::deserialize(serialized);

    // Print deserialized data
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "ID: " << deserializedData->id << std::endl;
    std::cout << "Name: " << deserializedData->name << std::endl;

    // Check if the deserialized pointer is equal to the original
    std::cout << "\nAre pointers equal? " << (originalData == deserializedData ? "Yes" : "No") << std::endl;

    // Clean up
    delete originalData;

    return 0;
}