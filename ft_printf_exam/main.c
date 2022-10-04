#include <stdio.h>

int	ft_printf(char const *format, ...);
int	ft_printfV2(char const *format, ...);

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

	








	ft_printfV2("========== V2 tests ==========\n");

	ft_printfV2("========== Decimal TESTS ==========\n");

	printf("Test 1 - Hello|%d|World\n", 42);
	printed = ft_printfV2("Test 1 - Hello|%d|World\n", 42);
	printf("%d\n", printed);

	printf("Test 2 - Hello|%d|World\n", 0);
	printed = ft_printfV2("Test 2 - Hello|%d|World\n", 0);
	printf("%d\n", printed);

	printf("Test 3 - Hello|%d|World\n", 2147483647);
	printed = ft_printfV2("Test 3 - Hello|%d|World\n", 2147483647);
	printf("%d\n", printed);

	printf("Test 4 - Hello|%d|World\n", -2147483648);
	printed = ft_printfV2("Test 4 - Hello|%d|World\n", -2147483648);
	printf("%d\n", printed);

	printf("Test 5 - Hello|%0d|World\n", 0);
	printed = ft_printfV2("Test 5 - Hello|%0d|World\n", 0);
	printf("%d\n", printed);

	printf("Test 6 - Hello|%1d|World\n", 0);
	printed = ft_printfV2("Test 6 - Hello|%1d|World\n", 0);
	printf("%d\n", printed);

	printf("Test 7 - Hello|%2d|World\n", 0);
	printed = ft_printfV2("Test 7 - Hello|%2d|World\n", 0);
	printf("%d\n", printed);

	printf("Test 8 - Hello|%10.0d|World\n", 0);
	printed = ft_printfV2("Test 8 - Hello|%10.0d|World\n", 0);
	printf("%d\n", printed);

	printf("Test 9 - Hello|%10.0d|World\n", 1);
	printed = ft_printfV2("Test 9 - Hello|%10.0d|World\n", 1);
	printf("%d\n", printed);

	printf("Test 10 - Hello|%10.0d|World\n", -1);
	printed = ft_printfV2("Test 10 - Hello|%10.0d|World\n", -1);
	printf("%d\n", printed);

	printf("Test 11 - Hello|%5.4d|World\n", 1234);
	printed = ft_printfV2("Test 11 - Hello|%5.4d|World\n", 1234);
	printf("%d\n", printed);

	printf("Test 12 - Hello|%5.5d|World\n", 1234);
	printed = ft_printfV2("Test 12 - Hello|%5.5d|World\n", 1234);
	printf("%d\n", printed);

	printf("Test 13 - Hello|%5.4d|World\n", -1234);
	printed = ft_printfV2("Test 13 - Hello|%5.4d|World\n", -1234);
	printf("%d\n", printed);

	printf("Test 14 - Hello|%5.5d|World\n", -1234);
	printed = ft_printfV2("Test 14 - Hello|%5.5d|World\n", -1234);
	printf("%d\n", printed);

	printf("Test 15 - Hello|%5.6d|World\n", -1234);
	printed = ft_printfV2("Test 15 - Hello|%5.6d|World\n", -1234);
	printf("%d\n", printed);

	printf("Test 16 - Hello|%8.6d|World\n", -1234);
	printed = ft_printfV2("Test 16 - Hello|%8.6d|World\n", -1234);
	printf("%d\n", printed);

	ft_printfV2("========== Hex TESTS ==========\n");

	printf("Test 1 - Hello|%10.x|World\n", 365);
	ft_printfV2("Test 1 - Hello|%10.x|World\n", 365);

	printed = ft_printfV2("Test 2 - Hello|%10.5x|World\n", 365);
	printf("%d\n", printed);

	printf("Test 3 - Hello|%10.0x|World\n", 0);
	printed = ft_printfV2("Test 3 - Hello|%10.0x|World\n", 0);
	printf("%d\n", printed);
	return 0;
}
