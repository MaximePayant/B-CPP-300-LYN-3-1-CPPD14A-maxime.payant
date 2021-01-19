
#ifndef REF_PTR_HPP_
#define REF_PTR_HPP_

#include <memory>
#include <cstddef>
#include <set>
#include "BaseComponent.hpp"

class RefPtr
{
    public:
        RefPtr();
        RefPtr(BaseComponent *rawPtr);
        RefPtr(RefPtr const &other);
        RefPtr &operator=(RefPtr const &other);
        ~RefPtr();

        BaseComponent *get() const;

        static std::set<BaseComponent *> _ptrList;

    private:
        BaseComponent *_rawPtr;
        bool _first;
};

#endif // REF_PTR_HPP_