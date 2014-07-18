#include "gl.h"

#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H

#include "tack.h"

#include <stdbool.h>
#include <stdint.h>

#define DEFAULT_DISPLAYLIST_CAPACITY 16

typedef struct {
    bool open;
    tack_t calls;
} displaylist_t;

extern displaylist_t *dl_alloc();
extern void dl_append(displaylist_t *dl, packed_call_t *call);
extern void dl_append_block(displaylist_t *dl, block_t *block);
extern void dl_call(displaylist_t *dl);
extern void dl_close(displaylist_t *dl);
extern void dl_decref(packed_call_t *call);
extern void dl_extend(displaylist_t *dl, displaylist_t *append);
extern void dl_free(displaylist_t *dl);
extern void dl_incref(packed_call_t *call);

#endif
