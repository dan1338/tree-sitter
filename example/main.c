#include <stdio.h>
#include <tree_sitter/api.h>

extern TSLanguage *tree_sitter_c(void);

static size_t text_size = 0;
static char text[0x4000];

void
read_file(const char *path)
{
	// quick & dirty
	FILE *fp = fopen(path, "r");
	text_size = fread(text, 1, sizeof text, fp);
	fclose(fp);
}

int
main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	const char *path = argv[argc - 1];

	TSParser *parser = ts_parser_new();
	TSLanguage *lang = tree_sitter_c();
	ts_parser_set_language(parser, lang);

	read_file(path);

	TSTree *tree = ts_parser_parse_string(parser, 0, text, text_size);
	TSNode root = ts_tree_root_node(tree);

	puts(ts_node_string(root));

	return 0;
}

