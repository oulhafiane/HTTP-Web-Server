/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualServer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarafi <akarafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:11:48 by zoulhafi          #+#    #+#             */
/*   Updated: 2022/08/26 02:02:33 by akarafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_SERVER_HPP
# define VIRTUAL_SERVER_HPP

#include <regex>
#include "Config.hpp"

typedef std::pair <std::multimap<std::string, string_string_map>::const_iterator, std::multimap<std::string, string_string_map>::const_iterator> string_string_range_multimap;
const std::string pattern_host_port = "^([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}):([0-9]+)$";
const std::string pattern_only_ip = "^([0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}):{0,1}$";
const std::string pattern_only_port = "^:{0,1}([0-9]+)$";
const std::string pattern_location_modifier = "\\s*([=|~|*|^|~|@]*)\\s*([a-z|A-Z|\\/|.|_|\\.\\*\\^\\$\\+\\?\\(\\)\\|\\[\\]\\{\\}\\\\]+)\\s*";

class VirtualServer
{
	private:
		std::string									_host;
		int											_port;
		std::string									_root;
		std::string									_index;
		std::vector<std::string>					_server_names;
		std::map<std::string, string_string_map>	_locations;
		std::string									_allowed_methods;
		std::string									_directory_listing;
	public:
		VirtualServer(const string_string_map &server_config, const string_string_range_multimap &locations, const string_string_map &http_config);
		~VirtualServer();
		const std::string								&get_host() const;
		int												get_port() const;
		const std::string								&get_root() const;
		const std::string								&get_index() const;
		const std::vector<std::string>					&get_server_names() const;
		const std::string								&get_allowed_methods() const;
		const std::string								&get_directory_listing() const;
		std::map<std::string, string_string_map> const	&get_locations() const;
		std::string									    location_match(const std::string &location) const;
};

#endif
