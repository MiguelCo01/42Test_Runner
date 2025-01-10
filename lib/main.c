/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimelo-d <mimelo-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:16:09 by miguel            #+#    #+#             */
/*   Updated: 2025/01/10 21:53:52 by mimelo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./include/42Tester.h"

# define TEST(test_name, test) do { test } while(0);

void assert_fail(char *msg)
{
	fprintf(stderr, "%s", msg);
	exit(1);
}

void assert_true(char * msg)
{
	fprintf(stdout, "%s", msg);
}

