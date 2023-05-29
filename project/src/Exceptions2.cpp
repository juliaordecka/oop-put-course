#include "Exceptions.h"
#pragma once

const char* Exceptions::what() const noexcept
{
    return "Input a valid choice (1,2,3,4,5)";
}