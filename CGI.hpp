/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:26:19 by akarafi           #+#    #+#             */
/*   Updated: 2022/09/03 12:38:27 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HPP
# define CGI_HPP

#include "Request.hpp"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef std::map<std::string, std::string>::const_iterator  map_iterator;
typedef std::vector<std::pair<std::string, std::string> >    vector_string_string;

class CGI
{
    private:
        std::map<std::string, std::string>  _env;
        Request     const                   &_request;
        std::string const                   &_cgi_path;
        std::string const                   &_file;
        std::string                         _content;
        int                                 _status;
    public:
        CGI(Request const &_req, std::string const &_file_path, std::string const &_fast_cgi_path);
        ~CGI();
        std::string _get_content() const;
        int         _get_status() const;
    
    private:
        void        _set_content();
        void        _set_env_variables();
        std::string _get_header(std::string const &) const;
        char        **_get_env_array() const;
};

#endif
