//
// main.cpp for 206 in /home/alexandre/Projects/B4/maths/206neutrinos
// 
// Made by Alexandre Vanhoutte
// Login   <alexandre@epitech.net>
// 
// Started on  Thu Apr 30 17:27:37 2015 Alexandre Vanhoutte
// Last update Mon May  4 15:26:17 2015 Alexandre Vanhoutte
//

#include	"Exception.hh"
#include	"neutrinos.hpp"

int		main(int ac, char **av)
{
  try {
  Neutrinos	neutrinos;

  neutrinos.run(ac, av);
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return (-1);
  }
  return (0);
}
