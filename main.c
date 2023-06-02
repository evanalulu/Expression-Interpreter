#include "prog.h"

void err_command() {
    printf("usage: ./project04 -e \"expr\" -b\n");
    printf("  example: ./project04 -e \"1 + 2\" -b 2\n");
    exit(-1);
}

int main(int argc, char **argv) {

    struct scan_table_st scan_table;   // table of tokens
    struct parse_table_st parse_table; // table of parse nodes
    struct parse_node_st *parse_tree;  // tree (pointers only) of parse nodes

    char input[SCAN_INPUT_LEN];
    int len;
    int base = 10;
    int width = 32;

    if (argc < 3 || argc > 7)
        err_command();

    // Find command line flags
    for (int i = 1; i < argc; i++) {
        if (!strncmp(argv[i], "-e", 3)) {
			if (!argv[i + 1])
				err_command();
			strncpy(input, argv[i + 1], SCAN_INPUT_LEN);
			len = strnlen(input, SCAN_INPUT_LEN);
			i++;
		} else if (!(strncmp(argv[i], "-b", SCAN_TOKEN_LEN))) {
            if (!argv[i + 1])
                err_command();
            base = atoi(argv[i + 1]);
            i++;
        } else if (!strncmp(argv[i], "-w", SCAN_TOKEN_LEN)) {
            if (!argv[i + 1])
                err_command();
           	width = atoi(argv[i + 1]);
           	i++;
        }
    }
    
    scan_table_init(&scan_table);
    scan_table_scan(&scan_table, input, len);

    parse_table_init(&parse_table);
    parse_tree = parse_program(&scan_table);

	// Get result
    int result = evaluate(parse_tree);

    char dest[32];
    if (base == 10) {
        printf("%d\n", result);
    } else if (base == 2) {
        printf("0b%s\n", dec_to_base(dest, result, base, width));
    } else if (base == 16) {
        printf("0x%s\n", dec_to_base(dest, result, base, width));
    } else {
        printf("Error: Invalid base");
    }

    return 0;
}
