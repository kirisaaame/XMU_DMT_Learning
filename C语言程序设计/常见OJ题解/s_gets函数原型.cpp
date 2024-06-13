char* s_gets(char* st, int n)
{
	char * ret_val;
	char * find;
	ret_val=fgets(st,n,stdin);
	if (ret_val)
	{
		find=strchr(st,'\n');
		if (find)
		*find='\0';
		else 
			while(getchar()!='\n')
				continue;
	}
	return ret_val;