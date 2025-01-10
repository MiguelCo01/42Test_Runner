/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42Tester.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimelo-d <mimelo-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:40:10 by miguel            #+#    #+#             */
/*   Updated: 2025/01/10 22:04:39 by mimelo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_42_H
# define TESTER_42_H

# define TEST(test_name, test) do { test } while(0);

void assert_fail(char *msg);
void assert_true(char * msg);

#endif