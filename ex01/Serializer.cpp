/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:41:48 by absalah           #+#    #+#             */
/*   Updated: 2024/10/14 23:44:35 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &serializer) 
{
	(void)serializer;
}

Serializer &Serializer::operator=(Serializer const &serializer) 
{
	(void)serializer;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *data)
{
	return reinterpret_cast<uintptr_t>(data);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}