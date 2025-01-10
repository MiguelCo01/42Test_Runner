/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42Tester.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:40:10 by miguel            #+#    #+#             */
/*   Updated: 2025/01/10 17:00:47 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_42_H
# define TESTER_42_H

# define TEST(test_name, test) do { test } while(0);

void assert_fail(char *msg);
void assert_true(char * msg);

#endif