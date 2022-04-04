/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:10:58 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 17:26:47 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H_
# define CLAPTRAP_H_

# include <string>

class ClapTrap {
public:
  ClapTrap(void);
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &claptrap);
  ~ClapTrap(void);
  ClapTrap &operator=(const ClapTrap &claptrap);

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  const std::string &get_name(void) const;
  unsigned int get_hit_points(void) const;
  unsigned int get_energy_points(void) const;
  unsigned int get_attack_damage(void) const;

  void set_name(std::string &name);
  void set_hit_points(const unsigned int hit_point);
  void set_energy_points(const unsigned int energy_point);
  void set_attack_damage(const unsigned int attack_damage);

protected:
  std::string name_;
  unsigned int hit_points_;
  unsigned int energy_points_;
  unsigned int attack_damage_;
  unsigned int max_hit_points_;

private:
  static const unsigned int kHitPoints = 10;
  static const unsigned int kEnergyPoints = 10;
  static const unsigned int kAttackDamage = 0;
  static const std::string kRobotType;
};

#endif
