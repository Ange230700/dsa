// packages\ts\src\concepts\iteration\test.ts

import { describe, expect, it } from "vitest";
import { sum, countGreaterThan, maxOrThrow, reverseInPlace } from "./solution";

describe("iteration", () => {
  it("sum handles empty + basics", () => {
    expect(sum([])).toBe(0);
    expect(sum([1])).toBe(1);
    expect(sum([1, 2, 3])).toBe(6);
    expect(sum([-2, 5, -3])).toBe(0);
  });

  it("countGreaterThan works", () => {
    expect(countGreaterThan([], 10)).toBe(0);
    expect(countGreaterThan([1, 2, 3], 2)).toBe(1);
    expect(countGreaterThan([5, 5, 5], 4)).toBe(3);
    expect(countGreaterThan([-1, 0, 1], 0)).toBe(1);
  });

  it("maxOrThrow throws on empty", () => {
    expect(() => maxOrThrow([])).toThrow();
    expect(maxOrThrow([7])).toBe(7);
    expect(maxOrThrow([1, 9, 3])).toBe(9);
    expect(maxOrThrow([-10, -2, -30])).toBe(-2);
  });

  it("reverseInPlace reverses", () => {
    const a: number[] = [];
    reverseInPlace(a);
    expect(a).toEqual([]);

    const b = [1];
    reverseInPlace(b);
    expect(b).toEqual([1]);

    const c = [1, 2, 3, 4];
    reverseInPlace(c);
    expect(c).toEqual([4, 3, 2, 1]);
  });
});
