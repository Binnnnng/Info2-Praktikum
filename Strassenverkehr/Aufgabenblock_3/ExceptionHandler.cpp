#include "ExceptionHandler.h"



ExceptionHandler::ExceptionHandler(int excepType,string excepString)
{
	if (excepType == 1)
	{
		throw("MapException:" + excepString);
	}
	if (excepType == 2)
	{
		throw("ParseException:" + excepString);
	}
	if (excepType == 3)
	{
		throw("GenericException:" + excepString);
	}
	if (excepType == 0)
	{
		throw("UnknownException:" + excepString);
	}
}


ExceptionHandler::~ExceptionHandler()
{
}
