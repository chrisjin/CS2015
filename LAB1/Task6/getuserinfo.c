#include <unistd.h>
#include <stdio.h>
int main()
{
	char username[250];
	getlogin_r(username, 250);
	printf("The User name is %s\n", username);
	printf("The User ID is %d\n", getuid());
	printf("The Effective User ID is %d\n", geteuid());
	return 0;

}
