/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:34:18 by absalah           #+#    #+#             */
/*   Updated: 2024/10/14 23:44:27 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data
{
	int id;
	std::string name;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &serializer);
		Serializer &operator=(Serializer const &serializer);
		~Serializer();

	public:
		static uintptr_t serialize(Data *data);
		static Data *deserialize(uintptr_t raw);
};

#endif