char	*get_next_line(int fd)
{
	static char	*line;
	char		*readl;
	char		*returnl;
	int			l;

	readl = NULL;
	line = NULL;
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	readl = ft_read_fd(fd, readl);
	l = ft_strlen(line);
	if ((line) && (l != 0))
	{
		line = ft_save_line(readl);
		printf("Line:%s", line);
		returnl = ft_get_line(readl);
		printf("Returnl:%s", returnl);
	}
	l = ft_strlen(returnl);
	if ((returnl == NULL) || (l == 0))
	{
		free(returnl);
		return (NULL);
	}
	else
		return (returnl);
}

char	*ft_get_line(char	*line)
{
	int		l1;
	int		l2;
	char	*eol;
	char	*getline;

	eol = ft_strchr(line, '\n');
	l1 = ft_strlen(line);
	if (eol)
		l2 = ft_strlen(eol + 1);
	else
		l2 = 0;
	getline = (char *)malloc ((l1 - l2 + 1) * sizeof(char));
	if (getline == NULL)
		return (NULL);
	ft_strlcpy(getline, line, (l1 - l2 + 1));
	return (getline);
}

char	*ft_save_line(char	*line)
{
	char	*eol;
	char	*saveline;

	eol = ft_strchr(line, '\n');
	saveline = ft_strjoin(eol + 1, "");
	return (saveline);
}
