#include<stdio.h>
#include<stdint.h>
#include <netinet/in.h>
int main(int argc, char* argv[]){
	FILE *fFile;
	uint32_t sum = 0;
	char output[3]="+=";
	for(int i=1;i<=2;i++){
		fFile = fopen(argv[i], "r");
		uint32_t imsi;
		fread(&imsi, sizeof(uint32_t), 1, fFile);
		imsi = ntohl(imsi);
		sum += imsi;
		printf("%d(%#x) %c ", imsi, imsi, output[i-1]);
		fclose(fFile);
	}
	printf("%d(%#x)\n", sum, sum);
}
