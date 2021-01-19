
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <string>

class NasaError :
    public std::exception
{

    private:
        std::string _message;
        std::string _component;

    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown");

        virtual std::string const &getComponent() const;

        virtual const char* what() const throw() { return _message.c_str(); }

};

class MissionCriticalError :
    public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown");
};

class LifeCriticalError :
    public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown");
};

class UserError :
    public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown");
};

class CommunicationError :
    public NasaError
{
    public:
        CommunicationError(std::string const &message);
};

#endif
