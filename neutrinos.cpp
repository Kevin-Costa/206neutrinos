//
// neutrinos.cpp for 206 in /home/alexandre/Projects/B4/maths/206neutrinos
// 
// Made by Alexandre Vanhoutte
// Login   <alexandre@epitech.net>
// 
// Started on  Thu Apr 30 17:14:33 2015 Alexandre Vanhoutte
// Last update Thu May  7 12:18:45 2015 Kevin Costa
//

#include	<stdio.h>

#include	<iostream>
#include	<stdlib.h>
#include	<sstream>
#include	<math.h>
#include	<iomanip>
#include	"Exception.hh"
#include	"neutrinos.hpp"

Neutrinos::Neutrinos()
{
}

Neutrinos::~Neutrinos()
{
}

void		check_arguments(std::string str)
{
  for (int i = 0; str[i]; i++) {
    if (str[i] < '0' || str[i] > '9')
      throw(Exception("Fejl : Argumenterne skal være tal."));
  }
}

void		Neutrinos::run(int ac, char **av)
{
  double	text[5];
  std::string	str;
  std::stringstream ss;
  static double	i = 0;
    double		devia;
    double		devia0;
    double		res;
    double		res0 = 0;
    double		res1 = 0;
    double		res2 = 0;


  if (ac != 5)
    throw(Exception("Fejl : Programmet har brug 4 argumenter"));
  for (int i = 1; i < ac; i++) {
    check_arguments(av[i]);
    text[i - 1] = atof(av[i]);
    }
  while (str != "ende") {
    std::string	str;

    std::cout << "indstast din vaerdi : ";
    std::cin >> str;

    if (str.empty())
      exit(0);
    if (str == "ende")
      exit(0);
    check_arguments(str);
    ss.clear();
    ss.str("");
    ss.str(str);
    ss >> text[4];
    // text[4] = atof(str);
    text[0] += 1.0;
    std::cout << "\tantal mãlinder :\t" << text[0] << std::endl;

    /* devia */


    if (i == 0) {
      devia = text[3];
      devia = sqrt((((((pow(devia, 2) + pow(text[1], 2))) * (text[0] - 1.0)) + pow(text[4], 2)) / text[0]) - pow((((text[1] * (text[0] - 1.0)) + text[4]) / text[0]), 2));
    }
    else {
      devia0 = devia;
      devia = sqrt((((((pow(devia, 2) + pow(res, 2))) * (text[0] - 1.0)) + pow(text[4], 2)) / text[0]) - pow((((res * (text[0] - 1.0)) + text[4]) / text[0]), 2));
    }
    std::cout << "\tstandardafvilgelse :\t" << std::fixed << std::setprecision(2)<< devia << std::endl;

    /* arithmetique */
    if (i == 0)
      res = text[1];
    res0 = res;
    res = ((res * (text[0] - 1.0)) + text[4]) / text[0];
    std::cout << "\taritmetisk gennemsnit :\t" <<res << std::endl;

    /* quadratique */

    if (i == 0) {
      res1 = text[1];
      res1 = sqrt((((pow(text[3], 2) + pow(res1, 2)) * (text[0] - 1.0)) + pow(text[4], 2)) / text[0]);
    }
    else {
      res1 = sqrt((((pow(devia0, 2) + pow(res0, 2)) * (text[0] - 1.0)) + pow(text[4], 2)) / text[0]);
    }
    std::cout << "\tkvadratisk gennemsnit :\t" << res1 << std::endl;

    /* harmonique */
    if (i == 0)
      res2 = text[2];
    if (text[0] == 0 || text[2] == 0)
      std::cout << "\tharmonisk gennemsnit :\tDet harmoniske gennemsnit kan ikke beregnes." << std::endl;
    else {
      res2 = text[0] / ((1.0 / res2 * (text[0] - 1.0)) + (1.0 /text[4]));
      std::cout << "\tharmonisk gennemsnit :\t" << res2 << std::endl;
    }
    i++;
  }

}

