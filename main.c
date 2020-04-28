#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "includes/libasm.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"


void		test_ft_strdup()
{
	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strdup("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strdup("0123456789"));
}

void		test_ft_read()
{
	int			fd;
	char		buffer[100];
	char		show[100];
	ssize_t		ret;

	printf("\x1b[32mft_read:\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '0'\x1b[0m\n");
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'open(\"Makefile\", O_RDONLY)' '' '50'\x1b[0m\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buffer, 50);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
	close(fd);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '10'\x1b[0m\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'open(\"testlib.c\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	close(fd);
	fd = open("testlib.c", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
	close(fd);
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'42' '' '10'\x1b[0m\n");
	ret = read(42, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = read(42, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\x1b[0m\n");
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	ret = read(fd, buffer, 10);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
	close(fd);
	remove("empty_file");
}

void		test_ft_write()
{
	int			fd;
	char		buffer[100];

	printf("\x1b[32mft_write :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'1' '' '0'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "", 0));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "", 0));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 4));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'1' 'toto' '2'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 2));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 2));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'1' 'toto' '40'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 40));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 40));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'1' 'NULL' '6'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, NULL, 6));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, NULL, 6));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'0' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(0, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(0, "toto", 4));
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'42' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(42, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(42, "toto", 4));
	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'-1' 'toto' '4'\x1b[0m\n");
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(-1, "toto", 4));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(-1, "toto", 4));
	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("	\x1b[34m[9]\x1b[0m \x1b[36m'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15'\x1b[0m\n");
	write(fd, "<unistd.h> toto", 15);
	ft_write(fd, "<libasm.h> toto", 15);
	close(fd);
	fd = open("ft_write_test", O_RDONLY);
	read(fd, buffer, 15);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %s\n", buffer);
	read(fd, buffer, 15);
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", buffer);
	close(fd);
	remove("ft_write_test");
}

void		test_ft_strcmp()
{
	printf("\x1b[32mft_strcmp :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("", ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'toto' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", ""));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("", "toto"));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'tototest' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("tototest", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("tototest", "toto"));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'bbbonjour' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("bbbonjour", "bbonjour"));
}

void		test_ft_strcpy()
{
	char	dst[100];

	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "0123456789"));
}

void		test_ft_strlen()
{
	printf("\x1b[32mft_strlen :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("    "));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("    "));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("0123456789"));
}

int			main(int argc, char *argv[])
{
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", ft_write(1, "toto", 4));
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", ft_write(42, "toto", 4));
	if (argc == 1 || !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	if (argc == 1 || !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
	if (argc == 1 || !strcmp(argv[1], "ft_write"))
		test_ft_write();
	if (argc == 1 || !strcmp(argv[1], "ft_read"))
		test_ft_read();
	if (argc == 1 || !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup();
	if (argc == 1 || !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();

		char *s1, *s2;
	unsigned int u1, u2;

	printf("\n________ ft_strdup ____________\n");
	char *test5 = ft_strdup("hello");
	printf("ft_strdup -> %s\n", s1 = test5);
	printf("strlen should be -> %u\n", u1 = strlen(test5));
	free(test5);
	char *test6 = strdup("hello");
	printf("strdup -> %s\n", s2 = test6);
	printf("strlen should be -> %u\n", u2 = strlen(test6));
	free(test6);
	(strcmp(s1, s2) || u1 != u2) ? printf("%sft_strdup failed%s\n", RED, RESET) :
	printf("%sft_strdup passed%s\n", GREEN, RESET);


	printf("\n________ ft_write ____________\n");
	printf("%d\n", errno);
	ft_write(1, "test\n", 5);
	printf("%d\n", errno);
	printf("%sft_write passed%s\n", GREEN, RESET);



	printf("\n________ ft_strcmp ____________\n");
    char str1[] = "abcdef", str2[] = "abCD";
    int result;

    result = ft_strcmp(str1, str2);
    printf("%s fcmp %s = %d \n", str1, str2, result);


    result = ft_strcmp(str2, str1);
    printf("%s fcmp %s = %d \n", str2, str1, result);


    result = ft_strcmp(str1, str1);
    printf("%s fcmp %s = %d \n", str1, str1, result);

    result = strcmp(str1, str2);
    printf("%s scmp %s = %d \n", str1, str2, result);


    result = strcmp(str2, str1);
    printf("%s scmp %s = %d \n", str2, str1, result);


    result = strcmp(str1, str1);
    printf("%s scmp %s = %d \n", str1, str1, result);
	printf("%sft_strcmp passed%s\n", GREEN, RESET);

	printf("\n________ ft_strcpy ____________\n");
   char src[40];
   char dest[100];
   char src2[40];
   char dest2[100];
  
   memset(dest, '\0', sizeof(dest));
   ft_strcpy(src, "Copied using ft_strcpy");
   ft_strcpy(dest, src);

   printf("Final copied string : %s\n", dest);
   
   memset(dest2, '\0', sizeof(dest2));
   strcpy(src2, "Copied using strcpy");
   strcpy(dest2, src2);

   printf("Final copied string : %s\n", dest2);

	printf("%sft_strcpy passed%s\n", GREEN, RESET);
   return(0);
}
