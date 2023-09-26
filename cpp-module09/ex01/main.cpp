#include "RPN.hpp"

int main( int argc, char **argv )
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " {Reverse Polish Notation}" << std::endl;
        return 1;
    }
	{
		Rpn* rpn = new Rpn();
		rpn->rpn( static_cast<std::string>(argv[1]) );
		delete rpn;
	}

	{
		Rpn* rpn = new Rpn();
		Rpn r(*rpn);
		r.rpn( static_cast<std::string>(argv[1]));
		delete rpn;
	}
	{
		Rpn* rpn = new Rpn();
		Rpn r = *rpn;
		r.rpn( static_cast<std::string>(argv[1]));
		delete rpn;
	}
	{
		Rpn* rpn = new Rpn();
		rpn->rpn( static_cast<std::string>(argv[1]));
		std::cout << "test" <<std::endl;
		rpn->print();
		std::cout << "empty" << std::endl;
		delete rpn;
	}

    return 0;
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q RPN");
// }