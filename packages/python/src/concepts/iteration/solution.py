# packages\python\src\concepts\iteration\solution.py

from __future__ import annotations


def sum_list(xs: list[int]) -> int:
    return sum(xs)


def count_greater_than(xs: list[int], threshold: int) -> int:
    return sum(1 for v in xs if v > threshold)


def max_or_throw(xs: list[int]) -> int:
    if not xs:
        raise ValueError("empty input")
    return max(xs)


def reverse_in_place(xs: list[int]) -> None:
    xs.reverse()

