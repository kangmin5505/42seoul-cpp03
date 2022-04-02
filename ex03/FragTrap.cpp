/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:21:45 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/02 23:36:11 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

const std::string FragTrap::kRobotType = "FragTrap";

FragTrap::FragTrap(void) {
  std::cout << "[ " << kRobotType << " ] "
          << "Default constructor is called." << std::endl;
  hit_points_ = kHitPoints;
  energy_points_ = kEnergyPoints;
  attack_damage_ = kAttackDamage;
}

FragTrap::FragTrap(const std::string &name)
  : ClapTrap(name)
{
  std::cout << "[ " << kRobotType << " ] "
            << "Constructor with name is called." << std::endl;
  hit_points_ = kHitPoints;
  energy_points_ = kEnergyPoints;
  attack_damage_ = kAttackDamage;
}

FragTrap::FragTrap(const FragTrap &fragtrap) {
  std::cout << "[ " << kRobotType << " ] "
            << "Copy constructor is called." << std::endl;
  *this = fragtrap;
}

FragTrap::~FragTrap(void) {
  std::cout << "[ " << kRobotType << " ] "
            << "Destructor of " << name_ << "'s is called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
  std::cout << "[ " << kRobotType << " ] "
            << "Copy assignment operator is called." << std::endl;
  ClapTrap::operator=(fragtrap);
  return *this;
}

void FragTrap::attack(const std::string &target) {
  if (hit_points_ == 0 || energy_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " can't do anything." << std::endl;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << "FragTrap " << name_ << " attacks " << target
              << ", causing " << attack_damage_ << " points of damage!"
              << std::endl;
    energy_points_--;
  }
}

void FragTrap::takeDamage(unsigned int amount)
{
  if (hit_points_ <= amount || hit_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << "'s hit point is 0." << std::endl;
    hit_points_ = 0;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " take damage " << amount << std::endl;
    hit_points_ -= amount;
  }
}

void FragTrap::beRepaired(unsigned int amount)
{
  if (hit_points_ == 0 || energy_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " can't do anything." << std::endl;
    return;
  }
  else if (hit_points_ == kMaxHitPoints) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << "'s hit point is full." << std::endl;
    return;
  }
  else if (hit_points_ + amount > kMaxHitPoints) {
    hit_points_ = kMaxHitPoints;
    std::cout << "[ " << kRobotType << " ] "
              << "Max hit points is " << kMaxHitPoints
              << ". You are already full." << std::endl;
  }
  else {
    hit_points_ += amount;
    std::cout << "[ " << kRobotType << " ] "
              << name_ << " gets " << amount
              << " hit points back. Total : " << hit_points_ << std::endl;
  }
  energy_points_--;
}

void FragTrap::highFivesGuys(void) {
  if (hit_points_ == 0) {
    std::cout << "[ " << kRobotType << " ] "
              << name_ << "dosn't do the high five."
              << "Because he is dead." << std::endl;
  }
  else {
    std::cout << "[ " << kRobotType << " ] "
              << "I'm " << name_ << ". Let's high five!" << std::endl;
  }
}
