# packages\python\src\concepts\iteration\test_iteration.py

import pytest

from .solution import (
    sum_list,
    count_greater_than,
    max_or_throw,
    reverse_in_place,
)


def test_sum_list_handles_empty_and_basic():
    assert sum_list([]) == 0
    assert sum_list([1]) == 1
    assert sum_list([1, 2, 3]) == 6
    assert sum_list([-2, 5, -3]) == 0


def test_count_greater_than_basic():
    assert count_greater_than([], 10) == 0
    assert count_greater_than([1, 2, 3], 2) == 1
    assert count_greater_than([5, 5, 5], 4) == 3
    assert count_greater_than([-1, 0, 1], 0) == 1


def test_max_or_throw_behaviour():
    with pytest.raises(ValueError):
        max_or_throw([])

    assert max_or_throw([7]) == 7
    assert max_or_throw([1, 9, 3]) == 9
    assert max_or_throw([-10, -2, -30]) == -2


def test_reverse_in_place_basic():
    a: list[int] = []
    reverse_in_place(a)
    assert a == []

    b = [1]
    reverse_in_place(b)
    assert b == [1]

    c = [1, 2, 3, 4]
    reverse_in_place(c)
    assert c == [4, 3, 2, 1]

