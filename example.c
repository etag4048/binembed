#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "resources.h"

void ls_resources(void)
{
	int i;

	for (i = 0; i < resource_count; i++) {
		fprintf(stdout, "%d\t%s\n", resources[i].size, resources[i].path);
	}

}

void pr_resource(int i)
{
	char *content;

	content = malloc(resources[i].size + 1);
	memcpy(content, resources[i].data, resources[i].size);
	content[resources[i].size] = '\0';

	fprintf(stderr, "path: %s\n", resources[i].path);
	fprintf(stderr, "size of resource: %d\n", resources[i].size);

	fprintf(stdout, "%s", content);

	free(content);

}

int main(int argc, char **argv)
{

	char *path;
	int i;

	if (argc == 1) {
		ls_resources();
		exit(0);
	}

	path = argv[1];

	for (i = 0; i < resource_count; i++) {
		if (strncmp(resources[i].path, path, strlen(path)) == 0) {

			pr_resource(i);
			exit(0);
		}
	}

	fprintf(stderr, "resource not found: '%s'\n", path);
	exit(1);
}
