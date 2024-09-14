#pragma once
#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>
#include <iostream>

class extPersonType : public personType
{
private:
	dateType birthdate;
	addressType address;

};

