export function sum(xs: number[]): number {
  return xs.reduce((acc, v) => acc + v, 0);
}

export function countGreaterThan(xs: number[], threshold: number): number {
  let c = 0;
  for (const v of xs) if (v > threshold) c++;
  return c;
}

export function maxOrThrow(xs: number[]): number {
  if (xs.length === 0) throw new Error("empty input");
  let m = xs[0]!;
  for (let i = 1; i < xs.length; i++) {
    if (xs[i]! > m) m = xs[i]!;
  }
  return m;
}

export function reverseInPlace(xs: number[]): void {
  let i = 0;
  let j = xs.length - 1;
  while (i < j) {
    const tmp = xs[i]!;
    xs[i] = xs[j]!;
    xs[j] = tmp;
    i++;
    j--;
  }
}
