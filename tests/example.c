/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimelo-d <mimelo-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:13:24 by miguel            #+#    #+#             */
/*   Updated: 2025/01/10 21:52:25 by mimelo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "include/42Tester.h"

int main(void)
{
	TEST("SmokeTest - Fail", {
		assert_fail("Should Fail");
	});

	TEST("SmokeTest - Pass", {
		assert_true("Should Pass");
	})
	return (0);
}