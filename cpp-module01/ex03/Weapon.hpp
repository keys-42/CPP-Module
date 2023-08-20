#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>

class Weapon{
    public:
        Weapon();
        ~Weapon();
        const std::string& get_type() const ;
        void  set_type(const std::string& new_type);

    private:
            std::string type_;
};

#endif
