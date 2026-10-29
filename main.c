/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dianasta <dianasta@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:05:47 by dianasta          #+#    #+#             */
/*   Updated: 2026/10/29 18:16:02 by dianasta         ###   ########.fr       */
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

int check_int(char *s)
{
	while (*s && *s >= '0' && *s <= '9')
		s++;
	if(!*s)
		return(atoi(s)); ///hmmm  do i need this at all?? how did atoi work
	// so atoi does work just fine here and i don't need this function at all actually mmmh 
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
	else if (argv[1] == "--bench")
		*strat = 7;// idk what to put here so typed this with the strat for a place holder... in this case we need to check again for the strategy nxt but this also must be implemented with the strat flags because we might have a bench flag afterwards too
	else
		return_error();
		/* 
		this is not correct right now but im keeping it until
		i figure out what to put here whats next is again a check for the flags again in the
		case of a bench flag or strat and then we need to check if there is the another flag shi
		but careful cuz the next flag could only be one we haven't used yeeettttt
		adn then we need to check for numbers... i think i can do that with just atoi but i need
		to wokr on it and change up some things because it needs to give me errors in some cases
		and before that shouldn't be pasing the things with ft_split?? omit the spaces and create
		new strings that are separate, but then what if i get different strings i wouldn't need this 
		shhiiiiiit idk mate how do i make this then

		so a question is when we input like ./push_swap 1 3 5 2 do 
		
		*/
	return(1);
}

// sooooo how do i figure this out actually then mmmmmmmm

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



