/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalah <absalah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:19:43 by absalah           #+#    #+#             */
/*   Updated: 2024/10/13 23:57:54 by absalah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

int	convert_char(const std::string &str) 
{
	char c = str[0];
	if (str.length() == 1 && !std::isdigit(c)) 
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
		return 1;
	}
	return 0;
}

int convert_int(const std::string &str) 
{
	int i = std::stoi(str);
	if (str.length() > 1 || (str.length() == 1 && std::isdigit(str[0]))) 
	{
		std::cout << "char: ";
		if (i >= 0 && i <= 127 && std::isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
		return 1;
	}
	return 0;
}

int convert_float(const std::string &str) 
{
	float f = std::stof(str);
	if (str.length() > 1 || (str.length() == 1 && std::isdigit(str[0]))) 
	{
		std::cout << "char: ";
		if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
			std::cout << static_cast<int>(f) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return 1;
	}
	return 0;
}

int convert_double(const std::string &str) 
{
	double d = std::stod(str);
	if (str.length() > 1 || (str.length() == 1 && std::isdigit(str[0]))) 
	{
		std::cout << "char: ";
		if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
			std::cout << static_cast<int>(d) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "float: ";
		if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
			std::cout << static_cast<float>(d) << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		std::cout << "double: " << d << std::endl;
		return 1;
	}
	return 0;
}

void	handle_special_cases(const std::string &str) 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &str) 
{
	if (str.empty()) 
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: 0.0f" << std::endl;
		std::cout << "double: 0.0" << std::endl;
		return;
	}

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff") 
	{
		handle_special_cases(str);
		return;
	}

	if (convert_char(str) || convert_int(str) || convert_float(str) || convert_double(str))
		return;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}