#pragma once

#include <stdexcept>

class Exceptions : public std::exception
{
public:
    const char* what() const noexcept override;
};