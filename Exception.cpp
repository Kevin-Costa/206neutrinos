//
// Exception.cpp for 206 in /home/alexandre/Projects/B4/maths/206neutrinos
// 
// Made by Alexandre Vanhoutte
// Login   <alexandre@epitech.net>
// 
// Started on  Mon May  4 15:19:23 2015 Alexandre Vanhoutte
// Last update Mon May  4 15:28:28 2015 Alexandre Vanhoutte
//

#include		<ostream>
#include		<sstream>
#include		"Exception.hh"

Exception::Exception(std::string const &what)
{
  std::ostringstream	oss;

  oss << what;
  this->_what = oss.str();
}

const char		*Exception::what() const throw()
{
  return (_what.c_str());
}
