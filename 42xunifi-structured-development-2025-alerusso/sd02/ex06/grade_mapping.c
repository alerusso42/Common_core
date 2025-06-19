#include "grade_mapping.h"

static void plusminus(const char **mapped_grades, const int *scores, int size);
static void passfail(const char **mapped_grades, const int *scores, int size);
static void standard(const char **mapped_grades, const int *scores, int size);

// returns a positive integer less or equal than size
// int	random(int size)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, 0);
// 	usleep(1000);
// 	return (time.tv_usec % size);
// }

/*
	Da fare:
	controllo voto < 0 e > 100 (ASSEGNA A NULL)
*/
// int	main(void)
// {

// 	int		i;
// 	char	*grades_conv[SIZE + 1];
// 	int		grades_int[SIZE + 1];
// 	GradeMapper map = MAP;

// 	i = -1;
// 	while (++i != SIZE)
// 		grades_int[i] = random(100);
// 	map_scores(grades_int, SIZE, map, (const char **)grades_conv);
// 	i = -1;
// 	printf("[i]\t[Num]\t[Grade]\n\n");
// 	while (++i != SIZE)
// 	{
// 		printf("[%d]\t[%d]\t[%s]\n", i, grades_int[i], grades_conv[i]);
// 	}
// 	return (0);
// }

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	if(mapper == STANDARD)
	{
		standard(mapped_grades, scores, size);
	}
	else if(mapper == PLUSMINUS)
	{
		plusminus(mapped_grades, scores, size);
	}
	else if(mapper == PASSFAIL)
	{
		passfail(mapped_grades, scores, size);
	}

}

static void standard(const char **mapped_grades, const int *scores, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (scores[i] < 0 || scores[i] > 100)
			mapped_grades[i] = INVALID;
		else if (scores[i] <= F)
			mapped_grades[i] = GRADE_F;
		else if (scores[i] <= DP)
			mapped_grades[i] = GRADE_D;
		else if (scores[i] <= CP)
			mapped_grades[i] = GRADE_C;
		else if (scores[i] <= BP)
			mapped_grades[i] = GRADE_B;
		else if (scores[i] <= AP)
			mapped_grades[i] = GRADE_A;
		i++;
	}
}

static void passfail(const char **mapped_grades, const int *scores, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (scores[i] < 0 || scores[i] > 100)
			mapped_grades[i] = INVALID;
		else if (scores[i] <= F)
			mapped_grades[i] = GRADE_F;
		else if (scores[i] <= AP)
			mapped_grades[i] = GRADE_P;
		i++;
	}
}

static void plusminus(const char **mapped_grades, const int *scores, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (scores[i] < 0 || scores[i] > 100)
			mapped_grades[i] = INVALID;
		else if (scores[i] <= F)
			mapped_grades[i] = GRADE_F;
		else if (scores[i] <= DM)
			mapped_grades[i] = GRADE_DM;
		else if (scores[i] <= D)
			mapped_grades[i] = GRADE_D;
		else if (scores[i] <= DP)
			mapped_grades[i] = GRADE_DP;
		else if (scores[i] <= CM)
			mapped_grades[i] = GRADE_CM;
		else if (scores[i] <= C)
			mapped_grades[i] = GRADE_C;
		else if (scores[i] <= CP)
			mapped_grades[i] = GRADE_CP;
		else if (scores[i] <= BM)
			mapped_grades[i] = GRADE_BM;
		else if (scores[i] <= B)
			mapped_grades[i] = GRADE_B;
		else if (scores[i] <= BP)
			mapped_grades[i] = GRADE_BP;
		else if (scores[i] <= AM)
			mapped_grades[i] = GRADE_AM;
		else if (scores[i] <= A)
			mapped_grades[i] = GRADE_A;
		else if (scores[i] <= AP)
			mapped_grades[i] = GRADE_AP;
		i++;
	}
}
