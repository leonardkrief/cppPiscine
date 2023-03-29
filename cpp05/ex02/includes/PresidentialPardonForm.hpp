/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:30:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/28 18:20:21 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include <ostream>
# include "AForm.hpp"

// Required grades: sign 25, exec 5
class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm( const std::string& target );
        PresidentialPardonForm( const PresidentialPardonForm& s );
        ~PresidentialPardonForm();

        PresidentialPardonForm& operator=( const PresidentialPardonForm& f );

        bool execute(Bureaucrat const & executor) const;
};

# define PARDON_MESSAGE "\n    ["\
      << this->getTarget() << "] has been pardoned by Zaphod Beeblebrox\n\
    Shout out to [" << executor.getName() << "]\n"

#endif