func IsPrime(param n int, m int) (bool, error):
  for i in 2...n / 2:
    if n % i == 0:
      return false, nil
  return true, nil
