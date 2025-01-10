/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:13:24 by miguel            #+#    #+#             */
/*   Updated: 2025/01/10 17:01:15 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "../../tester/include/42Tester.h"

void main(void)
{
	TEST("SmokeTest - Fail", {
		assert_fail("Should Fail");
	});

	TEST("SmokeTest - Pass", {
		assert_true("Should Pass");
	})
}