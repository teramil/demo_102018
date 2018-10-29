#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "convertor.h"


#define INT32_BUF_SIZE 15


conv_res_t convert_int_to_str(int s, char* r)
{
	char buf[INT32_BUF_SIZE];
	uint8_t cntr = INT32_BUF_SIZE - 1;
	uint8_t is_negative = 0;

	if (s < 0) {
		is_negative = 1;
		s = -s;
	}

	buf[cntr--] = '\0';

	while (s) {
		buf[cntr--] = (char)(s % 10 + (int)'0');
		s /= 10;
	}

	if (is_negative) {
		buf[cntr--] = '-';
	}

	memcpy(r, &buf[cntr+1], INT32_BUF_SIZE-cntr);
	
	return convERR_OK;
}

#if DEBUG
int main()
{
	char res[100];
	convert_int_to_str(2000023456, res);
	printf("%s\n", res);

	return 0;
}
#endif