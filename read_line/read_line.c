#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "read_line.h"

#define ALLOC_SIZE (256)

static char	*st_buf = NULL;
static int	st_buf_size = 0;
static int	st_used_buf_size = 0;

// なぜchはint型? 多分ascii以外の文字コードを想定しているため
static ReadLineStatus add_ch(int ch);
void free_buffer(void);
ReadLineStatus read_line(FILE *fp, char **line);

static ReadLineStatus add_ch(int ch)
{

	assert(st_buf_size >= st_used_buf_size);
	if (st_buf_size == st_used_buf_size) {
		char *tmp;
		tmp = realloc(st_buf, sizeof(char) * (st_buf_size + ALLOC_SIZE));
		if (tmp == NULL)
			return READ_LINE_OUT_OF_MEMORY;
		st_buf = tmp;
		st_buf_size += ALLOC_SIZE;
	}
	st_buf[st_used_buf_size++] = ch;
	return READ_LINE_SUCCESS;
}

void free_buffer(void)
{
	free(st_buf);
	st_buf = NULL;
	st_buf_size = 0;
	st_used_buf_size = 0;
}

ReadLineStatus read_line(FILE *fp, char **line)
{
	int ch;
	ReadLineStatus status = READ_LINE_SUCCESS;

	st_used_buf_size = 0;
	st_buf_size = 0;
	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') {
			status = add_ch('\0');
			if (status != READ_LINE_SUCCESS)
				goto FUNC_END;
			break;
		}
		status = add_ch(ch);
		if (status != READ_LINE_SUCCESS)
			goto FUNC_END;
	}

	if (ch == EOF) {
		if (st_used_buf_size > 0) {
			status = add_ch('\0');
			if (status != READ_LINE_SUCCESS)
				goto FUNC_END;
		} else {
			status = READ_LINE_EOF;
			goto FUNC_END;
		}
	}

	*line = malloc(sizeof(char) * st_used_buf_size);
	if (line == NULL) {
		status = READ_LINE_OUT_OF_MEMORY;
		goto FUNC_END;
	}

	strcpy(*line, st_buf);

FUNC_END:
	if (!(status == READ_LINE_SUCCESS || status == READ_LINE_EOF))
		free_buffer();
	return status;
}
