/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:06:21 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 16:40:49 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

int main(void) {
  std::cout << "===== Default Constructor && Destructor =====" << std::endl;
  {
    FragTrap robot;
  }
  std::cout << std::endl;
  std::cout << "===== Constructor with name && Copy assignment =====" << std::endl;
  {
    FragTrap robot1("Frag");
    FragTrap robot2;

    robot2 = robot1;
  }
  std::cout << std::endl;
  std::cout << "===== Attack && takeDamage && beRepaired =====" << std::endl;
  FragTrap robot1("Frag");
  FragTrap robot2("Trap");

  for (int i = 0; i < 100; i++) {
    robot1.attack("Trap");
  }
  robot1.attack("Trap");
  std::cout << std::endl;
  std::cout << "==============================================" << std::endl;

  for (int i = 0; i < 100; i++) {
    robot2.takeDamage(1);
    robot2.beRepaired(1);
  }
  robot2.beRepaired(1);
  std::cout << std::endl;

  std::cout << "===== highfive =====" << std::endl;
  robot1.highFivesGuys();
  std::cout << std::endl;
}
