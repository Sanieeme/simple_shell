int main(void)
{
	int i;
	char **tokens = _tokenize(":name=mvuyisi: surname=ndlovu: age=26 ", " : ");

	for (i = 0; tokens[i] != NULL; i++)
	{
		printf("%s\n", tokens[i]);
	}
	return (0);
}
