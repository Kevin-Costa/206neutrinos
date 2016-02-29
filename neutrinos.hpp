//
// neutrinos.hpp for 206 in /home/alexandre/Projects/B4/maths/206neutrinos
// 
// Made by Alexandre Vanhoutte
// Login   <alexandre@epitech.net>
// 
// Started on  Thu Apr 30 16:59:58 2015 Alexandre Vanhoutte
// Last update Mon May  4 15:26:37 2015 Alexandre Vanhoutte
//

class		Neutrinos
{
public:
  Neutrinos();
  ~Neutrinos();
  void		run(int, char **);
private:
  int		_nb_val_rel;
  int		_moy_ari;
  int		_moy_har;
  int		_ecart_type;
};
