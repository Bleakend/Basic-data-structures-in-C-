#include <iostream>
#include <exception>

#ifndef EXCEPTION_H_INCLUDED 
#define EXCEPTION_H_INCLUDED 

struct IndexOutOfBoundException : public std::exception {
   const char * what () const throw () {
      return "Array Index out of bound";
   }
};

#endif