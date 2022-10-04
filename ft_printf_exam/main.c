#include <stdio.h>

int	ft_printf(char const *format, ...);

int main() {
	char	*ptr;
	int		printed;

	ptr = NULL;
	printed = 0;

	char *word;
	word = "word";

	printf("|%12.11d|\n", -2147483648);
	printed = ft_printf("|%12.11d|\n", -2147483648);
	printf("%d\n", printed);
	ft_printf("========== STRING TESTS ==========\n");
	printed = ft_printf("Test 1 - Hello|%10.6s|World\n", ptr);
	printf("%d\n", printed);

	printed = ft_printf("Test 2 - test%", ptr);
	printf("\n%d\n", printed);

	printed = ft_printf("Test 3 - Hello|%s|World\n", ptr);
	printf("DEBUG - Hello|%s|World\n", ptr);//------------------------------

	//printf("\ntest%O\n", ptr);

	ft_printf("========== Decimal TESTS ==========\n");
	printed = ft_printf("Test 1 - Hello|%10.5d|World\n", 42);
	printf("%d\n", printed);

	ft_printf("========== Hex TESTS ==========\n");
	printed = ft_printf("Test 1 - Hello|%10.5x|World\n", 365);
	printf("%d\n", printed);
	return 0;
}
