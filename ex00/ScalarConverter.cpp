/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:03:56 by chnaranj          #+#    #+#             */
/*   Updated: 2026/03/12 19:03:58 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <cctype>

void ScalarConverter::convert(const std::string& literal)
{
	if (literal.empty())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	char* endptr;
	double val = std::strtod(literal.c_str(), &endptr);

	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		val = static_cast<double>(literal[0]);
	}
	else if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0'))
	{
		if (literal != "nan" && literal != "nanf" && literal != "inf" && literal != "inff" && 
			literal != "+inf" && literal != "+inff" && literal != "-inf" && literal != "-inff")
		{
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
			return;
		}
	}

	std::cout << "char: ";
	if (val != val || val > std::numeric_limits<char>::max() || val < std::numeric_limits<char>::min())
	{
		std::cout << "impossible" << std::endl;
	}
	else if (!std::isprint(static_cast<int>(val)))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
	}

	std::cout << "int: ";
	if (val != val || val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << static_cast<int>(val) << std::endl;
	}

std::cout << "float: ";
if (val != val)
{
	std::cout << "nanf" << std::endl;
}
else if (val > std::numeric_limits<float>::max() || val < -std::numeric_limits<float>::max())
{
	if (literal.find("inf") != std::string::npos)
	{
		if (val < 0)
			std::cout << "-inff" << std::endl;
		else if (literal[0] == '+')
			std::cout << "+inff" << std::endl;
		else
			std::cout << "inff" << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}
else if (val == std::floor(val))
{
	std::cout << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
}
else
{
	std::cout << static_cast<float>(val) << "f" << std::endl;
}

std::cout << "double: ";
if (val != val)
{
	std::cout << "nan" << std::endl;
}
else if (val > std::numeric_limits<double>::max() || val < -std::numeric_limits<double>::max())
{
	if (val < 0)
		std::cout << "-inf" << std::endl;
	else if (literal[0] == '+')
		std::cout << "+inf" << std::endl;
	else
		std::cout << "inf" << std::endl;
}
else if (val == std::floor(val))
{
	std::cout << std::fixed << std::setprecision(1) << val << std::endl;
}
else
{
	std::cout << val << std::endl;
}	
	

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}
