#include <stdio.h>
#include "./include/ft_printf.h"

int	main(void)
{
	char c;

	c = 'A';
	printf("   ==> start dash%-10xend\n", 15);
	ft_printf("FT ==> start dash%-10dend\n", 15);
	printf("   ==> start plus%+dend\n", 15);
	ft_printf("FT ==> start plus%+dend\n", 15);
	printf("   ==> start zero%010dend\n", 15);
	ft_printf("FT ==> start zero%010dend\n", 15);
	printf("   ==> start space% 10dend\n", 15);
	ft_printf("FT ==> start space% 10dend\n", 15);
	printf("   ==> start plus space%+ 10dend\n", 15);
	ft_printf("FT ==> start plus space%+ 10dend\n", 15);
	printf("   ==> start dash zero%-010dend\n", 15);
	ft_printf("FT ==> start dash zero%-010dend\n", 15);
	printf("   ==> 1 %c 2 %c \n", 65, 'A');
	ft_printf("FT ==> 1 %c 2 %c \n", 65, 'A');
	printf("   ==> adresse %p \n", 10);
	ft_printf("FT ==> adresse %p \n", 10);
	printf("   ==> unsigned %u \n", 4690278);
	ft_printf("FT ==> unsigned %u \n", 4690278);

	printf("    ==> start c %c\n", c);
	ft_printf("FT  ==> start c %c\n", c);

	printf("    ==> start s %s\n", "test");
	ft_printf("FT  ==> start s %s\n", "test");

	printf("    ==> start p %p\n", c);
	ft_printf("FT  ==> start p %p\n", c);

	printf("    ==> start d %d\n", 15);
	ft_printf("FT  ==> start d %d\n", 15);

	printf("    ==> start i %i\n", 15);
	ft_printf("FT  ==> start i %i\n", 15);

	printf("    ==> start u %u \n", -1);
	ft_printf("FT  ==> start u %u \n", -1);

	printf("    ==> start x %x\n", 28);
	ft_printf("FT  ==> start x %x\n", 28);

	printf("    ==> start X %X\n", 28);
	ft_printf("FT  ==> start X %X\n", 28);

	printf("    ==> start %  %% %%\n");
	printf("    ==> start %  %% %%\n");
	ft_printf("FT  ==> start %  %% %%\n");
	printf("    ==> start c %?\n", c);
	ft_printf("FT  ==> start c %?\n", c);
	return (0);
}
