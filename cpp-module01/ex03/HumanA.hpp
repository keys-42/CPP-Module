#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA {
	public:
			HumanA(const std::string name,Weapon& w);
			~HumanA();
			void attack();

	private:
			std::string name_;
			Weapon *w_;

};

#endif
