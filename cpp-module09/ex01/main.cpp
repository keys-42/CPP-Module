#include "RPN.hpp"

int main( int argc, char **argv )
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " {Reverse Polish Notation}" << std::endl;
        return 1;
    }
	Rpn* rpn = new Rpn();
		rpn->rpn( static_cast<std::string>(argv[1]));

	// {
	// 	Rpn r(*rpn);
	// 	r.rpn( static_cast<std::string>(argv[1]));
	// }
	// {
	// 	Rpn r = *rpn;
	// 	r.rpn( static_cast<std::string>(argv[1]));

	// }
	// rpn->rpn( static_cast<std::string>(argv[1]));
	// {
	// 	std::cout << "test" <<std::endl;
	// 	rpn->print();
	// }
	delete rpn;

    return 0;
}
