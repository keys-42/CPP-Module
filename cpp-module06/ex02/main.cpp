#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

Base *generate(void) {

  srand(static_cast<unsigned>(time(0)));
  int choice = rand() % 3;

  if (choice == 0) {
    Base *base = new A();
    std::cout << "A was created." << std::endl;
    return base;
  } else if (choice == 1) {
    Base *base = new B();
    std::cout << "B was created." << std::endl;
    return base;
  }
  std::cout << "C was created." << std::endl;
  Base *base = new C();
  return base;
}

void identify(Base *p) {
  try {
    if (dynamic_cast<A *>(p))
      std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
      std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
      std::cout << "C" << std::endl;
  } catch (const std::exception &e) {
    std::cout << "exception :" << e.what() << std::endl;
  }
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (const std::exception &e) {
  }

  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (const std::exception &e) {
  }

  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Unknown type" << std::endl;
  }
}

int main() {
  Base *base;

  base = generate();
  identify(base);
  identify(*base);

  delete base;
  return (0);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q realType");
// }
