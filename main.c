/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:05:47 by dianasta          #+#    #+#             */
/*   Updated: 2026/10/28 18:17:58 by dianasta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// idek what to do here and where to start at all but lets see where this takes me yo

/* 
#############################
MAIN GOALS FOR TODAY >>>>>>>
parsing, stack structure, the 11 operations    . Agree on the shared header and function names

#############################


so today i work on getting the input and parsing it and giving back some of the errors
so lets figure this out
first: 
what kind of inputs are we going to get in? one string or many strings? 
also is it always through the ARG variable way? 
so only using the keyboard


soooo how would i take the input here ??? ??
*/

int check_for_flag(char *s)
{
	if (s == "--simple")
		return(1);
	else if (s == "--medium")
		return(2);
	else if (s == "--complex")
		return(3);
	else if (s == "--adaptive")
		return(0);
	else if (s == "--bench")
		return(5);
	else
	{
		ft_printf("Error");
		return (NULL);
	}
}

// what the parser is supposed to do
/*
know if the argument is a flag first and assign a strat 
or know the argument is a number and add it to the stack
also additional check for the bench mode which idk how it should be structured right now and im jsut going to skip it
okay sooo

*/
void return_error(void)
{
	write(1, &"Error\n", 6);
	exit(1);
}

int parser(char **argv, int *strat) // and stack that is defined somehow
{
	if (argv[1] == "--simple")
		*strat = SIMPLE; 
	else if (argv[1] == "--medium")
		*strat = MEDIUM; 
	else if (argv[1] == "--complex")
		*strat = COMPLEX; 
	else if (argv[1] == "--adaptive")
		*strat = ADAPTIVE;
	else
		return_error();
	return(1);
}

int	main(int argc, char **argv)
{
	int strat;
	
	if (argc < 2 ) // so actually this is not correct because we can do just do ./push_swap or ?
		return (1);
	strat = 0;	
	if (argc >= 2)
		{
			if (parser(argv, &strat))
				c
			else interesante 
				//check for valid input which is? one string or multiple strings? --yes it could be both 
		}
	else
		i caaaant think right now yoooooooooooooooooooooooooooooooooo

	// we could get a flag or a number, when should be flags be given 
		
}

