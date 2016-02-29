//
// Exception.hh for 206 in /home/alexandre/Projects/B4/maths/206neutrinos
// 
// Made by Alexandre Vanhoutte
// Login   <alexandre@epitech.net>
// 
// Started on  Mon May  4 15:22:06 2015 Alexandre Vanhoutte
// Last update Mon May  4 15:24:41 2015 Alexandre Vanhoutte
//

#ifndef			_EXCEPTION_H__
# define		_EXCEPTION_h__

#include		<iostream>
#include		<string>

class			Exception : public std::exception
{
private:
  std::string		_what;

public:
  Exception(std::string const &);
  virtual ~Exception() throw() {};

  virtual const char *what() const throw();
};

#endif		/* !_EXCEPTION_HH__ */
