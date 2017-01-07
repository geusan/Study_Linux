#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void copyFile(char *input, char *output)
{
	int in_o, out_o;//input, output
	int read_o;	//temp
	
	char buff[1024]; //buffer

	//open the input file
	in_o = open(input, O_RDONLY);

	//open the output file, when the output file not exist, create new one
	out_o = open(output, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	
	//copy all lines by buffer
	while((read_o = read(in_o, buff, sizeof(buff))) > 0){
		write(out_o, buff, read_o);
	}
}

int main(int argc, char **argv)
{
	//if input source not exist
	if(access(argv[1], F_OK) != 0){
		copyFile(argv[1], argv[2]);
	}else {
		//print error message
		printf("the input is not exist\n");
	}
}
