/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:30:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/28 18:20:21 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <ostream>
# include "AForm.hpp"

// Required grades: sign 72, exec 45
class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm( const std::string& target );
        RobotomyRequestForm( const RobotomyRequestForm& s );
        ~RobotomyRequestForm();

        RobotomyRequestForm& operator=( const RobotomyRequestForm& f );

        bool execute(Bureaucrat const & executor) const;
        // bool execute(Bureaucrat const & executor) const override;
};

# define ROBOTOMY_START "\n\
      * BRUCE BUFFER comes in. He doesn't even clears his throat *\n\
      aaaaand NOOOWWWWWWWWWWW !!!!!!!!!\n\
      RO... BO... TOMY !!!!    STAAAAAAAAAAARTSS !!!!!\n\
      drill... bzzz BBZzz... *squish* *squish splash* *splash*\n\
      *SPLASH* *SPLASHhhhh* *FWTT FWTT* ....... \n\n"
# define ROBOTOMY_FAILURE "\
      AAAAAAAAANNNNNNDDDD... robotomy was... a failure...\n      ["\
      << this->getTarget() << "] does not look in great shape... but...\n\
      BUT IT'S OKAYYYYY. Come back next time and TRY AGAIIINNNNNNN !!!!\n"
# define ROBOTOMY_SUCCESS "\
      AAAAAAAAANNNNNNDDDD... robotomy was... A SUUUUUCCESSSSSSSSS...\n      ["\
      << this->getTarget() << "] was ROBOTOMIZEDD like a charm.\n      "\
      << executor.getName() << " can now install a nice LLM on its mind and have a\n"\
      << "      [" << this->getTarget() << "]\
 replicant at home FORRRRRR FREEEEEE !!!!!!!\n"

#endif