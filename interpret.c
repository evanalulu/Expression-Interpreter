/* interpret.c: Traversing through parse tree to find value */

#include "prog.h"

// Conduct depth-first search to traverse through the list and evaluate parse tree
int evaluate (struct parse_node_st* node) {
    if (node->type == EX_INTVAL) {
        return node->intval.value;
    } else if (node->type == EX_OPER2) {
        int l_value = evaluate(node->oper2.left);
        int r_value = evaluate(node->oper2.right);
        switch (node->oper2.oper) {
            case OP_PLUS:
                return l_value + r_value;
                break;
            case OP_MINUS:
                return l_value - r_value;
                break;
            case OP_MULT:
                return l_value * r_value;
                break;
            case OP_DIV:
                return l_value / r_value;
                break;
            case OP_AND:
                return l_value & r_value;
                break;
            case OP_OR:
                return l_value | r_value;
                break;
            case OP_XOR:
                return l_value ^ r_value;
                break;
            case OP_LSHIFT:
                return l_value << r_value;
                break;
            case OP_RSHIFT:
                return l_value >> r_value;
                break;
        }
    } else if (node->type == EX_OPER1) {
        int operand_value = evaluate(node->oper1.operand);
        switch (node->oper1.oper) {
            case OP_MINUS:
                return -1 * operand_value;
                break;
            case OP_NOT:
                return ~operand_value;
                break;
        }
    }
}
