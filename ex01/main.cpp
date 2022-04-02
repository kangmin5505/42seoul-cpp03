/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:06:21 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/02 19:52:44 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

int main(void) {
  std::cout << "===== Default Constructor && Destructor =====" << std::endl;
  {
    ScavTrap robot;
  }
  std::cout << std::endl;
  std::cout << "===== Constructor with name && Copy assignment =====" << std::endl;
  {
    ScavTrap robot1("Scav");
    ScavTrap robot2;

    robot2 = robot1;
  }
  std::cout << std::endl;
  std::cout << "===== Attack && takeDamage && beRepaired =====" << std::endl;
  ScavTrap robot1("Scav");
  ScavTrap robot2("Trap");

  for (int i = 0; i < 50; i++) {
    robot1.attack("Trap");
  }
  robot1.attack("Trap");
  std::cout << std::endl;
  std::cout << "==============================================" << std::endl;

  for (int i = 0; i < 50; i++) {
    robot2.takeDamage(1);
    robot2.beRepaired(1);
  }
  robot2.beRepaired(1);
  std::cout << std::endl;

  std::cout << "===== guardGate =====" << std::endl;
  robot1.guardGate();
  std::cout << std::endl;
}
