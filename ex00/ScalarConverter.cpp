#include "ScalarConverter.hpp"

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

void ScalarConverter::convert(const std::string& literal)
{
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
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
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

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << val << std::endl;
}
