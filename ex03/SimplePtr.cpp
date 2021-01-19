/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** SimplePtr.cpp
*/

#include "SimplePtr.hpp"

SimplePtr::SimplePtr(BaseComponent *rawPtr) :
_rawPtr(rawPtr)
{}

SimplePtr::~SimplePtr()
{
    delete (_rawPtr);
}

BaseComponent* SimplePtr::get() const
{
    return (_rawPtr);
}