/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 01:15:06 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 19:07:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define UN_BOTTO 100
#define TRUE 1
#define FALSE 0

static char	ft_uppercharacter(unsigned int index, char c)
{
	if (index)
		++index;
    if ((c >= 'a') && (c <= 'z'))
        return (c - 32);
    return (c);
}

static void	del(void *data)
{
	if (data)
	{
		free(data);
		data = NULL;
	}
}

void	ft_toupper_custom1(void	*string)
{
    char	*pointer;

	pointer = (char *)string;
	while ((pointer) && (*pointer))
	{
    	*pointer = ft_toupper(*pointer);
		++pointer;
	}
}

void	*ft_toupper_custom2(void *string)
{
	char	*pointer;

	pointer = (char *)string;
	while ((pointer) && (*pointer))
	{
    	*pointer = ft_toupper(*pointer);
		++pointer;
	}
	return (string);
}

int	main(void)
{
	int	error;

	error = 0;
	//#ft_atoi
	printf("FT_ATOI: ");
	char    str[30] = "  \f\n\r \t \v ++-2147483646";
	char    str2[30] = "  \f\n\r \t \v -2147483647";
	char    str3[30] = "  \f\n\r \t \v +2147483646";
	char    str4[30] = "  \f\n\r \t \v -0";
	char    str5[30] = "  \f\n\r \t \v 8";

    if (atoi(str) != ft_atoi(str))
	{
		printf("\nERROR: expected \"%d\", ", atoi(str));
		printf("got \"%d\"\n", ft_atoi(str));
		++error;
	}
	if (atoi(str2) != ft_atoi(str2))
	{
		printf("\nERROR: expected \"%d\", ", atoi(str2));
		printf("got \"%d\"\n", ft_atoi(str2));
		++error;
	}
	if (atoi(str3) != ft_atoi(str3))
	{
		printf("\nERROR: expected \"%d\", ", atoi(str3));
		printf("got \"%d\"\n", ft_atoi(str3));
		++error;
	}
	if (atoi(str4) != ft_atoi(str4))
	{
		printf("\nERROR: expected \"%d\", ", atoi(str4));
		printf("got \"%d\"\n", ft_atoi(str4));
		++error;
	}
	if (atoi(str5) != ft_atoi(str5))
	{
		printf("\nERROR: expected \"%d\", ", atoi(str5));
		printf("got \"%d\"\n", ft_atoi(str5));
		++error;
	}
	if (error == 0)
		printf("OK!\n");
	printf("\n");
	//#ft_bzero
	printf("FT_BZERO: ");
	// Test 1: Zero size (should not change anything)
    char str6[20] = "Hello, World!";
    ft_bzero(str6, 0);
    if (strncmp(str6, "Hello, World!", 20) != 0) {
        printf("\nERROR: expected \"Hello, World!\", got \"%s\"\n", str6);
        ++error;
    }

    // Test 2: Normal case (n = 5)
    char str7[20] = "Hello, World!";
    ft_bzero(str7, 5);
    if (strncmp(str7, "\0\0\0\0\0World!", 20) != 0) {
        printf("\nERROR: expected \"\\0\\0\\0\\0\\0World!\", got \"%s\"\n", str7);
        ++error;
    }

    // Test 3: Large size, overwriting the entire array
    char str8[20] = "Non-zero string!";
    ft_bzero(str8, 20);
    if (strncmp(str8, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20) != 0) {
        printf("\nERROR: expected zeroed array, got \"%s\"\n", str8);
        ++error;
    }

    // Test 4: Setting part of the memory to zero (starting in the middle)
    char str9[20] = "This is a test!";
    ft_bzero(str9 + 5, 10); // Set starting from the 6th character (index 5)
    if (strncmp(str9, "This \0\0\0\0\0\0\0\0\0test!", 20) != 0) {
        printf("\nERROR: expected \"This \\0\\0\\0\\0\\0\\0\\0\\0\\0test!\", got \"%s\"\n", str9);
        ++error;
    }

    // Test 5: Large n value (n > size of array)
    char str10[10] = "Some data!";
    ft_bzero(str10, 100); // n exceeds the size of str5
    if (strncmp(str10, "\0\0\0\0\0\0\0\0\0\0", 10) != 0) {
        printf("\nERROR: expected fully zeroed array, got \"%s\"\n", str10);
        ++error;
    }

    // Test 6: Empty array (should remain zeroed)
    char str11[0]; // Empty string (no memory)
    ft_bzero(str11, 0); // Nothing to change
    // No way to check the contents, so no assertion for this case.
	
	if (error == 0)
		printf("OK!\n");
	printf("\n");
	//#ft_calloc
    printf("FT_CALLOC: ");

    // Test 1: Zero elements (nmemb = 0)
    void *ptr1 = ft_calloc(0, 10);
    if (ptr1 != NULL) {
        printf("\nERROR: expected NULL for (nmemb = 0, size = 10), got non-NULL\n");
        ++error;
    }

    // Test 2: Zero size (size = 0)
    void *ptr2 = ft_calloc(10, 0);
    if (ptr2 != NULL) {
        printf("\nERROR: expected NULL for (nmemb = 10, size = 0), got non-NULL\n");
        ++error;
    }

    // Test 3: Normal case (nmemb = 5, size = 4)
    int *ptr3 = ft_calloc(5, sizeof(int));
    if (ptr3 == NULL) {
        printf("\nERROR: allocation failed for (nmemb = 5, size = 4)\n");
        ++error;
    } else {
        for (int i = 0; i < 5; i++) {
            if (ptr3[i] != 0) {
                printf("\nERROR: memory not zeroed, element %d = %d\n", i, ptr3[i]);
                ++error;
                break;
            }
        }
        free(ptr3);
    }

    // Test 4: Large allocation (nmemb = 100, size = 1000)
    void *ptr4 = ft_calloc(100, 1000);
    if (ptr4 == NULL) {
        printf("\nERROR: large allocation failed for (nmemb = 100, size = 1000)\n");
        ++error;
    } else {
        free(ptr4);
    }

    // Test 5: Multiplication overflow (nmemb * size > SIZE_MAX)
    void *ptr5 = ft_calloc((size_t)-1 / 2 + 1, 2); // Intentionally overflows
    if (ptr5 != NULL) {
        printf("\nERROR: expected NULL for overflow (nmemb * size > SIZE_MAX), got non-NULL\n");
        ++error;
        free(ptr5); // Avoid memory leak
    }

    // Test 6: Edge case (allocation of 1 element of size 1)
    char *ptr6 = ft_calloc(1, 1);
    if (ptr6 == NULL) {
        printf("\nERROR: allocation failed for (nmemb = 1, size = 1)\n");
        ++error;
    } else if (*ptr6 != 0) {
        printf("\nERROR: memory not zeroed, got value %d\n", *ptr6);
        ++error;
        free(ptr6);
    } else {
        free(ptr6);
    }

    // Test 7: Double allocation and comparison
    void *ptr7a = ft_calloc(10, sizeof(char));
    void *ptr7b = calloc(10, sizeof(char)); // Standard calloc for comparison
    if (ptr7a == NULL || ptr7b == NULL) {
        printf("\nERROR: allocation failed for double test\n");
        ++error;
    } else if (memcmp(ptr7a, ptr7b, 10 * sizeof(char)) != 0) {
        printf("\nERROR: memory content mismatch between ft_calloc and calloc\n");
        ++error;
    }
    free(ptr7a);
    free(ptr7b);

    if (error == 0)
        printf("OK!\n");
    printf("\n");
	error = 0;
	//#ft_itoa
	printf("FT_ITOA: ");
	int		numitoa;
	
	numitoa = 7;
	if (strncmp(ft_itoa(numitoa), "7", UN_BOTTO) != 0)
	{
		printf("\nERROR: expected 7, get %s\n", ft_itoa(numitoa));
		++error;
	}
	numitoa = 0;
	if (strncmp(ft_itoa(numitoa), "0", UN_BOTTO) != 0)
	{
		printf("\nERROR: expected 0, get %s\n", ft_itoa(numitoa));
		++error;
	}
	numitoa = -7;
	if (strncmp(ft_itoa(numitoa), "-7", UN_BOTTO) != 0)
	{
		printf("\nERROR: expected -7, get %s\n", ft_itoa(numitoa));
		++error;
	}
	numitoa = 2147483647;
	if (strncmp(ft_itoa(numitoa), "2147483647", UN_BOTTO) != 0)
	{
		printf("\nERROR: expected 2147483647, get %s\n", ft_itoa(numitoa));
		++error;
	}
	numitoa = -2147483648;
	if (strncmp(ft_itoa(numitoa), "-2147483648", UN_BOTTO) != 0)
	{
		printf("\nERROR: expected -2147483648, get %s\n", ft_itoa(numitoa));
		++error;
	}
	if (error == 0)
        printf("OK!\n");
    printf("\n");
	error = 0;
	//#ft_is
	printf("FT_IS... functions: ");
	char	c_is;

	c_is = '^';
	if (ft_isdigit((int)c_is) == TRUE)
	{
		printf("\nERROR: %c recognized as digit\n", c_is);
		++error;
	}
	if (ft_isalpha((int)c_is) == TRUE)
	{
		printf("\nERROR: %c recognized as alpha\n", c_is);
		++error;
	}
	if (ft_isalnum((int)c_is) == TRUE)
	{
		printf("\nERROR: %c recognized as alphanum\n", c_is);
		++error;
	}
	if (ft_isprint((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as not printable\n", c_is);
		++error;
	}
	if (ft_isascii((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as not ascii\n", c_is);
		++error;
	}
	c_is = '6';
	if (ft_isdigit((int)c_is) == FALSE)
	{
		printf("\nERROR: %c NOT recognized as digit\n", c_is);
		++error;
	}
	if (ft_isalpha((int)c_is) == TRUE)
	{
		printf("\nERROR: %c recognized as alpha\n", c_is);
		++error;
	}
	if (ft_isalnum((int)c_is) == FALSE)
	{
		printf("\nERROR: %c NOT recognized as alphanum\n", c_is);
		++error;
	}
	if (ft_isprint((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as NOT printable\n", c_is);
		++error;
	}
	if (ft_isascii((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as NOT ascii\n", c_is);
		++error;
	}
	c_is = 'E';
	if (ft_isdigit((int)c_is) == TRUE)
	{
		printf("\nERROR: %c recognized as digit\n", c_is);
		++error;
	}
	if (ft_isalpha((int)c_is) == FALSE)
	{
		printf("\nERROR: %c NOT recognized as alpha\n", c_is);
		++error;
	}
	if (ft_isalnum((int)c_is) == FALSE)
	{
		printf("\nERROR: %c NOT recognized as alphanum\n", c_is);
		++error;
	}
	if (ft_isprint((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as NOT printable\n", c_is);
		++error;
	}
	if (ft_isascii((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as NOT ascii\n", c_is);
		++error;
	}
	c_is = 'a';
	if (ft_isdigit((int)c_is) == TRUE)
	{
		printf("\nERROR: %c recognized as digit\n", c_is);
		++error;
	}
	if (ft_isalpha((int)c_is) == FALSE)
	{
		printf("\nERROR: %c NOT recognized as alpha\n", c_is);
		++error;
	}
	if (ft_isalnum((int)c_is) == FALSE)
	{
		printf("\nERROR: %c NOT recognized as alphanum\n", c_is);
		++error;
	}
	if (ft_isprint((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as NOT printable\n", c_is);
		++error;
	}
	if (ft_isascii((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as NOT ascii\n", c_is);
		++error;
	}
	c_is = 127;
	if (ft_isdigit((int)c_is) == TRUE)
	{
		printf("\nERROR: %d recognized as digit\n", c_is);
		++error;
	}
	if (ft_isalpha((int)c_is) == TRUE)
	{
		printf("\nERROR: %d recognized as alpha\n", c_is);
		++error;
	}
	if (ft_isalnum((int)c_is) == TRUE)
	{
		printf("\nERROR: %d NOT recognized as alphanum\n", c_is);
		++error;
	}
	if (ft_isprint((int)c_is) == TRUE)
	{
		printf("\nERROR: %d recognized as printable\n", c_is);
		++error;
	}
	if (ft_isascii((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as NOT ascii\n", c_is);
		++error;
	}
	c_is = 31;
	if (ft_isdigit((int)c_is) == TRUE)
	{
		printf("\nERROR: %d recognized as digit\n", c_is);
		++error;
	}
	if (ft_isalpha((int)c_is) == TRUE)
	{
		printf("\nERROR: %d recognized as alpha\n", c_is);
		++error;
	}
	if (ft_isalnum((int)c_is) == TRUE)
	{
		printf("\nERROR: %d NOT recognized as alphanum\n", c_is);
		++error;
	}
	if (ft_isprint((int)c_is) == TRUE)
	{
		printf("\nERROR: %d recognized as printable\n", c_is);
		++error;
	}
	if (ft_isascii((int)c_is) == FALSE)
	{
		printf("\nERROR: %d recognized as NOT ascii\n", c_is);
		++error;
	}
	if (ft_isdigit(500) == TRUE)
	{
		printf("\nERROR: %d recognized as digit\n", 500);
		++error;
	}
	if (ft_isalpha(500) == TRUE)
	{
		printf("\nERROR: %d recognized as alpha\n", 500);
		++error;
	}
	if (ft_isalnum(500) == TRUE)
	{
		printf("\nERROR: %d recognized as alphanum\n", 500);
		++error;
	}
	if (ft_isprint(500) == TRUE)
	{
		printf("\nERROR: %d recognized as printable\n", 500);
		++error;
	}
	if (ft_isascii(500) == TRUE)
	{
		printf("\nERROR: %d recognized as ascii\n", 500);
		++error;
	}
	if (error == 0)
        printf("OK!\n");
    printf("\n");
	error = 0;
	//#ft_memchr
    printf("FT_MEMCHR: ");

    // Test 1: Basic case (c in middle of string)
    char str1memchr[] = "Hello, World!";
    char *result1memchr = ft_memchr(str1memchr, 'W', strlen(str1memchr));
    if (result1memchr != memchr(str1memchr, 'W', strlen(str1memchr))) {
        printf("\nERROR: expected \"%p\", got \"%p\"\n", memchr(str1memchr, 'W', strlen(str1memchr)), result1memchr);
        ++error;
    }

    // Test 2: Character not present
    char str2memchr[] = "abcdef";
    char *result2memchr = ft_memchr(str2, 'z', strlen(str2memchr));
    if (result2memchr != memchr(str2, 'z', strlen(str2memchr))) {
        printf("\nERROR: expected NULL, got \"%p\"\n", result2memchr);
        ++error;
    }

    // Test 3: Character at the beginning
    char str3memchr[] = "abcdef";
    char *result3memchr = ft_memchr(str3memchr, 'a', strlen(str3memchr));
    if (result3memchr != memchr(str3, 'a', strlen(str3memchr))) {
        printf("\nERROR: expected \"%p\", got \"%p\"\n", memchr(str3memchr, 'a', strlen(str3memchr)), result3memchr);
        ++error;
    }

    // Test 4: Character at the end
    char str4memchr[] = "abcdef";
    char *result4memchr = ft_memchr(str4, 'f', strlen(str4memchr));
    if (result4memchr != memchr(str4, 'f', strlen(str4memchr))) {
        printf("\nERROR: expected \"%p\", got \"%p\"\n", memchr(str4memchr, 'f', strlen(str4memchr)), result4memchr);
        ++error;
    }

    // Test 5: Searching in zero bytes (n = 0)
    char str5memchr[] = "abcdef";
    char *result5memchr = ft_memchr(str5memchr, 'a', 0);
    if (result5memchr != memchr(str5memchr, 'a', 0)) {
        printf("\nERROR: expected NULL, got \"%p\"\n", result5memchr);
        ++error;
    }

    // Test 6: Large memory block
    char str6memchr[100] = {0};
    str6memchr[50] = 'X';
    char *result6memchr = ft_memchr(str6memchr, 'X', 100);
    if (result6memchr != memchr(str6memchr, 'X', 100)) {
        printf("\nERROR: expected \"%p\", got \"%p\"\n", memchr(str6memchr, 'X', 100), result6memchr);
        ++error;
    }

    // Test 7: Non-character byte value
    unsigned char str7memchr[] = {0, 1, 2, 3, 255};
    void *result7memchr = ft_memchr(str7memchr, 255, 5);
    if (result7memchr != memchr(str7memchr, 255, 5)) {
        printf("\nERROR: expected \"%p\", got \"%p\"\n", memchr(str7memchr, 255, 5), result7memchr);
        ++error;
    }

    if (error == 0)
        printf("OK!\n");
    printf("\n");
	//#ft_lst
	char	*data;
	t_list	*node;
	t_list	*lstmap_node;
	t_list	*node_pointer;
	t_list	*new_pointer;
	size_t	size_of_list;
	size_t	counter;

	size_of_list = 20;
	counter = 0;
	data = (char *)malloc(UN_BOTTO);
	if (!data)
		return (2);
	ft_strlcpy(data, (const char *)"mega_rayquaza e gabibbo", UN_BOTTO);
	if (counter < size_of_list)
		node = ft_lstnew((void *)data);
	else
		node = NULL;
	if (!node)
	{
		free(data);
		data = NULL;
		return (2);
	}
	node_pointer = node;
	++counter;
	while ((counter < size_of_list) && (node_pointer))
	{
		new_pointer = ft_lstnew((void *)data);
		if (new_pointer)
		{
			ft_lstadd_front(&node_pointer, new_pointer);
		}
		else
		{
			break ;
		}
		node_pointer = new_pointer;
		++counter;
	}
	node_pointer->next = NULL;
	printf("Contenuto: %s", (char *)node->content);
	printf("\nNext: %p", node->next);
	printf("\nSIZE: %d", ft_lstsize(node));
	ft_strlcpy(node_pointer->content, (char *)"Sono l'ultimo!", UN_BOTTO);
	printf("\nLAST: %s\n", (char *)ft_lstlast(node)->content);
	ft_lstiter(node, *ft_toupper_custom1);
	node_pointer = node;
	counter = 1;
	while (node_pointer->next)
	{
		printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, (char *)node_pointer->content);
		node_pointer = node_pointer->next;
		++counter;
	}
	printf("\nLSTITER(To_upper) node n. %ld: %s\n", counter, (char *)node_pointer->content);
	lstmap_node = ft_lstmap(node, *ft_toupper_custom2, *del);
	node_pointer = lstmap_node;
	counter = 1;
	while (node_pointer->next)
	{
		printf("\nLSTMAP(To_upper) node n. %ld: %s\n", counter, (char *)node_pointer->content);
		node_pointer = node_pointer->next;
		++counter;
	}
	printf("\nLSTMAP(To_upper) node n. %ld: %s\n", counter, (char *)node_pointer->content);
	while ((node->next))
	{
		node_pointer = node;
		node = node->next;
		ft_lstdelone(node_pointer, *del);
	}
	ft_lstdelone(node, *del);
	while ((lstmap_node->next))
	{
		node_pointer = lstmap_node;
		lstmap_node = lstmap_node->next;
		ft_lstdelone(node_pointer, *del);
	}
	ft_lstdelone(lstmap_node, *del);
	free(data);
	data = NULL;
	//#ft_strmapi
	char	*s = "JolL7y";

	printf("\nStringa iniziale: \"%s\"\n", s);
	s = ft_strmapi(s, *ft_uppercharacter);
	printf("Risultato: \"%s\"\n", s);
	free(s);
	//
	int		fd;

	fd = open("testoh.txt", O_RDWR);
	if (fd == -1)
		return (1);
	ft_putstr_fd("Mi trovo in testo.h!", fd);
	ft_putnbr_fd(52352, fd);
	close(fd);
	return (0);
}
