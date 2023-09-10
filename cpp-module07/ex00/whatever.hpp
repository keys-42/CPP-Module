#ifndef WHATEVER_HPP
# define WHATEVER_HPP

class Whatever
{
    public:
        Whatever();
        Whatever(Whatever const &other);
        ~Whatever();
        Whatever &operator=(Whatever const &other);
};

#endif