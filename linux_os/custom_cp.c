#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void copyFile(char *input, char *output)
{
	int in_o, out_o;//input, output
	int read_o;	//temp
	
	char buff[1024]; //buffer

	in_o = open(input, O_RDONLY);
	out_o = open(output, O_WRONLY | O_CREAT, S_IWUSR);
	
	while((read_o = read(in_o, buff, sizeof(buff))) > 0){
		write(out_o, buff, read_o);
	}
}

int main(int argc, char **argv)
{
	copyFile(argv[1], argv[2]);
}
