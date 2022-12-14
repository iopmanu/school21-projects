#include "s21_stack.h"

enum STACK_CODES stack_ctor(stk_t *stk, enum DATA_INFO _elements_type) {
    stk->top = NULL;
    stk->elements_type = _elements_type;
    stk->elements_quantity = 0;

    return SUCCESS;
}

enum STACK_CODES create_node(enum DATA_INFO elements_type, _value_type _real_data,
                             another_type *_symbol_data, node_t *source) {
    CHECK_BAD_PTR(source, ALLOCATION_ERROR);

    if (elements_type == REAL_NUMBER_DATA) {
        source->data = _real_data;
    } else if (elements_type == SYMBOL_DATA) {
        source->symbol_data = _symbol_data;
    } else {
        CHECK(UNINITIALIZED == elements_type, INITIALIZATION_ERROR);
    }

    source->next = NULL;

    return SUCCESS;
}

enum STACK_CODES push(stk_t *stk, _value_type _real_data, another_type *_symbol_data) {
    CHECK_BAD_PTR(stk, NULL_POINTER);
    enum STACK_CODES code = SUCCESS;

    node_t *source = calloc(1, sizeof(node_t));
    code = create_node(stk->elements_type, _real_data, _symbol_data, source);
    CHECK(SUCCESS != code, code);

    source->next = stk->top;

    stk->top = source;
    stk->elements_quantity++;

    return SUCCESS;
}

_value_type pop_number_data(stk_t *stk) {
    CHECK_BAD_PTR(stk, NULL_POINTER);

    _value_type _data = stk->top->data;

    node_t *top_copy = stk->top;
    stk->top = stk->top->next;
    free(top_copy);
    stk->elements_quantity--;

    return _data;
}

another_type *top_symbol(stk_t *stk) {
    CHECK_BAD_PTR(stk, POISON_PTR);
    CHECK_BAD_PTR(stk->top, POISON_PTR);

    another_type *_data = stk->top->symbol_data;
    return _data;
}

another_type *pop_symbol_data(stk_t *stk) {
    CHECK_BAD_PTR(stk, POISON_PTR);

    another_type *_data = stk->top->symbol_data;

    node_t *top_copy = stk->top;
    stk->top = stk->top->next;
    free(top_copy);
    stk->elements_quantity--;

    return _data;
}

enum STACK_CODES stack_dtor(stk_t *stk) {
    CHECK_BAD_PTR(stk, NULL_POINTER);
    CHECK_BAD_PTR(stk->top, NULL_POINTER);

    node_t *elem = stk->top;
    node_t *next_elem = NULL;

    do {
        next_elem = elem->next;

        free(elem);

        elem = next_elem;
        next_elem = NULL;
    } while (elem != NULL);

    stk = NULL;

    return SUCCESS;
}