#include "shell.h"

/**
 * get_history_file -Function that  gets the history file
 * @info: is parameter struct
 *
 * Return: allocated string with  history file
 */

char *get_history_file(info_t *info)
{
	char *buff, *dr;

	dr = _getenv(info, "HOME=");
	if (!dr)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dr) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dr);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * write_history - function that create file, or appends existing files
 * @info: is the parameter struct
 *
 * Return: 1 on success, otherwise -1
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filenm = get_history_file(info);
	list_t *node = NULL;

	if (!filenm)
		return (-1);

	fd = open(filenm, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filenm);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - Function that reads history from file
 * @info:Is the parameter struct
 *
 * Return: History count on success, 0 opposite
 */
int read_history(info_t *info)
{
	int j, last = 0, linecount = 0;
	ssize_t d, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filenam = get_history_file(info);

	if (!filenam)
		return (0);

	d = open(filenam, O_RDONLY);
	free(filenam);
	if (d == -1)
		return (0);
	if (!fstat(d, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(d, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(d);
	for (j = 0; j < fsize; j++)
		if (buf[j] == '\n')
		{
			buf[j] = 0;
			build_history_list(info, buf + last, linecount++);
			last = j + 1;
		}
	if (last != j)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - function that adds entry to  history linked list
 * @info: structure that has possible arguments. maintain
 * @buff: Buffer
 * @linecount1: history linecount
 * Return: always 0
 */
int build_history_list(info_t *info, char *buff, int linecount1)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buff, linecount1);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - function that renumbers history after changes
 * @info: sstructure that has arguments
 * Return: The new history count
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int pk = 0;

	while (node)
	{
		node->num = pk++;
		node = node->next;
	}
	return (info->histcount = pk);
}
