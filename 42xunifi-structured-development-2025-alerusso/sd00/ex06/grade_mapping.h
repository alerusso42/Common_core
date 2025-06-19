/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_mapping.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/13 08:22:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADE_MAPPING_H
# define GRADE_MAPPING_H

# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

//Qui definisci mappa e numero di voti (generati a caso)
#define MAP PASSFAIL
#define SIZE 100

#define INVALID "Error"
#define GRADE_F "F"
#define GRADE_DM "D-"
#define GRADE_D "D"
#define GRADE_DP "D+"
#define GRADE_CM "C-"
#define GRADE_C "C"
#define GRADE_CP "C+"
#define GRADE_BM "B-"
#define GRADE_B "B"
#define GRADE_BP "B+"
#define GRADE_AM "A-"
#define GRADE_A "A"
#define GRADE_AP "A+"
#define GRADE_P "P"

enum e_grades
{
	F = 59,
	DM = 62,
	D = 66,
	DP = 69,
	CM = 72,
	C = 76,
	CP = 79,
	BM = 82,
	B = 86,
	BP = 89,
	AM = 92,
	A = 96,
	AP = 100,
};

typedef enum s_GradeMapper
{
	PLUSMINUS,
	STANDARD,
	PASSFAIL,
}GradeMapper;

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif