#include <dirent.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ls(char *d) {
	struct dirent *de;
	DIR *dr;

	if ((dr = opendir(d)) == NULL) {
		perror("could not open current directory");
		exit(EXIT_FAILURE);
	}

	while ((de = readdir(dr)) != NULL) {
		if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, ".."))
			continue;

		char buf[256];
		strcpy(buf, d);
		strcat(buf, "/");
		strcat(buf, de->d_name);

		printf("%s\n", buf);

		if (de->d_type == DT_DIR) {
			ls(buf);
		}
	}

	closedir(dr);
}

int main() {
	ls(".");

	return 0;
}
