/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:16:09 by miguel            #+#    #+#             */
/*   Updated: 2025/01/10 17:08:25 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/42Tester.h"

# define TEST(test_name, test) do { test } while(0);

void assert_fail(char *msg)
{
	fprintf(stderr, "%s", msg);
}

void assert_true(char * msg)
{
	fprintf(stdout, "%s", msg);

	
}

