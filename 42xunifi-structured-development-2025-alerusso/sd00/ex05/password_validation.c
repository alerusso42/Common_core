#include "password_validation.h"



int ft_strlen(const char *c)
{
	int i;

	i = 0;
	while(c[i] != '\0')
		i++;
	return i;
	
}

int upper_case(const char *c)
{
	int i;

	i = 0;
	while(c[i] != '\0')
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
			return TRUE;
		i++;
	}
	return FALSE;
}

int lower_case(const char *c)
{
	int i;

	i = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	while(c[i] != '\0')
	{
		if (c[i] >= 'a' && c[i] <= 'z')
			return TRUE;
		i++;
	}
	return FALSE;
}
int digit(const char *c)
{
	int i;

	i = 0;
	while(c[i] != '\0')
	{
		if (c[i] >= '0' && c[i] <= '9')
			return TRUE;
		i++;
	}
	return FALSE;
}

int diff_current(const char *pre_passw, const char *c)
{
	int i;

	i = 0;
	while(c[i] != '\0')
	{
		if (c[i] - pre_passw[i] != 0)
			return TRUE;
		i++;
	}
	if (c[i] - pre_passw[i] != 0)
		return TRUE;
	return FALSE;
}

int special_char(const char *pass)
{
	int i;
	int j;
	char special[9] = "@#$%ˆ&*";

	i = 0;
	while(pass[i] != '\0')
	{
		j = 0;
		while(special[j] != 0)
		{
			if (pass[i] == special[j])
				return TRUE;
			++j;
		}
		i++;
	}
	return FALSE;
}

PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
	char		ret;
	PwStatus	data;

	ret = TRUE;
	if(diff_current(curr_pw, new_pw) == FALSE)
		ret = FALSE;
	else if(special_char(new_pw) == FALSE)
		ret = FALSE;
	else if(digit(new_pw) == FALSE)
		ret = FALSE;
	else if(upper_case(new_pw) == FALSE)
		ret = FALSE;
	else if(lower_case(new_pw) == FALSE)
		ret = FALSE;
	else if (ft_strlen(new_pw) < 8)
		ret  = FALSE;
	data.stat = ret;
	return (data);
}

// int	main(int argc, char *argv[])
// {
// 	PwStatus	data;

// 	if (argc != 3)
// 		return (1);
// 	data = validate_password(argv[1], argv[2]);
// 	return (data.stat);
// }
