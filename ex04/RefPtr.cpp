/*
** EPITECH PROJECT, 2021
** CPP_SEMINAR
** File description:
** RefPtr.cpp
*/

#include "RefPtr.hpp"

std::set<BaseComponent *> RefPtr::_ptrList;

RefPtr::RefPtr() :
_rawPtr(nullptr),
_first(false)
{}

RefPtr::RefPtr(BaseComponent *rawPtr) :
_rawPtr(rawPtr),
_first(false)
{
    if (_ptrList.find(_rawPtr) == _ptrList.end()) {
        _first = true;
        _ptrList.insert(_rawPtr);
    }
}

RefPtr::RefPtr(RefPtr const &other) :
_rawPtr(other.get()),
_first(false)
{
    if (_ptrList.find(_rawPtr) == _ptrList.end()) {
        _first = true;
        _ptrList.insert(_rawPtr);
    }
}

RefPtr::~RefPtr()
{
    if (_first)
        delete (_rawPtr);
}

RefPtr& RefPtr::operator=(RefPtr const &other)
{
    _rawPtr = other.get();
    return (*this);
}

BaseComponent* RefPtr::get() const
{
    return (_rawPtr);
}