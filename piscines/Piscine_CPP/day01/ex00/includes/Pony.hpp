#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP
# define MAXFOODLENGHT 16
# include <string>

class Pony
{
  private:
    std::string _foodEaten[MAXFOODLENGHT];
    std::string _color;

  public:
    Pony(std::string color);
    ~Pony();
};

#endif