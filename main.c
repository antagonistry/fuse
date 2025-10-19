#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 1024 + 1
#define LINES_LENGTH 512
#define USERNAME_LENGTH 256 + 1

int main(int argc, char *argv[]) {
	char username[USERNAME_LENGTH] = "Anonymous";
	int i = 0;

	for (i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--username") == 0) {
			if (i + 1 > argc) exit(1);

			strncpy(username, argv[i + 1], USERNAME_LENGTH);
			++i;
			continue;
		}
		exit(1);
	}

	FILE *file = fopen("log", "r");
	char line[LINE_LENGTH];
	int lines = 0;

	if (!file) return 1;

	while (fgets(line, LINE_LENGTH, file) != NULL) {
		printf("%s", line);

		if (line[strlen(line) - 1] != '\n') printf("\n");
	}

	printf("\n");
	fclose(file);
	*line = '\0';

	while (1) {
		*line = '\0';
		fgets(line, LINE_LENGTH, stdin);

		char *ptr = line;
		ptr[strlen(ptr) - 1] = '\0';

		while (*ptr == ' ') ++ptr;

		if (strcmp(ptr, "@quit") == 0) break;
		if (strcmp(ptr, "@q") == 0) break;
		if (strcmp(ptr, "@exit") == 0) break;
		if (strcmp(ptr, "@e") == 0) break;
		
		if (strcmp(ptr, "@help") == 0 || strcmp(ptr, "@h") == 0) {
			printf("\nCommands\n\t@quit, @q\n\t@exit, @e\n\t@help, @h\n\n");
			continue;
		}

		if (*ptr == '\0' || *line == '\0') continue;

		if (lines >= 1 && lines < LINES_LENGTH) {
			file = fopen("log", "a");
			fprintf(file, "[%s] %s\n", username, line);
			fclose(file);
			++lines;
			continue;
		}

		file = fopen("log", "w");
		fprintf(file, "=============   Welcome to Fuse System!   =============\n");
		fprintf(file, "You can send anything to the chat, no need to register!\n\n");
		fprintf(file, "[%s] %s\n", username, line);
		fclose(file);
		++lines;
	}
	return 0;
}
