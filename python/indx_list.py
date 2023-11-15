from __future__ import annotations

#  Originally, this code contained a single class with encapsulated fields,
#  but after profiling it turned out that calling ANY function from inside of a class
#  spends time comparable to one call to rand_part() function  of QuickSort algo.
#  As a result, I switched to Plain C-like structure (like in indx_list.h)

class indx_item:
    def __init__(self, indx: int):
        self.indx = indx
        self.next = None
        self.prev = None


def indx_add_next(self, indx: int) -> indx_item:
    res = indx_item(indx)
    res.next = self.next
    res.prev = self
    self.next = res
    return res


def indx_del_item(self):
    if self.prev is not None and self.next is not None:
        self.prev.next = self.next
        self.next.prev = self.prev
    elif self.next is not None:
        assert self.prev is None
        self.next.prev = None
    elif self.prev is not None:
        assert self.next is None
        self.prev.next = None
    else:
        assert self.prev is None
        assert self.next is None

        # Can't "free(self)" in python :)


def indx_print(el):
    while el.prev is not None: el = el.prev
    while el is not None:
        print(f"{el.indx}, ", end="")
        el = el.next
    print("")
