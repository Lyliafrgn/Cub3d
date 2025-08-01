/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:35:21 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/01 17:07:31 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

typedef struct s_global	t_global;
typedef struct s_map	t_map;

typedef struct s_parsing
{
	bool	empty; //empty line
	int		map; //map line : init 0, 1 = true, -1 = map already parsed
	bool	no; //texture line : init false, true = already parsed
	bool	so;
	bool	we;
	bool	ea;
	bool	roof; //roof line : init false, true = already parsed
	bool	ceilling;
}	t_pars;

int		parse_map_root(t_global *data, char *file_name);

/// Lines processing
int		process_line(t_global *data, t_map *map, char *line);
int		process_map_line(t_global *data, t_map *map, char *line);
int		process_colore_line(t_global *data, char *line);
int		process_texture_line(t_global *data, char *line);


/////////UTILS/////////

//MAPS
/// lines
int		is_permited_char_for_map(char c);
bool	start_with_one(char *line);
bool	all_line_is_one(char *line);
bool	is_valide_map_line(char *line);
bool	line_is_only_spaces(char *line);
bool	finish_with_one(char *line);

//string
char	*ft_strjoin3(char *s1, char *s2, char *s3);
bool	ft_isspace(char c);

#endif
