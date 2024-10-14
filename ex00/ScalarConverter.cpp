/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperko <sperko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:19:43 by absalah           #+#    #+#             */
/*   Updated: 2024/10/14 03:16:36 by sperko           ###   ########.fr       */
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

bool isChar(const std::string& literal) {
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool isInt(const std::string& literal) {
    char* end;
    long l = std::strtol(literal.c_str(), &end, 10);
    return *end == '\0' && l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max();
}

bool isFloat(const std::string& literal) {
    return literal.find('.') != std::string::npos && literal[literal.length() - 1] == 'f';
}

bool isDouble(const std::string& literal) {
    return literal.find('.') != std::string::npos && literal[literal.length() - 1] != 'f';
}

void convertChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convertInt(int i) {
    std::cout << "char: ";
    if (i >= 0 && i <= 127 && std::isprint(i))
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void convertFloat(float f) {
    std::cout << "char: ";
    if (f >= 0 && f <= 127 && std::isprint(static_cast<int>(f)))
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convertDouble(double d) {
    std::cout << "char: ";
    if (d >= 0 && d <= 127 && std::isprint(static_cast<int>(d)))
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    
    std::cout << "double: " << d << std::endl;
}

void handleSpecialCases(const std::string& literal) 
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
	else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || 
        literal == "+inff" || literal == "-inff") {
        handleSpecialCases(literal);
        return;
    }

    if (isChar(literal)) 
	{
        convertChar(literal[0]);
    } 
	else if (isInt(literal)) 
	{
        try 
		{
            int i = std::atoi(literal.c_str());
            convertInt(i);
        } 
		catch (...) 
		{
            std::cout << "Int conversion error" << std::endl;
        }
    } 
	else if (isFloat(literal)) 
	{
        try 
		{
            float f = std::atof(literal.c_str());
            convertFloat(f);
        } 
		catch (...) 
		{
            std::cout << "Float conversion error" << std::endl;
        }
    } 
	else if (isDouble(literal)) 
	{
        try 
		{
            double d = std::atof(literal.c_str());
            convertDouble(d);
        } 
		catch (...) 
		{
            std::cout << "Double conversion error" << std::endl;
        }
    } 
	else
        std::cout << "Invalid input" << std::endl;
}